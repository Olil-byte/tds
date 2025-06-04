CXX = g++
CXXFLAGS = -g -Wall -Isrc/

SRCMODULES = src/Window.cpp src/Render.cpp src/Texture.cpp
OBJMODULES = obj/Window.o obj/Render.o obj/Texture.o

obj/%.o: src/%.cpp src/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

tds: src/main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -lX11 -o $@

-include deps.mk

deps.mk: $(SRCMODULES)
	$(CXX) -MM $^ > $@

all: tds

run: all
	./tds &

clean:
	rm $(OBJMODULES)
