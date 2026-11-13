*This project has been created as part of the 42 curriculum by cczerwin.*  

# FdF (Fil de Fer)

This project aims to render a given height map in isometric view.

### Required steps to build the project:

This project requires:
- GNU Make
- a C compiler with libc (preferably GCC or Clang)
- X11 (used through mlx)

<br>

Build with `make` and start by giving it a map *(located in the maps folder)*.  
  
For exemple:
`./fdf ./maps/42.fdf`

## Controls

You can get a pixel coordinates by left clicking on it.  

You can **zoom**/**unzoom** with the mouse wheel, a wheel click reset the zoom to its default value.  

You can **rotate** the view with <kbd>A</kbd> *(counter-clockwise)* or <kbd>D</kbd> *(clockwise)*, press <kbd>X</kbd> to reset the rotation.  

You can **move** the view with **arrow keys**, press <kbd>Numpad 0</kbd> to reset the view.  

You can **move** the *image* with <kbd>Numpad 8</kbd> (up), <kbd>Numpad 2</kbd> (down), <kbd>Numpad 4</kbd> (left), <kbd>Numpad 6</kbd> (right) and <kbd>Numpad 5</kbd> to reset the image position.  

Press <kbd>Space</kbd> to reset all parameters.  

Press <kbd>Esc</kbd> to close fdf.

Additionally: 
- Pressing <kbd>F1</kbd> will display a 42 ASCII logo! *(disappearing on any movement, rotation or zoom)*
- Pressing <kbd>F3</kbd> to display a dancing parrot!

## Ressources

[minilibx documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)  
[Rasterisation wikipedia page](https://en.wikipedia.org/wiki/Rasterisation)  
[Bresenham line algorithm wikipedia page](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)  
[X11 character codes](https://codebrowser.dev/kde/include/X11/keysymdef.h.html)  
