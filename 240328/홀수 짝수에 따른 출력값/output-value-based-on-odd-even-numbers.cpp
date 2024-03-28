#include <iostream>
using namespace std;
int gogo(int n){
    if (n%2==0 && n==2){return 2;}
    else if(n%2==1 && n==1){return 1;}
    return n+gogo(n-2);

}


int main() {
    int n;
    cin >> n;
    cout << gogo(n);
    return 0;
}