# TEACHING FILE - Makefile for ex00
#
# PURPOSE: Compile C++ project with proper flags and rules
#
# LEARNING FROM PREVIOUS MODULES:
# - CPP00: Learned basic Makefile structure
# - CPP01-CPP05: Consistently used this pattern for building
# - CPP06: Same compilation approach, now with casting operators
#
# KEY CONCEPTS:
# 1. CXX: C++ compiler (g++ or clang++)
# 2. CXXFLAGS: Compilation flags for safety and standards compliance
# 3. TARGET: Final executable name
# 4. SOURCES: .cpp files to compile
# 5. OBJECTS: Intermediate .o files (object code)
#
# COMPILATION PROCESS:
# .cpp files --[compiler]--> .o files --[linker]--> executable
#
# WHY THESE FLAGS?
# - -Wall: Show all warnings
# - -Wextra: Show extra warnings
# - -Werror: Treat warnings as errors (forces clean code)
# - -std=c++98: Use C++98 standard (42 school requirement)
#   (No C++11 features like nullptr, auto, etc.)

NAME = convert

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp ScalarConverter.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# DEFAULT TARGET: make (builds the executable)
all: $(NAME)

# LINKING RULE:
# Takes all .o files and creates the final executable
# $^ = all dependencies (OBJECTS)
# $@ = target name (NAME)
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# COMPILATION RULE:
# Takes each .cpp file and creates corresponding .o file
# $< = first dependency (.cpp file)
# $@ = target (.o file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# CLEAN RULE: Remove object files
clean:
	rm -f $(OBJECTS)

# FCLEAN RULE: Remove everything except source code
fclean: clean
	rm -f $(NAME)

# RE RULE: Clean and rebuild everything
re: fclean all

# PHONY TARGETS: These don't represent actual files
.PHONY: all clean fclean re
