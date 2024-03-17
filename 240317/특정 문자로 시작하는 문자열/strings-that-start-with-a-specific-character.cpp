#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }

    char alp;
    cin >> alp;

    int count=0;
    float length=0;
    string::iterator add;
    for (int i=0;i<n;i++){
        add = arr[i].begin();
        if (*add == alp){
            //cout << *add << endl;
            length = (length * count + arr[i].length())/(count+1);
            count ++;
            
        }
    }
    // cout << count << " " << length ;
    printf("%d %.2f",count,length);

    return 0;
}