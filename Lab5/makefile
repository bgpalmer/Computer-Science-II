OBJS=ant.o critter.o doodlebug.o validation.o field.o helper_functions.o main.o
EXEC=prog
ZIP="palmebri_162_lab5.zip"
CXX=g++

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm -f ${OBJS} ${EXEC}

zip:
	zip ${ZIP} *

run: all
	./${EXEC}
