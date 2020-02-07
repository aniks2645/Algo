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
#define    SFE(a,b)         scanf("%d %d",&a, &b);adj[a].pb(b);adj[b].pb(a)
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

vector < pi > ways[10000];
vector < pi > v;
int idx;
bool check(pi p, pi q)
{
    if(p.first==q.first || p.second==q.second)return false;
    if(p.first+p.second==q.first+q.second)return false;
    if((p.first-q.first)==(p.second-q.second))return false;
    return true;
}
void back_track(int id)
{
    if(id==8)
    {
        ways[idx++] = v;
        return;
    }
    for(int i=0;i<8;i++)
    {
        bool flg = 0;
        for(auto x:v)
        {
            if(!check(x,{id,i}))
            {
                flg = 1;
                break;
            }
        }
        if(!flg)
        {
            v.pb({id,i});
            back_track(id+1);
            v.pop_back();
        }
    }
}
int dp[12][1<<8];
int vis[12][1<<8],cur;
int dpcall(int id, int ix, int mask)
{
    if(mask+1==1<<8)return 0;
    int &ret = dp[ix][mask];
    if(vis[ix][mask]==cur)return ret;
    vis[ix][mask] = cur;
    ret = MAX;
    rep(8)
    {
        int pos = (bool)(mask & 1<<i);
        if(pos)continue;
        pi p = ways[id][i];
        pi q = v[ix];
        if(p==q)
        {
            ret = min(ret,dpcall(id,ix+1,mask | 1<<i));

        }
        else if(!check(p,q))
        {
            ret = min(ret,1+dpcall(id,ix+1,mask | 1<<i));
        }
        else
        {
            ret = min(ret,2+dpcall(id,ix+1,mask | 1<<i));
        }
    }
    return ret;

}
int main() {


    back_track(0);
    int t,tt=1;
    SF(t);
    while(t--)
    {
        char s[20];
        v.clear();
        rep(8)
        {
            sf("%s",s);
            REP(8)
            {
                if(s[j]=='q')v.pb({i,j});
            }
        }
        int mx = MAX;
        rep(92)
        {
            cur++;
            mx = min(mx,dpcall(i,0,0));
        }
        pc();
        PF(mx);
    }



    return 0;
}
/*

*/
