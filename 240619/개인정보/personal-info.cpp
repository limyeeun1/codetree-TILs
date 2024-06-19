#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Student{
    public:
        string name;
        int hight;
        float weight;

        Student(string n="none",int h=0, float w=0.0){
            this -> name =n;
            this -> hight = h;
            this -> weight = w;
        };
};

bool cmd_name(Student a, Student b){
    return a.name < b.name;
};

bool cmd_height(Student a, Student b){
    return a.hight > b.hight;
};

void print_result(Student arr[]){
    for(int i=0; i<5; i++){
        cout << arr[i].name;
        printf(" %d %0.1f\n", arr[i].hight, arr[i].weight);
    }
}
int main() {
    Student arr[5];
    for (int i=0; i<5; i++){
        cin >> arr[i].name >> arr[i].hight >> arr[i].weight;
    }

    cout << "name" << endl;
    sort(arr, arr+5,cmd_name);
    print_result(arr);
    
    cout << "\nheight" << endl;
    sort(arr,arr+5, cmd_height);
    print_result(arr);

    return 0;
}