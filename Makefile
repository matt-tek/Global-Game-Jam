CXX	=	g++

CXXFLAGS	=	

CXXLFLAGS	=	-l jsoncpp

SRC	=	main.cpp \
		player.cpp \
		game.cpp


all:
	$(CXX) $(CXXFLAGS) -o main $(SRC) $(CXXLFLAGS)

clean:
	rm -f main

fclean: clean
	rm -rf *.o	
	rm vgcore*

re: fclean all