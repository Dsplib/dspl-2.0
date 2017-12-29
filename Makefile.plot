CC      = gcc
INC_DIR = include
LIB_DIR = lib/plot

SRC_DIR = $(LIB_DIR)/src
OBJ_DIR = $(LIB_DIR)/obj
BIN_DIR = $(LIB_DIR)/bin

LIB_NAME = libplot.a


CFLAGS  = -c -Wall -O3 -I$(INC_DIR)

SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

all: $(BIN_DIR)/$(LIB_NAME)


$(BIN_DIR)/$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(BIN_DIR)/$(LIB_NAME)  $(OBJ_FILES)

#	$(CC) -shared -o $(BIN_DIR)/$(LIB_NAME)  $(OBJ_FILES)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS)  $< -o $@


clean:
	rm -f   $(OBJ_DIR)/*.o
	rm -f   $(BIN_DIR)/*.so
	rm -f   $(BIN_DIR)/*.a
