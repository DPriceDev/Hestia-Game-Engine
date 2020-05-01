CC=clang
CXX=clang++
CFLAGS = -O3 -MMD
CXXFLAGS = -std=c++17 -O3 -MMD
BINARYFLAGS = -std=c++17 -O3
FRAMEWORKS = -framework Cocoa -framework IOKit -framework OpenGl
LIBS = -lglfw3
INCLUDES = -I ./include/glm -I ./include

SRC_DIR = ./src
BUILD_DIR = ./build
OUTPUT_DIR = ./output

SRCS = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp) $(wildcard src/*.c)  $(wildcard src/*/*.c) $(wildcard src/*/*/*.c) 
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
MKDIR_P = mkdir -p

.PHONY: engine

engine: $(OBJS)
	$(CXX) -o engine.app $(OBJS) $(LIBS) $(FRAMEWORKS) $(INCLUDES) $(BINARYFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) -c $< -o $@ $(CXXFLAGS) $(INCLUDES)

$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)

$(OUTPUT_DIR):
	$(MKDIR_P) $(OUTPUT_DIR)

-include $(OBJS:%.o=%.d)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)