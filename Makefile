# Calling Python code in C++
# Tutorial: https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

CXXFLAGS := -g -Wall -Werror

target := evaluation
pyhelper := pyhelper

# Linking: and compiling: https://docs.python.org/3/extending/embedding.html#compiling-and-linking-under-unix-like-systems
COMPILE_FLAGS = $(CXXFLAGS) $(shell python3-config --cflags) -fPIE
LD_FLAGS = $(shell python3-config --embed --ldflags)

# Specify CONDA=1 in command line, if compiling in conda virtual environment
# This needs to install gcc first in the conda environment, by typing:
# conda install gxx_linux-64
# WARNING: THIS IS SLOW!!!
ifeq ($(CONDA),1)
COMPILE_FLAGS = $(CXXFLAGS) $(shell python3.6-config --cflags)
LD_FLAGS = $(shell python3.6-config --ldflags)
endif

.PHONY: all
all: $(target).out

# For this part, I consulted: https://stackoverflow.com/questions/27672572/embedding-python-in-c-linking-fails-with-undefined-reference-to-py-initialize
$(target).out: $(target).o
	$(CXX) $(CXXFLAGS) $^ $(LD_FLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(target).o: $(target).cpp
	$(CXX) $(COMPILE_FLAGS) $(LD_FLAGS) -c $<

.PHONY: clean
clean:
	-rm -rf *.o *.out *.gch
