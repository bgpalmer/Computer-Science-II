OBJECTS=menu_function.o cell.o plane.o main.o validation.o
CXX=g++
EXEC=prog
ZIP="palmebri_162_project1.zip"

all: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

${OBJECTS}: %.o: %.cpp
	${CXX} -c $< -o $@

clean: 
	rm ${OBJECTS} ${EXEC}

zip:
	zip ${ZIP} *
