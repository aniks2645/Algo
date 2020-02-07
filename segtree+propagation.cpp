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
ll sum[2][MM], prop[2][MM];

ll a[MM];
void propagate(int l, int r, int k, int tp)
{
    if(l!=r)
    {
        prop[tp][k*2] += prop[tp][k];
        prop[tp][k*2+1] += prop[tp][k];
    }
    sum[tp][k] += prop[tp][k];
    prop[tp][k] = 0;
}
void update(int l, int r, int k, int L, int R, ll val, int tp)
{
    if(l>R || r<L || l>r)return;
    propagate(l,r,k,tp);
    if(l>=L && r<=R)
    {
        prop[tp][k] = val;
        propagate(l,r,k,tp);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,k*2,L,R,val,tp);
    update(mid+1,r,k*2+1,L,R,val,tp);
    sum[tp][k] = max(sum[tp][k*2] , sum[tp][k*2+1]);
}

ll query(int l, int r, int k, int L, int R, int tp)
{
    if(l>R || r<L)return -MAX;
    propagate(l,r,k,tp);
    if(l>=L && r<=R)return sum[tp][k];
    int mid = (l+r)/2;
    return max(query(l,mid,k*2,L,R,tp),query(mid+1,r,k*2+1,L,R,tp));
}
ll cum[MM];
int main() {

    I_O;

    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(n*4+2)
        {
            sum[0][i] = 0;
            sum[1][i] = 0;
            prop[0][i] = 0;
            prop[1][i] = 0;
            cum[i] = 0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            cum[i] = cum[i-1] + a[i];
        }
        for(int i=1;i<=n;i++)
        {
            update(1,n,1,1,i,a[i],0);
            update(1,n,1,i,n,a[i],1);
        }
//        for(int i=1;i<=n;i++)
//        {
//            ll an = query(1,n,1,i,i,0);
//            ll ann = query(1,n,1,i,i,1);
//            cout<<an<<" "<<ann<<endl;
//        }
        int m;
        cin>>m;
        while(m--)
        {
            int xx,yy,x,y;
            cin>>x>>y>>xx>>yy;
            if(xx<=y) xx = y;
            ll tot = 0;
            if(y+1<=xx-1) tot += cum[xx-1] - cum[y];

            ll dl = 0;
            if(y+1<=n)
            {
                dl = query(1,n,1,y+1,y+1,0);
            }
            update(1,n,1,1,y,-dl,0);
            update(1,n,1,1,x-1,-1e15,0);

            ll ans = query(1,n,1,1,y,0);

            update(1,n,1,1,x-1,1e15,0);
            update(1,n,1,1,y,dl,0);

            dl = 0;
            if(xx-1>=1)
            {
                dl = query(1,n,1,xx-1,xx-1,1);
            }
            update(1,n,1,xx,n,-dl,1);
            update(1,n,1,yy+1,n,-1e15,1);

            ll anss = query(1,n,1,xx,n,1);

            update(1,n,1,yy+1,n,1e15,1);
            update(1,n,1,xx,n,dl,1);

            ll nw = 0;
            if(y==xx) nw = a[y];
            cout<<ans<<" "<<anss<<" "<<tot<<" "<<nw<<endl;
            cout<<ans+anss+tot-nw<<endl;
//            if(y==xx)
//            {
//            }
//            else
//            {
//                ll tot = 0;
//                if(y+1<=xx-1) tot += cum[xx-1] - cum[y];
//                update(1,n,1,1,x-1,-1e15,0);
//                ll ans = query(1,n,1,1,y,0);
//                update(1,n,1,1,x-1,1e15,0);
//
//
//                update(1,n,1,yy+1,n,-1e15,1);
//                ll anss = query(1,n,1,y,n,1);
//                update(1,n,1,yy+1,n,1e15,1);
//                cout<<ans<<" "<<anss<<" "<<tot<<endl;
//                cout<<ans+anss+tot<<endl;
//            }
        }

    }


    return 0;
}
/*


2
6
3 -2 1 -4 5 2
2
1 3 2 5
1 1 2 3
1 1
1
1 1 1 1





*/

