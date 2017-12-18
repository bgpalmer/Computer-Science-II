OBJECTS=determinant.o matrix.o main.o
GXX=g++
EXEC=prog

all: ${OBJECTS}
	${GXX} ${OBJECTS} -o ${EXEC}

${OBJECTS}: %.o: %.cpp
	${GXX} -c $< -o $@

clean: 
	rm ${OBJECTS} ${EXEC}
