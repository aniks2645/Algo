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
typedef pair < int, int > pi;
typedef pair < int, pi > pii;
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
const int M = MM*32;
int   root[MM];
int avail;
struct node
{
    int l, r, val;
    node()
    {
        l = r = val = 0;
    }
};
node sum[M];

int update(int PreNode, int now, ll mask, int val)
{
    int NewNode = ++avail;
    if(now == -1)
    {
        sum[NewNode].val = sum[PreNode].val + val;
        return NewNode;
    }
    if((bool)(mask & 1LL<<now))
    {
        sum[NewNode].l = sum[PreNode].l;
        sum[NewNode].r = update(sum[PreNode].r,now-1,mask,val);
    }
    else
    {
        sum[NewNode].r = sum[PreNode].r;
        sum[NewNode].l = update(sum[PreNode].l,now-1,mask,val);
    }
    sum[NewNode].val = sum[sum[NewNode].l].val + sum[sum[NewNode].r].val;
    return NewNode;
}
int a[MM];
int id = 0;
int b[MM];
vi adj[MM];
int st[MM],ed[MM];

void dfs(int p, int x)
{
    ++id;
    st[x] = id;
    b[id] = a[x];
    for(auto y:adj[x])
    {
        if(y==p)continue;
        dfs(x,y);
    }
    ed[x] = id;
}
ll myquery(int st1, int ed1, int st2, int ed2, int now, ll mask, int k)
{
    if(now == -1)return 0;
    int lcnt1 = sum[sum[ed1].l].val - sum[sum[st1].l].val;
    int lcnt2 = sum[sum[ed2].l].val - sum[sum[st2].l].val;
    int rcnt1 = sum[sum[ed1].r].val - sum[sum[st1].r].val;
    int rcnt2 = sum[sum[ed2].r].val - sum[sum[st2].r].val;
    int pos = (1LL<<now & mask);
    if(pos)
    {
        if(rcnt1-rcnt2>=k) return myquery(sum[st1].r,sum[ed1].r,sum[st2].r,sum[ed2].r,now-1,mask,k);
        else return (1LL<<now) + myquery(sum[st1].l,sum[ed1].l,sum[st2].l,sum[ed2].l,now-1,mask,k-(rcnt1-rcnt2));
    }
    else
    {
        if(lcnt1-lcnt2>=k) return myquery(sum[st1].l,sum[ed1].l,sum[st2].l,sum[ed2].l,now-1,mask,k);
        else return (1LL<<now) + myquery(sum[st1].r,sum[ed1].r,sum[st2].r,sum[ed2].r,now-1,mask,k-(lcnt1-lcnt2));
    }
}
int main()
{

    int n, m, mbit = 29;
    SF2(n,m);
    rep(n)SF(a[i+1]);

    rep(n-1)
    {
        int u,v;
        SF2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,1);
    for(int i=1;i<=id;i++)
    {
        root[i] = update(root[i-1],mbit,b[i],1);
    }
    while(m--)
    {
        int x,y,z,k;
        SF2(x,y);
        SF2(z,k);
        int st1 = st[x]-1;
        int ed1 = ed[x];
        int st2 = st[y]-1;
        int ed2 = ed[y];
        int tot = (ed1-st1+1) - (ed2-st2+1);

        if(tot<k)PF(-1);
        else PFL(myquery(root[st1],root[ed1], root[st2],root[ed2],mbit,z,k));
    }




    return 0;
}
/*

*/
