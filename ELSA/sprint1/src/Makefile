CXXFLAGS = --std=c++17

all: store

store: store.o options.o desktop.o order.o customer.o main.o
	$(CXX) $(CXXFLAGS) store.o order.o options.o desktop.o customer.o main.o -o store

store.o: store.cpp
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o

options.o: options.cpp
	$(CXX) $(CXXFLAGS) -c options.cpp -o options.o

desktop.o: desktop.cpp
	$(CXX) $(CXXFLAGS) -c desktop.cpp -o desktop.o

order.o: order.cpp
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o

customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

options.gch: options.h
	$(CXX) $(CXXFLAGS) -c options.h -o options.gch

desktop.gch: desktop.h
	$(CXX) $(CXXFLAGS) -c desktop.h -o desktop.gch

order.gch: order.h
	$(CXX) $(CXXFLAGS) -c order.h -o order.gch

customer.gch: customer.h
	$(CXX) $(CXXFLAGS) -c customer.h -o customer.gch

clean:
	rm -f *.o *.gch ~* a.out store
