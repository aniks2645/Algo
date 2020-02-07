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
typedef pair < ll , pi > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < string > vs;

int tree[2*MM],n;
int a[2*MM];
void update(ll idx, ll val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}
ll query( ll idx )
{
    ll sum = 0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
struct data
{
    int l, r, val, id, t;
};

bool cmp( data a, data b )
{
    if(a.val==b.val) return (a.t>b.t);
    return a.val>b.val;
}

vector < data > v;

int main()
{

    data d;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i] = min(n,a[i]);
        if(a[i]>i)
        {
            d.l = i+1;
            d.r = a[i];
            d.val = i-1;
            d.t = 2;
            v.pb(d);
        }
        d.l = d.r = i;
        d.t = 1;
        d.val = a[i];
        v.pb(d);
    }
    sort(v.begin(),v.end(),cmp);
    ll sum = 0;
    rep(v.size())
    {
        if(v[i].t==1)
        {
            update(v[i].l,1);
        }
        else
        {
            sum += ll(query(v[i].r) - query(v[i].l - 1));
        }
    }
    cout<<sum<<endl;

	return 0;
}

/*

*/
