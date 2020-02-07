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

ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=x*x%c;
    if(b%2==1)x=x*a%c;return x;
}
ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}
/*
//FUNCTION//

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=x*a;return x;
}


ll LCM(ll a, ll b){ return a*b/ __gcd(a,b);}

int pr = 10000000;
int primelist[MM*100], psz;
bool a[MM*100];
void seive( )
{
    int i,j,k=sqrt(pr);
    a[1]=1;
    primelist[psz++] = 2;
    for(i=4;i<=pr;i+=2)a[i]=1;
    for(i=3;i<=k;i+=2)if(!a[i])for(j=i*i;j<=pr;j+=2*i)a[j]=1;
    for(i=3;i<=pr;i+=2)if(!a[i])primelist[psz++] = i;
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

char ch[105][105];
string s[105];
int n,m;

llu dp[105][1<<8], vis[105][1<<8],cur;


bool check(int x, int y, int mask)
{

    if(x>=n || y>=m || x<0 || y<0)return 0;
    if(s[x][y]=='#') return false;

    bool pos = (bool)(mask & 1<<y);
    if(pos) return false;

    return true;
}

int bset(int mask, int pos)
{
    return (mask | (1<<pos));
}
llu dpcall(int id, int mask);

llu btrack(int x, int y, int mask, int nmask)
{
    if(y==m)
    {
        return dpcall(x+1,nmask);
    }
    if((bool)(mask & 1<<y) || s[x][y]=='#') return btrack(x,y+1,mask,nmask);
    llu res = 0;
    //type |
    if(check(x,y,mask) && check(x+1,y,nmask))
    {
        int msk = bset(mask,y);
        int nmsk = bset(nmask,y);
        res += btrack(x,y+1,msk,nmsk);
    }
    //type _
    if(check(x,y,mask) && check(x,y+1,mask))
    {
        int msk = bset(mask,y);
        msk = bset(msk,y+1);
        res += btrack(x,y+1,msk,nmask);
    }
    //type L
    if(check(x,y,mask) && check(x+1,y,nmask) && check(x+1,y+1,nmask))
    {
        int msk = bset(mask,y);
        int nmsk = bset(nmask,y);
        nmsk = bset(nmsk,y+1);
        res += btrack(x,y+1,msk,nmsk);
    }
    //type |^
    if(check(x,y,mask) && check(x,y+1,mask) && check(x+1,y,nmask))
    {
        int msk = bset(mask,y);
        msk = bset(msk,y+1);
        int nmsk = bset(nmask,y);
        res += btrack(x,y+1,msk,nmsk);
    }
    //type _|
    if(check(x,y,mask) && check(x+1,y-1,nmask) && check(x+1,y,nmask))
    {
        int msk = bset(mask,y);
        int nmsk = bset(nmask,y);
        nmsk = bset(nmsk,y-1);
        res += btrack(x,y+1,msk,nmsk);
    }

    //type ^|
    if(check(x,y,mask) && check(x,y+1,mask) && check(x+1,y+1,nmask))
    {
        int msk = bset(mask,y);
        msk = bset(msk,y+1);
        int nmsk = bset(nmask,y+1);
        res += btrack(x,y+1,msk,nmsk);
    }
    return res;


}
llu dpcall(int id, int mask)
{
    if(id==n)
    {
        if(mask)return 0;
        else return 1;
    }
    llu &ret = dp[id][mask];
    if(vis[id][mask]==cur)return ret;
    vis[id][mask] = cur;

    ret = btrack(id,0,mask, 0);

    return ret;


}

int main() {



    int t,tt=1;
    SF(t);
    while(t--)
    {
        rep(100)s[i].clear();
        SF2(n,m);
        rep(n)sf("%s",ch[i]);
        if(n<m)
        {
            rep(m)REP(n)s[i].pb(ch[j][i]);
            swap(n,m);
        }
        else
        {
            rep(n) s[i] = ch[i];
        }
        cur++;
        llu ans = dpcall(0,0);
        pc();
        pf("%llu\n",ans);

    }


    return 0;
}
/*
3

2 3

...

...


2 4
#...
...#




*/

