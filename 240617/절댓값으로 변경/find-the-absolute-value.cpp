#include <iostream>
using namespace std;

void Do(int arr[],int n){
    for (int i=0; i<n; i++){
        if (arr[i] <0){
            arr[i] = arr[i]*-1;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    Do(arr,n);
    for (int i=0;i<n;i++){
        cout << arr[i] <<  " ";
    } 
    return 0;
}