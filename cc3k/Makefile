CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = cc3k
OBJECTS = main.o textDisplay.o cell.o manager.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
