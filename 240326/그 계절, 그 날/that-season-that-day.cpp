#include <iostream>
using namespace std;
bool check_yoon(int year){
    if (year%400==0){return true;}
    else if (year%100==0){return false; }
    else if(year%4==0){return true;}
    else{return false;}
}

int last_day(int month){
    if (month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12){
        return 31;
    }
    else {return 30;}
}

void seasons(int month){
    if (month>=3 && month<=5){cout <<"Spring";}
    else if(month>=6 && month <=8){cout << "Summer";}
    else if(month>=9 && month <=11){cout << "Fall";}
    else{cout << "Winter";}
}

int main() {
    int Y,M,D;
    cin>> Y >> M >> D;

    int ld = last_day(M);
    if (M==2 && check_yoon(Y)=ture){ld =29;}
    if (D>ld){cout <<"-1";return 0;}

    seasons(M);

    return 0;
}