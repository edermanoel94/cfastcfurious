.PHONY: all

all: debug

release: 
	g++ -o cfastcfurious ./src/main.cpp ./src/cfastcfurious.cpp ./src/http/request.cpp ./src/utils/string.cpp

debug:
	g++ -g -o cfastcfurious ./src/main.cpp ./src/cfastcfurious.cpp ./src/http/request.cpp ./src/utils/string.cpp
