#include <iostream>
using namespace std;
int plu(int a, int c){return a+c;}
int mi(int a, int c){return a-c;}
int multip(int a, int c){return a*c;}
int division(int a, int c){return (int) a/c;}
int main() {
    int a,c,ans;
    char o;
    
    cin >> a >> o >> c;
    if (o=='+'){ans=plu(a,c);}
    else if (o=='-'){ans=mi(a,c);}
    else if (o=='/'){ans=division(a,c);}
    else if (o=='*'){ans=multip(a,c);}
    else {cout << "False";return 0;}
    printf("%d %c %d = %d",a,o,c,ans);
    return 0;
}