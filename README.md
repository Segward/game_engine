# game_engine

A small OpenGL game engine sandbox. GLFW window, glad-loaded GL,
GLM for math, and Box2D for 2D physics.

## Requirements
- CMake 3.25+
- A C++23 compiler
- Git
- make, pkg-config, curl, zip, unzip, tar

### Linux (Debian/Ubuntu)
GLFW requires X11 and OpenGL development libraries. Install them with:

```sh
sudo apt install xorg-dev libgl1-mesa-dev
```

## Install
> [!IMPORTANT]
> Clone with `--recurse-submodules` — vcpkg is vendored as a submodule.

```sh
git clone --recurse-submodules https://github.com/Segward/game_engine.git
cd game_engine
```

## Build & run
Configure and build with the provided CMake preset:

```sh
cmake --preset default
cmake --build --preset default
```

Then run the produced binary:

```sh
./build/game_engine
```

## Third party
- GLFW: window and input.
- glad: OpenGL function loader.
- GLM: vector and matrix math.
- Box2D: 2D rigid-body physics.
- vcpkg: dependency manager, vendored as a submodule.
