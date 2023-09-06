cmake_minimum_required(VERSION 3.26)
project(BlackJackExercise C)

set(CMAKE_C_STANDARD 11)

add_executable(BlackJackExercise src/main.c
        src/game.h
        src/game.c
)
