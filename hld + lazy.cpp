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
vi adj[M];
int cost[M],n,idx[M],sbsz[M],spcd[M],chain[M],head[M],par[M],sum[4*M],lvl[M],id,a[M],clr, lst[M], prop[M*4];

int maxx(int x,int y){return max(x,y);}
int dfs(int x, int p, int level)
{
    par[x] = p;//parent store
    lvl[x] = level;//level store
    int sz = adj[x].size();
    sbsz[x] = 1;
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        sbsz[x] += dfs(y,x,level+1); // subtree size calculate
    }
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        if(sbsz[y]>sbsz[spcd[x]])
        {
            spcd[x] = y; // find special child
        }
    }
    return sbsz[x];
}

void decompose(int x, int p)
{
    ++id;
    idx[x] = id;
    chain[x] = clr;
    if(sbsz[x]==1)
    {
        lst[x] = id;
        return;
    }
    decompose(spcd[x],x);
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || y==spcd[x])continue;
        ++clr;
        head[clr] = y;
        decompose(y,x);
    }
    lst[x] = id;
}

void propagate(int l,int r, int k)
{
    if(l!=r)
    {
        prop[k*2] += prop[k];
        prop[k*2+1] += prop[k];
    }
    sum[k] += prop[k];
    prop[k] = 0;
}
void update(int l, int r, int k, int L, int R, int val)
{
    propagate(l,r,k);
    if(l>R || r<L)return;
    if(l>=L && r<=R)
    {
        prop[k] = val;
        propagate(l,r,k);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,k*2,L,R,val);
    update(mid+1,r,k*2+1,L,R,val);
    sum[k] = maxx(sum[k*2],sum[k*2+1]);
}
int query(int l, int r, int k, int L, int R)
{
    propagate(l,r,k);
//    cout<<l<<" "<<r<<endl;
//    cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>R || r<L)return -MAX;
    if(l>=L && r<=R)return sum[k];
    int mid = (l+r)/2;
    int p = query(l,mid,k*2,L,R);
    int q = query(mid+1,r,k*2+1,L,R);
    return maxx(p,q);
}
int process(int u, int v)
{
    if(chain[u]==chain[v])
    {
        if(lvl[u]>lvl[v])
        {
            int tm = u;
            u = v;
            v = tm;
        }
        return query(1,id,1,idx[u],idx[v]);
    }
    if(lvl[head[chain[u]]]>lvl[head[chain[v]]])
    {
        int mn = query(1,id,1,idx[head[chain[u]]],idx[u]);
        return maxx(mn,process(par[head[chain[u]]],v));
    }
    else
    {
        int mn = query(1,id,1,idx[head[chain[v]]],idx[v]);
        return maxx(mn,process(par[head[chain[v]]],u));
    }

}
int main() {

    SF(n);
    int u,v,c;

    rep(n-1)
    {
        SF2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    head[0] = 1;
    dfs(1,0,0);
    decompose(1,0);
    int q;
    SF(q);
    char s[20];
    while(q--)
    {
        int typ;
        scanf("%s", s);
        if(s[0]=='a')
        {
            int k;
            SF(k);
            SF(c);
            update(1,id,1,idx[k],lst[k],c);
        }
        else
        {
            SF2(u,v);
            PF(process(u,v));
        }
    }
    return 0;
}

