
BIN     := .
OBJ     := ./obj
SRC		:= .
SRCS    := $(wildcard $(SRC)/*.c)
OBJS    := $(patsubst $(SRC)/%.c,$(OBJ)/%.o,$(SRCS))
EXE     := $(BIN)/bsq
CC      := gcc


.PHONY: all run clean

all: $(EXE)

$(EXE): $(OBJS) | $(BIN)
	$(CC)  $^ -o $@

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN) $(OBJ):
	mkdir $@

run: $(EXE)
	$<

clean:
	rm -rf $(OBJ)
	rm $(EXE)
