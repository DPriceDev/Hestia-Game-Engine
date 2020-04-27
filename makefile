CC=clang
CXX=clang++
CFLAGS = -O3
CXXFLAGS = -std=c++17 -O3 -Wall
FRAMEWORKS = -framework Cocoa -framework IOKit -framework OpenGl
LIBS = -lglfw3

MKDIR_P = mkdir -p

SRC_DIR = ./src
BUILD_DIR = ./build
OUTPUT_DIR = ./output

INCLUDES = -I ./src/framework/Engine.hpp -I ./include

SRCS = $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*/*.cpp) $(wildcard */*/*/*/*.cpp) $(wildcard */*.c)  $(wildcard */*/*.c) $(wildcard */*/*/*.c) 
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

.PHONY: engine

engine: $(OBJS) $(OUTPUT_DIR)
	$(CXX) -o $(OUTPUT_DIR)/engine.app $(OBJS) $(LIBS) $(FRAMEWORKS) $(INCLUDES) $(CXXFLAGS)

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

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)