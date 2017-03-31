//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <string>

using namespace std;

struct Stu {
    string name, id;
    char gender;
    int score;
}stu;
int main(){
    Stu boy, girl;
    boy.score = 101, girl.score = -1;
    int n;
    cin >> n;
    bool m = 0, f = 0;
    for (int i = 0; i < n; ++i) {
        cin >> stu.name >> stu.gender >> stu.id >> stu.score;
        if (stu.gender == 'M') {
            m = 1;
            if (stu.score < boy.score) {
                boy = stu;
            }
        } else {
            f = 1;
            if (stu.score > girl.score) {
                girl = stu;
            }
        }
    }
    if (m && f) {
        cout<<girl.name<<" "<<girl.id<<endl;
        cout<<boy.name<<" "<<boy.id<<endl;
        cout << abs(girl.score - boy.score)<<endl;
    } else if (m) {
        cout<<"Absent"<<endl;
        cout<<boy.name<<" "<<boy.id<<endl;
        cout << "NA\n";
    } else {
        cout<<girl.name<<" "<<girl.id<<endl;
        cout<<"Absent"<<endl;
        cout << "NA\n";
    }
    return 0;
}
