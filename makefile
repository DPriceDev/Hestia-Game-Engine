CC=clang
CXX=clang++
CFLAGS = -O3
FRAMEWORKS = -framework Cocoa -framework IOKit -framework OpenGl
LIBS = -lglfw3

INCLUDES = -I ./include

MKDIR_P = mkdir -p

SRC_DIR = ./src
BUILD_DIR = ./build
OUTPUT_DIR = ./output

SRCS = $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*.c) 
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

.PHONY: engine

engine: $(OBJS) $(OUTPUT_DIR)
	$(CXX) -o $(OUTPUT_DIR)/engine.app $(OBJS) $(LIBS) $(FRAMEWORKS) $(INCLUDES) $(CFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)

$(OUTPUT_DIR):
	$(MKDIR_P) $(OUTPUT_DIR)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)