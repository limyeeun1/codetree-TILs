#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    public:
        int height,weight,number;
        Student(int h=0, int w=0, int n=0){
            this ->height = h;
            this -> weight = w;
            this -> number = n;
        };
};

bool cmd(Student a, Student b){
    if (a.height == b.height){
        return a.weight > b.weight;
    }
    return a.height < b.height;

}
int main() {

    int N;
    cin >> N;
    Student array[N];

    for (int i=0; i<N ; i++){
        cin >> array[i].height >> array[i].weight;
        array[i].number = i+1;
    }
    sort (array, array+N, cmd);

    for (int i=0; i<N; i++){
        cout << array[i].height << " " << array[i].weight << " " << array[i].number << endl;
    }


    return 0;
}