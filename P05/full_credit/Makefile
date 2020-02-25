CXXFLAGS = --std=c++17

all: store

store: store.o taxfree.o taxed.o product.o *.h
	$(CXX) $(CXXFLAGS) store.o product.o taxfree.o taxed.o -o store

store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o

taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o

taxed.o: taxed.cpp *.h
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o

product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o

product.gch: product.h
	$(CXX) $(CXXFLAGS) -c product.h -o product.gch

taxfree.gch: taxfree.h
	$(CXX) $(CXXFLAGS) -c taxfree.h -o taxfree.gch

taxed.gch: taxed.h
	$(CXX) $(CXXFLAGS) -c taxed.h -o taxed.gch

clean:
	rm -f *.o *.gch ~* a.out store
