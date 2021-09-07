BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TARGET = solver.exe
CXX = D:/dev_tools/toolchains/mingw64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/bin/g++.exe

all: $(BUILD_DIR)/$(TARGET)

CXX_ARGS := \
-g \
-std=c++17

include warns.mk
CXX_ARGS += $(CXX_WARNS)

CXX_ARGS += \
-fcheck-new \
-fsized-deallocation \
-fstack-check \
-fstrict-overflow \
-fchkp-first-field-has-own-bounds \
-fchkp-narrow-to-innermost-array \
-flto-odr-type-merging \
-fno-omit-frame-pointer


C_SOURCES := \
code/main.c \
code/SolveSqrEq.c 

OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(notdir $(C_SOURCES:.c=.o)))

.PHONY: echo_obj
echo_obj:
	echo $(OBJ_FILES)

#linking executable target
$(BUILD_DIR)/$(TARGET): $(OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXX_ARGS) -o $@ $(OBJ_FILES)

#compiling necessary sources
$(OBJ_DIR)/%.o: code/%.c | $(OBJ_DIR)
	$(CXX) $(CXX_ARGS) -MD -MP -c -o $@ $<

-include $(OBJ_FILES:.o=.d)


#create necessary directories
$(BUILD_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -r $(BUILD_DIR)


# doxygen documentation
DOX_EXE_DIR = D:/dev_tools/Utility/doxygen/bin
DOX_FOLDER = dox
DOX_CONFIG = $(DOX_FOLDER)/Doxyfile

.PHONY: doxygen doxGUI

doxGUI:
	$(DOXYGEN_DIR)/doxywizard.exe

doxygen:
	$(DOXYGEN_DIR)/doxygen.exe $(DOXYGEN_CONFIG)