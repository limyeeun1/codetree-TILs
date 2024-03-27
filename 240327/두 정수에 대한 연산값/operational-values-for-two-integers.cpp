#include <iostream>
using namespace std;

void multiple_min(int &a){
    a = a*2;
}
void plus_max(int &a){a = a+25;}

int main() {
    int a,b;
    cin >> a >> b;
    // int *minimum = &min(a,b);
    // int *maximum = &max(a,b);
    if (a<b){
        multiple_min(a);
        plus_max(b);
    }
    else{
        multiple_min(b);
        plus_max(a);
    }
    cout << a << " " << b;
    return 0;   
}