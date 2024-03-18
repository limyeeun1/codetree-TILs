#include <iostream>
#include <string>
using namespace std;
int main() {
    string inputstr;
    string purpose;
    cin >> inputstr >> purpose;

    int l = purpose.length();
    for (int i=0; i< inputstr.length()-l; i++){
        if (inputstr.substr(i,l) == purpose){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}