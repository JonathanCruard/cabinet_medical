# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# Makefile for Unix & Linux Systems #
# using a GNU C++ compiler #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

# compiler flags
# -g --Enable debugging
# -Wall --Turn on all warnings
# -D_USE_FIXED_PROTOTYPES_
# --Force the compiler to use the correct headers
# -ansi --Don't use GNU ext; do use ansi standard.


# Give path of .hpp files
INC=-I./include \
 -I./include/parsing \
 -I./include/statistics \
 -I./include/tools \
 -I./include/smmb_aco

# Save compiler call
 CXX=g++ -o
 CXXFLAGS=-std=c++11 -DNDEBUG -g $(INC)
 #Intial call
 LFLAGS=-std=c++11 -fopenmp -Wall -Wextra -DNDEBUG -I$(BOOST_FOLDER) -lm
# Save directory names
 SRCDIR=src
 OBJDIR=obj
 BINDIR=.
 rm=rm -f
#Give .o files to create
OBJ=$(OBJDIR)/main.o


TARGET=$(BINDIR)/gestion_cabinet.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	@g++ $^ -o $@ $(LFLAGS)
	@echo "Compilation complete, executable produced."

#---------------------
# Main
#---------------------
$(OBJDIR)/main.o: ./$(SRCDIR)/main.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled main.o"


#---------------------
# PHONEY
#---------------------
.PHONEY: clean
clean:
	@$(rm) $(OBJ)
	@echo "Cleanup complete."

.PHONEY: remove
remove: clean
	@$(rm) $(TARGET)
	@echo "Executable removed."
