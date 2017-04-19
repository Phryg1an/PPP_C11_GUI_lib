TARGET = scratch
INCDIR = include/PPP_C11_GUI
INC := -I$(INCDIR)
CXX = g++
CXXFLAGS := -w -Wall -std=c++11 `fltk-config --ldflags --use-images` -g $(INC)
LINKER := g++ -o
LFLAGS := -w -Wall -std=c++11 `fltk-config --ldflags --use-images` -g $(INC)

SRCDIR   = src/PPP_C11_GUI
OBJDIR   = obj
BINDIR   = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))


INCLUDES := $(wildcard $(INCDIR)/*.h)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS) $(OBJDIR)/$(TARGET).o
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS) $(OBJDIR)/$(TARGET).o
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(OBJDIR)/$(TARGET).o: src/$(TARGET).cpp
	@$(CXX) $(CXXFLAGS) -c src/$(TARGET).cpp -o $(OBJDIR)/$(TARGET).o
	@echo "Compiled "$(TARGET).o" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"