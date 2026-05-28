# TEACHING FILE - CPP07 ex00: Makefile for template functions
# 
# This Makefile compiles C++ source files with the required flags
# following the CPP Modules standards.
#
# COMPILATION FLAGS EXPLAINED:
# - c++: C++ compiler (same as g++ or clang++)
# - -Wall: Enable all standard compiler warnings
#   Helps catch common mistakes and suspicious code
# - -Wextra: Enable extra compiler warnings beyond -Wall
#   Catches more potential issues
# - -Werror: Treat all warnings as errors
#   Forces you to fix warnings before code will compile
# - -std=c++98: Use C++98 standard (original C++, no C++11 features)
#   Ensures compatibility, this course uses C++98 baseline

# NAME: executable name
NAME = template_test

# FLAGS: compilation flags for C++98 standard
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# CXX: C++ compiler command
CXX = c++

# SOURCE FILES: which .cpp files to compile
# Note: We only need main.cpp
# template.hpp will be included by the compiler when processing main.cpp
SRCS = main.cpp

# OBJECT FILES: .cpp files become .o files (intermediate compiled form)
# This substitution changes .cpp -> .o
# Example: main.cpp becomes main.o
OBJS = $(SRCS:.cpp=.o)

# PHONY TARGETS: targets that don't represent actual files
# Tells make: these are commands, not file names
.PHONY: all clean fclean re

# DEFAULT TARGET: 'make' with no arguments does this
all: $(NAME)

# RULE TO CREATE EXECUTABLE:
# $(NAME): the executable name (template_test)
# $(OBJS): depends on all .o object files
# $(CXX) $(OBJS) -o $(NAME): compile object files into executable
# 
# $^ means "all dependencies" (all .o files)
# -o specifies output file name
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# RULE TO CREATE OBJECT FILES:
# %.o: all .o files
# %.cpp: depend on corresponding .cpp file (pattern matching)
# $(CXX) $(CXXFLAGS) -c $< -o $@
#
# $<: first dependency (the .cpp file)
# $@: target file name (the .o file)
# -c: compile only, don't link
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# CLEAN TARGET: remove object files
# rm -f: remove files without asking, ignore if doesn't exist
# Keeps executable (useful for testing multiple times)
clean:
	rm -f $(OBJS)

# FCLEAN TARGET: remove everything (full clean)
# Remove both object files AND executable
fclean: clean
	rm -f $(NAME)

# RE TARGET: rebuild everything (rebuild)
# 1. fclean: remove everything
# 2. all: rebuild from scratch
# Ensures no stale object files or old executable
re: fclean all

# TEACHING NOTE:
# This is a VERY simple Makefile. More complex projects might:
# - Use variables for directories (SRCDIR, OBJDIR, BINDIR)
# - Have dependencies calculated automatically
# - Support different build configurations (debug, release)
# - Use libraries that need linking (-l flags)
# - Include header dependencies to recompile when headers change
#
# But for this exercise, simplicity is best to understand the basics.
# The key concept: Makefile automates compilation so you don't 
# manually type long compiler commands every time.
