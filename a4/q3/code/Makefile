CXX=g++
CXXFLAGS=-std=c++14 -Werror=vla
OBJECTS=main.o cell.o grid.o observer.o textdisplay.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q3

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
