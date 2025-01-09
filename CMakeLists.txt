cmake_minimum_required(VERSION 3.10)
project(TimeTable)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# 소스 파일들 재귀적으로 찾기
file(GLOB_RECURSE PROJECT_SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# 헤더 파일 경로 추가
include_directories(${CMAKE_SOURCE_DIR}/include)

# 실행 파일 생성
add_executable(timeTable ${PROJECT_SOURCES})