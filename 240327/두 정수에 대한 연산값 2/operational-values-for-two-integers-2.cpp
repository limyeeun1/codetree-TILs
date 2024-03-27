#include <iostream>
using namespace std;
void make(int &a,int &b){
    a +=10;
    b *=2;
}

int main() {
    int a,b;
    cin >> a >> b;
    if (a<b){
        make(a,b);
        cout << a << " " << b;
        return 0;}
    else {
        make(b,a);
        cout << a << " " << b;
        return 0;}


}