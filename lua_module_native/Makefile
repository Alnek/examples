SEARCH_FOR_SO_IN_CURRENT_DIR=-Wl,"-R."
FLAGS=${SEARCH_FOR_SO_IN_CURRENT_DIR}

all: test libhello.so

test: libhello.so
	g++ ${FLAGS} -L. -lhello test.cpp -o test
	
libhello.so: hello.o
	g++ -shared -fpic -llua5.2 hello.o -o libhello.so

hello.o: hello.cpp
	g++ -I/usr/include/lua5.2 -fpic -c hello.cpp

clean:
	rm -f *.o *.so test

