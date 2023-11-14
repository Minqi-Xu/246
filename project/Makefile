CXX=g++
CXXFLAGS=-std=c++14
OBJECTS=main.o concretegame.o game.o observer.o player.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=straights

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
