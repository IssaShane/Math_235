CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD
EXEC=235
OBJECTS=main.o vector.o _vector.o matrix.o system.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm *.o *.d
