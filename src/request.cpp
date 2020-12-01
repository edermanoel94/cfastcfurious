#include "request.hpp"
#include <iostream>

#define SEP_NEW_LINE "\r\n"
#define STEP_SIZE 20

Request::Request(char* raw_data) {

    char* line;

    char** lines = NULL;

    strtok(raw_data, SEP_NEW_LINE);
    
    int lines_count = 0;

    int i = 0;

    while (line != NULL) {
        
        if (i == lines_count) {

            lines_count += STEP_SIZE;
        }

        lines = (char **) realloc(NULL, lines_count * sizeof(char *));

        line = strtok(NULL, SEP_NEW_LINE);

        lines[i] = line;

        lines_count++;

        i++;
    }

    for (int i = 0; i < lines_count; i++) {

        std::cout << lines[i] << std::endl;
    }

    free(lines);

//    char *token;
//
//    char temp_data[4096];
//
//    std::cout << raw_data << std::endl;
//
//    memset(temp_data, 0, 4096);
//
//    // TODO: strcopy its not good, because buffer overflow, its better to use strncopy to set the length.
//    strcpy(temp_data, raw_data);
//
//    strtok(temp_data, " ");
//
//    while (token != NULL) {
//
//        token = strtok(NULL, " ");
//
//        std::cout << "token: " << token << std::endl;
//    }
//
}
