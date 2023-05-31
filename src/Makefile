OBJS = ./main.o
FILE_BIN = .main.bin
#CFLAGS = 
#LIBS = 
bin: $(OBJS)
	g++ -o $(FILE_BIN) $(OBJS)
%.o:%.cpp
	g++ -c $< -o $@
clean:
	rm *.o $(FILE_BIN)
