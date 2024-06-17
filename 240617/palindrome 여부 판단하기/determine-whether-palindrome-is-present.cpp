#include <iostream>
#include <string>
using namespace std;

void Is_palindrome(string &str, int N){
    int n=0;
    // for (iter = str.begin(); i÷ter !=str.end(); iter ++){
    for (int i=0; i<N/2 ; i++){

        if (str[n] != str[N-n-1]){
            cout << "No";
            return;
        }
        n++;
    }
    cout << "Yes";
    return;

}

int main() {
    // 여기에 코드를 작성해주세요.
    string str;
    cin >> str;
    int n = str.length();
    Is_palindrome(str,n);

    return 0;
}