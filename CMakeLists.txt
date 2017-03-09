cmake_minimum_required(VERSION 3.2)
project(SFMLDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/core/Engine.cpp src/core/Engine.h src/utils/Observable.h src/utils/Observer.h src/rendering/Renderer.h src/states/GameState.h src/states/MapState.h src/states/CharacterState.h src/rendering/renderers/MapRenderer.cpp src/rendering/renderers/MapRenderer.h src/reducers/map/MapReducer.cpp src/input/InputManager.cpp src/input/InputManager.h src/core/ActionDispatcher.cpp src/core/ActionDispatcher.h src/core/Game.h src/core/Game.cpp src/actions/ActionTypes.h src/reducers/map/MapReducer.h src/reducers/Reducer.h src/updaters/map/MapUpdater.cpp src/updaters/map/MapUpdater.h src/updaters/Updater.h src/core/UpdateDispatcher.h src/core/RenderDispatcher.h src/states/ConfigState.h src/data/DataProvider.h)
add_executable(SFMLDemo ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFMLDemo ${SFML_LIBRARIES})
endif()