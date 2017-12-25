#Makefile roñas
BIN_FILES = delreves
CC = gcc
CCGLAGS = -g -Wall -Wextra

all: CFLAGS=$(CCGLAGS)
all: $(BIN_FILES)
.PHONY: all

delreves: auxiliar.h auxiliar.c delreves.c
	@echo "\033[0;33mGenerating program 'delreves' for tarea-1.1 ...\033[0m"
	@$(CC) $(CFLAGS) -o delreves delreves.c auxiliar.c
	@echo "\033[0;32m[DONE]\033[0m"

clean:
	@echo "\033[0;33mCleaning all files form tarea-1.1 ...\033[0m"
	rm -f $(BIN_FILES) *.o
