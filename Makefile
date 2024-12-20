#Files
EXEC := vanilla_option
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))
#Options
CC := g++
CFLAGS := -Ofast
# Rules
$(EXEC): $(OBJ)
	$(CC) -std=c++17 -o $@ $^
%.o: %.cpp
	$(CC) -std=c++17 -c $(CFLAGS) $<
# $(EXEC):vanilla_option.o
# 	$(CC) -std=c++17 -lc++ -o vanilla_option vanilla_option.o
# vanilla_option.o:vanilla_option.cpp
# 	$(CC) -std=c++17 $(CFLAGS) -c vanilla_option.cpp
vanilla_option.o main.o : vanilla_option.h

all: $(EXEC)
#Cleaning
.PHONY: clean neat echo
clean: neat
	$(RM) $(OBJ) $(EXEC)
neat:
	$(RM) *~ .*~
echo:
	@echo $(OBJ)