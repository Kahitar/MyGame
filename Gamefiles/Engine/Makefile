# macros:

OBJ_DIR = ..\..\obj
FILES_DIR_ENGINE =
FILES_DIR_SPACEFUTURE = ..\SpaceFuture
MAIN = main
TARGET = ..\..\SpaceFuture

SOURCES_ENGINE = $(wildcard $(FILES_DIR_ENGINE)*.cpp)
OBJS_ENGINE = $(SOURCES_ENGINE:$(FILES_DIR_ENGINE)%.cpp=$(OBJ_DIR)/%.o)
SOURCES_SPACEFUTURE = $(wildcard $(FILES_DIR_SPACEFUTURE)/*.cpp)
OBJS_SPACEFUTURE = $(SOURCES_SPACEFUTURE:$(FILES_DIR_SPACEFUTURE)/%.cpp=$(OBJ_DIR)/%.o)
CC = g++
CFLAGS = -std=c++11 -Wall -I E:\OneDrive\c++\SFML\SFML-2.4.2\install\include -L E:\OneDrive\c++\SFML\SFML-2.4.2\install\lib
LFLAGS = -Wall

# Compilation and Linking

all : CREATE_DIRS $(OBJ_DIR)/$(MAIN).o $(OBJS_ENGINE) $(OBJS_SPACEFUTURE)
	$(CC) $(OBJ_DIR)/$(MAIN).o $(OBJS_ENGINE) $(OBJS_SPACEFUTURE) $(LFLAGS) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

$(OBJ_DIR)/$(MAIN).o : ../../$(MAIN).cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(FILES_DIR_ENGINE)%.cpp $(FILES_DIR_ENGINE)%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : $(FILES_DIR_SPACEFUTURE)/%.cpp $(FILES_DIR_SPACEFUTURE)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

CREATE_DIRS: 
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

clean :
	if exist $(OBJ_DIR) rmdir $(OBJ_DIR) /q /s
	if exist $(TARGET).exe del $(TARGET).exe