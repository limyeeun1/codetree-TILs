#include <iostream>
#include <string>
using namespace std;
int main() {
    // 여기에 코드를 작성해주세요.
    string A,B;
    cin >>A >>B;
    int a,b;
    for (int i=0; i<A.length(); i++){
        int asc = (int) A[i];
        if (asc > '9' || asc <'0'){
            string t = A.substr(0,i);
            a = stoi(t);
            // cout << "a" << a;
            break;
        }
        else if(i==A.length()-1){
            a = stoi(A);
        }
    }
    for (int i=0; i<B.length(); i++){
        int asc = (int) B[i];
        if (asc > '9' || asc <'0' ){
            string t = B.substr(0,i);
            b = stoi(t);
            // cout << "b" << b;
            break;
        }
        else if(i==B.length()-1){
            b = stoi(B);
        }
    }
    cout << a+b << endl;

    return 0;
}