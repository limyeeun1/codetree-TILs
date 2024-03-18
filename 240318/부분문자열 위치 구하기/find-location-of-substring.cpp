#include <iostream>
#include <string>
using namespace std;
int main() {
    string inputstr;
    string purpose;
    cin >> inputstr >> purpose;

    int l = purpose.length();
    if (l == inputstr.length()){
        if (inputstr==purpose){cout << 0;return 0;}
    }
    else{
        for (int i=0; i<= inputstr.length()-l; i++){
            if (inputstr.substr(i,l) == purpose){
                cout << i;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}