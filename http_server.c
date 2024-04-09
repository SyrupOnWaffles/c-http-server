#include "http_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char status_200[256]= "HTTP/1.1 200 OK\r\nContent-length: 2048\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
char status_404[256]= "HTTP/1.1 404 Not Found\r\nContent-length: 2048\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";


/*Only call if you are certain path exists*/
int parse_html(char* path, char* body, int status)
{
    // switches dont work for some reason
    if(status==200){
        strncat(body,status_200,256);
    }
    else if(status==404){
        strncat(body,status_404,256);
    }
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