# FDF (fil de fer)

This project aims to represent a formated map (see examples in /maps directory) via two different projections (orthogonal or isometric) by linking coordonates given with a simple line (like a grid made of steel wires).

BEFORE TO INSTALL

This project has been made for Linux environment.

Before to install you need 'Xlib.h' and 'XShm.h'.

If you don't already have them, run the following commands:

For 'Xlib.h':

sudo apt-get install xlibs-dev

For 'XShm.h':

sudo apt-get install libxext-dev


On WSL (Windows Subsystem Linux) you will need an X Window System Server for Windows running (I recommend Xming from SourceForge wich is open-source and widely used). You'll also need to set the following variable in your WSL shell:

export DISPLAY=:0

(otherwise fdf doesn't start and you'll get the following error message: "mlx_init returned 0")


HOW TO INSTALL

After cloning this repository, run the following commands:

cd fdf

make

HOW TO RUN

The 'fdf' executable needs a map to run. You have example maps in the '/maps' directory of this repo, but feel free to test yours or create a new one.

For example:

./fdf maps/42.fdf

Type 'h' in the new window to display all commands.
