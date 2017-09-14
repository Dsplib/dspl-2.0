CC      = gcc
INC_DIR = src
OBJ_DIR = obj



DSPL_SRC_DIR  = src/dspl

TEST_SRC_DIR  = src/test
TEST_BIN_DIR  = bin/test

VERIF_SRC_DIR  = src/verif
VERIF_BIN_DIR  = bin/verif

PERF_SRC_DIR  = src/perf
PERF_BIN_DIR  = bin/perf

CFLAGS  = -c -Wall -O3 -I$(INC_DIR) -fopenmp

DSPL_SRC_FILES	= $(wildcard $(DSPL_SRC_DIR)/*.c)
DSPL_OBJS	    = $(addprefix $(OBJ_DIR)/,$(notdir $(DSPL_SRC_FILES:.c=.o)))

TEST_SRC_FILES = $(wildcard $(TEST_SRC_DIR)/*.c)
TEST_FILES = $(addprefix $(TEST_BIN_DIR)/,$(notdir $(TEST_SRC_FILES:.c=.out)))
			
PERF_SRC_FILES = $(wildcard $(PERF_SRC_DIR)/*.c)
PERF_FILES = $(addprefix $(PERF_BIN_DIR)/,$(notdir $(PERF_SRC_FILES:.c=.out)))

VERIF_SRC_FILES = $(wildcard $(VERIF_SRC_DIR)/*.c)
VERIF_FILES = $(addprefix $(VERIF_BIN_DIR)/,$(notdir $(VERIF_SRC_FILES:.c=.out)))			                  
 



all: $(DSPL_OBJS) $(VERIF_FILES) $(TEST_FILES) $(PERF_FILES)
		

$(OBJ_DIR)/%.o:$(DSPL_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_BIN_DIR)/%.out: $(OBJ_DIR)/%.o  $(DSPL_OBJS)
	$(CC) $(DSPL_OBJS) $< -o $@

$(OBJ_DIR)/%.o:$(TEST_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(PERF_BIN_DIR)/%.out: $(OBJ_DIR)/%.o  $(DSPL_OBJS)
	$(CC) $(DSPL_OBJS) $< -o $@

$(OBJ_DIR)/%.o:$(PERF_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(VERIF_BIN_DIR)/%.out: $(OBJ_DIR)/%.o  $(DSPL_OBJS)
	$(CC)  $(DSPL_OBJS) -o $< -o $@

$(OBJ_DIR)/%.o:$(VRIF_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@



$(TEST_FILES):	 $(INC_DIR)/dspl.h
$(PERF_FILES):	 $(INC_DIR)/dspl.h 
$(VERIF_FILES):	 $(INC_DIR)/dspl.h 
$(DSPL_OBJS):	 $(INC_DIR)/dspl.h


clean:
	rm -f   $(OBJ_DIR)/*.o
	rm -f   $(TEST_BIN_DIR)/*.out
	rm -f   $(VERIF_BIN_DIR)/*.out
	rm -f   $(PERF_BIN_DIR)/*.out


print-%  : ; @echo $* = $($*)

	                                                                      
