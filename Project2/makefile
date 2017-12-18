OBJS=validation.o helper_functions.o list.o item.o main.o
CXX=g++
EXEC=prog
ZIP="palmebri_162_assignment2.zip"


all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm ${OBJS} ${EXEC}

run: all
	./${EXEC}

zip:
	zip ${ZIP} *
