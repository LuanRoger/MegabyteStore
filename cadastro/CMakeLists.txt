cmake_minimum_required(VERSION 3.23)
project(cadastro)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cadastro
        Account.cpp
        Account.h
        Admin.cpp
        Admin.h
        Client.cpp
        Client.h
        Login.cpp
        Login.h
        main.cpp
        Session.cpp
        Session.h
        Register.cpp
        Register.h
        )
