#include <iostream>
#include <string>
using namespace std;

int check_(string &str){
    string::iterator iter;
    for(iter=str.begin();iter!=str.end()-2;iter++){
        if (*iter!=*(iter+1)){cout << "Yes";return 0;}
    }
    cout << "No";
    return 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;

    check_(str);
    return 0;
}