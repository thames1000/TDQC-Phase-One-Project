add_executable(
        exe
        executable.c
)

target_include_directories(
        exe
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
