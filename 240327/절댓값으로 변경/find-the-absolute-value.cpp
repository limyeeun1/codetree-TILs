#include <iostream>
using namespace std;

void make_absolute(int ar[],int n){
    for (int i=0; i<n; i++){
        if(ar[i]<0){
            ar[i] *= -1;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i] ;
    }

    make_absolute(arr,n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}