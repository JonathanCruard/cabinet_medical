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
INC=-I./include

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
OBJ=$(OBJDIR)/main.o \
$(OBJDIR)/date.o \
$(OBJDIR)/person.o \
$(OBJDIR)/patient.o \
$(OBJDIR)/doctor.o \
$(OBJDIR)/prescription.o \
$(OBJDIR)/metting.o


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
# Person
#---------------------
$(OBJDIR)/person.o: ./$(SRCDIR)/person.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled person.o"
#---------------------
# doctor
#---------------------
$(OBJDIR)/doctor.o: ./$(SRCDIR)/doctor.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled doctor.o"
#---------------------
# patient
#---------------------
$(OBJDIR)/patient.o: ./$(SRCDIR)/patient.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled patient.o"
#---------------------
# meeting
#---------------------
$(OBJDIR)/meeting.o: ./$(SRCDIR)/meeting.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled meeting.o"
#---------------------
# date
#---------------------
$(OBJDIR)/date.o: ./$(SRCDIR)/date.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled date.o"
#---------------------
# perscription
#---------------------
$(OBJDIR)/perscription.o: ./$(SRCDIR)/perscription.cpp
	@$(CXX) $@ -c $< $(CXXFLAGS)
	@echo "Compiled perscription.o"


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
