# CP Road

## Introduction

**CP_Road** 主要是紀錄我從零到目前為止為 Competitive Programming 所做出的努力。這個 repository 包含了我在學習演算法、資料結構以及解題過程中的所有程式碼、筆記和心得。

從基礎的 C++ 語法開始，到演算法設計、資料結構實作，再到各大 Online Judge 平台的解題記錄，這裡記錄了我在競程之路上的每一步成長。

## Repository Structure

```
CP_Road/
├── Algorithm/          # 演算法學習與作業
├── Basic_cpp/          # C++ 基礎學習
├── CSESproblem/        # CSES 題庫解題
├── DataStructure/      # 資料結構學習與作業
└── Uva_record/         # UVa Online Judge 解題記錄
```

## Detail 

### Algorithm 
此資料夾包含演算法相關的學習與實作：
- **Learning**: 重要演算法概念與技巧的學習記錄
  - `distinct_binary_tree.cpp` - 不同二元樹的計數
  - `Hamiltonian_cycle.cpp` - 哈密頓迴路問題
  - `LIS.cpp` - 最長遞增子序列 (Longest Increasing Subsequence)
- **SchoolTask**: 學校課程作業（包含旅行推銷員問題 TSP 等經典問題）

### Basic_cpp
C++ 基礎語法與程式設計練習：
- **Weekly Labs**: 每週實驗課程練習 (week01 ~ week10)
  - 涵蓋基本輸入輸出、控制流程、函式、陣列、指標等
  - 每週包含 2 個題目與提交說明
- **Homework**: 課程作業 (hw1, hw2)
- **Midterm**: 期中考試題目 (p1 ~ p10)
- 所有編譯輸出存放於各資料夾的 `output/` 目錄

### CSESproblem 
[CSES Problem Set](https://cses.fi/problemset/) 解題記錄：
- **Part1_Introductory_Problems**: 入門題目
- **Part2_Sorting_and_Searching**: 排序與搜尋相關題目
- 已編譯的執行檔存放於 `output/` 目錄

### DataStructure
資料結構課程相關內容：
- **programming_assignment**: 程式作業
- **TextbookExample**: 教科書範例實作
- **CPE_Record**: CPE (College Programming Examination) 練習記錄

### Uva_record
[UVa Online Judge](https://onlinejudge.org/) 解題記錄：
- **Organized by Difficulty**: 依照CPE的難度表進行分類（1-star 到 5-star）
  - `UVA_0_star_question/` - 未分類題
  - `UVA_1_star_question/`
  - `UVA_2_star_question/`
  - `UVA_3_star_question/`
  - `UVA_4_star_question/`
  - `UVA_5_star_question/`
- **Multiple Languages**: 使用 C++、Python 等多種語言實作

## Build & Run

### Prerequisites
- C++ Compiler (g++ 或其他支援 C++11 以上的編譯器)
- CMake (用於 Uva_record 專案)

### Compile Individual Files
```bash
# 使用 g++ 編譯單一檔案
g++ -std=c++17 -O2 -o output/program source.cpp

# 或使用 VS Code 的建置任務
# 打開 .cpp 檔案後按 Ctrl+Shift+B
```

## Progress

這個 repository 持續更新中，記錄著我在競程道路上的學習歷程。每個解題都是一次成長，每個演算法都是一次突破。

## Notes

- 大部分程式碼使用 **C++** 撰寫
- 編譯輸出統一存放於各目錄下的 `output/` 資料夾
- 部分題目包含多種解法或優化版本
- 程式碼中包含註解說明解題思路

## Learning Resources

在這條競程之路上，我參考了許多優秀的資源：
- [CSES Problem Set](https://cses.fi/problemset/)
- [UVa Online Judge](https://onlinejudge.org/)
- 演算法課程教材與教科書
- 各大競程社群與論壇

---

**Keep Learning, Keep Coding! 💪**