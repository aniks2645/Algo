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

vector < string > v;
string s,p;
vector < pi > usr[105];
int slv[105];
int penalty[105];
vector < int > fpenalty[105];
int F[105][5005];
vector<int> team;
map < string  , int > mp;
ll dp[105][5005], vis[105][5005],cur,Sz;
int pcl[5005];
void clr()
{
    mp.clear();
    team.clear();
    v.clear();

    for(int i=0;i<=102;i++)
    {
        usr[i].clear();
        fpenalty[i].clear();
    }
}
ll dpcall(int id, int mask)
{
    if(id==Sz)return 1;
    ll &ret = dp[id][mask];
    if(vis[id][mask]==cur)return ret;
    vis[id][mask] = cur;
    ret = 0;
    ll tot = 0, pn = 0;
    if(id==0)
    {
        tot = 14;
    }
    else
    {
        int nw = team[id-1];
        tot = slv[nw] + pcl[mask];
        pn = penalty[nw] + F[nw][mask];
    }
    int nw = team[id];
    int N = fpenalty[nw].size();
    int msk = (1<<N)-1;
    int slvnw = slv[nw];
    int penalnw = penalty[nw];
    for(int i=msk;i>=0;i = (i-1)&msk)
    {
        int cn = pcl[i];
        int sm = F[nw][i];
        if(cn+slvnw<tot)
        {
            ret += dpcall(id+1,i);
            ret %= MOD;
        }
        else if(cn+slvnw==tot && sm+penalnw>=pn)
        {
            ret += dpcall(id+1,i);
            ret %= MOD;
        }

        if(i==0)break;
    }
    return ret;

}
int main() {

    I_O;
    for(int i=0;i<(1<<12);i++)
    {
        pcl[i] = __builtin_popcount(i);
    }
    int t,tt=1;
    cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n>>m;
        getline(cin,s);
        for(int i=0;i<1+(n+1)*2;i++)
        {
            getline(cin,s);
            if(i%2 && i!=1)v.pb(s);

        }
        int id = 0;
        for(auto x:v)
        {
            int sz = x.size();
            bool flg = 0;
            for(int i=0;i<sz;i++)
            {
                if(!flg)
                {
                    if(x[i]==' ')
                    {
                        x[i] = '#';
                        flg = 1;
                    }
                }
                if(x[i]=='|')x[i] = ' ';
            }
            stringstream ss(x);
            ss>>p;
            mp[p] = id;
            ss>>p;
            sz = p.size();
            for(int i=0;i<sz;i++)if(p[i]==47)p[i] = ' ';
            stringstream pp(p);
            int tot,pen;
            pp>>tot>>pen;
            slv[id] = tot;
            penalty[id] = pen;
            while(ss>>p)
            {
                if(p[0]!='?')continue;
                p[0] = ' ';
                int sz = p.size();
                for(int i=0;i<sz;i++)
                {
                    if(p[i]==47)p[i] = ' ';
                }
                stringstream pp(p);
                pp>>tot>>pen;
                usr[id].pb({tot,pen});
            }
            id++;

        }
        for(int i=0;i<id;i++)
        {
            for(auto x:usr[i])
            {
                fpenalty[i].pb(20*(x.first-1) + x.second);
            }

        }

        mem(F);
        for(int i=0;i<id;i++)
        {
            int N = fpenalty[i].size();
            for(int j=0;j<N;j++)
            {
                F[i][1<<j] = fpenalty[i][j];
            }
            for(int j = 0;j < N; ++j)
            {
                for(int mask = 0; mask < (1<<N); ++mask)
                {
                    if(mask & (1<<j))
                    {
                        F[i][mask] += F[i][mask^(1<<j)];
                    }
                }
            }

        }
        getline(cin,s);

        for(int j=0;j<n+2;j++)
        {
            getline(cin,s);
            if(s[1]=='-')continue;
            int sz = s.size();
            bool flg = 0;
            for(int i=0;i<sz;i++)
            {
                if(!flg)
                {
                    if(s[i]==' ')
                    {
                        s[i] = '#';
                        flg = 1;
                    }
                }
                if(s[i]=='|')s[i] = ' ';
            }
            stringstream ss(s);
            ss>>p;
            team.pb(mp[p]);

        }
        Sz = team.size();
        cur++;
        cout<<"Case "<<tt++<<": ";
        cout<<dpcall(0,0)<<"\n";;
        clr();
    }





    return 0;
}
/*
1
3 4
|--------------------|-------|-------|-------|-------|-------|
|Team Name           |Total  |A      |B      |C      |D      |
|--------------------|-------|-------|-------|-------|-------|
|Team X              |2/330  |?10/255|0/--   |1/10   |5/240  |
|--------------------|-------|-------|-------|-------|-------|
|Team Y              |2/330  |5/230  |0/--   |1/20   |?5/270 |
|--------------------|-------|-------|-------|-------|-------|
|Team Z              |1/30   |-4/--  |1/30   |?1/241 |?1/245 |
|--------------------|-------|-------|-------|-------|-------|

|--------------------|
|Team Z              |
|Team X              |
|Team Y              |
|--------------------|
*/
