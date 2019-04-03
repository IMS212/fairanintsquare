CC = g++
CFLAGS = -O3 -ffast-math
VFLAGS = --std=c++17
ifeq ($(OS), Windows_NT)
    LDFLAGS = -pthread -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
    TARGET = fairAintSquare.exe
    DTARGET = debug_fairAintSquare.exe
else
    LDFLAGS = -pthread -DSFML_STATIC -I SFML\include -L SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -lGL -lfreetype -ljpeg
    TARGET = fairAintSquare
    DTARGET = debug_fairAintSquare
endif
CDFLAGS = -g 
WARNINGS = -pedantic -Wall -Wextra
CPP = main.cpp

all:
	$(CC) $(WARNINGS) $(VFLAGS) $(CFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET)
	
windows:
	$g++ -O3 -std=c++14 main.cpp -o Finneon.exe -lsfml-graphics -lsfml-window -lsfml-system -lGL

debug:
	$(CC) $(WARNINGS) $(VFLAGS) $(CDFLAGS) $(CPP) $(LDFLAGS) -o $(DTARGET)

clean:
	rm -rf $(TARGET) $(DTARGET)
