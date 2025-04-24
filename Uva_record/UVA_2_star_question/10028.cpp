// #include<bits/stdc++.h>
// using namespace std;

// void print( int day , int ndp){
//     string d = "";
//     while(d.size() < 10){
//         d.push_back('0'+ day % 10);
//         day /= 10 ;    
//         if(d.size() == 2 || d.size() == 5){
//             d.push_back('-');
//         }
//     }
//     for(int i = d.size()-1 ; i >= 0 ; --i ){
//         cout << d[i];
//     }
//     cout << " ";
//     if(ndp == 0 ){
//         cout << "No merit or demerit points.";
//     }
//     else if (ndp > 0 ){
//         cout << ndp << " demerit point(s).";
//     }
//     else{
//         cout << abs(ndp) << " merit point(s)."; 
//     }
//     cout << endl;
// }

// int main(){
//     int t ;
//     cin >> t ;
//     while(t--){
//         int nd ;    // start day 
//         cin >> nd ;
//         cin.ignore();
//         int d ; // day 
//         int ndp = 0 ; // now demerit point 
//         int dp ;
//         print(nd , ndp);
//         string input ;
//         while(getline(cin,input) && input.size() > 0 ){
//             d = stoi(input.substr(0,8));
//             dp = stoi(input.substr(9,input.size()-9));
//             nd += 10000;
//             while(nd <= d && ndp > 0 ){
//                 if( ndp / 2 > ndp -2 ){
//                     ndp -= 2 ;
//                 }
//                 else{
//                     ndp /= 2 ;
//                 }
//                 print(nd , ndp);
//                 nd += 10000;
//             }
//             nd += 10000;
//             while(nd <= d && ndp <= 0 ){
//                 ndp--;
//                 print(nd,ndp);
//                 nd += 20000;
//             }
//             nd = d ;
//             if(ndp < 0 ){
//                 if(ndp*2 <= dp){
//                     ndp = ndp*2 + dp ;
//                 }
//                 else{
//                     if(dp & 1)
//                         ndp += (dp/2+1);
//                     else ndp += (dp/2);
//                 }
//             }
//             else{
//                 ndp += dp;
//             }
//             print(nd , ndp);
//         }
//         while(ndp > -5 ){
//             nd += 10000;
//             while(ndp > 0 ){
//                 if( ndp / 2 > ndp -2 ){
//                     ndp -= 2 ;
//                 }
//                 else{
//                     ndp /= 2 ;
//                 }
//                 print(nd , ndp);
//                 nd += 10000;
//             }   
//             nd += 10000;
//             while(ndp <= 0 && ndp > -5 ){
//                 ndp--;
//                 print(nd,ndp);
//                 nd += 20000;
//             }
//         }
//         if(t) cout << endl;
//     }
// }
// /*
// 1
// 19820508
// 19830606 2
// 19830607 2
// 19891212 15 

// */

// 上面一直過不了，懶得寫了QQ

//Steven Kester Yuwono - UVa 10028

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isOlder (string y1, string m1, string d1, string y2, string m2, string d2) {
	if (y1 < y2) {
		return true;
	}
	else if (y1 == y2) {
		if (m1 < m2) {
			return true;
		}
		else if (m1 == m2) {
			if (d1 <= d2) {
				return true;
			}
		}
	}
	return false;
}

void process(string currYear, string currMonth, string currDate, string newYear, string newMonth,string newDate,int &merit, int& demerit,bool limit) {
	int tempYear = atoi(currYear.c_str());
	char buffer[50];
	sprintf(buffer,"%d",tempYear+1);
	string oneYearAdvance = string(buffer);
	

	if (demerit>0) {
		while (isOlder(oneYearAdvance,currMonth,currDate,newYear,newMonth,newDate)) {
			//cout << merit << " " << demerit << endl;
			currYear = oneYearAdvance;
			
			demerit = min((demerit/2),(demerit-2));
			if(demerit < 0 ){
				demerit = 0;
			}

			if (demerit > 0) {
				printf("%s-%s-%s %d demerit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),demerit);
			}
			else if (merit > 0) {
				printf("%s-%s-%s %d merit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),merit);
			}
			else {
				printf("%s-%s-%s No merit or demerit points.\n",currYear.c_str(),currMonth.c_str(),currDate.c_str());
				break;
			}

			tempYear = atoi(currYear.c_str());
			sprintf(buffer,"%d",tempYear+1);
			oneYearAdvance = string(buffer);
		}
	}

	tempYear = atoi(currYear.c_str());
	sprintf(buffer,"%d",tempYear+2);
	string twoYearAdvance = string(buffer);

	if(demerit == 0){
		while (isOlder(twoYearAdvance,currMonth,currDate,newYear,newMonth,newDate)) {
			//cout << merit << " " << demerit << endl;
			currYear = twoYearAdvance;
			if(merit == 5){
				tempYear = atoi(currYear.c_str());
				sprintf(buffer,"%d",tempYear+2);
				twoYearAdvance = string(buffer);
				continue;
			}
			merit++;
			
			if (demerit > 0) {
				printf("%s-%s-%s %d demerit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),demerit);
			}
			else if (merit > 0) {
				printf("%s-%s-%s %d merit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),merit);
			}
			else {
				printf("%s-%s-%s No merit or demerit points.\n",currYear.c_str(),currMonth.c_str(),currDate.c_str());
			}
			if(limit){
				if(merit == 5){
					break;
				}
			}

			tempYear = atoi(currYear.c_str());
			sprintf(buffer,"%d",tempYear+2);
			twoYearAdvance = string(buffer);
		}
	}
}

int main() {
	int tc;
	string line;
	getline(cin,line);
	tc = atoi(line.c_str());
	getline(cin,line); // read the blank endline
	for (int d=0;d<tc;d++){
		if(d>0){
			cout << endl;
		}

		int merit = 0;
		int demerit = 0;
		string newYear, newMonth, newDate;
		getline(cin,line); //the first date;
		string currYear = line.substr(0,4);
		string currMonth = line.substr(4,2);
		string currDate = line.substr(6,2);
		printf("%s-%s-%s No merit or demerit points.\n",currYear.c_str(),currMonth.c_str(),currDate.c_str());
		while ((getline(cin,line))&&(line.length()>0)) {
			string newYear = line.substr(0,4);
			string newMonth = line.substr(4,2);
			string newDate = line.substr(6,2);
			int demeritPt = atoi(line.substr(9).c_str());
			
			process(currYear,currMonth,currDate,newYear,newMonth,newDate,merit,demerit,false);

			if(merit > 0){
				if(merit*2 > demeritPt){
					merit =(merit*2 - demeritPt) /2;
				}
				else {
					demeritPt -= merit*2;
					if(demeritPt > 0){
						demerit += demeritPt;
					}
					merit = 0;
				}
			}
			else {
				demerit += demeritPt;
			}
			currYear = newYear;
			currMonth = newMonth;
			currDate = newDate;
			if (demerit > 0) {
				printf("%s-%s-%s %d demerit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),demerit);
			}
			else if (merit > 0) {
				printf("%s-%s-%s %d merit point(s).\n",currYear.c_str(),currMonth.c_str(),currDate.c_str(),merit);
			}
			else {
				printf("%s-%s-%s No merit or demerit points.\n",currYear.c_str(),currMonth.c_str(),currDate.c_str());
			}
		}
		while(merit<5){
			process(currYear,currMonth,currDate,"9999","99","99",merit,demerit,true);
		}
	}
	return 0;
}
// 參考資料 : https://github.com/yulonglong/UVa-Solutions/blob/master/10028.cpp