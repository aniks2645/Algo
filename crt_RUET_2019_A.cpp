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

int pr = 100000;
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
const int M = MM;
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
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { ll x, y, d; };
GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}


const int Mn = 20;
ll a[Mn],b[Mn];
ll chinese_remainder_theorem(int n)
{
    ll ans = a[0];
    ll lcm = b[0];
    for(int i = 1; i < n; i++)
    {
        auto pom = ex_GCD(lcm, b[i]);
        ll x1 = pom.x;
        ll d = pom.d;
        if((a[i] - ans) % d != 0) return -1;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (b[i] / d) * lcm, lcm * b[i] / d);
        lcm = lcm * b[i] / d;
    }
    return ans;
}

const int M = 100000;
vi dvs[M+5];
vi prime;
void precal()
{
    for(int i=2;i<=M;i++)
    {
        if(dvs[i].size())continue;
        prime.pb(i);
        for(int j=i;j<=M;j+=i)
        {
            ll nw = j, mul = 1;
            while(nw%i==0)
            {
                mul *= i;
                nw /= i;
            }
            dvs[j].pb(mul);
        }
    }
}

string s;
pi v[10000];
int pcl[M+5];
bool vis[M+5];
int main() {

    I_O;
    precal();
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int m;
        mem(vis);
        cin>>s>>m;
        ll sum = 0, mul = 1;
        int id = 0;
        for(auto &x:s)
        {
            ll nw = x - '0';
            sum = sum*10LL + nw;
            mul *= 10LL;
            if(mul>=1e13)
            {
                v[id++] = make_pair(sum,mul);
                sum = 0;
                mul = 1;
            }
        }
        if(sum>0) v[id++] = make_pair(sum,mul);
        ll res = 0;
        for(auto &x:prime)
        {
            if(x>m)break;
            ll sum = 0;
            ll i = x;
            while(i*x<=m) i *= x;
            for(int j=0;j<id;j++)
            {
                pi xx = v[j];
                sum *= xx.second;
                sum += xx.first;
                sum %= i;
            }
            pcl[i] = sum;
            res += sum;
            for(int p=i/x;p>=x;p /= x)
            {
                pcl[p] = pcl[i]%p;
                res += pcl[p];
                vis[p] = 1;
            }
                vis[i] = 1;

        }
        for(int i=m;i>=2;i--)
        {
            if(vis[i])continue;
            if(i*2<=m)
            {
                pcl[i] = pcl[i*2] % i;
                res += pcl[i];
            }
            else
            {
                int nw = i;
                int cnt = 0;
                for(auto x : dvs[i])
                {
                    a[cnt] = pcl[x];
                    b[cnt] = x;
                    cnt++;
                }
                ll ans = chinese_remainder_theorem(cnt);
                pcl[i] = ans;
                res += ans;
            }

        }
        tc();
        cout<<res<<"\n";
    }



    return 0;
}
/*

*/
