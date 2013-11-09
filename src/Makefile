CC = g++
CFLAGS = -Wall
EXEC_NAME = DataDefense
OBJ_FILES = main.o Game.o SplashScreen.o MainMenu.o Level.o Map.o VisibleGameObject.o
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all : $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< $(LIBS)


%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean :
	rm $(EXEC_NAME) $(OBJ_FILES) *~
