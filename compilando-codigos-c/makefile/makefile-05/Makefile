APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src


all: libed myapps

libed: \
	$(OBJ)/float_vector.o \
	$(OBJ)/mytime.o

myapps:
	gcc $(APPS)/app.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app
	gcc $(APPS)/app_com_mytime.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/app_com_mytime


$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc -c $< -I $(INCLUDE) -o $@


run:
	./bin/app

clean:
	rm -rf ./bin/* ./obj/*
