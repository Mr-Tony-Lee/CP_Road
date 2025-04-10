#include<iostream>
#include<utility>
#include<vector>
using namespace std;
using ll = long long ;
vector<pair<string,int>> Haab;
vector<string> Tzolkin ; 
void EnterHaab();
void EnterTzolkin();

int main(){
    EnterHaab();
    EnterTzolkin();
    int times ;
    cin >> times;
    cout << times << endl;
    while(times--){
        string NTD , M ;
        int Y;
        cin >> NTD >> M >> Y;
        NTD.erase(NTD.begin()+NTD.size()-1);
        int D = stoi(NTD);
        ll total_day = (Y)*365 + D ;
        int sum = 0  ;
        for(int i = 0 ; i < 20 ; i++ ){
            if(Haab[i].first == M ){
                break;
            }
            else{
                sum += Haab[i].second;
            }
        }
        total_day += sum ;
        int total_M = total_day / 20 ;
        int Tzolkin_M = total_day % 20 ;
        int Tzolkin_N = (total_day) % 13 ;
        int Tzolkin_Y = total_M / 13;
        cout << Tzolkin_N+1 << " " << Tzolkin[Tzolkin_M] << " " << Tzolkin_Y << endl;
    }
}
void EnterHaab(){
    Haab.push_back(make_pair("pop",20));
    Haab.push_back(make_pair("no",20));
    Haab.push_back(make_pair("zip",20));
    Haab.push_back(make_pair("zotz",20));
    Haab.push_back(make_pair("tzec",20));
    Haab.push_back(make_pair("xul",20));
    Haab.push_back(make_pair("yoxkin",20));
    Haab.push_back(make_pair("mol",20));
    Haab.push_back(make_pair("chen",20));
    Haab.push_back(make_pair("yax",20));
    Haab.push_back(make_pair("zac",20));
    Haab.push_back(make_pair("ceh",20));
    Haab.push_back(make_pair("mac",20));
    Haab.push_back(make_pair("kankin",20));
    Haab.push_back(make_pair("muan",20));
    Haab.push_back(make_pair("pax",20));
    Haab.push_back(make_pair("koyab",20));
    Haab.push_back(make_pair("cumhu",20));
    Haab.push_back(make_pair("uayet",5));
}
void EnterTzolkin(){
    Tzolkin.push_back("imix");
    Tzolkin.push_back("ik");
    Tzolkin.push_back("akbal");
    Tzolkin.push_back("kan");
    Tzolkin.push_back("chicchan");
    Tzolkin.push_back("cimi");
    Tzolkin.push_back("manik");
    Tzolkin.push_back("lamat");
    Tzolkin.push_back("muluk");
    Tzolkin.push_back("ok");
    Tzolkin.push_back("chuen");
    Tzolkin.push_back("eb");
    Tzolkin.push_back("ben");
    Tzolkin.push_back("ix");
    Tzolkin.push_back("mem");
    Tzolkin.push_back("cib");
    Tzolkin.push_back("caban");
    Tzolkin.push_back("eznab");
    Tzolkin.push_back("canac");
    Tzolkin.push_back("ahau");
}