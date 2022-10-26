cmake_minimum_required(VERSION 3.23)
project(MegabyteStore)

set(CMAKE_CXX_STANDARD 17)

add_executable(MegabyteStore main.cpp Internals/MenuSystem/MenuBuilder.cpp Internals/MenuSystem/MenuBuilder.h Internals/MenuSystem/MenuInfoItem.cpp Internals/MenuSystem/MenuInfoItem.h Internals/MenuSystem/IMenuCommand.h Internals/MenuSystem/Menu.cpp Internals/MenuSystem/Menu.h MenuCommands/MenuCommand1.cpp MenuCommands/MenuCommand1.h)
