//
// Created by aleafall on 16-11-29.
//

#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(){
    string s;
    int k=0;
    cin >> s;
    if (s[0]=='-'){
        cout << "-";
    }
    s.erase(s.begin());
    int left=0;
    for(k=0;k<s.size();++k){
        if(s[k]=='E'){
            break;
        }
    }
    string ans=s.substr(0,k);
    left=k-2;
    int e=atoi(s.substr(k+1,s.size()).c_str());
    if(e>0){
        if(e>=left){
            ans.erase(ans.begin()+1);
            cout<<ans;
            for(int i=0;i<e-left;++i){
                cout<<"0";
            }
        } else {
            for(int i=0;i<ans.size();++i){
                if(ans[i]!='.'){
                    cout<<s[i];
                }
                if(i-1==e){
                    cout<<".";
                }
            }
        }
    } else if(e<0){
        cout<<"0.";
        for(int i=0;i<abs(e)-1;++i){
            cout<<"0";
        }
        ans.erase(ans.begin()+1);
        cout<<ans;
    } else{
        cout<<ans;
    }
    cout<<endl;
    return 0;
}