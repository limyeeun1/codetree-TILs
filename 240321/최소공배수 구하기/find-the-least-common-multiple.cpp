#include <iostream>
using namespace std;
void get(int n,int m){
    int n2=n,m2=m;
    while(1){
        if (n2==m2){
            cout << n2 ;
            break;
        }
        else if (n2 < m2){n2 +=n;}
        else if (n2 > m2){m2 +=m;}
        if (max(n2,m2) > n*m){
            cout << "ERROR";
            break;
        }
    }
}
int main() {
    int n,m;
    cin >> n >> m;
    get(n,m);

    return 0;
}