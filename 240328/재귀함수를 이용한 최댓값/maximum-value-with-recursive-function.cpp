#include <iostream>
using namespace std;

int find_max(int n, int m){
    int v;
    cin >> v;
    if (n==1){return v;}
    return max(find_max(n-1,v),m);

}


int main() {
    int n;
    cin >> n;
    int v;
    cin >> v;
    cout << find_max(n-1,v);


    return 0;
}