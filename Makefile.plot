LIB_DIR    = lib/plot
COMMON_DIR = lib/common

include Makefile.dirs

SRC_DIR = $(LIB_DIR)/src
OBJ_DIR = $(LIB_DIR)/obj

LIB_NAME = libplot.a

CFLAGS  = -c -Wall -O3 -I$(INC_DIR)

SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	= $(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

all: $(RELEASE_DIR)/$(LIB_NAME)


$(RELEASE_DIR)/$(LIB_NAME): $(OBJ_FILES) $(COMMON_OBJ_FILES)
	ar rcs $(RELEASE_DIR)/$(LIB_NAME)  $(OBJ_FILES)


$(OBJ_DIR)/%.o:$(COMMON_SRC_DIR)/%.c
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS)  $< -o $@

clean:
	rm -f   $(OBJ_DIR)/*.o
	rm -f   $(RELEASE_DIR)/$(LIB_NAME)
