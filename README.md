# c http server

a simple http server which sends html files to clients
## compile 
compile with

```
gcc -o server main.c http_server.c
```
## run 
has two arguments!!!!
first one is ipv4
second one is port

example
```
./server 127.0.0.1 42069
```
in order to get the executable to work there has to be at least a 404.html file and preferably an index.html file. both need to be in the same directory as the executable