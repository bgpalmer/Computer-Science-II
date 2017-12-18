OBJS=person.o menu_functions.o validation.o loaded_dice.o main.o game.o dice.o
EXEC=prog
ZIP="palmebri_162_Lab3.zip"
CXX=g++

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean:
	rm ${OBJS} ${EXEC} *.txt

zip:
	zip ${ZIP} * 

