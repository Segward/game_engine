# game_engine

A small OpenGL game engine sandbox.

## Requirements
- CMake 3.25+
- A C++23 compiler
- Git
- make, pkg-config, curl, zip, unzip, tar

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
- vcpkg: dependency manager, vendored as a submodule.
