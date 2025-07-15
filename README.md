# Fdf

## Introduction

**Fdf** is a wireframe viewer project built as part of the 42 school curriculum. It reads a file containing a 3D landscape represented by elevation data and displays it as a wireframe model using the MiniLibX graphical library. The project is designed to help students learn about graphics programming, coordinate systems, and event handling in C.

## Features

- 3D wireframe rendering of elevation maps
- Support for custom maps
- Interactive controls for moving, zooming, rotating, changing projection

## How to Compile

Make sure you are on a Unix-like system (Linux or macOS) and have `make` and `gcc` installed. MiniLibX should be provided with the project or installed separately.

```sh
make
```

This will generate an executable named `fdf`.

## How to Run

To run the program, use:

```sh
./fdf <map_file>
```

Replace `<map_file>` with the path to your `.fdf` map file.

## Controls (Key Hooks)

Here are the main keys you can use when running Fdf, **as implemented in this repository**:

- **Arrow Keys** (`Up`, `Down`, `Left`, `Right`): Move the map up, down, left, or right
- **R**: Reset Map
- **W / S / A / D**: Rotate the map
    - W/S: Rotate X axis
    - A/D: Rotate Y axis
- **Mouse Wheel** (`Scroll Up` / `Scroll Down`): Zoom in / Zoom out
- **+ / -**: Adjust Z axis (height)
- **ESC**: Quit the program
- **1 / 2 / 3 / 4**: Change projection (Isometric, Top, Side, Front views)

> **Note:** There is currently no key for "reset view to default" in this implementation.
> These controls are based on the source code of this repository.

## Example

```sh
./fdf maps/42.fdf
```

## License

This project is part of the 42 school curriculum and for educational purposes.

---

# Feel free to contribute or open issues if you find bugs or have suggestions!
