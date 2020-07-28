# Calling Python code in C++
# Tutorial: https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

CXXFLAGS := -g -Wall -Werror

PY3CONFIG := python3-config
CONDA_PY3CONFIG := python3.6-config

CLEAN := -rm -rfv *.o *.out *.gch

target := prediction
pyhelper := pyhelper

# Linking and compiling: https://docs.python.org/3/extending/embedding.html#compiling-and-linking-under-unix-like-systems
COMPILE_FLAGS = $(CXXFLAGS) $(shell $(PY3CONFIG) --cflags) -fPIE
LD_FLAGS = $(shell $(PY3CONFIG) --embed --ldflags)

# Specify CONDA=1 in command line, if compiling in conda virtual environment (IF YOU DON'T HAVE IT, COMPILATION WILL FAIL!!!)
# This needs to install gcc first in the conda environment, by typing:
# conda install gxx_linux-64
# WARNING: THIS IS SLOW!!!
ifeq ($(CONDA),1)
COMPILE_FLAGS = $(CXXFLAGS) $(shell $(CONDA_PY3CONFIG) --cflags)
LD_FLAGS = $(shell $(CONDA_PY3CONFIG) --ldflags)
endif

.PHONY: all
all: $(target).out

# For this part, I consulted: https://stackoverflow.com/questions/27672572/embedding-python-in-c-linking-fails-with-undefined-reference-to-py-initialize
$(target).out: $(target).o $(pyhelper).o
	$(CXX) $(CXXFLAGS) $^ $(LD_FLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(COMPILE_FLAGS) $(LD_FLAGS) -c $<

# Clean up

.PHONY: clean
clean: # This keeps the pyhelper.o file
	mv $(pyhelper).o $(pyhelper).o1
	$(CLEAN)
	mv $(pyhelper).o1 $(pyhelper).o

.PHONY: clean_all
clean_all:
	$(CLEAN)
