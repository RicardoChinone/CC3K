CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k
OBJECTS = main.o gameplay.o subject.o cell.o stuff.o character.o dragon.o dwarf.o elf.o human.o halfling.o merchant.o orc.o player.o hoard.o wounddef.o gold.o restore.o woundatk.o boostatk.o boostdef.o poison.o door.o path.o empty.o tile.o stair.o wall.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

