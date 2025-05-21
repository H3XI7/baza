CXX = g++
CXXFLAGS = -fopenmp -O3 -std=c++17

APP = app

all: $(APP)

$(APP): main.cpp biblioteka.cpp biblioteka.h
	$(CXX) $(CXXFLAGS) -o $(APP) main.cpp biblioteka.cpp

run: all
	./$(APP)

clean:
	rm -f $(APP)