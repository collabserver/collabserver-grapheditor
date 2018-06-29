CC				= g++
LD 				= g++
LDFLAGS  			= -lcurl
CPPFLAGS 			= -Wall -ggdb  -std=c++11
OBJ_DIR 			= obj
CPP_DIR				= src
BIN_DIR 			= bin
INCLUDE_DIR			= include
CORE 				= main.cpp MVKWrapper.cpp Prompt.cpp UuidGenerator.cpp
HEADER				= include/MVKWrapper.h include/Prompt.h include/UuidGenerator.h
FINAL_TARGET	 		= main.exe


default: creadirs $(BIN_DIR)/$(FINAL_TARGET)


# Création de votre .exe
$(BIN_DIR)/$(FINAL_TARGET): $(CORE:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de TOUT les .o (normalement)
$(OBJ_DIR)/%.o: $(CPP_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) -I./$(INCLUDE_DIR) $< -o $@


.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR) $(BIN_DIR) log.txt doc
else
	-rm -rf $(OBJ_DIR) $(BIN_DIR) log.txt doc
endif

.PHONY: doc
doc: $(HEADER)
ifeq ($(wildcard doc/.*),)
	mkdir doc doc/doxygen
	doxygen Doxyfile
endif


.PHONY: creadirs
creadirs:
ifeq ($(wildcard obj/.*),)
	-mkdir $(OBJ_DIR)
endif
ifeq ($(wildcard bin/.*),)
	-mkdir $(BIN_DIR)
endif
