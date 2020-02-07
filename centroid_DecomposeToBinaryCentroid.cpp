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
const int M = 2*MM;
vi adj[M],adjj[M];
int sbz[M],parent[M],vis[M],lvl[M],N;
ll mp[22][M];
map < ll , ll > dist[M];
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
vector < ll > msl[M],msr[M];
void cal_dis(int p, int x, ll cost, ll cntr)
{
    mp[lvl[cntr]][x] = cost;
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
    if(r-l+1==0)return;
    if(r-l+1==1)
    {
        ///level assign krte hbe

        parent[adjj[p][r]] = x;
        lt[x] = adjj[p][r];

    }
    else if(r-l+1==2)
    {
        ///
        parent[adjj[p][l]] = x;
        lt[x] = adjj[p][l];
        parent[adjj[p][r]] = x;
        rt[x] = adjj[p][r];

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

void dfs(int p, int x, int lev, int side)
{
    if(x==0)return;
    if(x<=N)
    {
        if(side==1)
        {
            msl[p].pb(mp[lev][x]);
        }
        else
        {
            msr[p].pb(mp[lev][x]);
        }
    }
    dfs(p,lt[x],lev,side);
    dfs(p,rt[x],lev,side);
}
void traverse_binary_tree(int x)
{
    if(x==0)return;
    if(x<=N)
    msl[x].pb(0);
    if(x<=N)
    msr[x].pb(0);
    dfs(x,lt[x],lvl[x],1);
    dfs(x,rt[x],lvl[x],2);
    sort(msl[x].begin(),msl[x].end());
    sort(msr[x].begin(),msr[x].end());
    traverse_binary_tree(lt[x]);
    traverse_binary_tree(rt[x]);

//    cout<<"start ---->"<<endl;
//    cout<<"Node = "<<x<<endl;
//    cout<<"Values are: "<<endl;
//    cout<<"Left: "<<endl;
//    for(auto z:msl[x])cout<<z<<" ";
//    cout<<endl;
//    cout<<"Right: "<<endl;
//    for(auto z:msr[x])cout<<z<<" ";
//    cout<<endl;
//    cout<<"<-----end "<<endl<<endl<<endl;
}
///Result part

ll res;
ll query_centroid(int p, int x, ll sbnd, ll l)
{
    ll ans = 0;
    while(x!=0)
    {
        ll dst = mp[lvl[x]][p];
        if(rt[x]==sbnd && msl[x][0]<=l-dst)
        {
            ll sum = upper_bound(msl[x].begin(),msl[x].end(),l-dst) - msl[x].begin();
            ans += sum;
        }
        if(lt[x]==sbnd && msr[x][0]<=l-dst)
        {
            ll sum = upper_bound(msr[x].begin(),msr[x].end(),l-dst) - msr[x].begin();
            ans += sum;
        }
        sbnd = x;
        x = parent[x];
    }
    ll sum = upper_bound(msl[p].begin(),msl[p].end(),l) - msl[p].begin();
    ans += sum;
    sum = upper_bound(msr[p].begin(),msr[p].end(),l) - msr[p].begin();
    ans += sum;
    ans--;
    return ans;
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
    traverse_binary_tree(adjj[0][0]);
    ll l;
    while(m--)
    {
        SF(v);
        SFL(l);
        PFL(query_centroid(v, v, v, l));
    }



    return 0;
}
/*
4 6
1 2 3
2 3 10
3 4 51
1 2
1 10
3 30
3 51
2 60
2 61
*/
