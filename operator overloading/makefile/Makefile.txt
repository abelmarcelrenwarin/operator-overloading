CXX ?=g++ 
CXXFLAGS += -std=gnu++14 -O3 -Wall -Wextra -Iinclude
SOURCES = $(wildcard src/.cpp)
TARGET = rectangle

src/%.o: src/%.cpp 
    $(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(SOURCES:.cpp=.o)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f src/.o $(TARGET).exe