cmake_minimum_required(VERSION 3.2)
project(SFMLDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/core/Engine.cpp src/core/Engine.h src/windows/Context.h src/windows/MainMenu.cpp src/windows/MainMenu.h src/windows/ContextSwitcher.cpp src/windows/ContextSwitcher.h src/Characters/Character.cpp src/Characters/Character.h src/maps/Map.cpp src/maps/Map.h src/maps/town/Town.cpp src/maps/town/Town.h src/utils/Logger.cpp src/utils/Logger.h src/utils/Observable.h src/utils/Observer.h src/utils/Event.h src/core/Actions.cpp src/core/Actions.h src/rendering/Drawable.h src/core/states/MapState.h src/core/states/GameState.h src/core/eventTypes.h)
add_executable(SFMLDemo ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLDemo ${SFML_LIBRARIES})
endif()