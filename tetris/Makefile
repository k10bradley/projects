CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = tetris
OBJECTS = block.o shape.o oShape.o iShape.o jShape.o lShape.o tShape.o sShape.o zShape.o cell.o game.o textDisplay.o subject.o main.o factory.o factory1.o controller.o trie.o testFactory.o factory2.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
