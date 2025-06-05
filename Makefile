CXX = g++
CXXFLAGS = -g -Wall -Isrc/

SRCMODULES = src/Window.cpp src/Render.cpp src/Texture.cpp
OBJMODULES = obj/Window.o obj/Render.o obj/Texture.o

all: tds

run: all
	./tds &

clean:
	rm $(OBJMODULES)

deps.mk: $(SRCMODULES)
	$(CXX) -MM $^ > $@

-include deps.mk

obj:
	mkdir obj

obj/%.o: src/%.cpp src/%.h obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

tds: src/main.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -lX11 -o $@




