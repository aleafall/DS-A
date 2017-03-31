//
// Created by aleafall on 16-10-23.
//

#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int> &vi) {
    for (size_t i = 0; i < vi.size(); ++i) {
        cout << vi[i];
    }
    cout << endl;
}

bool check(const vector<int> &vi) {
    int n = (int) vi.size();
    int sum = 0;
    for (size_t i = 0; i < n; ++i) {
        if (vi[i]) {
            sum += i + 1;
        }
    }
    if (sum == 0 || sum % (n + 1) == 0) {
        return 1;
    }
    return 0;
}

void Del(const vector<int> &vi) {
    int n = (int)vi.size() - 1;
    int sum = 0;
    for (size_t i = 0; i < vi.size(); ++i) {
        if (vi[i] == 1) {
            sum += i + 1;
        }
    }
    for (size_t i = 0; i <vi.size() ; ++i) {
        vector<int> temp;
        for (size_t j = 0; j <vi.size() ; ++j) {
            if (j != i) {
                temp.push_back(vi[j]);
            }
        }
        if (check(temp)) {
            print(temp);
            break;
        }
    }
}

void Insert(const vector<int> &vi) {
    for (size_t i = 0; i < vi.size() + 1; ++i) {
        vector<int> v1, v2;
        for (size_t j = 0; j < vi.size() + 1; ++j) {
            if (j == i) {
                v1.push_back(0);
                v2.push_back(1);
            }
            if (j < vi.size()) {
                v1.push_back(vi[j]);
                v2.push_back(vi[j]);
            }
        }
        if (check(v1)) {
            print(v1);
            break;
        }
        if (check(v2)) {
            print(v2);
            break;
        }
    }
}

void Replace(vector<int> &vi) {
    if (check(vi)) {
        print(vi);
    } else {
        int sum = 0, n = (int) vi.size();
        for (size_t i = 0; i < vi.size(); ++i) {
            if (vi[i] == 1) {
                sum += i + 1;
            }
        }
        for (size_t i = 0; i < vi.size(); ++i) {
            if (vi[i] == 1 && (sum - i - 1 == 0 || (sum - i - 1) % (n + 1) == 0)) {
                vi[i] = 0;
                print(vi);
                break;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vi((unsigned long) n);
    vector<int> line;
    string str;
    while (getline(cin, str)) {
        if (str.size()==0) continue;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                line.push_back(str[i] - '0');
            }
        }
        int len = (int) line.size();
        if (len > n) {
            Del(line);
        } else if (len < n) {
            Insert(line);
        } else {
            Replace(line);
        }
        line.clear();
    }
    return 0;
}
