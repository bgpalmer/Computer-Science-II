OBJS=main.o node.o queue.o menu.o queue_menu.o stack_menu.o stack.o menu_functions.o validation.o main_menu.o
CXX=g++
EXEC=prog

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm -f ${OBJS} ${EXEC}

run: all
	./${EXEC}
