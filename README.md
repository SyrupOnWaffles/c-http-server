# c http server

a simple http server which sends html files to clients
## compile 
compile with

```
gcc -o server main.c http_server.c
```
has all standard libs and will compile happily on linux
## run 
has two arguments!!!!<br>
first one is ipv4<br>
second one is port<br>

example
```
./server 127.0.0.1 42069
```
in order to get the executable to work there has to be at least a 404.html file and preferably an index.html file. both need to be in the same directory as the executable