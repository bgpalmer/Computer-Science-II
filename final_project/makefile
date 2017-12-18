OBJS=world.o world_test.o town.o field.o space.o helper_functions.o validation.o
OBJS+=garden.o campfire.o item.o plant.o pack.o
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
