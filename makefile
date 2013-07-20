OBJ = engine.o events.o graphics.o game.o entity.o interface.o
CFLAGS = -Wall
LIBS = -lSDL -lSDL_image -lSDL_ttf

all: bin

bin: $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o bin $(LIBS)

%.o : %.c
	g++ $(CFLAGS) -c $<

clean:
	rm bin $(OBJ)
