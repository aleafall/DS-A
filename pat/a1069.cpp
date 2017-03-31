//
// Created by aleafall on 16-11-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string now, temp, left, right;
    cin >> n;
    now = to_string(n);
    while (1) {
        while (now.size() < 4) {
            now = "0" + now;
        }
        temp = now;
        sort(temp.begin(), temp.end());
        left = temp;
        reverse(temp.begin(), temp.end());
        right = temp;
        int next = atoi(right.c_str()) - atoi(left.c_str());
        printf("%s - %s = %04d\n", right.c_str(), left.c_str(), next);
        if (left == right || next==6174) {
            break;
        }
        now = to_string(next);
    }
    return 0;
}
