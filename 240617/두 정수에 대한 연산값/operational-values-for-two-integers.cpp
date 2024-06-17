#include <iostream>
using namespace std;

void Do(int &a,int &b){
    if (a<b){
        b = b+25;
        a = a*2;
    }
    else{
        a = a+25;
        b = b*2;
    }
    return;
}


int main() {
    int a,b;
    cin >> a >> b;
    Do(a,b);
    cout << a << " " << b;
    return 0;
}