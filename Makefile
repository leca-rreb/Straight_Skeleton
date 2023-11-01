CXX      = g++
CXXFLAGS =  -g -std=c++23 -pedantic-errors -Wall -Wextra  \
		   -Wconversion -Wsign-conversion

BIN_DIR   = ./Binaries
BUILD_DIR = ./Build
SRCS_DIR  = ./Sources
SRCS_DIRS = $(shell find $(SRCS_DIR) -type d -name '*Private*')
HDRS_DIRS = $(shell find $(SRCS_DIR) -type d -name '*Public*')

BIN  = sskel
SRCS = $(shell find $(SRCS_DIRS) -name '*.cpp')
HDRS = $(shell find $(HDRS_DIRS) -name '*.h')
OBJ  = $(patsubst %.cpp, %.o, $(SRCS))
OBJS = $(patsubst $(SRCS_DIR)%, $(BUILD_DIR)%, $(OBJ))
DEPS = $(patsubst %.o, %.d, $(OBJS))

INCFLAGS = $(addprefix -I, $(HDRS_DIRS))
CPPFLAGS = $(INCFLAGS) -MMD -MP

.PHONY: clean clear

$(BIN_DIR)/$(BIN): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)/*

clear: clean
	rm -rf $(BIN_DIR)/*