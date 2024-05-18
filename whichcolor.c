#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_to_clipboard(const char *text) {
    char command[256];
    snprintf(command, sizeof(command), "echo -n '%s' | xclip -selection clipboard", text);
    system(command);
}

int main(int argc, char *argv[]) {
    int copy_to_clip = 0;

    // Parse command-line arguments
    if (argc > 1 && strcmp(argv[1], "-c") == 0) {
        copy_to_clip = 1;
    }

    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Failed to open display\n");
        exit(1);
    }

    Window root = DefaultRootWindow(display);
    Cursor cursor = XCreateFontCursor(display, XC_crosshair);

    XEvent event;
    XButtonEvent *button_event;

    XGrabPointer(display, root, True, ButtonPressMask, GrabModeAsync,
                 GrabModeAsync, root, cursor, CurrentTime);

    while (1) {
        XNextEvent(display, &event);
        if (event.type == ButtonPress) {
            button_event = (XButtonEvent *)&event;
            break;
        }
    }

    XUngrabPointer(display, CurrentTime);
    XFreeCursor(display, cursor);

    int x = button_event->x;
    int y = button_event->y;

    XColor color;
    XImage *image = XGetImage(display, root, x, y, 1, 1, AllPlanes, ZPixmap);
    color.pixel = XGetPixel(image, 0, 0);
    XFree(image);

    XQueryColor(display, DefaultColormap(display, DefaultScreen(display)), &color);

    printf("Color information for pixel at (%d, %d):\n", x, y);
    printf("RGB: (%d, %d, %d)\n", color.red / 256, color.green / 256, color.blue / 256);
    char hex_code[8];
    snprintf(hex_code, sizeof(hex_code), "#%02x%02x%02x", color.red / 256, color.green / 256, color.blue / 256);
    printf("HEX: %s\n", hex_code);

    if (copy_to_clip) {
        copy_to_clipboard(hex_code);
        printf("Hex code copied to clipboard\n");
    }

    XCloseDisplay(display);
    return 0;
}

