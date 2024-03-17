#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;

    // if (str.length()<=n){
    //     cout << str;
    // }
    // else{
    string::iterator iter;
    int count=0;
    for(iter = str.end()-1;count<n;iter--){
        cout << *iter;
        count ++;
        if (count==str.length()){break;}
    }
    // }

    return 0;
}