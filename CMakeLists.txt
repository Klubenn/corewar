cmake_minimum_required(VERSION 3.15)
project(corewar C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES to_bytecode.c op.h print_file.c asm.h champ_exec_code.c)
add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar /Users/student/corewar/libft/libft.a)
include_directories(./libft)

