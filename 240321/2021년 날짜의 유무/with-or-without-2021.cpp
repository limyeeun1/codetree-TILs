#include <iostream>
using namespace std;

bool legtgo(int M,int D){
    if (M==2){return (1<=D && D<=28);}
    else if (M==4 || M==6 || M==9 || M==11){return (1<=D && D<=30);}
    else if(M==1 || M==3 || M==5|| M==7 || M==8 || M==10 || M==12){return (1<=D && D<=31);}
    else {return false;}
}
int main() {
    int M,D;
    cin >>M >> D;
    bool ans;
    ans = legtgo(M,D);
    if (ans){cout << "Yes";}
    else {cout << "No";}
    return 0;
}