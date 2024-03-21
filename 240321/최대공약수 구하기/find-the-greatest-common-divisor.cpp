#include <iostream>
using namespace std;
void get(int n, int m){
    
    int ans=1;
    for (int i=1; i<=min(n,m);i++){
        if(n%i==0 && m%i==0){
            ans=i;
        }
    }
    cout << ans;

}
int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin >> n >> m;

    get(n,m);

    return 0;
}