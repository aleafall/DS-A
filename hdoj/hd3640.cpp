//
// Created by aleafall on 16-12-7.
//

#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Plant{
    char type;
    int hp;
    bool isDead;
    Plant():hp(50),isDead(0){}
};
int main(){
    int n,ans=0;
    string s;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        vector<Plant> plants;
        Plant plant;
        cin >> s;
        reverse(s.begin(),s.end());
        for(int j=0;j<s.size();++j){
            plant.type=s[j];
            plants.push_back(plant);
        }
        while(!s.empty()){

        }
    }

}
