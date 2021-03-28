.PHONY: all, release, debug

all: debug

release: 
	g++ -o cfastcfurious ./main.cpp ./src/server.cpp ./src/http/Request.cpp ./src/http/Response.cpp ./src/utils/errors.cpp ./src/utils/string.cpp

debug:
	g++ -g -Wall -o cfastcfurious ./src/main.cpp ./src/server.cpp ./src/http/Request.cpp ./src/http/Response.cpp  ./src/utils/errors.cpp ./src/utils/string.cpp