/*
    Author : 李承諺(B123040032)
    Date : Dec. 14, 2024 
    PurPose : 以Huffman 演算法製作一個檔案壓縮與解壓縮之軟體，此為無GUI介面之檔案
*/
#include <bits/stdc++.h> // 引入標準 C++ 所有常用標頭檔案
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
    int number_size = sizeof(int) + sizeof(int) + sizeof(float);

    int originalSize = data.size(); // 計算原始檔案大小 (以位元為單位)
    int compressedSize = (encoded.size()+7)/8 + table_size + number_size ; // 計算壓縮後大小
    float compressionRatio = (float)(originalSize) / (compressedSize); // 計算壓縮率

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
    float compressionRatio;
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


int main(int argc, char* argv[]) {
    if (argc < 5) {
        cerr << "使用方式: " << argv[0] << " [-c|-u] -i <輸入檔案> -o <輸出檔案>\n";
        return 1;
    }
    string mode = argv[1];       // -c 或 -u
    string inputFlag = argv[2];  // 應為 -i
    string inputFile = argv[3];  // 輸入檔案名稱
    string outputFlag = argv[4]; // 應為 -o
    string outputFile = argv[5]; // 輸出檔案名稱

    // 檢查模式
    if (mode != "-c" && mode != "-u") {
        cerr << "錯誤的模式！請使用 -c 進行壓縮或 -u 進行解壓縮。" << endl;
        return 1;
    }

    // 檢查輸入與輸出標誌
    if (inputFlag != "-i" || outputFlag != "-o") {
        cerr << "錯誤的引數標誌！請使用 -i 指定輸入檔案，-o 指定輸出檔案。" << endl;
        return 1;
    }
    try {
        if (mode == "-c") {
            compressFile(inputFile, outputFile);
        }
        else if (mode == "-u") {
            decompressFile(inputFile, outputFile);
        }
    } 
    catch (const exception& e) {
        cerr << "操作失敗：" << e.what() << endl;
        return 1;
    }
    return 0;
}