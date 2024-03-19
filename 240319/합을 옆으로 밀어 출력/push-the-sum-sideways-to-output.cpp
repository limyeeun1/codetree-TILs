#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count=0;
    for (int i=0;i<n;i++){
        string str;
        cin >> str;
        count += stoi(str);
    }
    string output = to_string(count);
    int k = output.length();
    if (k!=1){
        cout << output.substr(1,k-1) << output[0];
    }
    else if (k==1){
        cout << output;
    }
    // cout << count;
    return 0;
}