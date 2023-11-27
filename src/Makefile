CXXFLAGS = -Wall -Wextra -std=c++17 -Wno-unused-parameter
GLFLAGS = -lGL -lGLU -lglut


# Won't make new files
.PHONY: clean

# # https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# #  $@ is the name of the target
# #  $+ is a list of all the dependencies
# #  $< is the first dependency


Game: game.o
	g++ $(CXXFLAGS) $+ -o $@ $(GLFLAGS)


game.o: game.cpp
	g++ $(CXXFLAGS) -c $<



clean:
	rm *.o lib/*.gch Game
