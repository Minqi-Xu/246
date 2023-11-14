CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD
OBJECTS = position.o drone.o main.o 
DEPENDS = ${OBJECTS:.o=.d}
EXEC = drone

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
