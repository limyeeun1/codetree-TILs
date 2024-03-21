#include <iostream>
using namespace std;

bool Is_sosu(int n){
    for (int j=2;j<n;j++){
        if(n%j==0){return 0;}
    }
    return 1;
}

bool Is_zz(int n){

    return (n%10 + n/10)%2 == 0;
}


int main() {
    int a,b,idx=0;
    cin >> a >> b;
    for (int i=min(a,b);i<=max(a,b);i++){
        if (Is_sosu(i) && Is_zz(i)){idx++;}
    }
    cout << idx;
    // 여기에 코드를 작성해주세요.
    return 0;
}