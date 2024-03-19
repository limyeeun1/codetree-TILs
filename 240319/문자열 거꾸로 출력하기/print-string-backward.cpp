#include <iostream>
#include <string>
using namespace std;
int main() {
    while(1){
        string str;
        cin >> str;
        if (str == "END"){break;}
        string::iterator iter;
        for (iter=str.end()-1;iter!=str.begin()-1;iter--){
            cout << *iter;
        }
        cout << endl;
    }
    // 여기에 코드를 작성해주세요.
    return 0;
}