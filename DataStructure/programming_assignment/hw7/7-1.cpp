/*
    Author : 李承諺(B123040032)
    Date : Nov. 19, 2024 
    PurPose : 測試五種排序(sorting)演算法的執行效率
*/
#include<bits/stdc++.h>
using namespace std;

// Selection Sort 的函式
void Selection_Sort(int* array , int size ){    // 傳入一維陣列，跟陣列的size
    for(int i = 0 ; i < (int) size-1 ; i++){    // 用 i 從 頭跑到 size-1
        int min = array[i] , min_index = i ;    
        for(int j = i+1 ; j < (int) size; j++ ){//用 j 從 i + 1 往後跑到底，找最小值，並與array[i]交換
            if(array[j] < min ){    // 如果array[j] 比 現在的最小值還小
                min = array[j]; // 更換最小值
                min_index = j;  // 更換index
            }
        }
        swap(array[min_index] , array[i]);  // 交換
    }
}

// Merge Sort 的函式
void merge(int* arr , int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    int* L = new int[n1] ;
    int* R = new int[n2];

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int* arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void Merge_Sort(int* array , int size ){    //傳入一維陣列，跟陣列的size
    mergeSort(array, 0, size - 1);
}

// A utility function to get maximum
// value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void countSort(int *arr, int n, int exp)
{
    // Output array
    int output[n];
    int i, count[10] = { 0 };

    // Store count of occurrences
    // in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i]
    // now contains actual position
    // of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[],
    // so that arr[] now contains sorted
    // numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[]
// of size n using Radix Sort
void radixsort(int* arr, int n)
{

    // Find the maximum number to
    // know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit.
    // Note that instead of passing digit
    // number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Radix Sort 的函式
void Radix_Sort(int* array , int size ){    //傳入一維陣列，跟陣列的size
    radixsort(array,size);
}

// C++ sort 的函式
void CSort(int* array , int size ){ //傳入一維陣列，跟陣列的size
    sort(array,array+size);
}

int compare(const void *a , const void*b ){     //寫給Cqsort的compare函式
    int c = *(int *)a; //指定 a 是 int的指標 ， 並賦值給c
    int d = *(int *)b; //指定 b 是 int的指標 ， 並賦值給d
    if(c < d) return -1;            
    else if (c == d) return 0;      
    else return 1; 
}

// Cqsort 的函式
void Cqsort(int* array , int size ){    //傳入一維陣列，跟陣列的size
    qsort(array , size , sizeof(int) , compare );
}

//創造亂數的function 
void generate(int* array , int size ){  //傳入array , array的size
    for(int i = 0 ; i < size ; i++ ){   
        array[i] = rand() % size;   //生成亂數給array
    }
}

//測試用，印出Array
void printArray(int*array , int size ){
    if(size > 100 ){    //只印出size <= 100的長度的array
        return ;
    }
    cout << "Array : " ;
    for(int i = 0 ; i  < size ; i++ ){
        cout << array[i] << " ";
    }
    cout << endl;
}

//用來執行每一個sort 
void Execute(int* array, int size ){    //傳入一維陣列，跟陣列的size
    int *array_for_Select = new int[size];  //創造一個新的array 給 Select 用，用的是同一個亂數
    for(int i = 0 ; i < size ; i++ ){
        array_for_Select[i] = array[i];
    }
    
    // printArray(array_for_Select,size);
    
    double START,END; 
    START = clock();    //開始計時
    Selection_Sort(array_for_Select,size);
    END = clock();      //結束計時
    cout <<"Selection Sort For size " << size << " Execute : "<<  (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;   // 輸出計時結果

    // printArray(array_for_Select,size);

    int * array_for_Merge = new int[size]; //創造一個新的array 給 Merge 用，用的是同一個亂數
    for(int i = 0 ; i < size ; i++ ){
        array_for_Merge[i] = array[i];
    }
    // printArray(array_for_Merge,size);

    START = clock();    //開始計時
    Merge_Sort(array_for_Merge,size);
    END = clock();      //結束計時
    cout <<"Merge Sort For size " << size << " Execute : "<<  (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;   // 輸出計時結果

    // printArray(array_for_Merge,size);
    
    int * array_for_Radix = new int[size];  //創造一個新的array 給 Radix 用，用的是同一個亂數
    for(int i = 0 ; i < size ; i++ ){
        array_for_Radix[i] = array[i];  //給array賦值
    }
    // printArray(array_for_Radix,size);

    START = clock();    //開始計時
    Radix_Sort(array_for_Radix,size);
    END = clock();      //結束計時
    cout <<"Radix Sort For size " << size << " Execute : "<<  (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;   // 輸出計時結果
    
    // printArray(array_for_Radix,size);
    
    int * array_for_CSort = new int[size];  //創造一個新的array 給 CSort 用，用的是同一個亂數
    for(int i = 0 ; i < size ; i++ ){
        array_for_CSort[i] = array[i];
    }
    // printArray(array_for_CSort,size);

    START = clock();    //開始計時
    CSort(array_for_CSort,size);
    END = clock();      //結束計時
    cout <<"C++ Sort For size " << size << " Execute : "<<  (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;   // 輸出計時結果
    
    // printArray(array_for_CSortsize);
    
    int * array_for_Cqsort = new int[size]; //創造一個新的array 給 Cqsort 用，用的是同一個亂數
    for(int i = 0 ; i < size ; i++ ){
        array_for_Cqsort[i] = array[i];
    }
    //printArray(array_for_Cqsort,size);

    START = clock();    //開始計時
    Cqsort(array_for_Cqsort,size);
    END = clock();      //結束計時
    cout <<"C qSort For size " << size << " Execute : "<<  (END - START) / CLOCKS_PER_SEC << " sec" << endl << endl;   // 輸出計時結果
    
    //printArray(array_for_Cqsort,size);
}

// 用來測試大量資料的函式
void testcase(){
    // 以下是大量資料的測試code
    int size[8] = {100,500,1000,5000,10000,50000,100000,500000};    //創造8種出不同的size
    // 創造 array , 生成亂數，並執行全部的排序法
    int * array1 = new int[size[0]]; generate(array1 , size[0]); Execute(array1, size[0]);  
    int * array2 = new int[size[1]]; generate(array2 , size[1]); Execute(array2, size[1]);
    int * array3 = new int[size[2]]; generate(array3 , size[2]); Execute(array3, size[2]);
    int * array4 = new int[size[3]]; generate(array4 , size[3]); Execute(array4, size[3]);
    int * array5 = new int[size[4]]; generate(array5 , size[4]); Execute(array5, size[4]);
    int * array6 = new int[size[5]]; generate(array6 , size[5]); Execute(array6, size[5]);
    int * array7 = new int[size[6]]; generate(array7 , size[6]); Execute(array7, size[6]);
    int * array8 = new int[size[7]]; generate(array8 , size[7]); Execute(array8, size[7]);
}

//用來輸出到檔案的函式
void fileoutput(string name  , int* array , int size ){
    ofstream out ; //宣告要寫出的檔案
    out.open("../"+ name + ".txt"); //開啟要寫出的檔案  
    string sort_name;
    if( name == "outputA" ){        //如果進來的name是outputA
        sort_name = "Selection Sort";   //那使用selection sort
        Selection_Sort( array, size );
    }
    else if ( name == "outputB" ){  //如果進來的name是outputB
        sort_name = "Merge Sort";   //那使用Merge sort
        Merge_Sort( array , size );
    }
    else if ( name == "outputC" ){  //如果進來的name是outputC
        sort_name = "Radix Sort";   //那使用Radix sort
        Radix_Sort( array , size) ; 
    }
    else if ( name == "outputD" ){  //如果進來的name是outputD
        sort_name = "C++ Sort()";   //那使用C++ sort()
        CSort( array , size );
    } 
    else if ( name == "outputE" ){  //如果進來的name是outputE
        sort_name = "Cqsort()";     //那使用Cqsort()
        Cqsort( array , size );
    }
    out << sort_name ; //先輸出第一行，使用的是什麼排序法
    for(int i = 0 ; i < size ; i++ ){   // 輸出所有數字
        if(i % 10 == 0 ) out << "\n";
        out << array[i] << " ";
    }
    out << "\n" << "Program End";   //輸出Program End代表輸出結束
    out.close();    //關閉寫出檔案
}

//關於檔案的處理的函式 ( 包含讀入 + 創造array + call 寫出的函式 )
void filerelate(){
    ifstream in ;   // 讀入的檔案宣告
    in.open("../input.txt");    // 開啟檔案
    int size ; 
    in >> size ; // 讀入第一行的size
    int *input_array_A = new int[size]; // 建立一個陣列給outputA
    int *input_array_B = new int[size]; // 建立一個陣列給outputB 
    int *input_array_C = new int[size]; // 建立一個陣列給outputC
    int *input_array_D = new int[size]; // 建立一個陣列給outputD
    int *input_array_E = new int[size]; // 建立一個陣列給outputE
    for(int i = 0 ; i < size ; i++ ){
        in >> input_array_A[i];        //將檔案的內容讀入到其中一個陣列
    }
    for(int i = 0 ; i < size ; i++ ){
        input_array_B[i] = input_array_A[i];    //用那個陣列幫其他陣列賦值
        input_array_C[i] = input_array_A[i];    //用那個陣列幫其他陣列賦值
        input_array_D[i] = input_array_A[i];    //用那個陣列幫其他陣列賦值
        input_array_E[i] = input_array_A[i];    //用那個陣列幫其他陣列賦值
    }
    fileoutput("outputA" , input_array_A , size );  // call output 到 outputA 的 function 
    fileoutput("outputB" , input_array_B , size );  // call output 到 outputB 的 function 
    fileoutput("outputC" , input_array_C , size );  // call output 到 outputC 的 function 
    fileoutput("outputD" , input_array_D , size );  // call output 到 outputD 的 function 
    fileoutput("outputE" , input_array_E , size );  // call output 到 outputE 的 function 
    in.close(); //關閉讀入的檔案
}

int main(){
    srand(time(NULL));
    //testcase();  //用來測試大量資料
    filerelate();   //關於檔案的處理
}