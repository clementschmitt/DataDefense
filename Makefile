CC = g++
CFLAGS = -Wall
EXEC_NAME = DataDefense
INCLUDES =
LIBS =
OBJ_FILES = fichier_1.o fichier_2.o
INSTALL_DIR = /usr/bin

all :
	cd src && ${MAKE}
	mv src/DataDefense bin
