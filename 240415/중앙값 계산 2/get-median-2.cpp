#include <iostream>
#include <algorithm>
using namespace std;
void middle(int arr[],int n){
    sort(arr, arr+n+1);
    cout << arr[n/2] << " ";
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
        if (i%2==0){
            middle(arr,i);
        }
    }

    return 0;
}