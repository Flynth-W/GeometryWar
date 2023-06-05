OBJS = ../src/main.o \
	   ../src/app/app.o \
	   ../src/scenes/orchestrator.o \
	   ../src/scenes/beginGame/beginGame.o \
	   ../src/utils/classes/Draw/rectangle/rectangle.o \
	   ../src/factory/objets/startButton.o \
	   ../src/factory/app/app.o \
	   ../src/event/events.o  \
	   ../src/scenes/one/one.o 

FILE_BIN = Asteroid.bin
LIBS = -lGL -lglfw -lGLEW 
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm $(FILE_BIN) ../src/*.o ../src/*/*.o ../src/*/*/*.o ../src/*/*/*/*.o ../src/*/*/*/*/*.o
th: 
	@ ./mk $(OBJS) $(LIBS) 
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
