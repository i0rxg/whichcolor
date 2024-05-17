CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lX11

SRCDIR = src
BINDIR = bin

EXEC = whichcolor
SRC = $(SRCDIR)/whichcolor.c

.PHONY: all clean install uninstall

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -rf $(BINDIR)

install: $(BINDIR)/$(EXEC)
	sudo cp $(BINDIR)/$(EXEC) /usr/local/bin/

uninstall:
	sudo rm -f /usr/local/bin/$(EXEC)
