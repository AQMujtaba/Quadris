CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g
OBJECTS=main.o abstractblock.o abstractlevel.o cell.o commandinterpreter.o graphicsdisplay.o grid.o iblock.o jblock.o lblock.o level0.o level1.o level2.o level3.o level4.o oblock.o quadris.o sblock.o scorekeeper.o subject.o tblock.o textdisplay.o window.o zblock.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=main
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
