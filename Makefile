WIDTH = 800
HEIGHT = 600

FILES := main.c shared.c
EXEC := astro

CC	= gcc
CFLAGS	= -Wall -Wextra -std=c99 -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
LDFLAGS	= -lSDL2 -lSDL2_ttf -lm -lrt

run: $(FILES)
	$(CC) main.c -o $(EXEC) $(LDFLAGS) $(CFLAGS)
	@echo "Code compiled"
	clear -x
	@./$(EXEC)

compile:
	$(CC) main.c -o $(EXEC) $(LDFLAGS) $(CFLAGS)
	@echo "Code compiled"

clean:
	rm -f $(EXEC)
