# Falling Sand Simulation

A colorful particle physics simulation where you can create and interact with falling sand particles in real-time.


## Overview

This project implements a simple falling sand simulation using the Raylib library. The simulation features:

- Rainbow-colored sand particles that flow realistically
- Mouse-controlled sand generation
- Physics-based particle movement with gravity and collision handling

## How It Works

The simulation uses a cellular automaton approach where each cell in a grid can either be empty or contain a sand particle. The rules are simple:

1. Sand particles fall downward if the space below is empty
2. If a sand particle can't fall straight down, it tries to fall diagonally (left or right)
3. If a sand particle can't fall in any direction, it stays in place

The particles' colors are generated using HSV color model based on their position, creating a beautiful rainbow effect as you draw.

## Controls

- **Left Mouse Button**: Click and drag to create sand particles
- **ESC**: Exit the simulation

## Requirements

- C++ compiler with C++11 support
- Raylib graphics library
- Make (for building)

## Installation

### Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/falling-sand.git
   cd falling-sand
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the simulation:
   ```bash
   ./build
   ```

### Dependencies

#### Ubuntu/Debian
```bash
sudo apt install build-essential git
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
```

Then install Raylib:
```bash
git clone https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install
```

#### Fedora
```bash
sudo dnf install gcc-c++ make git
sudo dnf install alsa-lib-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel
```

#### Arch Linux
```bash
sudo pacman -S base-devel git
sudo pacman -S alsa-lib mesa libx11 libxrandr libxi libxcursor libxinerama
```

#### Windows
Install MinGW or Visual Studio and download Raylib from the [official website](https://www.raylib.com/).

## Project Structure

```
falling-sand/
├── main.cpp    # Main simulation code
├── makefile    # Build configuration
└── README.md   # Project documentation
```

## Technical Implementation

### Grid-Based System

The simulation uses a 2D grid where each cell represents a discrete position that can contain a sand particle. The grid dimensions are determined by:

```cpp
const int Width = 800;
const int Height = 800;
const int blockSize = 5;
const int cols = Height / blockSize;
const int row = Width / blockSize;
```

### Particle Physics

The sand particles follow these simple rules:
- Try to move directly downward
- If blocked, try to move diagonally down-left
- If still blocked, try to move diagonally down-right
- If all options are blocked, remain stationary

### Color Generation

Each sand particle's color is determined by its position in the grid:

```cpp
float hue = static_cast<float>(col + row) / static_cast<float>(cols) * 360.0f;
Color color = ColorFromHSV(hue, saturation, 1.0f);
```

This creates a beautiful rainbow effect as you draw across the screen.

## Customization

You can easily modify the simulation by changing the following parameters in `main.cpp`:

- **blockSize**: Change the size of each sand particle
- **Width/Height**: Adjust the window dimensions
- **SetTargetFPS(80)**: Change the simulation speed

### Adding New Particle Types

You can extend the simulation by adding different types of particles. For example, to add water particles:

1. Add a new particle type value in the grid array (e.g., `2` for water)
2. Create a new drawing function for this particle type
3. Implement the physics rules for the new particle type

## Performance Tips

- Increasing `blockSize` will improve performance at the cost of resolution
- The simulation becomes more resource-intensive as more particles are added
- Consider implementing chunking if you want to create a larger simulation area

## Troubleshooting

### Common Issues

- **Compilation Errors**: Make sure Raylib is properly installed and linked in the makefile
- **Performance Issues**: Reduce the number of particles or increase the block size
- **Windows Issues**: If using MinGW, make sure your PATH includes the bin directory

## Future Enhancements

- Add multiple particle types (water, fire, smoke, etc.)
- Implement temperature and pressure systems
- Add user interface for selecting different particle types
- Save and load functionality for created scenes
- Optimize with multithreading for better performance

## Contributing

Contributions are welcome! Some areas that could use improvement:

- Performance optimizations
- Additional particle types and interactions
- User interface improvements
- Saving/loading functionality

## License

This project is released under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Built with [Raylib](https://www.raylib.com/)
- Inspired by classic falling sand games like Powder Game and The Sandbox
