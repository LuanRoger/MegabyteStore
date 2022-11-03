cmake_minimum_required(VERSION 3.23)
project(MegabyteStore)

set(CMAKE_CXX_STANDARD 14)

add_executable(MegabyteStore main.cpp Models/Produto.cpp Models/Produto.h Models/Hardware.cpp Models/Hardware.h Models/PlacaMae.cpp Models/PlacaMae.h Models/CPU.cpp Models/CPU.h Models/Socket.cpp Models/Socket.h Models/RAMMemory.cpp Models/RAMMemory.h Models/GPU.cpp Models/GPU.h Models/StorageUnit.cpp Models/StorageUnit.h)
