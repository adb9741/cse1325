CXXFLAGS = --std=c++17

all: cart

cart: main.o cart.o item.o *.h
	$(CXX) $(CXXFLAGS) main.o cart.o item.o -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

cart.o: cart.cpp *.h
	$(CXX) $(CXXFLAGS) -c cart.cpp -o cart.o

item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o

cart.gch: cart.h
	$(CXX) $(CXXFLAGS) -c cart.h -o cart.gch

item.gch: item.h
	$(CXX) $(CXXFLAGS) -c item.h -o item.gch

clean:
	rm -f *.o *.gch ~* a.out cart
