#include <iostream>
using namespace std;

void calculate_m(int &m){
    if (m%2==1){m-=1;}
    else {m /=2;}
}

int main() {
    int n,m;
    cin >> n >> m;
    int arr[n];
    for (int i=0; i<n ; i++){
        cin >> arr[i];
    }
    int sum =arr[m-1];
    while (m>1){
        calculate_m(m);
        // cout << m;
        sum += arr[m-1];
        // cout << " " << arr[m] ;
    }
    cout << sum ;
    return 0;
}