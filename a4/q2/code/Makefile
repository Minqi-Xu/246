CXX=g++
CXXFLAGS=-std=c++14 -Werror=vla
OBJECTS=main.o basic.o decorator.o exception.o flip.o image.o ppm.o rotate.o sepia.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q2

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
