#ifndef HTTP_SERVER_H_INCLUDED
#define HTTP_SERVER_H_INCLUDED

int parse_html(char* path, char* body);
extern char status_200[256];
extern char status_404[256];

#endif