OBJS=medusa.o vampire.o creature.o harry_potter.o blue_men.o
OBJS+=helper_functions.o barbarian.o validation.o dice.o main.o
OBJS+=stack.o queue.o player.o game.o node.o
CXX=g++
ZIP="palmebri_162_assignment4.zip"
EXEC=prog

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
