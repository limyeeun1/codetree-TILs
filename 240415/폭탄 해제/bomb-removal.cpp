#include <iostream>
#include <string>
using namespace std;
class OH{
    public:
        string code;
        char color;
        int sec;
        OH(string c, char co, int sec){
            this->code = c ;
            this->color = co;
            this->sec = sec;
        }
};

        
int main() {
    string c;
    char co;
    int s;
    cin >> c>>co>> s;
    OH cl=OH(c,co,s);
    cout << "code : " << cl.code << endl;
    cout << "color : " <<cl.color << endl;
    cout << "second : " <<cl.sec << endl;
    return 0;
}