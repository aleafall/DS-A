//
// Created by aleafall on 16-11-23.
//

#include <iostream>
#include <set>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n, m, id;
    map<string, set<int>> mp[5];
    string title, author, keys, pub, year;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> id;
        cin.get();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keys);
        getline(cin, pub);
        getline(cin, year);
        mp[0][title].insert(id);
        mp[1][author].insert(id);
        istringstream in(keys);
        string word;
        while (in >> word) {
            mp[2][word].insert(id);
        }
        mp[3][pub].insert(id);
        mp[4][year].insert(id);
    }
    cin >> m;
    int index;
    string query;
    for (int i = 0; i < m; ++i) {
        scanf("%d: ", &index);
        getline(cin, query);
        printf("%d: %s\n", index, query.c_str());
        if (mp[index - 1].find(query) != mp[index - 1].end()) {
            for (auto item:mp[index - 1][query]) {
                printf("%07d\n", item);
            }
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}
