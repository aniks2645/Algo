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
#define    dbg(x)           cout << #x << " -> " << x << endl;
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
#define    I_O              ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
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
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=(x*x)%c;
    if(b%2==1)x=(x*a)%c;return x;
}

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=(x*a);return x;
}

ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}

ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}

int pr = 50000;
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
int phi[MM];
void calculatePhi() {
  for (int i = 1; i < M; i++) {
    phi[i] = i;
  }
  for (int p = 2; p < M; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k < M; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
}

ll fact_divs( ll n, ll p)
{
    ll cnt=0;while(p<=n){cnt += n/p;n /= p;}return cnt;
}
struct point{double x, y;};
double area( point A, point B, point C){
return 0.5*(A.x*(B.y-C.y) - A.y*(B.x-C.x) + B.x*C.y - C.x*B.y);
}

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

//*/
const int M = 200005;
vector < pi > adj[M];
vector < int > dag[M], parent[M], dtree[M], toporder;
int subsz[M] ,sp[M][22],  lvl[M], vis[M];
ll cost[M];
void initialize(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear();
        dag[i].clear();
        parent[i].clear();
        dtree[i].clear();
        vis[i] = lvl[i] = subsz[i] = 0;
        for(int j=0; j<=18; j++){
            sp[i][j] = 0;
        }
    }

    toporder.clear();
}
void dijkstra(int n, int src){
    for(int i=1; i<=n; i++) cost[i] = 1e18;
    cost[src] = 0;

    multiset < pair < ll, ll > > min_heap;
    min_heap.insert({cost[src], src});

    while(min_heap.size()){
        pair < ll, ll > p = *min_heap.begin();
        min_heap.erase(min_heap.find(p));

        int cur_node = p.second;
        ll dist = p.first;

        if(dist > cost[cur_node])continue;
        for(auto x : adj[cur_node]){
            int next_node = x.first;
            ll weight = x.second;

            if(cost[next_node] > cost[cur_node] + weight){
                cost[next_node] = cost[cur_node] + weight;
                min_heap.insert({cost[next_node], next_node});
            }
        }
    }
}
void build_dag(int n){
    for(int i=1; i<=n; i++){
        if(cost[i] == 1e18) continue;
        for(auto x : adj[i]){
            int y = x.first;
            ll w = x.second;
            if((cost[i] + w) == cost[y]){
                dag[i].pb(y);
                parent[y].pb(i);
            }
        }
    }
}
void toposort(int x){
    vis[x] = 1;
    for(auto y : dag[x]) if(!vis[y]) toposort(y);
    toporder.pb(x);
}

void build_lca(int n, int p, int x){
    sp[x][0] = p;
    lvl[x] = lvl[p] + 1;
    for(int i=1; (1<<i)<=n; i++){
        sp[x][i] = sp[sp[x][i-1]][i-1];
    }
}
int lca_of(int u, int v){
    if(lvl[u] > lvl[v])swap(u, v);
    for(int i=17; i>=0; i--){
        if(!sp[v][i])continue;
        if(lvl[sp[v][i]] >= lvl[u]){
            v = sp[v][i];
        }
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--){
        if(sp[u][i]==sp[v][i])continue;
        u = sp[u][i]; v = sp[v][i];
    }
    return sp[u][0];
}

void build_dominator_tree(int n){
    reverse(toporder.begin(), toporder.end());
    for(auto x : toporder){
        int lca = -1;
        for(auto y : parent[x]){
            if(lca == -1){
                lca = y;
            }
            else {
                lca = lca_of(lca, y);
            }
        }
        if(lca == -1) continue;
        build_lca(n, lca, x);
        dtree[lca].pb(x);
    }
}
void dfs(int x){
    subsz[x] = 1;
    for(auto y : dtree[x]){
        dfs(y);
        subsz[x] += subsz[y];
    }
}
int main() {

    I_O;
    ll n, m, s;
    cin>>n>>m>>s;
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijkstra(n, s);
    build_dag(n);
    toposort(s);
    build_dominator_tree(n);
    dfs(s);
    ll res = 1;
    n = toporder.size();
    int ans = 0;
    for(auto x : dtree[s]){
        ans = max(ans, subsz[x]);

    }
    cout<<ans<<endl;

    return 0;
}
/*





*/
