OBJS=main.o reverse_string.o sum.o triangular.o menu_functions.o validation.o
CXX=g++
EXEC=prog
ZIP="palmebri_162_lab4.zip"

all: complete

complete: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm ${OBJS} ${EXEC}

run: all
	./${EXEC}

zip:
	zip ${ZIP} *
