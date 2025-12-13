file(GLOB_RECURSE APP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Parsers/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Search/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Tokenizers/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Command/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/DataBase/*.cpp"
)

add_executable(MiniGitHub
    ${APP_SOURCES}
    Main.cpp
)

target_include_directories(MiniGitHub PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Parsers
    ${CMAKE_CURRENT_SOURCE_DIR}/Search
    ${CMAKE_CURRENT_SOURCE_DIR}/Tokenizers
    ${CMAKE_CURRENT_SOURCE_DIR}/Command
    ${CMAKE_CURRENT_SOURCE_DIR}/DataBase
)
