/*
    Author : 李承諺(B123040032)
    Date : Sept. 23, 2024 
    PurPose : 給予一串數字，利用Binary Search Tree 找出所有出現次數為奇數之數字
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{ //class Node
    friend class Tree;  //set friend class >> tree can use Node's private 
    public:
        Node(int = 0 , Node* = NULL , Node* = NULL);    //constructor 
    private:    
        int value;  //用來存值
        Node* left ;    //存左子節點的位置
        Node* right ;   //存右子節點的位置
};
Node::Node(int v , Node* l , Node* r ) : value(v), left(l), right(r){}  //constructor 
class Tree{ //class Tree
    public:
        Tree( Node* = NULL );   //constructor 
        void insertNode(int);   // function for insert Node into tree
        Node* searchNode(int);  // function for search Node from the tree
        Node* searchParent(Node*);  // function for search Node's parent from the tree
        void deleteNode(int);   // function for delete Node from the tree
        void inorder_iterative(Node* now);  //function for print 
    
        Node* root ;    //Node for 根節點
};
Tree::Tree(Node* r): root(r){}  //constructor

void Tree::insertNode(int number){  // function for insert Node into tree
    Node* temp = new Node(number);  //創建一個新的指標，並存著要push進去的值
    if(root == NULL){   //如果根節點是空
        root = temp ;   //那就直接放入根節點
    }
    else{   //如果根節點不為空
        Node*now = root ;   //那就從根節點開始找哪裡可以放
        while(now != NULL){ //直到跑到NULL
            if(now->value > temp->value ){  //如果現在這個點的值 比 要插入的值還大 那就向左跑
                if(now->left == NULL){  //如果左邊是空的，就直接插入了
                    now->left = temp ;
                    break;
                }
                now = now->left;    //如果左邊不為空，那就往左邊跑，並繼續比對
            }
            else{   //如果現在這個點的值 比 要插入的值還小 那就向右跑
                if(now->right == NULL){ //如果右邊是空的，就直接插入了
                    now->right = temp ;
                    break;
                }
                now = now->right ;  //如果右邊不為空，那就往右邊跑，並繼續比對
            }
        }
    }
}
Node* Tree::searchNode(int value ){ // function for search Node from the tree
    if(root == NULL){   //如果根節點沒有東西，那就不用找了，樹是空的
        return NULL;
    }
    Node* now = root;   //如果有，就從根節點開始找
    while(now != NULL){ //當然，如果最後結果是NULL就代表沒找到
        if(now->value > value ){    //如果現在這個點的值 比 要找的值還大 那就向左跑
            now = now->left;
        }
        else if ( now->value < value ){ //如果現在這個點的值 比 要找的值還小 那就向右跑
            now = now->right;
        }
        else{   //如果現在這個點的值 跟 要找的值 一樣 那就直接return 
            return now;
        }
    }
    return NULL;    //如果最後是NULL ，那就回傳NULL表示沒找到
}
Node* Tree::searchParent(Node* target){     // function for search Node's parent from the tree
    if(root == NULL || target == root ){    //如果沒有根節點，或要找的那個點就是根節點(根節點沒有父親)，就return NULL
        return NULL;
    }
    else {  // 如果有
        Node* parent = root;    //從root開始找
        while(parent->right != target && parent->left != target ){  //只要這個父節點的其中一個子節點是target，就return 
            if(target->value > parent->value ){ //如果現在這個父節點的值 比 要找的值還小 那就向右跑
                parent = parent->right;
            }
            else{   //如果現在這個父節點的值 比 要找的值還大 那就向左跑
                parent = parent->left;
            }
        }
        return parent;  //回傳他的父節點，如果根節點不為空，那必定有父節點
    }
}
void Tree::deleteNode(int value){   // function for delete Node from the tree
    if(searchNode(value) == NULL || root == NULL){  //如果找不到這個點，就直接結束
        return;
    }   
    Node* now = searchNode(value);  //把要刪的這個點找出來
    Node* parent = searchParent(now);   //並找到他的父節點
    if(now->left == NULL && now->right == NULL){    //如果要刪的點沒有子節點，那就可以直接刪
        if(now == root ){   //當然，這個點有可能是根節點
            root = NULL;    //根節點設為NULL 
        }
        else if(parent->left == now ){  //如果父節點的左子節點是要刪的
            parent->left = NULL;    //設為NULL
        }
        else{   //如果父節點的右子節點是要刪的
            parent->right = NULL;    //設為NULL
        }
        delete now ;    //刪掉此節點
        return ;    //並結束
    }   
    else if ( now->left == NULL && parent){ //如果有父節點，並且右子節點不為空，左子節點為空
        if(parent->left == now ){   //如果現在要刪的是左子節點
            parent->left = now->right;  //那就讓要刪的節點的右子節點代替它的位置
        }
        else{   //如果現在要刪的是右子節點
            parent->right = now->right; //那就讓要刪的節點的右子節點代替它的位置
        }
        delete now ;    //刪掉此節點
        return ;    //並結束
    }
    else if (now->right == NULL && parent){ //如果有父節點，並且左子節點不為空，右子節點為空
        if(parent->left == now ){   //如果現在要刪的是左子節點
            parent->left = now->left;   //那就讓要刪的節點的右子節點代替它的位置
        }   
        else{   //如果現在要刪的是右子節點
            parent->right = now->left;  //那就讓要刪的節點的右子節點代替它的位置
        }
        delete now;     //刪掉此節點
        return ;    //並結束
    }
    else{   //最後，如果此節點沒有父節點，且左、右其中一個存在，或左、右子節點都存在
        Node* sucessor ;    //先要找到可以繼承他的點
        if(now->left != NULL ){ //如果左邊不為空
            sucessor = now->left ;  //那就先往左邊走
            bool state = false; //state是用來看左節點的右子節點是否為空
            while(sucessor->right != NULL){ //如果不為空
                sucessor = sucessor->right ;    //那就一直往右邊下面走
                state = true;   //並把state設為true，表示原本的左節點的右子節點不是空的
            }
            Node*sucessor_parent = searchParent(sucessor);  //找到繼承的點後，看看找不找的到父節點
            if(state){  //如果剛剛確實是有往右走
                if(sucessor->left != NULL ){    //且繼承點的左邊不是空的
                    sucessor_parent->right = sucessor->left;    //要先把繼承點的左邊移到繼承點的位置
                }
                else{   //如果繼承點的左邊是空的，那就把繼承點設為空的
                    sucessor_parent->right = NULL;
                }
            }
            else{   //如果剛剛沒有往右走
                if(sucessor->left == NULL){ //如果繼承點的左邊是空的
                    sucessor_parent->left = NULL;   //那就把繼承點的位置設成空的
                }
                else{   //如果繼承點的左子節點不為空
                    sucessor_parent->left = sucessor->left ;    //那就把繼承者的位置改成繼承者的左節點
                }
            }
            now->value = sucessor->value ;  //並且把現在的位置改成繼承點的值(等同於刪掉現在的位置的值)
            delete sucessor;    //刪掉繼承點
            return ;
        }
        else{   //如果左邊是空的，右邊不為空
            sucessor = now->right ; //那就往右邊走
            bool state = false ;    //檢查有沒有往左走
            while(sucessor->left != NULL){  //如果往右子節點的左子節點不為空
                sucessor = sucessor->left ;    //那就往左邊走
                state = true;   //並把state設為true
            }
            Node*sucessor_parent = searchParent(sucessor);  //先看有沒有父節點
            if(state){  //如果剛剛有往左走
                if(sucessor->right != NULL){    //如果繼承者的右邊不為空
                    sucessor_parent->left = sucessor->right;    //那就把父節點的左子節點設為繼承者的右節點
                }
                else{   //如果繼承者的右邊是空的
                    sucessor_parent->left = NULL;   //那就設為null
                }
            }
            else{   //如果剛剛沒有往左走
                if(sucessor->right == NULL ){   //如果繼承者的右子節點是空的
                    sucessor_parent->right = NULL;  //那就把父節點的右子節點設為null 
                }
                else{   //如果繼承點的右子節點不為空
                    sucessor_parent->right = sucessor->right ;
                }
            }
            now->value = sucessor->value ;  //把值覆蓋
            delete sucessor;    //刪掉繼承點
            return ;    //並結束
        }
    }
}
void Tree::inorder_iterative(Node* now ){   //function for print 
    stack<Node*> parentnode_record; //用stack去紀錄現在跑了那些父節點 
    vector<int> output_Node;    //把Node放這裡
    vector<int> output_left;    //把Node的左節點放這
    vector<int> output_right ;  //把Node的左節點放這
    while(now || parentnode_record.size() != 0 ){   //只要now不為空，或stack不為空
        if(now != NULL){    //當Now不是空的
            parentnode_record.push(now);    //那就push 點進去
            now = now->left;    //然後往左子節點走
        }
        else{   //只要走到盡頭了
            now = parentnode_record.top();  //那就讓點是stack的最上面(一開始是最左下角)
            parentnode_record.pop();        //並把stack pop出來
            output_Node.push_back(now->value);  //然後push進去
            if(now->left == NULL ){ //如果他的左子節點是空的，就push 0
                output_left.push_back(0);   
            }
            else{   //不為空，就push他的值
                output_left.push_back(now->left->value);
            }
            if(now->right == NULL ){    //如果他的右子節點是空的，就push 0
                output_right.push_back(0);
            }
            else{   //不為空，就push他的值
                output_right.push_back(now->right->value);
            }
            now = now->right;   //然後走向右邊
        }
    }
    //以下是分別輸出每個vector
    cout << "node : " ;  
    for(int i = 0 ; i < (int)output_Node.size(); i++ ){
        cout << output_Node[i] << " ";
    }
    cout << endl;
    cout << "left : " ;
    for(int i = 0 ; i < (int)output_Node.size(); i++ ){
        cout << output_left[i] << " ";
    }
    cout << endl;
    cout << "right: " ;
    for(int i = 0 ; i < (int)output_Node.size(); i++ ){
        cout << output_right[i] << " ";
    }
    cout << endl;
}
int main(){
    int count = 0 ; //計算現在是第幾個輸入
    while(1){   //用while無限迴圈，直到end of file，都不會結束
        Tree mytree;    //宣告tree
        int number ;    //宣告number
        while(cin >> number ){  //然後一直輸入number
            if(number == -1 && count > 0 ){ //如果number是-1 且不是第一組測資
                cout << endl;   //就先輸入換行，保證每組測資之間隔一行
                break;  //並退出
            }
            else if (number == -1 ){    //如果number是-1，又是第一組測資，就直接退出
                break;
            }
            if(mytree.searchNode(number) != NULL ){ //如果要插入的點在樹裡面找的到
                mytree.deleteNode(number);  //那就刪掉此節點
            }
            else{   //如果要插入的點在樹裡面找不到
                mytree.insertNode(number);  //那就插入此點
            }
        }
        mytree.inorder_iterative(mytree.root);  //最後印出
        count++;    //並count+1
    }
}