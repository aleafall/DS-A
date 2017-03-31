//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isP(vector<int> &vi){
    vector<int> temp=vi;
    reverse(temp.begin(), temp.end());
    return vi == temp;
}
int main(){
    long long n;
    int k;
    cin >> n >> k;
    vector<int> vi;
    while (n) {
        vi.push_back((int &&) (n % 10));
        n /= 10;
    }
    int step = 0;
    while (!isP(vi) && step < k) {
        ++step;
        vector<int> next;
        int carry = 0;
        for (int i = 0; i < vi.size(); ++i) {
            next.push_back((vi[i] + vi[vi.size() - 1 - i] + carry) % 10);
            carry = (vi[i] + vi[vi.size() - 1 - i] + carry) / 10;
        }
        if (carry) {
            next.push_back(carry);
        }
        reverse(next.begin(), next.end());
        vi = next;
    }
    for (auto item:vi) {
        cout<<item;
    }
    cout<<endl<<step<<endl;
    return 0;
}
