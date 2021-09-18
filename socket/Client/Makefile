SRC=$(shell find ./src/ -name "*.cpp" -type f)
$(shell mkdir -p objects)
PROJ=cliente
OBJ=$(patsubst ./src%, ./objects%, $(patsubst %.cpp, %.o , $(SRC)))
FLAGS= -std=c++17 -Wall -Wextra -Wshadow -Werror -I include

all: $(PROJ)

$(PROJ): $(OBJ)
	g++ -o $@ $^ $(FLAGS)

objects/%.o: src/%.cpp
	g++ -c -o $@ $^ $(FLAGS)

run: $(PROJ)
	./$(PROJ)

clean:
	@find . -type f -name "*.o" -exec rm '{}' \;
	@find . -type f -name "$(PROJ)" -exec rm '{}' \;

remake:
	$(MAKE) clean
	$(MAKE)

runmake:
	$(MAKE) remake
	$(MAKE) run

valgrind:
	$(MAKE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROJ)