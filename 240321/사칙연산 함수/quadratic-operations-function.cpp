#include <iostream>
using namespace std;
void plu(int a, int c){cout << a+c;}
void mi(int a, int c){cout << a-c;}
void multip(int a, int c){cout << a*c;}
void division(int a, int c){cout << (int) a/c;}
int main() {
    int a,c;
    char o;
    cin >> a >> o >> c;
    if (o=='+'){plu(a,c);}
    else if (o=='-'){mi(a,c);}
    else if (o=='/'){division(a,c);}
    else if (o=='*'){multip(a,c);}
    else {cout << "False";}
    return 0;
}