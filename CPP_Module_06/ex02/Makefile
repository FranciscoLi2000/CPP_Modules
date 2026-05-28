# TEACHING FILE - Makefile for ex02
#
# PURPOSE: Compile RTTI (Runtime Type Identification) program
#
# NOTE: No implementation files for A, B, C, or Base classes
# They are header-only (classes with no member functions)
# Only main.cpp needs compilation
#
# HOWEVER: We still create .o files for object linking
# This follows standard practice even with minimal code

NAME = identify

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp
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
