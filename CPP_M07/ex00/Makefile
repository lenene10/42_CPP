# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address,undefined,leak

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = template

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link object files into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean up object files
clean:
	rm -f $(OBJS)


# Clean up object files and executable
fclean: clean
	rm -f $(TARGET)

re:	fclean all
