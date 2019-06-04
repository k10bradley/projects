CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = hanabi
OBJECTS = main.o card.o player.o deck.o game.o human.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
