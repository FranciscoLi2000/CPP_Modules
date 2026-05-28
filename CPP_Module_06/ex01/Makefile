# TEACHING FILE - Makefile for ex01
#
# PURPOSE: Compile serialization/deserialization program
#
# PATTERN: Same as ex00, with additional source files
#
# FILES COMPILED:
# - main.cpp: testing code
# - Serializer.cpp: serialize/deserialize implementation
# - Data.cpp: Data struct (minimal, mostly header-based)
#
# COMPILATION ORDER (handled by make automatically):
# 1. Compile each .cpp to .o
# 2. Link all .o files into final executable

NAME = serializer

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Serializer.cpp Data.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
