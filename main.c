#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <stdlib.h>
#include <pthread.h>
#include "http_server.h"

// default ip
int port = 8080;
char* ip = "127.0.0.1";

#define max_file_send_size 60000

int visit_count = 0;

void handle_client(int client_fd){
    visit_count += 1;

    char body[max_file_send_size] = {0};
    char footer[256];
    sprintf(footer,"<center><footer>visit count: %d</footer></center>\r\n",visit_count);
    char recv_buf[256] = {0};
    recv(client_fd, recv_buf, 256, 0);

    char* f = recv_buf + 5;
    char * token = strtok(f, " ");
    
    // check if file request is empty and redirect to index.html. only works with get requests and will prolly crash on post request
    if(recv_buf[5]==32){
        // check if file exists
        FILE* file;
        if((file = fopen("index.html","r"))!=NULL)
                {
                    parse_html("index.html",&body,200);
                    strcat(body,footer);
                    send(client_fd,body,max_file_send_size,0);
                }
            else
                {
                    parse_html("404.html",&body,404);
                    send(client_fd,body,max_file_send_size,0);
                }
    }
    else{
        // check if file exists
        FILE* file;
        if((file = fopen(token,"r"))!=NULL)
                {
                    parse_html(token,&body,200);
                    strcat(body,footer);
                    send(client_fd,body,max_file_send_size,0);
                }
            else
                {
                    parse_html("404.html",&body,404);
                    send(client_fd,body,max_file_send_size,0);
                }
    }
}

void check(int function,char* error_msg){
    if(function == -1){
        fflush(stdout);
        printf("%s\n",error_msg);
        exit(-1);
    }
}

int main(int argc, char const *argv[])
{
    fflush(stdout);
    if(argc>1){
        ip = argv[1];
        if(argc>2){
            port = atoi(argv[2]);
        }
    }
    else{
        fflush(stdout);
        printf("no address or port specified, using defaults\n");
    }
    // start server
    printf("starting server at %s:%d\n",ip,port);
    int s = socket(AF_INET,SOCK_STREAM,0);
    check(s,"error making socket");
    struct sockaddr_in addr = {
        AF_INET,
        htons(port),
        0,
    };
    inet_aton(ip,&addr.sin_addr.s_addr);
    check(bind(s,&addr,sizeof(addr)),"error binding");
    check(listen(s,10),"error listening");

    while(1){
        int client_fd = accept(s, 0, 0);
        pthread_t thread_id; 
        pthread_create(&thread_id, NULL, handle_client, client_fd); 
        pthread_join(thread_id,0);
    }



    return 0;
}