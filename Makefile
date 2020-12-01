.PHONY: all

all: debug


release: 
	g++ -o cfast2furious ./src/cfast2furious.cpp ./src/request.cpp

debug:
	g++ -g -o cfast2furious ./src/cfast2furious.cpp ./src/request.cpp
