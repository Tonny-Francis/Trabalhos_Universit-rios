all:
	g++ -c ./cpp/class.cpp -I ./Headers  -o ./bin/class.o
	g++ -c ./cpp/functions.cpp -I ./Headers  -o ./bin/functions.o
	g++ ./cpp/main.cpp ./bin/*.o -I ./Headers -o ./exe/main

clean:
	rm ./bin/*.o ./exe/main
run:
	./exe/main