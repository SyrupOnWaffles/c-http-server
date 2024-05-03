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
in order to get the executable to work there has to be an index.html file in the same directory. this version of the server is a lot simpler and the path is ignored meaning no 404. 
<br><br>
<b>no compatability with external js/css so everything has to be inline. i told you this was simple<b>
<br>now go have fun and make some cool websites!!