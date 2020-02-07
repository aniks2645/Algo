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
int   root[MM*10];
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
ll query(int mnode, int nnode, int now, int mask) /// to find max xor within range respect to mask.
{
    if(now==-1)return 0;

    int pos = (bool)(1LL<<now & mask);

    if(pos)
    {
        if((sum[sum[nnode].l].val-sum[sum[mnode].l].val)>0)
        {
            return (1LL<<now) + query(sum[mnode].l,sum[nnode].l,now-1,mask);
        }
        else
        {
            return query(sum[mnode].r,sum[nnode].r,now-1,mask);
        }
    }
    else
    {
        if((sum[sum[nnode].r].val-sum[sum[mnode].r].val)>0)
        {
            return (1LL<<now) + query(sum[mnode].r,sum[nnode].r,now-1,mask);
        }
        else
        {
            return query(sum[mnode].l,sum[nnode].l,now-1,mask);
        }
    }
}

ll queryy(int mnode, int nnode, int now, ll mask) /// count numbers within range less/equal to mask
{
    if(now==-1)return sum[nnode].val-sum[mnode].val;

    int pos = (1LL<<now & mask);
    int lcnt = sum[sum[nnode].l].val-sum[sum[mnode].l].val;
    int rcnt = sum[sum[nnode].r].val-sum[sum[mnode].r].val;
    if(pos && rcnt>0)
    {
        return lcnt + queryy(sum[mnode].r,sum[nnode].r,now-1,mask);
    }
    else if(!pos && lcnt>0)
    {
        return queryy(sum[mnode].l, sum[nnode].l,now-1,mask);
    }
    return lcnt;
}

ll queryyy(int mnode, int nnode, int now, int k) /// find kth element in sorted order within a range
{
    if(now==-1)return 0;
    int lcnt = sum[sum[nnode].l].val-sum[sum[mnode].l].val;
    int rcnt = sum[sum[nnode].r].val-sum[sum[mnode].r].val;
    if(lcnt>=k)
    {
        return queryyy(sum[mnode].l,sum[nnode].l,now-1,k);
    }
    else
    {
        return (1LL<<now) + queryyy(sum[mnode].r,sum[nnode].r,now-1,k-lcnt);
    }
}

int main()
{

    I_O;
    int n = 0, m, mbit = 22;
    cin>>m;
    rep(m)
    {
        int typ;
        cin>>typ;
        if(typ==0)
        {
            int a;
            cin>>a;
            ++n;
            root[n] = update(root[n-1],mbit,a,1);
        }
        else if(typ==1)
        {
            int l, r, y;
            cin>>l>>r>>y;
//            cout<<i+1<<" query 1: "<<n<<" -> ";
            ll mxor = query(root[l-1],root[r],mbit,y);
            cout<<(y ^ mxor)<<"\n";
        }
        else if(typ==2)
        {
            int k;
            cin>>k;
            n = n - k;
        }
        else if(typ==3)
        {
            int l,r,x;
            cin>>l>>r>>x;
//            cout<<i+1<<" query 3: "<<n<<" -> ";
            cout<<queryy(root[l-1],root[r],mbit,x)<<"\n";
            //
        }
        else if(typ==4)
        {
            int l,r,k;
            cin>>l>>r>>k;
//            cout<<i+1<<" query 4: "<<n<<" -> ";
            cout<<queryyy(root[l-1],root[r],mbit,k)<<"\n";
            //
        }
    }


    return 0;
}
/*
10
0 8
4 1 1 1
0 2
1 2 2 7
1 2 2 7
0 1
3 2 2 2
1 1 2 3
3 1 3 5
0 6

Type 0: Add the integer number x at the end of the array.
Type 1: On the interval L..R find a number y, to maximize (x xor y).
Type 2: Delete last k numbers in the array
Type 3: On the interval L..R, count the number of integers less than or equal to x.
Type 4: On the interval L..R, find the kth smallest integer (kth order statistic).
*/
