# Compiler and flags
# -std=c++23: Use the C++23 standard
# -Wall:      Enable all compiler warnings
# -g:         Generate debugging information
# -MMD -MP:   Generate dependency files for automatic header tracking
CXX      := clang++
CXXFLAGS := -std=c++23 -Wall -g -MMD -MP
LDFLAGS  :=

# Project structure
TARGET     := crazyeights
SRCDIR     := src
INCLUDEDIR := include
OBJDIR     := obj

# Add include path to compiler flags
CXXFLAGS += -I$(INCLUDEDIR)

# Find all .cpp files in the source directory
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Generate object file names from source file names (e.g., src/main.cpp -> obj/main.o)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Generate dependency file names (e.g., obj/main.o -> obj/main.d)
DEPS    := $(OBJECTS:.o=.d)

.PHONY: all clean

# Default target: build the executable
all: $(TARGET)

# Rule to link the final executable
$(TARGET): $(OBJECTS)
	@echo "==> Linking..."
	$(CXX) $(LDFLAGS) -o $@ $^

# Rule to compile a .cpp file into a .o file
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "==> Compiling $<..."
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to clean up generated files
clean:
	@echo "==> Cleaning up..."
	@rm -rf $(OBJDIR) $(TARGET)

# Include generated dependency files. The '-' suppresses errors if they don't exist.
-include $(DEPS)
