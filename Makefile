CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lX11

EXEC = whichcolor
SRC = whichcolor.c

.PHONY: all clean install uninstall

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f $(EXEC)

install: $(EXEC)
	sudo install -m 755 $(EXEC) /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/$(EXEC)

