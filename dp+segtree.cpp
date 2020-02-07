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
#define    SFE(a,b)         scanf("%d %d",&a, &b);adj[a].pb(b);adj[b].pb(a)
#define    SFEC(a,b,c)      scanf("%d%d%d",&a,&b,&c);adj[a].pb(b);adj[a].pb(c);adj[b].pb(a)adj[b].pb(c)
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
typedef pair < pi , ll > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < string > vs;

const int M = MM*2;

ll sum[M*4];

void build(int l, int r, int k)
{
    if(l==r)
    {
        sum[k] = 0;
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,k*2);
    build(mid+1,r,k*2+1);
    sum[k] = 0;
}
void update(int l, int r, int k, int L, ll val)
{
    if(l==r)
    {
        sum[k] = max(sum[k],val);
        return;
    }
    int mid = (l+r)/2;
    if(mid>=L)
    update(l,mid,k*2,L,val);
    else
    update(mid+1,r,k*2+1,L,val);
    sum[k] = max(sum[k*2],sum[k*2+1]);
}

ll query(int l, int r, int k, int L, int R)
{
    if(l>R || r<L)return 0;
    if(l>=L && r<=R)return sum[k];
    int mid = (l+r)/2;
    return max(query(l,mid,k*2,L,R),query(mid+1,r,k*2+1,L,R));
}
vector<pi> v[MM];
ll dp[MM];
int main() {

    int t,tt=1, N = 200000;
    SF(t);
    while(t--)
    {
        mem(dp);
        build(1,N,1);
        int n,a,b,c;
        SF(n);
        rep(n)
        {
            SF3(a,b,c);
            v[a].pb({b,c});
        }
        for(int i = 100000; i >= 0; i--)
        {
            dp[i] = dp[i+1];
            for(auto x:v[i])
            {
                ll to = i + x.first;
                ll cost = x.second;
                ll ret = query(1,N,1,to,N);
                dp[i] = max(dp[i],ret+cost);
                update(1,N,1,i,ret+cost);
            }
        }
        pc();
        PFL(dp[0]);
        for(int i=0;i<=100000;i++)
        {
            dp[i] = 0;
            v[i].clear();
        }
    }
    return 0;
}
/*

*/
