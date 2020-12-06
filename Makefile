.PHONY: all

all: debug

release: 
	g++ -o cfastcfurious ./src/cfastcfurious.cpp ./src/request.cpp

debug:
	g++ -g -o cfastcfurious ./src/main.cpp ./src/cfastcfurious.cpp ./src/request.cpp ./src/string_utils.cpp
