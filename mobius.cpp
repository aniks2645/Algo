#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> F[maxn];
int p[maxn];
int Count[maxn];

void sieve(){
    for(int i=1; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            F[j].push_back(i);
        }
    }
}

int a[maxn];
int main(){
    sieve();

    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        for(int x : F[a[i]]) p[x] += a[i];
    }

    for(int i=6; i>=1; i--){
        Count[i] = p[i] * p[i];
//        cout<<p[i]<<endl;
        for(int j=i+i; j<=6; j+=i) Count[i] -= Count[j]*j;
        Count[i] /= i;
//        cout<<i<<" "<<Count[i]<<endl;
    }

    int sum = 0;
    for(int i=1; i<maxn; i++) sum += Count[i];
    cout<<sum<<endl;
}
