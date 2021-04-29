APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src


all: libed clean_apps myapps

libed: \
	$(OBJ)/float_vector.o \
	$(OBJ)/mytime.o

myapps: \
	$(BIN)/app \
	$(BIN)/app_com_mytime

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.c
	gcc $< $(OBJ)/*.o -I $(INCLUDE) -o $@

run:
	$(BIN)/app

clean:
	rm -rf $(BIN)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*
