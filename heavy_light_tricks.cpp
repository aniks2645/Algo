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
ll n,m,q;
vi light[MM],heavy[400];
vi lt[MM],hv[MM];
ll a[MM],hsum[400],sum[400];
int hth[400][400];
int lth[MM][400];
ll hcnt,lcnt;
ll track[MM];
int main() {

    SFL3(n,m,q);
    ll sq = sqrt(n),k,val;
    for(int j=1;j<=n;j++)SFL(a[j]);
    for(int j=1;j<=m;j++)
    {
        SFL(k);
        if(k>=sq)
        {
            ++hcnt;
            rep(k)
            {
                SFL(val);
                hv[val].pb(hcnt);
                sum[hcnt] += a[val];
                heavy[hcnt].pb(val);
            }
            track[j] = hcnt;
        }
        else
        {
            ++lcnt;
            rep(k)
            {
                SFL(val);
                lt[val].pb(lcnt);
                light[lcnt].pb(val);
            }
            track[j] = -lcnt;
        }
    }
    for(int i=1;i<=hcnt;i++)
    {
        for(int j=0;j<heavy[i].size();j++)
        {
            int x = heavy[i][j];
            for(int k=0;k<hv[x].size();k++)
            {
                hth[i][hv[x][k]]++;
            }
        }
    }
    for(int i=1;i<=hcnt;i++)
    {
        for(int j=0;j<heavy[i].size();j++)
        {
            int x = heavy[i][j];
            for(int k=0;k<lt[x].size();k++)
            {
                lth[lt[x][k]][i]++;
            }
        }
    }
    char s[10];
    int id;
    ll ans = 0;
    while(q--)
    {
        sf("%s", s);
        SF(id);
        ans = 0;
        if(strcmp(s,"?")==0)
        {
            if(track[id]<0)
            {
                id = -track[id];
                rep(light[id].size())
                {
                    ans += a[light[id][i]];
                }
                for(int i=1;i<=hcnt;i++)
                {
                    ans+= hsum[i]*(ll)lth[id][i];
                }
                PFL(ans);
            }
            else
            {
                id = track[id];
                ans = sum[id];
                for(int i=1;i<=hcnt;i++)
                {
                    ans+= hsum[i]*(ll)hth[id][i];
                }
                PFL(ans);
            }
        }
        else
        {
            SFL(val);
            if(track[id]<0)
            {
                id = -track[id];
                rep(light[id].size())
                {
                    a[light[id][i]] += val;
                }
                for(int i=1;i<=hcnt;i++)
                {
                    sum[i] += val*(ll)lth[id][i];
                }
            }
            else
            {
                id = track[id];
                hsum[id] += val;
            }
        }
    }

    return 0;
}
/*

*/
