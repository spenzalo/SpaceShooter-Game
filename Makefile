
# Compiler to use
CXX = g++

# Flags for the compiler
CXXFLAGS = -I/opt/homebrew/Cellar/sfml/2.6.0/include -L/opt/homebrew/Cellar/sfml/2.6.0/lib -lsfml-window -lsfml-system -lsfml-graphics

# Source files
SOURCES = main.cpp SecondaryWindow.cpp planet1.cpp alien.cpp GameEntity.cpp SpecialAlien.cpp

# Output binary
OUTPUT = main

# Default target
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) $(SOURCES)

clean:
	rm -f $(OUTPUT)
