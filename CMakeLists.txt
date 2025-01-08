# 최소 CMake 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름 설정
project(TimeTable)

# 컴파일러 설정
# compile_commands.json 생성 (LSP 지원)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# C++17 표준 사용
set(CMAKE_CXX_STANDARD 17)

# 소스 디렉토리 경로 설정
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TAB_DIR ${SRC_DIR}/tab)
set(CLASS_DIR ${SRC_DIR}/class)
set(STUDY_PLAN_TAB_DIR ${TAB_DIR}/studyPlanTab)

# 클래스 소스 파일
set(CLASS_SOURCES
    ${CLASS_DIR}/studyPlan.cpp
    ${CLASS_DIR}/timeTable.cpp
    ${CLASS_DIR}/subject.cpp
)

# 기본 탭 소스 파일
set(TAB_SOURCES
    ${TAB_DIR}/retakable.cpp
    ${TAB_DIR}/curriculum.cpp
    ${TAB_DIR}/etcTabs.cpp
)

# Study Plan 탭 관련 소스 파일
set(STUDY_PLAN_TAB_SOURCES
    ${STUDY_PLAN_TAB_DIR}/studyPlanTab.cpp
    ${STUDY_PLAN_TAB_DIR}/plansManager.cpp
    ${STUDY_PLAN_TAB_DIR}/planList.cpp
)

# 헤더 파일 디렉토리 추가
include_directories(${CMAKE_SOURCE_DIR}/include)

# 실행 파일 생성
add_executable(timeTable 
    ${SRC_DIR}/main.cpp
    ${CLASS_SOURCES}
    ${TAB_SOURCES}
    ${STUDY_PLAN_TAB_SOURCES}
)