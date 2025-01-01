CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./include  # include 디렉토리 경로 추가

TARGET = timeTable
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.cpp)  # src 디렉토리의 모든 cpp 파일
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)  # 오브젝트 파일 경로 변경
HEADERS = $(wildcard $(INC_DIR)/*.h)  # include 디렉토리의 모든 헤더 파일

all: $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean all