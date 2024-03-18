#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int q;
    cin >> s >> q;
    
    for(int i=0;i<q;i++){
        int type;
        cin >> type;
        if (type ==1){
            int a,b;
            cin >> a >> b;
            // cout << a << b;
            if (a !=b){
                //swap a,b
                // cout << "swap";
                char tmp = s[a-1];
                s[a-1] = s[b-1];
                s[b-1] = tmp;
            }
            cout << s << endl;
        
        }
        else{
            char a,b;
            cin >> a >> b;
            string::iterator iter;
            for (iter = s.begin(); iter != s.end();iter++){
                if (*iter == a){
                    *iter = b;
                }
            }
            cout << s << endl;
            //
        }
    }


    return 0;
}