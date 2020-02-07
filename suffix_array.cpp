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
#define    SFE(a,b)         scanf("%d %d",&a, &b);adj[a].pb(b);adj[b].pb(a);
#define    SFEC(a,b,c)      scanf("%d%d%d",&a,&b,&c);adj[a].pb(b);adj[a].pb(c);adj[b].pb(a)adj[b].pb(c)
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
typedef pair < pi , int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef vector < string > vs;

const int M = 1000005;

struct data
{
    int fc,sc,id,len;
    bool operator<(const data &a)const
    {
        if(fc!=a.fc)
        {
            return fc < a.fc;
        }
        return sc<a.sc;
    }
}suffix[M];
int sp[22][M],lcp[M], step;
string s;

void build_suffix_array()
{
    int n = s.size();
    for(int i=0;i<n;i++) sp[0][i] = s[i];
    step = 1;
    mem(suffix);
    for(int i=1;i<=n;i*=2)
    {
        for(int j=0;j<=n;j++)
        {
            suffix[j].id = j;
            suffix[j].fc = sp[step-1][j];
            suffix[j].sc = (i + j) < n ? sp[step-1][i+j] : -1;
        }
        sort(suffix,suffix+n);
        sp[step][suffix[0].id] = 0;
        for(int k=1;k<n;k++)
        {
            if(suffix[k].fc == suffix[k-1].fc && suffix[k].sc == suffix[k-1].sc)
            {
                sp[step][suffix[k].id] = sp[step][suffix[k-1].id];
            }
            else
            {
                sp[step][suffix[k].id] = k;
            }
        }
        step++;
    }
    lcp[0] = 0;
    int fst,scd;
    for(int i=1;i<n;i++)
    {
        fst = suffix[i-1].id;
        scd = suffix[i].id;
        lcp[i] = 0;
        for(int j = step-1;j>=0 && fst<n && scd <n ;j--)
        {
            if(sp[j][fst] == sp[j][scd])
            {
                lcp[i] += (1<<j);
                fst += (1<<j);
                scd += (1<<j);
            }
        }
    }
}
vector < pi > v;
int idx[M];
int main() {

    I_O;
    cin>>s;
    build_suffix_array();
    int n = s.size();
    int pos;
    rep(n)
    {
        if(suffix[i].id==0)
        {
            pos = i;
        }
        suffix[i].len = n-suffix[i].id;
        idx[suffix[i].len] = i;
    }
    int pre = pos, post = pos;
    for(int i=n-1;i>=1;i--)
    {
        while(pre>=1 && lcp[pre]>=i)pre--;
        while(post<n-1 && lcp[post+1]>=i)post++;
        if(idx[i]>=pre && idx[i]<=post && post-pre+1>2)
        {
            REP(i)cout<<s[j];
            cout<<endl;
            return 0;
        }
    }
    cout<<"Just a legend"<<endl;


    return 0;
}

/*

*/
