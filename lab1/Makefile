all: game
game: bin main.o userAction.o field.o field_image.o cell.o pass_cell.o entity.o
	g++ -std=c++17 bin/main.o bin/userAction.o bin/field.o bin/field_image.o bin/cell.o bin/pass_cell.o bin/entity.o -o game

main.o: src/main.cpp 
	g++ -std=c++17 -c src/main.cpp -o bin/main.o

userAction.o: src/userAction.cpp
	g++ -std=c++17 -c src/userAction.cpp -o bin/userAction.o

field.o: src/field.cpp
	g++ -std=c++17 -c src/field.cpp -o  bin/field.o

field_image.o: src/field_image.cpp
	g++ -std=c++17 -c src/field_image.cpp -o bin/field_image.o

cell.o: src/cell.cpp
	g++ -std=c++17 -c src/cell.cpp -o bin/cell.o

pass_cell.o: src/pass_cell.cpp
	g++ -std=c++17 -c src/pass_cell.cpp -o bin/pass_cell.o

entity.o: src/entity.cpp 
	g++ -std=c++17 -c src/entity.cpp -o bin/entity.o


