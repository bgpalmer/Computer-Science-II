OBJS=main.o menu_functions.o validation.o main_menu.o queue.o
CXX=g++
EXEC=prog
ZIP="palmebri_162_lab6.zip"

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm -f ${OBJS} ${EXEC} ${ZIP}

zip:
	zip ${ZIP} *

run: all
	./${EXEC}
