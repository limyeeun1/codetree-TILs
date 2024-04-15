#include <iostream>
#include <algorithm>
using namespace std;

void get_input(int arr[],int n){
    for (int i =0; i<n; i++){
        cin >> arr[i];
    }
}

void compare(int A[],int B[],int n){
    for (int i =0; i<n; i++){
        if (A[i]!=B[i]){
            cout << "No";
            return;}
    }
    cout << "Yes";
    return;
}


int main() {
    int n;
    cin >> n;
    int A[n],B[n];
    get_input(A,n);
    get_input(B,n);

    sort(A,A+n);
    sort(B,B+n);
    compare(A,B,n);
    return 0;
}