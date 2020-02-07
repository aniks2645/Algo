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


///AUTOMATA
const int M = 262144+5;
struct state
{
    int len, link,fpos;
    bool isclone;
    int next[16];
} st[2*M];

int sz, last;
int cnt[2*M];


void initialize()
{
    rep(sz+1)
    {
        mem(st[i].next);
    }
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
}
void build_automata(char c)
{
    int cur = ++sz;
    cnt[cur] = 1;
    st[cur].len = st[last].len + 1;
    st[cur].isclone = 0;
    st[cur].fpos = st[cur].len;
    int p;
    for(p=last;p!=-1 && !st[p].next[c];p=st[p].link)
    {
        st[p].next[c] = cur;
    }
    if(p==-1)
    {
        st[cur].link = 0;
    }
    else
    {
        int q = st[p].next[c];
        if(st[p].len+1==st[q].len)
        {
            st[cur].link = q;
        }
        else
        {
            int clone = ++sz;
            cnt[clone] = 0;
            st[clone] = st[q];
            st[clone].len = st[p].len+1;
            st[clone].isclone = 1;
            for(;p!=-1 && st[p].next[c]==q;p=st[p].link)
            {
                st[p].next[c] = clone;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

char s[M];
vi v[M];
void cal_occuarence(int len)
{
    for(int i = sz;i>=1;i--)
    {
        v[st[i].len].pb(i);
    }
    for(int i = len;i>=1;i--)
    {
        for(auto x : v[i])
        {
            cnt[st[x].link] += cnt[x];
        }
        v[i].clear();
    }
}
int Len;
int magic(int id, int now, int flg)
{
    if(id==Len)
    {
        return cnt[now];
    }
    ll ans = 0;
    int ch = s[id] - 'a';
    if(flg)
    {
        if(st[now].next[ch])
        {
            now = st[now].next[ch];
            if(now) ans = magic(id+1,now,flg);

        }
        return ans;
    }

    rep(16)
    {
        if(!st[now].next[i])continue;
        int tmp = st[now].next[i];
        if(i==ch)
        {
            ans += magic(id+1,tmp,0);
        }
        else
        {
            ans += magic(id+1,tmp,1);
        }
    }
    return ans;
}

int main() {


    int t,tt=1;
    SF(t);
    while(t--)
    {
        sf("%s",s);
        int len = strlen(s);
        initialize();
        rep(len)build_automata(s[i]-'a');
        cal_occuarence(len);
        int m;
        pf("Case %d:\n",tt++);
        SF(m);
        while(m--)
        {
            sf("%s",s);
            Len = strlen(s);

            PF(magic(0,0,0));
        }

    }
    return 0;
}
/*
2
abcdcabcdacbfefe
8
abcd
dabc
dc
p
ff
acbd
gg
efef
aaaababa
4
bbbb
aaaa
abcdcabcdacbfefe
aa
*/

