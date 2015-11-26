CXXFLAGS+=-Wall -O2 -fPIC -std=c++14
LIBFLAGS=`pkg-config --cflags gtkmm-2.4 libxml++-2.6`
LIBS=`pkg-config --libs gtkmm-2.4 libcurl libxml++-2.6`

all: ui.o utils.o main.o
	gcc -shared main.o ui.o utils.o -o ddb_lyricbar.so $(LIBS)
ui.o: ui.cpp
	g++ $(CXXFLAGS) ui.cpp -c $(LIBFLAGS)
utils.o: utils.cpp
	g++ $(CXXFLAGS) utils.cpp -c $(LIBFLAGS)
main.o: main.c
	gcc -Wall -fPIC -std=c11 -D_GNU_SOURCE main.c -c `pkg-config --cflags gtkmm-2.4`
install:
	cp *.so /usr/lib/deadbeef/
clean:
	rm -f *.o *.so

