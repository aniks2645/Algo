#include<bits/stdc++.h>
using namespace std;
/// HISTOGRAM sp O(1)
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

int a[MM*2],sp[20][MM*2], lg[MM*2],n;

void logcal()
{
    int cnt = 0;
    int p = 2;
    while(p<=200000)
    {
        lg[p] = 1;
        p *= 2;
    }
    for(int i=0;i<=200000;i++)
    {
        if(lg[i])
        {
            cnt++;
        }
        lg[i] = cnt;
    }
}
ll query(int l, int r)
{
    int ln = lg[r-l+1];
    int k = 1<<ln;
    int df = r-l+1-k;
    return (min(sp[ln][l],sp[ln][l+df]));
}
ll lbs(int id, int val)
{
    int lw = 1, hi = id;
    int mid;
    rep(20)
    {
        mid = (lw+hi)/2;
        if(query(mid,id)<val)
        {
            lw = mid+1;
        }
        else
        {
            hi = mid;
        }
    }
    if(query(hi,id)<val)hi++;
    return id-hi+1;
}
ll rbs(int id, int val)
{
    int lw = id, hi = n;
    int mid;
    rep(20)
    {
        mid = (lw+hi)/2;
        if(query(id,mid)<val)
        {
            hi = mid-1;
        }
        else
        {
            lw = mid;
        }
    }
    if(query(id,hi)<val)hi--;
    return hi-id+1;
}

int res[MM*2];
int main()
{

    int q,t,tt=1;
    logcal();

    SF(n);
    for(int i=1;i<=n;i++)
    {
        SF(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sp[0][i] = a[i];
    }
    for(int i=1;1<<i<=n;i++)
    {
        for(int j=1;j+(1<<i)<=n+1;j++)
        {
            sp[i][j] = min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
        }
    }
    ll sum = 0, ans = 0;
    for(int i=1;i<=n;i++)
    {
        sum = lbs(i,a[i]) + rbs(i,a[i]) - 1;
        res[sum] = max(res[sum],a[i]);
    }
    for(int i=n;i>=1;i--) res[i] = max(res[i+1],res[i]);
    for(int i=1;i<=n;i++)cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
/*




*/
