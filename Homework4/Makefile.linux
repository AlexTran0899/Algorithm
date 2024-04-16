PROJECT_DIR=.

CFLAGS=-I${PROJECT_DIR}/include/ -std=c++14 -DUSE_AVL
CC=gcc
CXX=g++

FILES=algorithms/mst.cpp graph.cpp main.cpp

# Using OpenCV for Visualization
OPENCV=0
ifeq ($(OPENCV), 1)
	LDFLAGS+=  `pkg-config --libs opencv4`
	CFLAGS+= -DOPENCV=1 `pkg-config --cflags opencv4`
endif


SRC_DIR=${PROJECT_DIR}/src/

SRC_FILES=$(addprefix ${SRC_DIR}, ${FILES})

all: 
	$(warning "You have to type one of the following commands")
	$(warning "     Type 'make qsort' to run compile and run quick sort")
	$(warning "     Type 'make msort' to run compile and run merge sort")
	$(warning "     Type 'make hsort' to run compile and run heap sort")

qsort: ${SRC_FILES} ${SRC_DIR}sort/qsort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

hsort: ${SRC_FILES} ${SRC_DIR}sort/hsort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 
msort: ${SRC_FILES} ${SRC_DIR}sort/msort.cpp
	${CXX} ${CFLAGS} $^ ${LDFLAGS} -o bin/$@ 
	./bin/$@ 

