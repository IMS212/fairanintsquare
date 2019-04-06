# Fair ain't square

A 2D sidescrolling platform-shooter that adapts to playstyles of all kind, making skill, and by extent speed, 
key. WIP.

# Controls

Arrow keys or WASD to move
C to spawn NPC
V to delete NPC

## Meeting the Requirements 

### Linux

Make sure all the dev-libs are present. You can install the pakages from your package manager.
```
sudo apt-get install libsfml-dev libjpeg-dev libfreetype6-dev
```
If you are using cmake,
```
sudo apt-get install cmake
```
You can refer <a href="https://www.sfml-dev.org/download.php">SFML's website</a> for instructions on installing the libraries on your variant.

### Windows 

Make sure you install SFML from <a href="https://www.sfml-dev.org/download.php">here.</a>


## Building

### Linux/Windows/Mac

Clone the repository and run `make` within the project root.
The executable will be built in the builds folder.

Also make sure to copy all the resources from `/res` into `/build`. (Will be automated for make soon)

You can also use cmake.
```
cd build
cmake ..
make
```
The executable will be inside the bin folder. The resources will be copied there.
