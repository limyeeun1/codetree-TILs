#include <iostream>
using namespace std;
int arr[100];

void fun(int a, int b){

    int sum=arr[a-1];
    for (int i=a;i<b;i++){
        sum+=arr[i];
    }
    cout << sum << endl;
}

int main() {
    int n,m; 
    cin >> n >> m;
    for (int i=0; i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >>a>>b;
        fun(a,b);
    }
    return 0;
}