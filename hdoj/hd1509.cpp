//
// Created by aleafall on 16-12-6.
//

#include<bits/stdc++.h>

using namespace std;

struct Msg {
    string name;
    int para, pri, order;

    bool operator<(Msg a) const {
        if (pri != a.pri)
            return pri > a.pri;
        return order > a.order;
    }
} msg;

bool cmp(Msg a, Msg b) {
    return a.pri < b.pri;
}

int main() {
    priority_queue<Msg> pq;
    string cmd, name;
    int para, pri,cnt=0;
    while (cin >> cmd) {
        if (cmd == "GET") {
            if (pq.empty()) {
                cout << "EMPTY QUEUE!\n";
            } else {
                msg = pq.top();
                pq.pop();
                cout << msg.name << " " << msg.para << endl;
            }
        } else {
            cin >> name >> para >> pri;
            msg.name = name;
            msg.para = para;
            msg.pri = pri;
            msg.order=cnt++;
            pq.push(msg);
        }
    }
    return 0;
}
