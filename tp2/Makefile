CC=g++
CFLAGS=-std=c++11 -Wall

BUILD_DIR=./build
SRC_DIR=./src
INCLUDE_DIR=./include

EXEC=./tp2
TARGET=tp2
TESTS_TARGET=uno_tests
TMPOUT=tp2.testresult

$(EXEC): ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/list.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/list.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/list/list.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/list/list.cpp -o ${BUILD_DIR}/list.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

test: $(EXEC)
	@bash run_tests.sh ${BUILD_DIR}/$(EXEC) $(TMPOUT)


clean:
	rm -f ${BUILD_DIR}/*