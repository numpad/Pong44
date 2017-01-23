CC=g++
CFLAGS=-c -Wall -pedantic
LDFLAGS=-lm -lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp Random.cpp Vec2.cpp Background.cpp ParticleFuel.cpp Paddle.cpp Player.cpp Obstacles.cpp Ball.cpp Particle.cpp ParticleSystem.cpp
OBJECTS=$(SOURCES:%.cpp=%.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o