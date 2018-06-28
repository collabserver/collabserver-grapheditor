CC					= g++
LD 					= g++
LDFLAGS  			= -lcurl
CPPFLAGS 			= -Wall -ggdb  -std=c++11
OBJ_DIR 			= obj
CPP_DIR				= src
BIN_DIR 			= bin
INCLUDE_DIR			= -I./include
CORE 				= main.cpp MVKWrapper.cpp Prompt.cpp
FINAL_TARGET	 	= main.exe


default: creadirs $(BIN_DIR)/$(FINAL_TARGET)


# Création de votre .exe
$(BIN_DIR)/$(FINAL_TARGET): $(CORE:%.cpp=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS)

# Création de TOUT les .o (normalement)
$(OBJ_DIR)/%.o: $(CPP_DIR)/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@


.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	del /f $(OBJ_DIR)
	del /f $(BIN_DIR)
else
	-rm -rf $(OBJ_DIR)
	-rm -rf $(BIN_DIR)
endif

.PHONY: creadirs
creadirs:
	-mkdir $(OBJ_DIR)
	-mkdir $(BIN_DIR)

