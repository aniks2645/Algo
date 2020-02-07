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
int kx8[] = {1, 1, 2, 2, -1, -1, -2, -2};
int ky8[] = {2, -2, 1, -1, 2, -2, 1, -1};

typedef long long ll;
typedef unsigned long long llu;
typedef priority_queue < int > PQ;
typedef pair < int , int > pi;
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
const int M = MM;
vi adj[M],adjj[M];
int sbz[M],parent[M],vis[M],lvl[M],N;
ll mp[20][M];
map < int , ll > dist[M];
void find_size(int p, int x)
{
    sbz[x] = 1;
    int sz = adj[x].size();
    int y;
    rep(sz)
    {
        y = adj[x][i];
        if(p==y || vis[y])continue;
        find_size(x,y);
        sbz[x] += sbz[y];
    }
}
ll find_center(int p, int x, int l)
{
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        if(sbz[y]>l/2)
        {
            return find_center(x,y,l);
        }
    }
    return x;
}
vector < ll > ms[M];
void cal_dis(int p, int x, ll cost, ll cntr)
{
    mp[lvl[cntr]][x] = cost;
    ms[cntr].pb(cost);
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y] || y==p)continue;
        cal_dis(x,y,cost+dist[x][y],cntr);///change
    }
}

void decompose(int p, int x, int lev)
{
    find_size(p,x);
    x = find_center(p,x,sbz[x]);
    parent[x] = p;
    lvl[x] = lev;
    adjj[p].pb(x);
    vis[x] = 1;
    rep(adj[x].size())
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        cal_dis(x,y,dist[x][y],x);///change
    }
    ms[x].pb(1e18);
    ms[x].pb(0);
    sort(ms[x].begin(),ms[x].end());
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y])continue;
        decompose(x,y,lev+1);
    }

}
int nnode, lt[M],rt[M];
void make_binary(int p, int x, int l, int r)
{
    if(r-l+1==1)
    {
        ///level assign krte hbe

        parent[adjj[p][r]] = x;
        lt[x] = adjj[p][r];
        ms[x].clear();
        for(auto z : ms[lt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][lt[x]]);
        }
        for(auto z : ms[rt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][rt[x]]);
        }
        sort(ms[x].begin(),ms[x].end());
    }
    else if(r-l+1==2)
    {
        ///
        parent[adjj[p][l]] = x;
        lt[x] = adjj[p][l];
        parent[adjj[p][r]] = x;
        rt[x] = adjj[p][r];
        ms[x].clear();
        for(auto z : ms[lt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][lt[x]]);
        }
        for(auto z : ms[rt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][rt[x]]);
        }
        sort(ms[x].begin(),ms[x].end());

    }
    else if(r-l+1==3)
    {
        ///
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        lt[x] = nnode;
        make_binary(p,nnode,l,l+1);
        parent[adjj[p][r]] = x;
        rt[x] = adjj[p][r];
        ms[x].clear();
        for(auto z : ms[lt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][lt[x]]);
        }
        for(auto z : ms[rt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][rt[x]]);
        }
        sort(ms[x].begin(),ms[x].end());
    }
    else
    {
        int mid = (l+r)/2;
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        lt[x] = nnode;
        make_binary(p,nnode,l,mid);
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        rt[x] = nnode;
        make_binary(p,nnode,mid+1,r);

        ms[x].clear();
        for(auto z : ms[lt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][lt[x]]);
        }
        for(auto z : ms[rt[x]])
        {
            ms[x].pb(z+mp[lvl[x]][rt[x]]);
        }
        sort(ms[x].begin(),ms[x].end());
    }
}
void lift_to_binary(int x)
{
    int sz = adjj[x].size();
    make_binary(x,x,0,sz-1);
    for(auto y :adjj[x])
    {
        lift_to_binary(y);
    }
}
///Result part

ll res[M][2];
void init(int n)
{
    rep(n)res[i+1][0] = MAX;
}
void update_centroid(int p, int x)
{
    if(p==0)return;
    int dist = mp[lvl[p]][x];
    if(res[p][0]>dist)
    {
        res[p][0] = dist;
        res[p][1] = x;
    }
    update_centroid(parent[p],x);
}

ll query_centroid(int p, int x, ll d, int side)
{
    ll ans = 0;
    if(side==0)
    {
        ///ll tot = lower_bound(ms[rt[p]].begin(),ms[rt[p]].end(),d-)
        ///do it here.
    }
}
int main() {

    I_O;
    int n,m;
    SF2(n,m);
    N = n;
    nnode = n;
    int u,v;
    ll c;
    rep(n-1)
    {
        SF2(u,v);
        SFL(c);
        adj[u].pb(v);
        adj[v].pb(u);
        dist[u][v] = c;
        dist[v][u] = c;
    }
    decompose(0,1,0);
    lift_to_binary(adjj[0][0]);



    return 0;
}
