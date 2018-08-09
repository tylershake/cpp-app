# Copyright [year] [organization]
#
# Build makefile for cpp tests
#

# Include directives
include ../Makefile.inc

# Include path for header dependencies
LOCAL_INCPATH = -I../build/include -I../config

# Include path for library dependencies
LIB_INCPATH = -L../build/lib

# Compiler flags
CXXFLAGS = $(SYSTEM_CXXFLAGS) $(LOCAL_INCPATH) $(LIB_INCPATH)

# Linking dependencies
LDFLAGS = -lcpputils -lgtest -lboost_log -lpthread -lboost_thread -lboost_system -lboost_log_setup -lboost_program_options -lboost_filesystem

# Output executable path
EXE_OUTPUT_PATH = ../build/bin

# Output executable names
EXAMPLE_EXE_NAME = test_example

# Rules start here
all: test-example

test-example: $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)

$(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME): test_example.o
	mkdir -p $(EXE_OUTPUT_PATH)
	$(CXX) $(CXXFLAGS) test_example.o -o $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME) $(LDFLAGS)

test_example.o: test_example.cpp
	$(CXX) $(CXXFLAGS) -c test_example.cpp $(LDFLAGS)

clean:
	$(RM) $(EXE_OUTPUT_PATH)/$(EXAMPLE_EXE_NAME)
	$(RM) *.o
