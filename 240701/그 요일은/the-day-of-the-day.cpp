#include <iostream>
#include <string>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    
    int m1,d1,m2,d2;
    string days;
    int day;
    cin >>m1 >> d1 >> m2 >> d2;
    if (days == "Mon"){day =1;}
    else if(days =="Tue"){day =2;}
    else if(days =="Wed"){day =3;}
    else if(days =="Thu"){day =4;}
    else if(days =="Fri"){day =5;}
    else if (days == "Sat"){day = 6;}
    else if (days == "Sum"){day =7;}


    int number=1;
    while(1){
        if (m1 ==m2 && d1==d2){
            break;
        }
        number = number +1;
        d1 = d1+1;
        if (d1>month[m1]){
            m1 = m1+1;
            d1 =1;
        }
    }
    if (number%7 >= day){
        cout << number/7+1;
    }
    else {
        cout << number/7;
    }
    return 0;
}