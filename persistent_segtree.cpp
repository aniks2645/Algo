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
const int M = MM*80;
int  a[MM], root[MM];
int avail;
struct data
{
    int l, r, val;
    data()
    {
        l = r = val = 0;
    }
};
data sum[M];
int update(int PreNode, int l, int r, int L, int val)
{
    int NewNode = ++avail;
    if(l==r)
    {
        sum[NewNode].val = val;
        ///sum[NewNode].val = sum[PreNode].val + val;
        return NewNode;
    }
    int mid = (l+r)/2;
    if(L<=mid)
    {
        sum[NewNode].r = sum[PreNode].r;
        sum[NewNode].l = update(sum[PreNode].l,l,mid,L,val);
    }
    else
    {
        sum[NewNode].l = sum[PreNode].l;
        sum[NewNode].r = update(sum[PreNode].r,mid+1,r,L,val);
    }
    sum[NewNode].val = sum[sum[NewNode].l].val + sum[sum[NewNode].r].val;
    return NewNode;
}

ll query(int n, int l, int r, int k)
{
    if(l==r)
    {
        return l;
    }
    int mid = (l+r)/2;
    if(sum[sum[n].l].val>=k)
    {
        return query(sum[n].l,l,mid,k);
    }
    else
    {
        return query(sum[n].r,mid+1,r,k-sum[sum[n].l].val);
    }
}

ll query(int n, int l, int r, int L, int R)
{
    if(l>R || r<L)return 0;
    if(l>=L && r<=R)return sum[n].val;
    int mid = (l+r)/2;

    int tot = query(sum[n].l,l,mid,L,R) + query(sum[n].r,mid+1,r,L,R);
    return tot;
}

int idx[MM];
int main()
{

    I_O;
    int n;
    cin>>n;
    rep(n)cin>>a[i+1];
    a[n+1] = MM-2;
    n++;
    int rt;
    for(int i=n;i>=1;i--)
    {
        if(idx[a[i]])
        {
            root[i] = update(root[i+1],1,n,idx[a[i]],0);
            root[i] = update(root[i],1,n,i,1);
        }
        else
        {
            root[i] = update(root[i+1],1,n,i,1);
        }
        idx[a[i]] = i;

    }
    for(int k=1;k<n;k++)
    {
        int x = 1, ans=0;
        while(x<n)
        {
           x = query(root[x],1,n,k+1);
           ans++;
        }
        cout<<ans<<" ";
    }
    cout<<endl;


    return 0;
}
