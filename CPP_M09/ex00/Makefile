# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address,undefined,leak

# Source files
SRCS = main.cpp BitcoinExchange.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
TARGET = btc

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
