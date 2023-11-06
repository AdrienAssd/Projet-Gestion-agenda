cmake_minimum_required(VERSION 3.26)
project(Gestion_agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(Gestion_agenda main.c
        cells.c
        lists.c
        lists.h
        timer.c
        timer.h
        timer.c)
