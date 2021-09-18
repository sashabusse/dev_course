#common settings
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
CXX = D:/dev_tools/toolchains/mingw64/x86_64-8.1.0-win32-seh-rt_v6-rev0/mingw64/bin/g++.exe
include args.mk

all: application
# << application settings >> -------------------------------------------------
APP_NAME = strfuncs
APP_SRC = $(wildcard code/*.c)
APP_OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(notdir $(APP_SRC:.c=.o)))
APP_INC_FOLDERS = -Icode/ 

.PHONY: application
application: $(BUILD_DIR)/$(APP_NAME).exe

#linking executable APPLICATION target
$(BUILD_DIR)/$(APP_NAME).exe: $(APP_OBJ_FILES) | $(BUILD_DIR)
	$(CXX) $(CXX_ARGS) -o $@ $(APP_OBJ_FILES)

application: INC_FOLDERS = $(APP_INC_FOLDERS)
#compiling necessary sources
$(OBJ_DIR)/%.o: */%.c | $(OBJ_DIR)
	$(CXX) $(CXX_ARGS) $(INC_FOLDERS) -MD -MP -c -o $@ $<

#all obj files (sort to delete duplicates)
ALL_OBJ_FILES := $(APP_OBJ_FILES)
ALL_OBJ_FILES := $(sort $(ALL_OBJ_FILES))

-include $(ALL_OBJ_FILES:.o=.d)


#create necessary directories
$(BUILD_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -r $(BUILD_DIR)


# doxygen documentation
DOXYGEN_DIR = D:/dev_tools/Utility/doxygen/bin
DOX_FOLDER = do
DOXYGEN_CONFIG = Doxyfile

.PHONY: doxygen doxGUI

doxGUI:
	$(DOXYGEN_DIR)/doxywizard.exe

doxygen:
	$(DOXYGEN_DIR)/doxygen.exe $(DOXYGEN_CONFIG)
