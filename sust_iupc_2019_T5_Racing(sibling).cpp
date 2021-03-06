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

ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}
/*
//FUNCTION//
ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=x*x%c;
    if(b%2==1)x=x*a%c;return x;
}

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=x*a;return x;
}

ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}


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
const int M = 300;

ll dp[M][M][4], cost[M],rt[M],child[M];
vi adj[M];

void find_sibling(int p, int x)
{
    bool flg = 0;
    int pre = -1;
    for(auto y:adj[x])
    {
        if(y==p)continue;
        if(!flg)
        {
            child[x] = y;
            flg = 1;
            find_sibling(x,y);
        }
        else
        {
            rt[pre] = y;
            find_sibling(x,y);
        }
        pre = y;
    }
}
ll dpcall(int p, int x, int k, int flg)
{
    if(!x || k<flg)return 0;
    ll &ret = dp[x][k][flg];
    if(~ret)return ret;
    ret = dpcall(p,rt[x],k,flg);
    ret = max(ret,cost[x]+dpcall(x,child[x],k-flg,flg));
    ll rest = k-flg;
    for(int i=0;i<=rest;i++)
    {
        ll rst = rest - i;
        if(flg==2)
        {
            ret = max(ret,cost[x]+dpcall(x,child[x],i, flg)+dpcall(p,rt[x],rst, flg));
        }
        else
        {
            ret = max(ret,cost[x]+dpcall(x,child[x],i, flg)+dpcall(p,rt[x],rst, 2));
            if(i>=1)
            {
                ret = max(ret,cost[x]+dpcall(x,child[x],i-1, 2)+dpcall(p,rt[x],rst, flg));
            }

        }
    }
    return ret;
}
int main() {

    I_O;
    int n,k,t,tt=1;
    cin>>t;
    while(t--)
    {
        SET(dp);
        mem(rt);
        mem(child);

        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
            adj[i].clear();
        }
        rep(n-1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        find_sibling(0,1);
        ll res = dpcall(0,1,k+1,1);
        tc();
        cout<<res<<endl;
    }

    return 0;
}
/*
1
4 2
1 4 2 3
1 2
1 3
3 4



*/

