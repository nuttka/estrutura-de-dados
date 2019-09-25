CC=g++
CFLAGS=-std=c++11 -Wall

BUILD_DIR=./build
SRC_DIR=./src
INCLUDE_DIR=./include
# TESTS_DIR=./tests

TARGET=main
# TESTS_TARGET=uno_tests

all: ${BUILD_DIR}/${TARGET} # ${TESTS_DIR}/${TESTS_TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/list.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/list.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/list/list.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/list/list.cpp -o ${BUILD_DIR}/list.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o


# ${TESTS_DIR}/${TESTS_TARGET}: ${TESTS_DIR}/list.o ${TESTS_DIR}/main_test.o
# 	${CC} ${CFLAGS} -o ${TESTS_DIR}/${TESTS_TARGET} ${TESTS_DIR}/*.o

# ${TESTS_DIR}/list.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/list/list.cpp
# 	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/list/list.cpp -o ${TESTS_DIR}/list.o

# ${TESTS_DIR}/main_test.o: ${INCLUDE_DIR}/list/list.hpp ${SRC_DIR}/main_test.cpp
# 	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/list/ -c ${SRC_DIR}/main_test.cpp -o ${TESTS_DIR}/main_test.o


clean:
	rm -f ${BUILD_DIR}/*
	# rm -f ${TESTS_DIR}/*