<h1 align="center"> Fair ain't square </h1>
<p align="center">
A 2D sidescrolling platform-shooter that adapts to playstyles of all kind
</a>



## Controls

- Arrow keys or WASD to move
- C to spawn NPC
- V to delete NPC


## Meeting the Requirements 

### Linux (Debian)

Make sure all development libraries are present. You can install the packages from your package manager.

```
sudo apt-get install libsfml-dev libjpeg-dev libfreetype6-dev
```

If you are using cmake,
```
sudo apt-get install cmake
```

You can refer <a href="https://www.sfml-dev.org/download.php">SFML's website</a> for instructions on installing the libraries on your OS.

### Windows 

You will need to install <a href="http://www.mingw.org/">make</a> (MinGW) and <a href="https://cmake.org/download/">cmake</a> to build the project. Make sure to **use mingw-make instead of make** while building.

You need to  install the <a href="https://www.sfml-dev.org/download.php">SFML libraries</a> to compile the project.


## Building

### Linux/Windows/Mac

Clone the repository and run `make` from the project root. You can also download the zip file <a href="https://github.com/EdgeCutter/fairaintsquare/archive/master.zip">directly</a> and skip this step if you wish to not download git.
```
git clone https://github.com/EdgeCutter/fairaintsquare
cd fairaintsquare
make
```
The executable will be built inside the `build`. Also make sure to copy all the files from `res` to `build`. (Will be automated soon.)

We are also experimenting with CMake, so you can also build this way.
```
cd build
cmake ..
make
```
The executable will be inside `build/bin`. The resource files will be copied there automatically.


## Documentation

The project uses Doxygen for managing its documentation. If you wish to read the documentation, install Doxygen. You might also need to install `graphviz` for visualizing the relations.

### Linux (Debian)
```
sudo apt-get install doxygen-gui graphviz
doxygen
```
### Windows

You need to <a href="https://sourceforge.net/projects/doxygen/files/snapshots/">download</a> Doxygen.


You can create the docs by running `doxygen` inside the root folder. All the documentation will be created inside the `docs` folder.

## Contributing / Testing

We are open to contributions. If you wish to contribute, start an issue. For discussions on the game, check out our <a href="https://discord.gg/VMFawez">discord server.</a>

We are planning on adding unit tests and integration tests soon.
