cmake_minimum_required(VERSION 3.25)
project(PollSysUnited C)

set(CMAKE_C_STANDARD 11)

add_executable(PollSysUnited main.c user.h candidate.h admin.h officer.h user.c admin.c officer.c candidate.c)
