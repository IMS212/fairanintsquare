find_package(SFML 2 REQUIRED network audio graphics window system)

set(EXECUTABLE_NAME fairanintsquare)
add_executable(
  ${EXECUTABLE_NAME} 
  main.cpp
  npc.cpp
  player.cpp
  text.cpp
  tiles.cpp
  texture_manager.cpp
  animation.cpp
  resource_exception.cpp
)
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 14)

target_compile_options(${EXECUTABLE_NAME} PRIVATE 
-Wall -Wextra -pedantic -Weffc++ -Winit-self -Wzero-as-null-pointer-constant -Wnon-virtual-dtor 
-Winline -Wmissing-declarations -Wmissing-include-dirs -Wundef -Wredundant-decls -Wfloat-equal 
-Wmain -Wunreachable-code -Wshadow -Wcast-align -Wswitch-default -Wswitch-enum)

if(SFML_FOUND)
  include_directories(${PROJECT_SOURCE_DIR}/src/include ${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Might need to copy resources at some point.
FILE(COPY ${CMAKE_SOURCE_DIR}/res/fontT.png 
     DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

