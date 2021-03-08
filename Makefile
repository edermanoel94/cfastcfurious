.PHONY: all

all: debug

release: 
	g++ -o cfastcfurious ./src/main.cpp ./src/cfastcfurious.cpp

debug:
	g++ -g -o cfastcfurious ./src/main.cpp ./src/cfastcfurious.cpp ./src/utils/errors.cpp ./src/utils/string.cpp
