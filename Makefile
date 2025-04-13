FILES := main.c shared.c
EXEC := astro

CC	= gcc
CFLAGS	= -Wall -Wextra -std=c99
LDFLAGS	= -lSDL3

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
