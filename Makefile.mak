# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Executables
VICTIM = victim
ATTACKER = attacker

# Source files
VICTIM_SRCS = main.cpp calculator.cpp backdoor.cpp
ATTACKER_SRCS = attacker.cpp

# Object files
VICTIM_OBJS = $(VICTIM_SRCS:.cpp=.o)
ATTACKER_OBJS = $(ATTACKER_SRCS:.cpp=.o)

# Default build rule
all: $(VICTIM) $(ATTACKER)

# Build the victim executable
$(VICTIM): $(VICTIM_OBJS)
	$(CXX) $(CXXFLAGS) -o $(VICTIM) $(VICTIM_OBJS)

# Build the attacker executable
$(ATTACKER): $(ATTACKER_OBJS)
	$(CXX) $(CXXFLAGS) -o $(ATTACKER) $(ATTACKER_OBJS)

# Clean up
clean:
	rm -f $(VICTIM) $(ATTACKER) *.o
