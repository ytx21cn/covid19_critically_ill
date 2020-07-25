CXXFLAGS := -g -Wall -Werror

target := evaluation
pyhelper := pyhelper

TARGET_FLAGS = $(CXXFLAGS)
TARGET_FLAGS += $(shell pkg-config --cflags --libs python3)

LD_FLAGS += $(shell python3-config --embed --ldflags)

.PHONY: all
all: $(target).out

# For this part, I consulted: https://stackoverflow.com/questions/27672572/embedding-python-in-c-linking-fails-with-undefined-reference-to-py-initialize
$(target).out: $(target).o
	$(CXX) $(CXXFLAGS) $^ $(LD_FLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(target).o: $(target).cpp
	$(CXX) $(TARGET_FLAGS) $(LD_FLAGS) -c $<

.PHONY: clean
clean:
	-rm -rf *.o *.out *.gch
