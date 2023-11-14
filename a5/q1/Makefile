CXX=g++
CXXFLAGS=-std=c++14 -Werror=vla
OBJECTS=flight.o flight_planner.o flightPlan.o flightPlanner.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a5q1

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY:clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
