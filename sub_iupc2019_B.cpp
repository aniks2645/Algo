#include<bits/stdc++.h>

using namespace std;

#define    pf               printf
#define    PF(a)            printf("%d\n",(a))
#define    PF2(a,b)         printf("%d %d\n",(a), (b))
#define    PF3(a,b,c)       printf("%d %d %d\n",(a), (b), (c))
#define    PFL(a)           printf("%lld\n",(a))
#define    PFL2(a,b)        printf("%lld %lld\n",(a), (b))
#define    PFL3(a,b,c)      printf("%lld %lld %lld\n",(a), (b), (c))
#define    get(a)           cin>>a
#define    sf               scanf
#define    SF(a)            scanf("%d",&a)
#define    SF2(a,b)         scanf("%d %d",&a, &b)
#define    SF3(a,b,c)       scanf("%d %d %d",&a, &b, &c)
#define    SFL(a)           scanf("%lld",&a)
#define    SFL2(a,b)        scanf("%lld %lld",&a, &b)
#define    SFL3(a,b,c)      scanf("%lld %lld %lld",&a, &b, &c)
#define    gl(a)            getline(cin,(a))
#define    gc()             getchar()
#define    pb               push_back
#define    m_p              make_pair
#define    pc()             printf("Case %d: ",tt++)
#define    tc()             cout<<"Case "<<tt++<<": "
#define    SZ(a)            (int)(a).size()
#define    all(a)           a.begin(),a.end()
#define    FF               first
#define    SS               second
#define    MAX              2134567891
#define    MOD              1000000007
#define    MM               100005
#define    PI               2*acos(0.0)
#define    cond(n,m)        (xx>=0 && xx<(n) && yy>=0 && yy<(m))

#define    mem(a)           memset((a),0,sizeof (a))
#define    SET(a)           memset((a),-1,sizeof (a))
#define    output           freopen("output.txt","w",stdout);
#define    input            freopen("input.txt","r",stdin);
#define    I_O              ios_base::sync_with_stdio(0); cin.tie(0)
#define    rep(a)           for(int i=0;i<(a);i++)
#define    FOR(a,b)         for(int i=(a);i<(b);i++)
#define    REP(a)           for(int j=0;j<(a);j++)
#define    rev(a)           for(int i=(a);i>=0;i--)
#define    fr(i,n)          for(i=0;i<n;i++)
#define    fr1(i,n,m)       for(i=n;i<m;i++)

int dx[]  = {0, 0, 1, -1};
int dy[]  = {1, -1, 0, 0};
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1, -1, -1, 0, 1, -1, 0, 1};


typedef long long ll;
typedef unsigned long long llu;
typedef priority_queue < int > PQ;
typedef pair < ll , ll > pi;
typedef pair < int , pi > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < string > vs;

ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=x*x%c;
    if(b%2==1)x=x*a%c;return x;
}
ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}
ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}
/*
//FUNCTION//

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=x*a;return x;
}



int pr = 10000000;
vi primelist;
bool a[MM*100];
void seive( )
{
    int i,j,k=sqrt(pr);
    a[1]=1;
    primelist.pb(2);
    for(i=4;i<=pr;i+=2)a[i]=1;
    for(i=3;i<=k;i+=2)if(!a[i])for(j=i*i;j<=pr;j+=2*i)a[j]=1;
    for(i=3;i<=pr;i+=2)if(!a[i])primelist.pb(i);
}

ll fact_divs( ll n, ll p)
{
    ll cnt=0;while(p<=n){cnt += n/p;n /= p;}return cnt;
}
struct point{double x, y;};
double area( point A, point B, point C){
return 0.5*(A.x*(B.y-C.y) - A.y*(B.x-C.x) + B.x*C.y - C.x*B.y);
}

//*/
const int M = 1000005;
vector < pi > dv[M];

void precal()
{
    for(int i=2;i<M;i++)
    {
        if(dv[i].size())continue;
        for(int j=i;j<M;j+=i)
        {
            int nw = j, mul=1;
            while(nw%i==0)
            {
                mul *= i;
                nw /= i;
            }
            dv[j].push_back({i,mul});
        }
    }
}
vector < int > add[MM],del[MM];

multiset < int > ms[M];
int pm[M];
vi prm_for_clear;
ll res[MM];
int main() {


    precal();
    int t,tt=1;
    SF(t);
    while(t--)
    {

        int n,m;
        SF2(n,m);
        int l,r,x,value;
        ll lc = 1;
        rep(m)
        {
            SF3(l,r,x);
            add[l].push_back(x);
            del[r].push_back(x);
        }
        ll ans = 1;
        for(int i=1;i<=n;i++)
        {
            for(auto x:add[i])
            {
                value = x;
                for(auto y:dv[value])
                {
                    int prm = y.first;
                    int val = y.second;
                    if(!pm[prm])
                    {
                        prm_for_clear.pb(prm);
                        pm[prm] = 1;
                        ms[prm].insert(1);
                    }
                    int mx = *--ms[prm].end();
                    if(mx>=val)
                    {
                        ms[prm].insert(val);
                    }
                    else
                    {
                        ll mdinv = mod_inverse(mx,MOD);
                        ans *= mdinv;
                        ans %= MOD;
                        ans *= val;
                        ans %= MOD;
                        ms[prm].insert(val);
                    }
                }
            }
            res[i] = ans;
            for(auto x:del[i])
            {
                value = x;
                for(auto y:dv[value])
                {
                    int prm = y.first;
                    int val = y.second;
                    int mx = *--ms[prm].end();
                    if(mx>val)
                    {
                        ms[prm].erase(ms[prm].find(val));
                    }
                    else
                    {
                        ll mdinv = mod_inverse(val,MOD);
                        ans *= mdinv;
                        ans %= MOD;
                        ms[prm].erase(ms[prm].find(val));
                        int nw = *--ms[prm].end();
                        ans *= nw;
                        ans %= MOD;
                    }
                }
            }
        }

        pf("Case %d:",tt++);
        for(int i=1;i<=n;i++)
        {
            pf(" %lld",res[i]);
            add[i].clear();
            del[i].clear();
        }
        pf("\n");
        for(auto x:prm_for_clear)
        {
            pm[x] = 0;
            ms[x].clear();
        }
        prm_for_clear.clear();

    }
    return 0;
}
/*
1
7 2
2 5 2
5 7 3
*/

