# game_engine

## Requirements
- CMake 3.25+
- A C++23 compiler
- Git (with submodules)

## Install
Clone this repository:

```sh
git clone <repo-url> game_engine
```

This project uses [vcpkg](https://github.com/microsoft/vcpkg) as a git submodule.
After cloning, initialize submodules:

```sh
git submodule update --init --recursive
```

## Build
Configure and build using the provided CMake preset:

```sh
cmake --preset default
cmake --build --preset default
```

The executable is written to `build/game_engine`.

## Run

```sh
./build/game_engine
```
