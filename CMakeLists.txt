cmake_minimum_required(VERSION 3.8)
project(Blackjack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Card.cpp src/Card.h src/Deck.cpp src/Deck.h src/Gameplay.cpp src/Gameplay.h)
add_executable(Blackjack ${SOURCE_FILES})
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()