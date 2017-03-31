//
// Created by aleafall on 16-12-7.
//

#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main(){
    int t;
    string s1, s2,temp;
    cin>>t;
    cin.get();
    for (int i = 0; i < t; ++i) {
        while(getline(cin,temp)){
            if(temp=="END") {
                break;
            }
            if(temp!="START"){
                s1+=temp;
            }
            if(temp.empty()){
                s1+='\n';
            }
        }
        while(getline(cin,temp)){
            if(temp=="END") {
                break;
            }
            if(temp!="START"){
                s2+=temp;
            }
            if(temp.empty()){
                s2+='\n';
            }
        }
        string ans1,ans2;
        for(int i=0;i<s1.size();++i){
            if (s1[i] != '\n' && s1[i] != ' ' && s1[i] != '\t') {
                ans1+=s1[i];
            }
        }
        for(int i=0;i<s2.size();++i){
            if (s2[i] != '\n' && s2[i] != ' ' && s2[i] != '\t') {
                ans2+=s2[i];
            }
        }
//        cout<<"s1 "<<s1<<endl;
//        cout<<"s2 "<<s2<<endl;
//        cout<<"ans1 "<<ans1<<endl;
//        cout<<"ans2 "<<ans2<<endl;
        if(s1==s2){
            printf("Accepted\n");
        } else if(ans1==ans2){
            printf("Presentation Error\n");
        } else {
            printf("Wrong Answer\n");
        }
        s1.clear();
        s2.clear();
    }
    return 0;
}
