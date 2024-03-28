#include <iostream>
using namespace std;

void cresendo(int n){
    if (n==0){return;}
    cout << n << " ";
    cresendo(n-1);
    cout << n << " ";
}


int main() {
    int n;
    cin >> n;
    cresendo(n);

    return 0;
}