SRC_DIR = src
BUILD_DIR = build
PROGRAM_NAME = main
GCC = g++

build: clean
	mkdir $(BUILD_DIR); \
	$(GCC) $(SRC_DIR)/*.cpp -o $(BUILD_DIR)/$(PROGRAM_NAME)

clean:
	rm -rf $(BUILD_DIR)

run:
	$(BUILD_DIR)/$(PROGRAM_NAME) ${a}

.PHONY: build
