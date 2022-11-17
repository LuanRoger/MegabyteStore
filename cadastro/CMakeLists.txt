cmake_minimum_required(VERSION 3.23)
project(cadastro)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cadastro
        Admin.cpp
        Admin.h
        Cadastro.cpp
        Cadastro.h
        Client.cpp
        Client.h
        Conta.cpp
        Conta.h
        Login.cpp
        Login.h
        main.cpp
        Session.cpp
        Session.h
        )
