/*
    Author : 李承諺(B123040032)
    Date : Sept. 23, 2024 
    PurPose : 設計一個程式，可以處理兩個多項式之加法與乘法
*/
#include<iostream>
#include<map>
using namespace std;
class Node{ //class Node 
    public:
        Node(int = 0 , int = 0 , Node* = NULL); //constructor for Node class
        friend ostream& operator << (ostream& , Node* );    //控制輸出格式的operator overloading
        int X ; // coefficient 
        int Y ; // exponent 
        Node* next ;    //next Node address 
};
Node::Node(int coefficient , int exponent , Node* n): X(coefficient), Y(exponent), next(n) {}   //constructor 

ostream& operator << (ostream& output , Node* object){  //控制輸出格式的operator overloading 
    output << object->X << " " << object->Y ;   //輸出格式符合題目敘述 >> X Y
    return output ; //回傳output
}
class SLL{  //class Singly linked list to store polynomial
    friend SLL operator + (const SLL, const SLL);   //operator overloading for + 
    friend SLL operator * (const SLL, const SLL);   //operator overloading for *
    public:
        SLL(Node* = NULL );     //constructor 
        void push(int , int );  //function for push Node into polynomial
        void print();           //function for print polynomial
        void clear();           // function for clear the linked list 
        Node* head ;            // 最前面的節點 
};
SLL::SLL(Node* h): head(h){}    //constructor 
//push node into linked list  
void SLL::push(int x , int y){
    Node*temp = new Node(x,y);  //先創建一個新的指標指向一個Node
    if(head == NULL){   //如果現在SLL裡面還沒有東西
        head = temp ;   //那這個Node 就是頭
        return;     //並結束
    }
    temp->next = head;  //如果有東西，那就讓新的Node的next是現在的頭
    head = temp;        //再把頭的指標指向現在這個新的Node 
}
//print the linked list 
void SLL::print(){
    Node* temp = head;  //先用一個temp 指向開頭
    while(temp != NULL ){   //只要這個temp 不是空的
        cout << temp << endl;   //那就輸出這個Node
        temp = temp->next ;     //並在最後，把temp 改成原本temp的下一個
    }
}
void traversal_SLL_and_record_into_map (SLL poly , map<int,int>& exp_coe ){ //traversal SLL and record into map
    Node* temp = poly.head ;            //先用一個temp 指向開頭
    while( temp != NULL ){              //一樣用temp把整個SLL遍歷一次
        exp_coe[temp->Y] += temp->X;    //key = 次方 value += 係數 (map的value初始化為0)
        temp = temp->next ;        
    }
}
void push_Node_from_map_to_SLL(SLL& ans , map<int,int> exp_coe ){   //push Node from map to SLL
    //second 是係數，first 是次方，用map，first會自動排序
    //for(auto& it:exp_coe){
    //     if(it.second != 0 ){
    //         poly.push(it.second,it.first);
    //     }
    // }
    for(map<int, int>::iterator it = exp_coe.begin(); it != exp_coe.end(); it++){   //iterator遍歷map
        if((*it).second != 0 ){ //如果係數不為0，那就push進去
            ans.push((*it).second,(*it).first);    //push一個Node(係數,次方)
        }
    }
}
void sort(SLL& poly){   //把一樣的整合並排序 ，傳進來一個SLL 代表polynomial
    map<int,int> exp_coe;   //用map來存係數跟次方 >> key 是次方，value 是係數 >> 用map的好處是能自動排序key(由小到大)
    traversal_SLL_and_record_into_map (poly , exp_coe); //traversal SLL and record into map
    poly.clear();   //把poly整個清掉，等等重新放入
    push_Node_from_map_to_SLL(poly , exp_coe);  //push Node from map to SLL
}
SLL operator + (const SLL object1 ,const SLL object2 ){ //operator overloading for + 
    SLL ans ;   // 回傳的SLL
    map<int,int> exp_coe;       //過程中用來操作的map
    traversal_SLL_and_record_into_map (object1 , exp_coe);  //traversal poly1 and record into map
    traversal_SLL_and_record_into_map (object2 , exp_coe);  //traversal poly2 and record into map
    push_Node_from_map_to_SLL(ans , exp_coe);               //push Node from map to SLL
    if(ans.head == NULL ){  //如果ans 是空的，代表運算結果是0，就push(0,0)
        ans.push(0,0);
    }
    return ans ;    //回傳ans
}
SLL operator * (const SLL object1 , const SLL object2){ //operator overloading for * 
    SLL ans ;   //回傳的SLL
    map<int,int> exp_coe ;  //過程中用來操作的map
    Node* temp_2 = object2.head ;   //先用一個temp 指向其中一個poly的開頭
    while(temp_2 != NULL ){ //遍歷這個poly
        Node*temp_1 = object1.head;     //再用另一個temp 指向另一個poly的開頭
        while(temp_1 != NULL ){ //固定其中一個poly，然後去遍歷另一個Poly，把所有遍歷到的結果放進map中
            exp_coe[temp_2->Y+temp_1->Y] +=  temp_2->X * temp_1->X; //乘法，次方相加，指數相乘
            temp_1 = temp_1->next;  //讓temp 前往下一個 ，遍歷整個 poly 
        }
        temp_2 = temp_2->next;  //讓temp 前往下一個 ，遍歷整個 poly 
    }
    push_Node_from_map_to_SLL(ans , exp_coe);   //push Node from map to SLL
    if(ans.head == NULL ){  //如果ans 是空的，代表運算結果是0，就push(0,0)
        ans.push(0,0);
    }
    return ans ;    //回傳ans
}
void SLL::clear(){  //function for clear SLL 
    Node* temp = head ; //先用一個temp指向head 
    while (head != NULL){   //然後讓temp 遍歷整個SLL
        head = head->next;  //先把head往後移
        delete temp ;   //刪掉temp 
        temp = head ;   //再把temp設定為下一個要刪掉的(也就是head)
    }
}
int main(){
    SLL poly1 , poly2;  //宣告兩個SLL ， poly1 和 poly2 
    int count = 1 ; //計算現在是第幾個case
    while(1){   //無限迴圈，直到輸入 P = 0 , Q = 0
        int P , Q; 
        cin >> P ;  //輸入P 
        for(int i = 0 ; i < P ; i++ ){
            int X , Y ;
            cin >> X >> Y ;     //輸入第一個poly的係數and指數
            poly1.push(X,Y);    //把輸入的push到SLL中
        }
        cin >> Q ;
        for(int i = 0 ; i < Q ; i++ ){
            int X , Y ;
            cin >> X >> Y ;     //輸入第二個poly的係數and指數
            poly2.push(X,Y);    //把輸入的push到SLL中
        }
        if( P == Q && P == 0 ){ //無限迴圈，直到輸入 P = 0 , Q = 0
            break;  //跳出無限迴圈
        }
        sort(poly1);    //整理整個polynomial並排序
        sort(poly2);    //整理整個polynomial並排序
        cout << "Case" << count++ << ":" << endl; //輸出這是第幾個case 
        cout << "ADD" << endl;  //輸出ADD
        SLL C = poly1 + poly2;  //計算相加的結果賦值給 C
        C.print();  //把C印出
        cout << "MULTIPLY" << endl; //輸出MULTIPLY
        SLL D = poly1 * poly2 ; //計算相乘的結果賦值給 D
        D.print();  //把D印出
        cout << endl;   //每個testCase結束，空一行
        poly1.clear();  //清空記憶體空間，避免發生錯誤配置
        poly2.clear();  //清空記憶體空間，避免發生錯誤配置
        C.clear();      //清空記憶體空間，避免發生錯誤配置
        D.clear();      //清空記憶體空間，避免發生錯誤配置
    }   
}