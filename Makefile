CC = g++
CFLAGS = -O3 -ffast-math
VFLAGS = --std=c++17
ifeq ($(OS), Windows_NT)
    LDFLAGS = -pthread -DSFML_STATIC -I ./src/include -I SFML\include -L SFML\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype -ljpeg
else
    LDFLAGS = -pthread -DSFML_STATIC -I ./src/include -I SFML\include -L SFML\lib -lsfml-graphics -lsfml-window -lsfml-system -lGL -lfreetype -ljpeg
endif
TARGET = fairAintSquare
TARGET_DIR=./build/
DTARGET = debug_fairAintSquare
CDFLAGS = -g 
WARNINGS = -Wall -Weffc++ -Wextra -Winit-self -Wzero-as-null-pointer-constant -Wnon-virtual-dtor -Winline -Wmissing-declarations -Wmissing-include-dirs -Wundef -Wredundant-decls -Wfloat-equal -Wmain -Wunreachable-code -Wshadow -Wcast-align -Wswitch-default -Wswitch-enum
CPP = src/*.cpp

all:
	$(CC) $(WARNINGS) $(VFLAGS) $(CFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET_DIR)$(TARGET)
	
windows:
	$(CC) $(WARNINGS) $(VFLAGS) $(CFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET_DIR)$(TARGET).exe

debug:
	$(CC) $(WARNINGS) $(VFLAGS) $(CDFLAGS) $(CPP) $(LDFLAGS) -o $(TARGET_DIR)$(DTARGET)

clean:
	rm -rf $(TARGET) $(DTARGET)
