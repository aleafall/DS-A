//
// Created by aleafall on 16-9-28.
//

#include <iostream>

using namespace std;

bool isPrime(int n){
    if (n<=1) return 0;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i==0) return 0;
    }
    return 1;
}
const int maxn=10005;
int main(){
    bool check[maxn]={0};
    int score[maxn]={0};
    int n,m,s;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>s;
        score[s]=i+1;
    }
    cin>>m;
    for (int j = 0; j < m; ++j) {
        cin>>s;
        printf("%04d: ",s);
        if (score[s]==0){
            cout<<"Are you kidding?";
        } else {
            if (check[s]) {
                cout<<"Checked";
            } else{
                check[s]=1;
                if (score[s]==1){
                    cout<<"Mystery Award";
                } else if (isPrime(score[s]))
                    cout<<"Minion";
                else
                    cout<<"Chocolate";
            }
        }
        cout<<endl;
    }
    return 0;
}
