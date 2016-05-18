$gcc -c -fpic foo.c
$gcc -shared -o libfoo.so foo.o
$unset LD_LIBRARY_PATH 
$export LD_LIBRARY_PATH=`pwd`
$gcc -L `pwd` -o test main.c -lfoo
$./test
This is a shared lib test
Hello, I'm a shared lib

