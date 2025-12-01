#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct Student{
    char name[20];
    int score;
};

Student* findTopStudent(Student* list , int N ){
    if(N == 0 ) return nullptr;
    Student* mmax;
    int smax = 0 ; 
    for(int i = 0 ; i < N ; i++ ){
        if(list[i].score > smax){
            mmax = &list[i];
            smax = list[i].score;
        }
    }
    return mmax ;
}

int main(){
    int N ;
    cin >> N ;

    Student* list = new Student[N];
    for(int i = 0 ; i < N ; i++ ){
        string n ;
        int s;
        cin >> n >> s ;
        for(int j = 0 ; j < n.size() ; j++ ){
            list[i].name[j] = n[j];
        }
        list[i].score = s ;
    }
    Student* mmax = findTopStudent(list, N);
    cout << "Top student: ";
    for(int i = 0 ; i < strlen(mmax->name) ; i++ ){
        cout << mmax->name[i] ;
    }
    cout << endl;
}