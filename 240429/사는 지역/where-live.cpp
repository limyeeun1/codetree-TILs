#include <iostream>
#include <string>
using namespace std;
class Student {
    public:
        string name;
        string add;
        string city;

        Student(string n="lim", string a="000-000", string l="none"){
            this->name = n;
            this->add = a;
            this->city = l;
        }
};

int main() {
    int n;
    cin >> n;

    Student book[n];
    string last = "a";
    int k;
    for (int i=0; i<n; i++){
        cin >> book[i].name >> book[i].add >> book[i].city;
        if (book[i].name> last){
            last = book[i].name;
            k =i;
        }
    }
    cout << "name " << book[k].name << endl;
    cout << "addr " << book[k].add << endl;
    cout << "city " << book[k].city ;

    return 0;
}