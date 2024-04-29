#include <iostream>
#include <string>
using namespace std;

#define MAXN 100

class Data{
    public:
        string Date;
        string Week;
        string Weather;
        Data(string d, string w, string wt){
            this->Date = d;
            this->Week = w;
            this->Weather = wt;
        }
        Data(){}
};
int main() {
    int n;
    cin >> n;
    Data storage[MAXN];
    
    string key;
    int k=-1;

    for(int i=0; i<n ;i++){
        string d,w,wt;
        cin >> d >> w >> wt;
        storage[i] = Data(d,w,wt);
        if (wt=="Rain"){
            if (k==-1){
                key = d;
                k=i;}
            else if(key > d){
                key = d;
                k=i;}
        }
    }
    
    cout << storage[k].Date << " " << storage[k].Week << " " << storage[k].Weather;

    return 0;
}