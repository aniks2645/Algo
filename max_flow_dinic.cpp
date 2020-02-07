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

ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}

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
const int M = 30005;
struct edge
{
    ll to,rev,flow,cap;
};
vector < edge > adj[M];
int lvl[5005], source, sink,N, ptr[5005];
void create_graph(ll u, ll v, ll Cap)
{
    edge x = {v,(ll)adj[v].size(),0LL,Cap};
    edge y = {u,(ll)adj[u].size(),0LL,Cap};///Cap = 0 when edge is directed.
    adj[u].pb(x);
    adj[v].pb(y);
}
bool make_level_graph(int s, int d)
{
    rep(N+1)lvl[i] = 0;
    queue < int > q;
    q.push(s);
    lvl[s] = 1;
    while(q.size())
    {
        int x = q.front();
        q.pop();
        int sz = adj[x].size();
        rep(sz)
        {
            int y = adj[x][i].to;
            ll cap = adj[x][i].cap - adj[x][i].flow;
            if(!lvl[y] && cap>0)
            {
                lvl[y] = lvl[x] + 1;
                q.push(y);
            }
        }
    }
    if(lvl[d])return 1;
    else return 0;
}
ll send_flow(int x, ll mn)
{
    if(!mn)return 0;
    if(x==sink)return mn;
    int sz = adj[x].size();
    for(int i = ptr[x];i<sz;i++,ptr[x]++)
    {
        int y = adj[x][i].to;
        ll cap = adj[x][i].cap - adj[x][i].flow;
        if(lvl[y] == lvl[x]+1 && cap>0)
        {
            ll flow = send_flow(y,min(mn,cap));
            if(flow>0)
            {
                adj[x][i].flow += flow;
                adj[y][adj[x][i].rev].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}
ll dinic()
{
    ll res = 0;
    while(make_level_graph(source,sink))
    {
        rep(N+1)ptr[i] = 0;
        while(ll flow = send_flow(source,MAX))
        {
            res += flow;
        }
    }
    return res;
}
void Reset(int n)
{
    rep(n+2)adj[i].clear();
}
int main() {

    I_O;

    int n,k;
    SF(n);
    N = n;
    SF(k);
    source = 1;
    sink = n;
    int u,v,c;
    rep(k)
    {
        SF3(u,v,c);
        create_graph(u,v,c);
    }
    PFL(dinic());
    return 0;
}
/*

*/
