#include <iostream>
#include <string>
using namespace std;
int main() {
    string A,B;
    cin >> A >> B;
    int l = B.length();
    int i=0;
    for(i=0;i<A.length();i){
        // cout << A << ","<<"i" << i<< A.substr(i,l) << "compare" << B << endl;
        if (A.substr(i,l) == B){
            A = A.substr(0,i) + A.substr(i+l,A.length()-i-l);
            // cout << A << "and" << i << endl;
            i = i-1;
        }
        else {i=i+1;}
        // cout << i;
    }
    cout << A ;

    return 0;
}