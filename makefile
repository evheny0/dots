OBJ = engine.o events.o graphics.o entity.o interface.o game.o
CFLAGS = -Wall
LIBS = -lSDL -lSDL_image -lSDL_ttf

all: bin

bin: $(OBJ)
	g++ $(CFLAGS) $(OBJ) -o bin $(LIBS)

%.o : %.c
	g++ $(CFLAGS) -c $<

clean:
	rm bin $(OBJ)
