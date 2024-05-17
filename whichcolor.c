#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>  // Include this header for cursor constants
#include <stdio.h>
#include <stdlib.h>

int main() {
    Display *display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Failed to open display\n");
        exit(1);
    }

    Window root = DefaultRootWindow(display);
    Cursor cursor = XCreateFontCursor(display, XC_crosshair);  // Use the XC_crosshair constant from cursorfont.h

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
    printf("HEX: #%02x%02x%02x\n", color.red / 256, color.green / 256, color.blue / 256);

    XCloseDisplay(display);
    return 0;
}
