add_library(
    stack
    SHARED
    stack_adt.c
)

target_include_directories(
        stack
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)
