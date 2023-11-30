CXXFLAGS = -Wall -Wextra -std=c++17 -Wno-unused-parameter
GLFLAGS = -lGL -lGLU -lglut
BREWFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib


# Won't make new files
.PHONY: clean

# # https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# #  $@ is the name of the target
# #  $+ is a list of all the dependencies
# #  $< is the first dependency


Prog: main.o Game.o Entity.o
	g++ $(CXXFLAGS) $+ -o $@ $(BREWFLAGS) $(GLFLAGS)


main.o: main.cpp
	g++ $(CXXFLAGS) -c $<

Game.o: lib/Game.cpp lib/Game.h
	g++ $(CXXFLAGS) -c $<

Entity.o: lib/Entity.cpp lib/Entity.h
	g++ $(CXXFLAGS) -c $<


clean:
	rm *.o lib/*.gch Prog
