//
// Created by aleafall on 16-9-27.
//

#include <iostream>

using namespace std;

const int maxn=100010;
int pNum=0,p[maxn];
bool prime[maxn]={false};
bool isPrime(int n){
    if (n<=1) return 0;
    for (int i = 2; i*i <=n ; ++i) {
        if (n%i==0) return 0;
    }
    return 1;
}
void init(){
    for (int i = 2; i < maxn; ++i) {
        if (prime[i]==0){
            p[pNum++]=i;
            for (int j = 2*i; j < maxn; j+=i) {
                if (j>=maxn) cout<<"error"<<endl;
                prime[j]=1;
            }
        }
    }
}

bool check(int x){
    for (int i = 0; i < pNum&&p[i]*p[i]<=x; ++i) {
        if (x%p[i]==0&&isPrime(x/p[i])){
            return 1;
        }
    }
    return 0;

}
int main(){
    init();
    int n,x;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>x;
        if (check(x)) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}
