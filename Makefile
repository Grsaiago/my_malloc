NAME = a.out

SRC = $(wildcard *.c)

CFLAGS = -g -Wall -Wextra

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "$(COLOR_GREEN)Test Compiled"$(COLOR_END)

clean:
	@rm -rf $(NAME).dSYM
	@echo "$(COLOR_GREEN)Test clean$(COLOR_END)"

re: clean all

.PHONY: all clean re
