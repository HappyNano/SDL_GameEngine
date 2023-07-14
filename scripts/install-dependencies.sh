#!/bin/bash

# Находим полный путь до корня проекта
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )"

cd "$PROJECT_ROOT"

SDL_DIR="$PROJECT_ROOT/external/SDL"

git submodule add https://github.com/libsdl-org/SDL.git $SDL_DIR

cd "$SDL_DIR"

cmake -S . -B build
cmake --build build
sudo cmake --install build
