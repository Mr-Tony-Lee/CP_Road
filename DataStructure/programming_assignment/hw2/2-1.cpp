/*
    Author : 李承諺(B123040032)
    Date : Sept. 16, 2024 
    PurPose : 以C++製作一個「集合」類別(set class)，使其能進行「聯集」、「交集」、「差集」、「包含」、「屬於」等五種運算。
*/
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class Tset{
    friend Tset operator+ (Tset,Tset);  //聯集的operator overloading 
    friend Tset operator* (Tset,Tset);  //交集的operator overloading 
    friend Tset operator- (Tset,Tset);  //差集的operator overloading 
    friend void operator>= (Tset,Tset); //屬於的operator overloading 
    friend ostream& operator << (ostream& , const Tset );   //輸出格式的operator overloading
    public:
        Tset(string = "" , string = "");        //constructor(用來初始化class)
        void in(char);  //包含的function 
    private:
        string mystring;    //代表輸入的字串
        string name ;   //代表名字
};
//constructor 
Tset::Tset(string a , string n ){   //傳進來的字串內容 跟 他的名字
    int ascii[128] = {0};           //利用ascii code表去紀錄誰用過，最後再push進新的string裡
    int length = a.size();          //傳進來的字串的長度
    for(int i = 0 ; i < length ; i++ ){ //迴圈變數 for 跑過一遍傳進來的字串
        if(ascii[(int)a[i]] == 0 ){ //如果這個字沒有出現過
            ascii[(int)a[i]] = 1 ;  //就紀錄他出現了
        }
    }
    for(int i = 0 ; i < 128 ; i++ ){    //迴圈變數 for push字進新string中
        if(ascii[i] == 1 ){ //如果這個字在剛剛傳進來的字串裡出現過
            mystring.push_back((char)i);    //把他push進新的字串中 
        }
    }
    //以上做到自動排序，因為push時都是從小到大去push
    name = n ; //紀錄這個字串的名字 (A 或 B )
}
//operator overloading for 聯集
Tset operator+ (Tset object1 , Tset object2 ){  //傳進來兩個物件(集合)
    Tset object3 ;  //創建一個新物件 Tset 到時候回傳
    int ascii[128] = {0};   //創建一個ascii code表 
    int length1 = object1.mystring.size();  //這是第一個物件的字串的長度
    int length2 = object2.mystring.size();  //這是第二個物件的字串的長度
    for(int i = 0 ; i < length1 ; i++ ){    //迴圈變數 for 跑過第一個物件的字串
        ascii[(int)object1.mystring[i]] = 1 ;   //那麼就紀錄在ascii code表中，表示已出現
    }    
    for(int i = 0 ; i < length2 ; i++ ){    //迴圈變數 for 跑過第二個物件的字串
        ascii[(int)object2.mystring[i]] = 1 ;   //那麼就紀錄在ascii code表中，表示已出現
    }    
    for(int i = 0 ; i < 128 ; i++ ){    //迴圈變數 for 跑ascii code表
        if(ascii[i] == 1 ) object3.mystring.push_back((char)i);    //如果在ascii code表中有做記號，就把字push進新的string中
    }
    return object3 ;    //回傳新的物件(集合)
}
//operator overloading for 交集
Tset operator* (Tset object1 , Tset object2 ){  //傳進來兩個物件(集合)
    Tset object3 ;  //創建一個新物件 Tset 到時候回傳
    int ascii[128] = {0};   //創建一個ascii code表
    int length1 = object1.mystring.size();  //這是第一個物件的字串的長度
    int length2 = object2.mystring.size();  //這是第二個物件的字串的長度
    for(int i = 0 ; i < length1 ; i++ ){    //迴圈變數 for 跑過第一個物件的字串
        if(ascii[(int)object1.mystring[i]] == 0 ){  //如果這個字沒出現過
            ascii[(int)object1.mystring[i]] = 1 ;   //那麼就紀錄在ascii code表中，表示已出現
        }
    }    
    for(int i = 0 ; i < length2 ; i++ ){    //迴圈變數 for 跑過第二個物件的字串
        if(ascii[(int)object2.mystring[i]] == 1 ){  //如果這個字已經被記錄出現過，現在出現在字串2中，則特別紀錄
            ascii[(int)object2.mystring[i]] = 2 ;   //則特別紀錄
        }
    }    
    for(int i = 0 ; i < 128 ; i++ ){    //迴圈變數 for 跑 ascii code表
        if(ascii[i] == 2 ){ //如果這個字出現兩次
            object3.mystring.push_back((char)i);    //那就Push進新的字串中
        }
    }
    return object3 ;    //回傳新的物件(集合)
}
//operator overloading for 差集
Tset operator- (Tset object1 , Tset object2 ){  //傳進來兩個物件(集合)
    Tset object3 ;  //創建一個新物件 Tset 到時候回傳
    int ascii[128] = {0};   //創建一個ascii code表
    int length1 = object1.mystring.size();  //這是第一個物件的字串的長度
    int length2 = object2.mystring.size();  //這是第二個物件的字串的長度
    for(int i = 0 ; i < length1 ; i++ ){    //迴圈變數 for 跑第一個物件的字串
        if(ascii[(int)object1.mystring[i]] == 0 ){  //如果這個字沒出現過
            ascii[(int)object1.mystring[i]] = 1 ;   //那麼就紀錄在ascii code表中，表示已出現
        }
    }    
    for(int i = 0 ; i < length2 ; i++ ){    //迴圈變數 for 跑第二個物件的字串
        if(ascii[(int)object2.mystring[i]] == 1 ){  //如果這個在字串1中已經出現，那就歸0，因為我們要的是不能同時出現的
            ascii[(int)object2.mystring[i]] = 0 ;
        }
    }    
    for(int i = 0 ; i < 128 ; i++ ){    //迴圈變數 for 跑 ascii code表
        if(ascii[i] == 1 ){ //如果在表中有被做過紀錄
            object3.mystring.push_back((char)i);    //則push進新的物件中
        }
    }
    return object3 ;    //回傳新的物件(集合)
}
//operator overloading for 包含
void operator >= (Tset object1 , Tset object2 ){
    Tset object3 ;  //創建一個新物件 Tset 到時候回傳
    int ascii[128] = {0};   //創建一個ascii code表
    int count = 0 ; //算 被記錄的 有幾個字
    int length1 = object1.mystring.size();  //這是第一個物件的字串的長度
    int length2 = object2.mystring.size();  //這是第二個物件的字串的長度
    for(int i = 0 ; i < length1 ; i++ ){    //迴圈變數 for 跑第一個物件的字串
        if(ascii[(int)object1.mystring[i]] == 0 ){  //如果這個字在表中未出現
            ascii[(int)object1.mystring[i]] = 1 ;   //那麼就紀錄在ascii code表中，表示已出現
        }
    }    
    for(int i = 0 ; i < length2 ; i++ ){    //迴圈變數 for 跑第二個物件的字串
        if(ascii[(int)object2.mystring[i]] == 1 ){  //如果第二個物件的字串中的字元在表中有被做過紀錄，則count+1
            count++ ;
        }
    }    
    if(count == length2){   //如果count跟字串2一樣長，那麼就是包含在字串1中
        cout << object2.name << " is contain in " << object1.name << endl;    
    }
    else{   //如果count跟字串2不一樣長，那麼就是不包含在字串1中
        cout << object2.name << " is not contain in " << object1.name << endl;    
    }
}

//function for 屬於
void Tset::in(char x){  //傳入一個字元x
    int length = mystring.size();   //這是本身物件的字串長度
    for(int i = 0 ; i < length ; i++ ){ //迴圈變數for跑過本身的字串
        if(mystring[i] == x ){  //如果在自己的字串中有找到x，那麼x屬於此字串
            cout << "\'" << x << "\' is in " << name << endl; //印出
            return ;//直接結束
        }
    }
    //如果跑完上面的for迴圈。則代表x沒有出現在本身物件的字串中
    cout << "\'" << x << "\' is not in " << name << endl; //則印出不屬於

}

//輸出class Tset 的格式
ostream& operator << (ostream& output , const Tset object ){    //傳入ostream跟一個Tset物件
    output << "{" << object.mystring << "}" ;   //每次遇到這個物件都會照這個格式輸出
    return output;  //回傳輸出的東西
}

int main(){
    int times ; //用來看有幾筆測資
    cin >> times ;  //輸入測資的數量
    cin.ignore();       //使用ignore避免之後的getline讀取到 換行符號
    int count = 1 ; 
    while(times--){ //跑 (測資的數量) 的次數
        string string1 , string2 ;  //每次測資傳入兩個字串
        char x ;    //跟一個字元
        getline(cin,string1);   //用getline讀取每一個字串(因為有可能包含空格，不能用cin)
        Tset A(string1,"A");    //用字串創建一個Tset物件並取名"A"
        getline(cin,string2);   //用getline讀取每一個字串(因為有可能包含空格，不能用cin)
        Tset B(string2 , "B") ; //用字串創建一個Tset物件並取名"B"
        string string3 ;  //用來讀取字元的string
        getline(cin,string3);   //用getline讀取字元(因為有可能包含空格，不能用cin)
        x = string3[0];    //把字元存進x
        cout << "Test Case:" << count++ << endl;
        cout << "A: " << A << endl; //輸出A物件
        cout << "B: " << B << endl; //輸出B物件
        Tset C = A+B;   //做聯集的運算
        cout << "A+B: " << C << endl;   //輸出結果
        Tset D = A*B;   //做交集的運算
        cout << "A*B: " << D << endl;   //輸出結果
        Tset E = A-B;   //做差集的運算
        cout << "A-B: " << E << endl;   //輸出結果
        Tset F = B-A;   //做差集的運算
        cout << "B-A: " << F << endl;   //輸出結果
        A >= B ;    //做屬於的運算
        B >= A ;    //做屬於的運算
        A.in(x);    //做包含的運算
        B.in(x);    //做包含的運算
        cout << endl;
    }
}