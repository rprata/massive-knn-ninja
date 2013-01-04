CC = gcc
BIN = bin/main
INCLUDES = -I./includes
LIBS = -lm
SOURCE = main.c core.c list.c

MKDIR_P = mkdir -p bin/
RM_RF = rm -rf bin/

all:
	$(MKDIR_P)
	$(CC) -o $(BIN) $(SOURCE) $(INCLUDES) $(LIBS)

clean:
	$(RM_RF)
