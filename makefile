CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

OBJECTS = /tests/iaArryTest/Test_iaArray.o

program: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o program $(OBJECTS)

/tests/iaArryTest/Test_iaArray.o: /tests/iaArryTest/Test_iaArray.cpp
	$(CXX) $(CXXFLAGS) -c /tests/iaArryTest/Test_iaArray.cpp -o /tests/iaArryTest/Test_iaArray.o

clean:
	rm -f $(OBJECTS) program
