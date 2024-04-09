# c http server

a simple http server which sends html files to clients
## compile 
compile with

```
gcc -o server main.c http_server.c
```
## run 
has two arguments!!!!
first one is address??!!
second one is ip???

example
```
./server 127.0.0.1 42069
```
will default to seeing if index.html in the current directory is available. if not it will redirect to the 404 page titled 404.html. you need a 404 page or else it will seg fault. example files are in examples folder 