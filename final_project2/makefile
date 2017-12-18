OBJS=main.o space.o world.o mess_hall.o validation.o helper_functions.o player.o creature.o
OBJS+=soda.o soda_machine.o machine.o item.o node.o stack.o office.o queue.o
OBJS+=water.o loading_bay.o floor.o bathroom.o conveyor_belt.o key.o menu.o

CXX=g++
EXEC=prog
ZIP="palmebri_162_final.zip"

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
