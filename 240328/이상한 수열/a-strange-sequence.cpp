#include <iostream>
using namespace std;

int get(int n){
    if (n==1){return 1;}
    if (n==2){return 2;}
    return get(n/3) + get(n-1);
}

int main() {
    int n;
    cin >> n;
    cout << get(n);

    return 0;
}