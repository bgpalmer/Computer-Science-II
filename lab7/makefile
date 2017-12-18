OBJS=binary_menu.o linear_menu.o main_menu.o menu.o validation.o menu_functions.o search.o main.o sort_menu.o selection_sort.o
CXX=g++
ZIP="palmebri_162_lab7.zip"
EXEC=prog

all: ${OBJS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: %.o: %.cpp
	${CXX} -c $< -o $@

run: all
	./${EXEC}

clean:
	rm -f ${OBJS} ${EXEC}
