#include <iostream>
#include <string>
using namespace std;
int main() {
    int n=10;
    string arr[n];
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }
    char alp;
    cin >> alp;

    string::iterator iter;
    for (int i=0; i<n; i++){
        iter = arr[i].end() -1;
        if (*iter == alp){
            cout << arr[i] << endl;
        }
    }

    return 0;
}