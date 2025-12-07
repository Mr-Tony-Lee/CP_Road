# 定義變數
CXX = g++                # C++ 編譯器
CXXFLAGS = -Wall -Wextra -O3 # 編譯選項：-Wall 和 -Wextra 會開啟額外的警告
TARGET = submit            # 最終產生的執行檔名稱
SOURCE = submit.cpp        # 原始碼檔案

# 這是預設的目標 (default target)，當你直接執行 'make' 時會呼叫它
all: $(TARGET)

# 編譯規則：如何從 .cpp 檔案產生執行檔
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCE) -o $(TARGET)
# ./submit <dataset> <output_name> <run_times> <max_iteration> <M> <K> <alpha> <beta>
	./$(TARGET) point1.txt out_point1.txt 50 2000 60 15.0 0.3 0.02
	./$(TARGET) point2.txt 
	./$(TARGET) point3.txt 
	./$(TARGET) point4.txt

# 'clean' 目標：用來清除編譯過程中產生的檔案
clean:
	rm -f $(TARGET)