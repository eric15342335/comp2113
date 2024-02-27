gcd.o: gcd.cpp gcd.h
	g++ -c $<

lcm.o: lcm.cpp lcm.h
	g++ -c $<

calc.o: calc.cpp
	g++ -c $<

calc: gcd.o lcm.o calc.o
	g++ $^ -o $@

clean:
	rm *.o calc

.PHONY: clean
