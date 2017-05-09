# macros:

OBJ_DIR = obj
FILES_DIR_ENGINE = Gamefiles/Engine
FILES_DIR_SPACEFUTURE = Gamefiles/SpaceFuture
MAIN = main
TARGET = SpaceFuture

SOURCES_ENGINE = $(wildcard $(FILES_DIR_ENGINE)/*.cpp)
OBJS_ENGINE = $(SOURCES_ENGINE:$(FILES_DIR_ENGINE)/%.cpp=$(OBJ_DIR)/%.o)
SOURCES_SPACEFUTURE = $(wildcard $(FILES_DIR_SPACEFUTURE)/*.cpp)
OBJS_SPACEFUTURE = $(SOURCES_SPACEFUTURE:$(FILES_DIR_SPACEFUTURE)/%.cpp=$(OBJ_DIR)/%.o)
CC = g++
CFLAGS = -std=c++11 -Wall -fexceptions
LFLAGS = -Wall

# Compilation and Linking

all : CREATE_DIRS $(OBJ_DIR)/$(MAIN).o $(OBJS_ENGINE) $(OBJS_SPACEFUTURE)
	$(CC) $(OBJ_DIR)/$(MAIN).o $(OBJS_ENGINE) $(OBJS_SPACEFUTURE) $(LFLAGS) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

$(OBJ_DIR)/$(MAIN).o : $(MAIN).cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(FILES_DIR_ENGINE)/%.cpp $(FILES_DIR_ENGINE)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(FILES_DIR_SPACEFUTURE)/%.cpp $(FILES_DIR_SPACEFUTURE)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

CREATE_DIRS : 
	@echo Checking for existence: /$(OBJ_DIR)
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

clean :
	@echo Deleting Object Files and executable.
	@if exist $(OBJ_DIR) rmdir $(OBJ_DIR) /q /s
	@if exist $(TARGET).exe del $(TARGET).exe


#-I E:\OneDrive\c++\SFML\SFML-2.4.2\install\include -L E:\OneDrive\c++\SFML\SFML-2.4.2\install\lib

#-I C:\Users\Niklas\OneDrive\c++\SFML\SFML-2.4.1\include -L C:\Users\Niklas\OneDrive\c++\SFML\SFML-2.4.1\lib

# http://stackoverflow.com/questions/3707517/make-file-echo-displaying-path-string
# https://superuser.com/questions/87398/windows-7-administrator-command-prompt-start-in-path