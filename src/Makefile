CXXFLAGS = -Wall -Wextra -std=c++17 -Wno-unused-parameter -Wno-deprecated-declarations -Wno-deprecated
GLFLAGS  = -lGL -lGLU -lglut
OSXFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -framework OpenGL -framework GLUT 


# Won't make new files
.PHONY: clean

# # https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# #  $@ is the name of the target
# #  $+ is a list of all the dependencies
# #  $< is the first dependency


Prog: main.o Game.o Entity.o
	g++ $(CXXFLAGS) $+ -o $@ $(GLFLAGS)

Prog_OSX: main.o Game.o Entity.o
	g++ $(CXXFLAGS) $+ -o $@ $(OSXFLAGS)


main.o: main.cpp lib/Constants.h
	g++ $(CXXFLAGS) -c $<

Game.o: lib/Game.cpp lib/Game.h lib/Constants.h
	g++ $(CXXFLAGS) -c $<

Entity.o: lib/Entity.cpp lib/Entity.h lib/Constants.h
	g++ $(CXXFLAGS) -c $<


clean:
	rm *.o lib/*.gch Prog Prog_OSX
