# 定義變數
CXX = g++                # C++ 編譯器
CXXFLAGS = -Wall -Wextra # 編譯選項：-Wall 和 -Wextra 會開啟額外的警告
TARGET = submit            # 最終產生的執行檔名稱
SOURCE = submit.cpp        # 原始碼檔案

# 這是預設的目標 (default target)，當你直接執行 'make' 時會呼叫它
all: $(TARGET)

# 編譯規則：如何從 .cpp 檔案產生執行檔
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCE) -o $(TARGET)
	./$(TARGET) point1.txt point2.txt point3.txt

# 'clean' 目標：用來清除編譯過程中產生的檔案
clean:
	rm -f $(TARGET)