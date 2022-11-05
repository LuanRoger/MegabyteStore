cmake_minimum_required(VERSION 3.23)
project(MegabyteStore)

set(CMAKE_CXX_STANDARD 17)

add_executable(MegabyteStore main.cpp Models/Product.cpp Models/Product.h Models/Hardware.cpp Models/Hardware.h Models/Motherboard.cpp Models/Motherboard.h Models/CPU.cpp Models/CPU.h Models/Socket.cpp Models/Socket.h Models/RAMMemory.cpp Models/RAMMemory.h Models/GPU.cpp Models/GPU.h Models/StorageUnit.cpp Models/StorageUnit.h Models/PowerSupply.cpp Models/PowerSupply.h Internals/MenuSystem/MenuInfoItem.cpp Internals/MenuSystem/MenuInfoItem.h Internals/MenuSystem/Commands/IMenuCommand.h Internals/MenuSystem/Menu.cpp Internals/MenuSystem/Menu.h MenuCommands/RegistryProductCommand.cpp MenuCommands/RegistryProductCommand.h Internals/MenuSystem/Commands/ExitMenuCommand.cpp Internals/MenuSystem/Commands/ExitMenuCommand.h Internals/MenuSystem/Commands/OpenSubmenuCommand.cpp Internals/MenuSystem/Commands/OpenSubmenuCommand.h Utils/json.hpp MemoryStorage/ProductsStorage.cpp MemoryStorage/ProductsStorage.h Controllers/MemoryStorageController.cpp Controllers/MemoryStorageController.h)
