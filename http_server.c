#include "http_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char status_200[256]= "HTTP/1.1 200 OK\r\nContent-length: 32768\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";

/*Only call if you are certain path exists*/
int parse_html(char* path, char* body)
{
    strncat(body,status_200,256);
    FILE* filePointer;
    int bufferLength = 1024;
    char buffer[bufferLength];

    filePointer = fopen(path, "r");
    
    while(fgets(buffer, bufferLength, filePointer)) {
        strncat(buffer,"\r\n",8);
        strncat(body,buffer,bufferLength);
    }
    fclose(filePointer);

}