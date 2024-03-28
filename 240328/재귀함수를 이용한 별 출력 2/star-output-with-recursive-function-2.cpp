#include <iostream>
using namespace std;

void decresendo(int n){
    if (n==0){return;}
    for (int i=0; i<n ; i++){
        cout << "* ";
    }
    cout << endl;
    decresendo(n-1);
    for (int i=0; i<n ; i++){
        cout << "* ";
    }
    cout << endl;

}

int main() {
    int n;
    cin >> n;
    decresendo(n);
    return 0;
}