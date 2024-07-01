#include <iostream>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    
    int m1,d1,m2,d2;

    cin >>m1 >> d1 >> m2 >> d2;

    int number=0;
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
    cout << number/7+1;
    return 0;
}