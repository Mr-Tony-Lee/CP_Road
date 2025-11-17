/*
    Author : 李承諺(B123040032)
    Date : Dec. 14, 2024 
    PurPose : 以Huffman 演算法製作一個檔案壓縮與解壓縮之軟體，此為有GUI介面之檔案
*/
// 要放在Windows上有G++的環境執行，Ex: DevC++

#include <windows.h>
#include <commdlg.h>
#include<bits/stdc++.h>
using namespace std;

// 節點類別，表示 Huffman Tree 的一個節點
struct Node {
    char ch;          // 節點所代表的字符
    int freq;         // 字符的頻率
    Node* left;       // 左子樹
    Node* right;      // 右子樹
    // 節點的構造函數，初始化字符、頻率及左右子樹
    Node(char c, int f, Node* l = nullptr, Node* r = nullptr) : ch(c), freq(f), left(l), right(r) {}
};

// 遞迴查找節點中最小的字符
char findMinChar(Node* node) {
    if (!node->left && !node->right) return node->ch; // 如果是葉節點，直接返回字符
    char leftMin = node->left ? findMinChar(node->left) : CHAR_MAX; // 左子樹最小字符，若無則為最大值
    char rightMin = node->right ? findMinChar(node->right) : CHAR_MAX; // 右子樹最小字符，若無則為最大值
    return min(leftMin, rightMin); // 返回左右子樹中較小的字符
}

// 比較函數，用於優先佇列排序
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq) {
            // 頻率相同時比較字典順序
            char minCharA = findMinChar(a); // 找出節點 a 的最小字符
            char minCharB = findMinChar(b); // 找出節點 b 的最小字符
            return minCharA > minCharB; // 字典順序較小的優先
        }
        return a->freq > b->freq; // 頻率較低的優先
    }
};

// 建立字符頻率表
map<char, int> buildFrequencyMap(const string& data) {
    map<char, int> freqMap; // 使用 map 儲存每個字符的頻率
    for (char ch : data) {  // 遍歷輸入字串
        freqMap[ch]++;      // 計算每個字符出現的次數
    }
    return freqMap;         // 返回頻率表
}

// 建立 Huffman Tree
Node* buildHuffmanTree(const map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq; // 根據頻率和字典順序排序

    for (const auto& pair : freqMap) { // 將每個字符與其頻率封裝成節點並加入優先佇列
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) { // 重複合併節點直到只剩一棵樹
        Node* left = pq.top(); pq.pop();   // 優先佇列中最小頻率的節點作為左子樹
        Node* right = pq.top(); pq.pop(); // 優先佇列中次小頻率的節點作為右子樹

        // 確保左子樹字典順序較小
        if (findMinChar(left) > findMinChar(right)) {
            swap(left, right); // 若不符合規則，交換左右子樹
        }

        // 建立父節點，其頻率為左右子樹頻率之和
        Node* parent = new Node('\0', left->freq + right->freq, left, right);
        pq.push(parent); // 將父節點加入優先佇列
    }

    return pq.top(); // 返回 Huffman Tree 的根節點
}

// 建立 Huffman 編碼表
void buildHuffmanCodeMap(Node* root, const string& code, map<char, string>& codeMap) {
    if (!root) return; // 若節點為空則返回

    if (!root->left && !root->right) { // 若為葉節點，將其編碼加入編碼表
        codeMap[root->ch] = code;
    }

    // 遞迴遍歷左子樹，附加 '0' 到當前編碼
    buildHuffmanCodeMap(root->left, code + "0", codeMap);
    // 遞迴遍歷右子樹，附加 '1' 到當前編碼
    buildHuffmanCodeMap(root->right, code + "1", codeMap);
}

// 將輸入字串編碼為 Huffman 壓縮格式
string encode(const string& data, const map<char, string>& codeMap) {
    string encoded; // 儲存編碼結果
    for (char ch : data) { // 遍歷每個字符
        encoded += codeMap.at(ch); // 根據編碼表找到對應的編碼並加入結果
    }
    return encoded; // 返回編碼結果
}

// 壓縮檔案並儲存壓縮結果與編碼表
void compressFile(const string& inputFile, const string& outputFile) {
    double start = clock();
    ifstream in(inputFile, ios::binary);
    if (!in) { // 檢查檔案是否成功打開
        cerr << "無法打開檔案: " << inputFile << endl;
        exit(1);
    }

    string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>()); // 讀取檔案內容到字串
    in.close(); // 關閉檔案

    auto freqMap = buildFrequencyMap(data); // 建立字符頻率表
    Node* root = buildHuffmanTree(freqMap); // 建立 Huffman Tree
    map<char, string> codeMap;
    buildHuffmanCodeMap(root, "", codeMap); // 建立 Huffman 編碼表

    string encoded = encode(data, codeMap); // 將原始字串進行 Huffman 編碼
    
    ofstream out(outputFile, ios::binary); // 用二進位模式寫入壓縮檔案
    if (!out) { // 檢查檔案是否成功打開
        cerr << "無法打開輸出檔案: " << outputFile << endl;
        exit(1);
    }

    // File Header
    char codeMapSize = codeMap.size() == 256 ? 0 : codeMap.size() ; // 編碼表的大小    
    out.write((char*)(&codeMapSize), sizeof(codeMapSize)); // 寫入編碼表大小
    
    // 寫入編碼表
    int total_codeLength = 0 ; 
    string bitstring = "";
    for (const auto& pair : codeMap) {
        out.put(pair.first); // 寫入字符
        char codeLength = pair.second.size(); // 編碼長度
        out.write((char*)(&codeLength), sizeof(codeLength)); // 寫入編碼長度
        //out.write(pair.second.c_str(), codeLength); // 寫入編碼內容
        bitstring += pair.second ;
        while(bitstring.size() > 8 ){
            string byte = bitstring.substr(0, 8); // 取 8 位
            char byteChar = static_cast<char>(bitset<8>(byte).to_ulong()); // 轉換為位元組
            out.put(byteChar);
            bitstring = bitstring.substr(8);
        }
        if(bitstring.size()){
            while(bitstring.size() < 8 ){
                bitstring += '0';
            }
            char byteChar = static_cast<char>(bitset<8>(bitstring).to_ulong()); // 轉換為位元組
            out.put(byteChar);
            bitstring.clear();
        }
        total_codeLength += sizeof(pair.first) + sizeof(codeLength) + ((codeLength+7)/8);
    }
    int table_size = sizeof(char) + total_codeLength;
    int number_size = sizeof(int) + sizeof(int) + sizeof(double);

    int originalSize = data.size(); // 計算原始檔案大小 (以位元為單位)
    int compressedSize = (encoded.size()+7)/8 + table_size + number_size ; // 計算壓縮後大小
    double compressionRatio = (double)(originalSize) / (compressedSize); // 計算壓縮率

    // 寫入檔案資訊到 header
    out.write((char*)(&originalSize), sizeof(originalSize)); // 原始檔案大小
    out.write((char*)(&compressedSize), sizeof(compressedSize)); // 壓縮檔案大小
    out.write((char*)(&compressionRatio), sizeof(compressionRatio)); // 壓縮率
    
    // 壓縮資料
    string byteBuffer;
    for (int i = 0; i < encoded.size(); i += 8) { // 將編碼資料分組為 8 位元
        string byte = encoded.substr(i, 8);
        while (byte.size() < 8) {
            byte += "0";  // 填充不足 8 位的部分
        }
        char byteChar = static_cast<char>(bitset<8>(byte).to_ulong()); // 轉換為位元組
        out.put(byteChar);
    }
    out.close(); // 關閉壓縮檔案

    double end = clock();
    
    // 把compressed的資訊寫進ReadableCompress.txt 
    cout << "=== 編碼表 ===\n";
    for (const auto& pair : codeMap) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    cout << "\n=== 壓縮資料 ===\n";
    cout << "原始大小 (位元組): " << originalSize << '\n';
    cout << "壓縮後大小 (位元組): " << compressedSize << '\n';
    cout << "壓縮率: " << fixed << setprecision(2) << compressionRatio * 100 << "%\n";
    
    cout << "壓縮完成，檔案已儲存至: " << outputFile << endl;
    cout << "壓縮率: " << fixed << setprecision(2) << compressionRatio * 100 << "%" << endl;
    cout << "壓縮耗時: " << (end-start)/CLOCKS_PER_SEC << " Sec " << endl;
}

//解壓縮檔案
void decompressFile(const string& compressedFile, const string& outputFile) {
    double start = clock();
    ifstream in(compressedFile, ios::binary); // 開啟壓縮檔案以二進位模式讀取
    if (!in) {
        cerr << "無法打開壓縮檔案: " << compressedFile << endl;
        exit(1); // 若檔案無法打開，輸出錯誤訊息並退出程式
    }
    // 讀取 File Header
    char codeMapSize; // 用來儲存編碼表大小
    in.read((char*)(&codeMapSize), sizeof(codeMapSize)); // 從檔案中讀取編碼表大小
    int codeMapSize_i = codeMapSize == 0 ? 256 : (int)codeMapSize ;
    map<string, char> reverseCodeMap; // 用來儲存反向編碼表 (從編碼到字符)
    for (int i = 0; i < codeMapSize_i ; ++i) {
        char ch; // 當前字符
        char codeLength; // 當前字符對應編碼的長度
        in.get(ch); // 從檔案中讀取字符
        in.read((char*)(&codeLength), sizeof(codeLength)); // 讀取對應編碼的長度
        string code; // 初始化一個字串來儲存編碼
        int total_byte = (codeLength+7)/8;
        int readBits = 0 ;
        while(total_byte--){
            char byte;
            in.get(byte);
            for (int i = 7 ; i >= 0 && readBits < codeLength ; --i) {
                code += ((byte >> i) & 1) ? '1' : '0';
                ++readBits;
            }
        }
        reverseCodeMap[code] = ch; // 將編碼與字符對應存入反向編碼表
    }
    // 讀取壓縮檔案的統計資訊
    int originalSize, compressedSize;
    double compressionRatio;
    in.read((char*)(&originalSize), sizeof(originalSize)); // 原始檔案大小
    in.read((char*)(&compressedSize), sizeof(compressedSize)); // 壓縮檔案大小
    in.read((char*)(&compressionRatio), sizeof(compressionRatio)); // 壓縮率

    ofstream out(outputFile, ios::binary); // 開啟輸出檔案以二進位模式寫入
    if (!out) {
        cerr << "無法打開輸出檔案: " << outputFile << endl;
        exit(1); // 若檔案無法打開，輸出錯誤訊息並退出程式
    }

    string currentCode;       // 暫存當前正在匹配的編碼
    int readbytes = 0 ; 
    char byte;
    while (in.get(byte) && readbytes < originalSize) { 
        // 逐位解析壓縮資料
        for (int i = 7; i >= 0 && readbytes < originalSize ; --i) {
            currentCode += ((byte >> i) & 1) ? '1' : '0'; // 提取當前位元
            if (reverseCodeMap.count(currentCode)) {      // 檢查是否為有效編碼
                out.put(reverseCodeMap.at(currentCode)); // 解碼後直接寫入輸出檔案
                currentCode.clear();                     // 清空當前暫存的編碼
                ++readbytes;
            }
        }
    }
    in.close();
    out.close(); // 關閉輸出檔案
    double end = clock();
    cout << "解壓縮完成，檔案已儲存至: " << outputFile << endl; // 提示解壓縮完成
    cout << (end-start) / CLOCKS_PER_SEC << " Sec" << endl;
}

// 全域變數，用於存放使用者選擇的檔案路徑
string selectedFile;

// 處理壓縮按鈕按下的事件
void onCompress(HWND hwnd) {
    OPENFILENAME ofn; // 用於檔案選擇對話框的結構
    char szFile[260] = {0}; // 用於存放選擇的檔案路徑
    ZeroMemory(&ofn, sizeof(ofn)); // 將 ofn 結構清空
    ofn.lStructSize = sizeof(ofn); // 設定結構大小
    ofn.hwndOwner = hwnd; // 指定擁有者窗口的句柄
    ofn.lpstrFile = szFile; // 指定用於儲存檔案路徑的緩衝區
    ofn.nMaxFile = sizeof(szFile); // 設定緩衝區大小
    ofn.lpstrFilter = "All Files\0*.*\0"; // 設定檔案篩選器
    ofn.nFilterIndex = 1; // 設定預設的篩選器索引
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 強制要求路徑與檔案存在

    if (GetOpenFileName(&ofn)) { // 開啟檔案選擇對話框，若成功則進入此條件
        selectedFile = szFile; // 儲存選擇的檔案路徑到全域變數
        string outputFile = selectedFile + ".huff"; // 壓縮後檔案的路徑（加上 ".huff" 副檔名）
        compressFile(selectedFile, outputFile); // 調用壓縮檔案的函式
        MessageBox(hwnd, "壓縮完成！", "提示", MB_OK); // 顯示壓縮完成的提示框
    }
}

// 處理解壓縮按鈕按下的事件
void onDecompress(HWND hwnd) {
    OPENFILENAME ofn; // 用於檔案選擇對話框的結構
    char szFile[260] = {0}; // 用於存放選擇的檔案路徑
    ZeroMemory(&ofn, sizeof(ofn)); // 將 ofn 結構清空
    ofn.lStructSize = sizeof(ofn); // 設定結構大小
    ofn.hwndOwner = hwnd; // 指定擁有者窗口的句柄
    ofn.lpstrFile = szFile; // 指定用於儲存檔案路徑的緩衝區
    ofn.nMaxFile = sizeof(szFile); // 設定緩衝區大小
    ofn.lpstrFilter = "Huffman Files\0*.huff\0"; // 設定檔案篩選器為 .huff 檔案
    ofn.nFilterIndex = 1; // 設定預設的篩選器索引
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 強制要求路徑與檔案存在

    if (GetOpenFileName(&ofn)) { // 開啟檔案選擇對話框，若成功則進入此條件
        selectedFile = szFile; // 儲存選擇的檔案路徑到全域變數
        // 計算解壓縮後的檔案路徑，副檔名改為 "_decompressed"
        string outputFile = selectedFile.substr(0, selectedFile.find_first_of(".")) 
                            + "_decompressed"
                            + selectedFile.substr(selectedFile.find_first_of("."), selectedFile.size() - selectedFile.find_last_of(".") - 1);
        decompressFile(selectedFile, outputFile); // 調用解壓縮檔案的函式
        MessageBox(hwnd, "解壓縮完成！", "提示", MB_OK); // 顯示解壓縮完成的提示框
    }
}

// 窗口程序，處理窗口訊息
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) { // 根據訊息類型進行處理
        case WM_COMMAND: // 當有控制項的命令訊息時
            switch (LOWORD(wParam)) { // 判斷命令來源
                case 1: onCompress(hwnd); break; // 如果是壓縮按鈕，執行壓縮處理
                case 2: onDecompress(hwnd); break; // 如果是解壓縮按鈕，執行解壓縮處理
            }
            break;
        case WM_DESTROY: // 當窗口被銷毀時
            PostQuitMessage(0); // 發送退出訊息，結束程式
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam); // 使用預設的訊息處理
    }
    return 0;
}

// 程式進入點，負責建立主窗口
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    const char CLASS_NAME[] = "HuffmanGUI"; // 定義窗口類名稱
    WNDCLASS wc = { }; // 初始化窗口類
    wc.lpfnWndProc = WindowProc; // 指定窗口程序
    wc.hInstance = hInstance; // 指定程式實例
    wc.lpszClassName = CLASS_NAME; // 指定窗口類名稱

    RegisterClass(&wc); // 註冊窗口類

    // 建立主窗口
    HWND hwnd = CreateWindowEx(
        0, // 擴展樣式
        CLASS_NAME, // 窗口類名稱
        "Huffman 壓縮工具", // 窗口標題
        WS_OVERLAPPEDWINDOW, // 窗口樣式
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 200, // 窗口位置與大小
        NULL, // 父窗口句柄
        NULL, // 菜單句柄
        hInstance, // 程式實例
        NULL // 附加參數
    );

    if (hwnd == NULL) { // 如果窗口建立失敗
        return 0; // 結束程式
    }

    // 建立壓縮檔案按鈕
    CreateWindow("BUTTON", "壓縮檔案",
                 WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // 按鈕樣式
                 20, 50, 200, 30, // 按鈕位置與大小
                 hwnd, (HMENU)1, hInstance, NULL); // 按鈕父窗口、ID 與程式實例

    // 建立解壓縮檔案按鈕
    CreateWindow("BUTTON", "解壓縮檔案",
                 WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, // 按鈕樣式
                 240, 50, 200, 30, // 按鈕位置與大小
                 hwnd, (HMENU)2, hInstance, NULL); // 按鈕父窗口、ID 與程式實例

    ShowWindow(hwnd, nCmdShow); // 顯示窗口

    MSG msg = { }; // 初始化訊息結構
    while (GetMessage(&msg, NULL, 0, 0)) { // 循環處理訊息
        TranslateMessage(&msg); // 翻譯鍵盤訊息
        DispatchMessage(&msg); // 將訊息發送給窗口程序
    }
    
    return 0; // 程式結束
}