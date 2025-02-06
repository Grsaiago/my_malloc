NAME = libmalloc.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m

all: help

.PHONY: help
help: ## Prints help for targets with comments
	@echo "Available Rules:"
	@cat $(MAKEFILE_LIST) | grep -E '^[a-zA-Z_-]+:.*?## .*$$' | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


.PHONY: build
build: $(NAME) $(OBJS) ## Builds the libmalloc.a lib file

# Implicit rule to teach makefile how to create each .o file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

.PHONY: clean
clean: ## Deletes the build artifacts (.o files)
	@rm -rf $(NAME).dSYM
	@rm -f $(OBJS)/*.o

.PHONY: fclean
fclean: clean ## Deletes the build artifacts (.o files) and the lib file (.a)
	@rm -f $(NAME)

.PHONY: re
re: fclean build ## Deletes all artifacts and forces recompile
