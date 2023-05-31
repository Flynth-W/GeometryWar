OBJS = ./../src/main.o 

FILE_BIN = Asteroid.bin
LIBS = -lGL -lglfw -lGLEW 
CFLAGS = -Wall
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm $(FILE_BIN) ../src/*.o ../src/*/*.o ../src/*/*/*.o
th: 
	@ ./mk $(OBJS) $(LIBS) 
	g++ -o $(FILE_BIN) $(OBJS) $(LIBS) $(CFLAGS)
