cmake_minimum_required(VERSION 3.15)
project(corewar C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES src/to_bytecode.c includes/op.h src/op.c other/print_file.c includes/asm.h src/asm.c src/champ_exec_code.c other/sample_t_struct.c src/labels.c)
add_executable(corewar ${SOURCE_FILES})

target_link_libraries(corewar /Users/student/corewar/libft/libft.a)
include_directories(./libft)
include_directories(./includes)

