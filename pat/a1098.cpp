//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 105;

void print(vector<int> &vi){
    for (int i = 1; i < vi.size(); ++i) {
        if (i < vi.size() - 1) {
            cout << vi[i] << " ";
        } else {
            cout << vi[i] << endl;
        }
    }
}

void adjust(vector<int> &vi, int root, int len) {
    vi[0] = vi[root];
    for (int i = 2*root; i <=len ; i*=2) {
        if (i < len && vi[i] < vi[i + 1]) {
            ++i;
        }
        if (vi[0] > vi[i]) {
            break;
        } else {
            vi[root] = vi[i];
            root = i;
        }
    }
    vi[root] = vi[0];
}
void buildHeap(vector<int> &vi,int len){
    for (int i = len/2; i >0 ; --i) {
        adjust(vi, i, len);
    }
}
int main(){
    int n, v;
    vector<int> pre, temp, part;
    pre.push_back(0);
    part.push_back(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        pre.push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        cin >> v;
        part.push_back(v);
    }
    temp = pre;
    bool flag = 0;
    for (int i = 2; i <=n+1 ; ++i) {
        sort(temp.begin() + 1, temp.begin() + i);
        if (temp == part) {
            flag = 1;
            while (temp == part) {
                ++i;
                sort(temp.begin() + 1, temp.begin() + min(i, n + 1));
            }
            cout << "Insertion Sort\n";
            print(temp);
            break;
        }
    }
    if (!flag) {
        cout << "Heap Sort\n";
        int m = n;
        buildHeap(pre, m);
        pre[0] = 0;
        while (pre != part) {
            swap(pre[1],pre[m]);
            --m;
            adjust(pre, 1, m);
            pre[0] = 0;
        }
        swap(pre[1], pre[m]);
        --m;
        adjust(pre, 1, m);
        print(pre);
    }
    return 0;

}
