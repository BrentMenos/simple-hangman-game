cmake_minimum_required(VERSION 4.1)
project(9348_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(9348_Cplusplus
        .idea/.gitignore
        .idea/9348-Cplusplus.iml
        .idea/editor.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        README.md
        main.cpp
        wordbank.cpp
        HangmanGame.cpp)
