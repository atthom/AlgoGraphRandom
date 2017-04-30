#------------------------------------------------------------------------------

SOURCE=blossom/Edmonds.cpp blossom/Edmonds.h blossom/Graph.cpp blossom/Graph.h hopcroft/BipartGraph.cpp hopcroft/BipartGraph.h hopcroft/Hopcroft.cpp hopcroft/Hopcroft.h Main.cpp
MYPROGRAM= AlgoGraph


CC=g++ -std=c++11

#------------------------------------------------------------------------------



all: $(MYPROGRAM)



$(MYPROGRAM): $(SOURCE)

	$(CC) $(SOURCE) -o$(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)
