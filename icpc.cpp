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

///*
//FUNCTION//
ll bigmod(ll a, ll b, ll c)
{
    if(b==0)return 1%c;ll x=bigmod(a,b/2,c);x=(x*x)%c;
    if(b%2==1)x=(x*a)%c;return x;
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

///DATA STRUCTURE:

/// BIT
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

///PERSISTENT SEGMENT TREE
const int M = MM*80;
int  a[MM], root[MM];
int avail;
struct data
{
    int l, r, val;
    data()
    {
        l = r = val = 0;
    }
};
data sum[M];
int update(int PreNode, int l, int r, int L, int val)
{
    int NewNode = ++avail;
    if(l==r)
    {
        sum[NewNode].val = val;
        ///sum[NewNode].val = sum[PreNode].val + val;
        return NewNode;
    }
    int mid = (l+r)/2;
    if(L<=mid)
    {
        sum[NewNode].r = sum[PreNode].r;
        sum[NewNode].l = update(sum[PreNode].l,l,mid,L,val);
    }
    else
    {
        sum[NewNode].l = sum[PreNode].l;
        sum[NewNode].r = update(sum[PreNode].r,mid+1,r,L,val);
    }
    sum[NewNode].val = sum[sum[NewNode].l].val + sum[sum[NewNode].r].val;
    return NewNode;
}

ll query(int n, int l, int r, int k)
{
    if(l==r)
    {
        return l;
    }
    int mid = (l+r)/2;
    if(sum[sum[n].l].val>=k)
    {
        return query(sum[n].l,l,mid,k);
    }
    else
    {
        return query(sum[n].r,mid+1,r,k-sum[sum[n].l].val);
    }
}
int idx[MM];
int main()
{

    I_O;
    int n;
    cin>>n;
    rep(n)cin>>a[i+1];
    a[n+1] = MM-2;
    n++;
    int rt;
    for(int i=n;i>=1;i--)
    {
        if(idx[a[i]])
        {
            root[i] = update(root[i+1],1,n,idx[a[i]],0);
            root[i] = update(root[i],1,n,i,1);
        }
        else
        {
            root[i] = update(root[i+1],1,n,i,1);
        }
        idx[a[i]] = i;

    }
    for(int k=1;k<n;k++)
    {
        int x = 1, ans=0;
        while(x<n)
        {
           x = query(root[x],1,n,k+1);
           ans++;
        }
        cout<<ans<<" ";
    }
    cout<<endl;


    return 0;
}

///2D SEGMET TREE
const int M =4*500 + 5;
ll sum[M][M], a[M][M], n,m;
ll fun(ll x, ll y)
{
    return max(x,y);
}
void column_build(int r1, int r2, int k1, int c1, int c2, int k2)
{
    if(c1==c2)
    {
        if(r1==r2)
        {
            sum[k1][k2] = a[r1][c1];
            return;
        }
        sum[k1][k2] = fun(sum[k1*2][k2],sum[k1*2+1][k2]);
        return;
    }
    int mid = (c1+c2)/2;
    column_build(r1,r2,k1,c1,mid,k2*2);
    column_build(r1,r2,k1,mid+1,c2,k2*2+1);
    sum[k1][k2] = fun(sum[k1][k2*2],sum[k1][k2*2+1]);

}
void build(int r1, int r2, int k1)
{
    if(r1==r2)
    {
        column_build(r1,r2,k1,1,m,1);
        return;
    }
    int mid = (r1+r2)/2;
    build(r1,mid,k1*2);
    build(mid+1,r2,k1*2+1);
    column_build(r1,r2,k1,1,m,1);
}
ll column_query(int id, int l, int r, int k, int L, int R)
{
    if(l>R || r<L) return -MAX;
    if(l>=L && r<=R)
    {
        return sum[id][k];
    }
    int mid = (l+r)/2;
    return fun(column_query(id,l,mid,k*2,L,R),column_query(id,mid+1,r,k*2+1,L,R));
}

ll query(int l,int r,int k, int L, int R, int c1, int c2)
{
    if(l>R || r<L) return -MAX;
    if(l>=L && r<=R)
    {
        return column_query(k,1,m,1,c1,c2);
    }
    int mid = (l+r)/2;
    return fun(query(l,mid,k*2,L,R,c1,c2),query(mid+1,r,k*2+1,L,R,c1,c2));
}
int main() {

    int t,tt=1;
    ll q;
    SF(t);
    while(t--)
    {
        SFL2(n,q);
        m = n;
        rep(n)REP(m)SFL(a[i+1][j+1]);
        build(1,n,1);
        int x,y,x1,y1,k;
        pf("Case %d:\n",tt++);
        while(q--)
        {
            SF3(x,y,k);
            x1 = x+k-1;
            y1 = y+k-1;
            PFL(query(1,n,1,x,x1,y,y1));
        }
    }
    return 0;
}
///HISTOGRAM USING STACK
ll a[100005];

stack < int > stq;
int main()
{
    int t,tt=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        ll res = -1;
        ll i;
        for(i=0;i<n;i++)
        {
            if(stq.empty())
            {
                stq.push(i);
            }
            else
            {
                if(a[stq.top()]<a[i])
                {
                    stq.push(i);
                }
                else
                {
                    while(stq.size() && a[stq.top()]>a[i])
                    {
                        int tp = stq.top();
                        stq.pop();
                        if(stq.empty())
                        {
                            ll area = a[tp] * i;
                            res = max(area,res);
                        }
                        else
                        {
                            ll area = a[tp] * (i-stq.top()-1);
                            res = max(area,res);
                        }
                    }
                    stq.push(i);
                }
            }
        }
        while(stq.size())
        {
            int tp = stq.top();
            stq.pop();
            if(stq.empty())
            {
                ll area = a[tp] * i;
                res = max(area,res);
            }
            else
            {
                ll area = a[tp] * (i-stq.top()-1);
                res = max(area,res);
            }
        }
        printf("Case %d: %lld\n",tt++, res);
    }

    return 0;
}
///Sparse Table
int a[MM*3],sp[20][MM*3], lg[MM*3],n,spp[20][MM*3];

void logcal()
{
    int cnt = 0;
    int p = 2;
    while(p<=300000)
    {
        lg[p] = 1;
        p *= 2;
    }
    for(int i=0;i<=300000;i++)
    {
        if(lg[i])
        {
            cnt++;
        }
        lg[i] = cnt;
    }
}
pi query(int l, int r)
{
    int ln = lg[r-l+1];
    int k = 1<<ln;
    int df = r-l+1-k;
    int mn = min(sp[ln][l],sp[ln][l+df]);
    int gc = __gcd(spp[ln][l],spp[ln][l+df]);
    return {mn,gc};
}

void build()
{
    for(int i=1;i<=n;i++)
    {
        sp[0][i] = a[i];
        spp[0][i] = a[i];
    }
    for(int i=1;(1<<i)<=n;i++)
    {
        for(int j=1;j+(1<<i)<=n+1;j++)
        {
            sp[i][j] = min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
            spp[i][j] = __gcd(spp[i-1][j],spp[i-1][j+(1<<(i-1))]);
        }
    }
}
///MO'S
struct data
{
    ll l,r,id,sq;
};
data d[50010];
bool cmp( data a, data b )
{
    if(a.sq==b.sq) return a.r<b.r;
    return a.sq<b.sq;

}
ll a[MM],freq[MM],sum[MM],res[MM];
int main()
{

    int t, tt=1;

    SF(t);
    while(t--)
    {
        int n,c,q;
        mem(sum);
        mem(freq);
        SF3(n,c,q);
        rep(n)SF(a[i+1]);
        ll sqr = sqrt(n);
        rep(q)
        {
            SFL2(d[i].l,d[i].r);
            d[i].id = i;
            d[i].sq = d[i].l/sqr;
        }
        //
        sort(d,d+q,cmp);
        ll rt = 1,lf = 1, mx=1;
        freq[a[lf]]++;
        sum[mx]++;
        rep(q)
        {
            while(lf>d[i].l)
            {
                lf--;
                sum[freq[a[lf]]]--;
                freq[a[lf]]++;
                sum[freq[a[lf]]]++;
                mx = max(mx,freq[a[lf]]);
                //
            }
            while(lf<d[i].l)
            {

                sum[freq[a[lf]]]--;
                freq[a[lf]]--;
                sum[freq[a[lf]]]++;
                if(!sum[mx]) mx--;
                lf++;
                //
            }
            while(rt<d[i].r)
            {
                rt++;
                sum[freq[a[rt]]]--;
                freq[a[rt]]++;
                sum[freq[a[rt]]]++;
                mx = max(mx,freq[a[rt]]);

                //
            }
            while(rt>d[i].r)
            {
                sum[freq[a[rt]]]--;
                freq[a[rt]]--;
                sum[freq[a[rt]]]++;
                if(!sum[mx]) mx--;
                rt--;
                //
            }
            res[d[i].id] = mx;
        }
        pf("Case %d:\n",tt++);
        rep(q)
        {
            PFL(res[i]);
        }
    }


    return 0;
}
///HLD+LAZY
const int M = MM;
vi adj[M];
int cost[M],n,idx[M],sbsz[M],spcd[M],chain[M],head[M],par[M],sum[4*M],lvl[M],id,a[M],clr, lst[M], prop[M*4];

int maxx(int x,int y){return max(x,y);}
int dfs(int x, int p, int level)
{
    par[x] = p;//parent store
    lvl[x] = level;//level store
    int sz = adj[x].size();
    sbsz[x] = 1;
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        sbsz[x] += dfs(y,x,level+1); // subtree size calculate
    }
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        if(sbsz[y]>sbsz[spcd[x]])
        {
            spcd[x] = y; // find special child
        }
    }
    return sbsz[x];
}

void decompose(int x, int p)
{
    ++id;
    idx[x] = id;
    chain[x] = clr;
    if(sbsz[x]==1)
    {
        lst[x] = id;
        return;
    }
    decompose(spcd[x],x);
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || y==spcd[x])continue;
        ++clr;
        head[clr] = y;
        decompose(y,x);
    }
    lst[x] = id;
}

void propagate(int l,int r, int k)
{
    if(l!=r)
    {
        prop[k*2] += prop[k];
        prop[k*2+1] += prop[k];
    }
    sum[k] += prop[k];
    prop[k] = 0;
}
void update(int l, int r, int k, int L, int R, int val)
{
    propagate(l,r,k);
    if(l>R || r<L)return;
    if(l>=L && r<=R)
    {
        prop[k] = val;
        propagate(l,r,k);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,k*2,L,R,val);
    update(mid+1,r,k*2+1,L,R,val);
    sum[k] = maxx(sum[k*2],sum[k*2+1]);
}
int query(int l, int r, int k, int L, int R)
{
    propagate(l,r,k);
    if(l>R || r<L)return -MAX;
    if(l>=L && r<=R)return sum[k];
    int mid = (l+r)/2;
    int p = query(l,mid,k*2,L,R);
    int q = query(mid+1,r,k*2+1,L,R);
    return maxx(p,q);
}
int process(int u, int v)
{
    if(chain[u]==chain[v])
    {
        if(lvl[u]>lvl[v])
        {
            int tm = u;
            u = v;
            v = tm;
        }
        return query(1,id,1,idx[u],idx[v]);
    }
    if(lvl[head[chain[u]]]>lvl[head[chain[v]]])
    {
        int mn = query(1,id,1,idx[head[chain[u]]],idx[u]);
        return maxx(mn,process(par[head[chain[u]]],v));
    }
    else
    {
        int mn = query(1,id,1,idx[head[chain[v]]],idx[v]);
        return maxx(mn,process(par[head[chain[v]]],u));
    }
}
int main() {

    SF(n);
    int u,v,c;

    rep(n-1)
    {
        SF2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    head[0] = 1;
    dfs(1,0,0);
    decompose(1,0);
    int q;
    SF(q);
    char s[20];
    while(q--)
    {
        int typ;
        scanf("%s", s);
        if(s[0]=='a')
        {
            int k;
            SF(k);
            SF(c);
            update(1,id,1,idx[k],lst[k],c);
        }
        else
        {
            SF2(u,v);
            PF(process(u,v));
        }
    }
    return 0;
}
///HLD ICPC 2018
const int M = MM;
vi adj[M];
int cost[M],n,idx[M],sbsz[M],spcd[M],chain[M],head[M],par[M];
int sum[4*M],lvl[M],id,a[M],clr, lst[M], prop[M*4];
int summ[4*M];

int dfs(int x, int p, int level)
{
    par[x] = p;//parent store
    lvl[x] = level;//level store
    int sz = adj[x].size();
    sbsz[x] = 1;
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        sbsz[x] += dfs(y,x,level+1); // subtree size calculate
    }
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        if(sbsz[y]>sbsz[spcd[x]])
        {
            spcd[x] = y; // find special child
        }
    }
    return sbsz[x];
}

void decompose(int x, int p)
{
    ++id;
    idx[x] = id;
    chain[x] = clr;
    if(sbsz[x]==1)
    {
        lst[x] = id;
        return;
    }
    decompose(spcd[x],x);
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || y==spcd[x])continue;
        ++clr;
        head[clr] = y;
        decompose(y,x);
    }
    lst[x] = id;
}

void propagate(int l,int r, int k)
{
    if(l!=r)
    {
        prop[k*2] += prop[k];
        prop[k*2+1] += prop[k];
    }
    sum[k] += prop[k];
    summ[k] += prop[k];
    prop[k] = 0;
}
void update(int l, int r, int k, int L, int R, int val)
{
    propagate(l,r,k);
    if(l>R || r<L)return;
    if(l>=L && r<=R)
    {
        prop[k] = val;
        propagate(l,r,k);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,k*2,L,R,val);
    update(mid+1,r,k*2+1,L,R,val);
    sum[k] = max(sum[k*2],sum[k*2+1]);
    summ[k] = min(summ[k*2],summ[k*2+1]);
}

int ex_query(int l, int r, int k, int L, int R, int kk)
{
    propagate(l,r,k);
//    cout<<l<<" "<<r<<endl;
//    cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(l>R || r<L || sum[k]<kk)return 0;
    if(l>=L && r<=R && sum[k]==kk && summ[k]==kk)return r-l+1;
    int mid = (l+r)/2;
    int p = ex_query(l,mid,k*2,L,R,kk);
    int q = ex_query(mid+1,r,k*2+1,L,R,kk);
    return p+q;
}
int process(int u, int v, int kk)
{
    if(chain[u]==chain[v])
    {
        if(lvl[u]>lvl[v])
        {
            int tm = u;
            u = v;
            v = tm;
        }
        return ex_query(1,id,1,idx[u],idx[v],kk);
    }
    if(lvl[head[chain[u]]]>lvl[head[chain[v]]])
    {
        int mn = ex_query(1,id,1,idx[head[chain[u]]],idx[u],kk);
        return mn+process(par[head[chain[u]]],v,kk);
    }
    else
    {
        int mn = ex_query(1,id,1,idx[head[chain[v]]],idx[v],kk);
        return mn+process(par[head[chain[v]]],u,kk);
    }

}
void update_hld(int u, int v, int val)
{
    if(chain[u]==chain[v])
    {
        if(lvl[u]>lvl[v])
        {
            int tm = u;
            u = v;
            v = tm;
        }
        update(1,id,1,idx[u],idx[v],val);
        return;
    }
    if(lvl[head[chain[u]]]>lvl[head[chain[v]]])
    {
        update(1,id,1,idx[head[chain[u]]],idx[u],val);
        update_hld(par[head[chain[u]]],v,val);
    }
    else
    {
        update(1,id,1,idx[head[chain[v]]],idx[v],val);
        update_hld(par[head[chain[v]]],u,val);
    }
}
int Lf[55],Rt[55];
int main() {

    int t,tt=1;
    SF(t);
    while(t--)
    {


        SF(n);
        int u,v,c;

        rep(n-1)
        {
            SF2(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        head[0] = 1;
        dfs(1,0,0);
        decompose(1,0);
        int q;
        SF(q);
        pf("Case %d:\n",tt++);
        while(q--)
        {

            int k;
            SF(k);
            rep(k-1)
            {
                SF2(Lf[i],Rt[i]);
                update_hld(Lf[i],Rt[i],1);
            }
            int l,r;
            SF2(l,r);
            int tot = process(l,r,k-1);
            printf("%d\n",tot);
            rep(k-1)
            {
                update_hld(Lf[i],Rt[i],-1);
            }
        }
        rep(n+3)
        {
            adj[i].clear();
            sbsz[i] = spcd[i] = chain[i] = head[i] = lvl[i] = 0;
        }
        id = clr = 0;
        rep(n*4)prop[i] = sum[i] = summ[i] = 0;
    }
    return 0;
}

///HEAVY LIGHT TRICKS
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

///Centroid Decomposition Xenia & Tree
const int M = MM;
vi adj[M];
int sbz[M],parent[M],vis[M],lvl[M];
int mp[20][M];
void find_size(int p, int x)
{
    sbz[x] = 1;
    int sz = adj[x].size();
    int y;
    rep(sz)
    {
        y = adj[x][i];
        if(p==y || vis[y])continue;
        find_size(x,y);
        sbz[x] += sbz[y];
    }
}
ll find_center(int p, int x, int l)
{
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        if(sbz[y]>l/2)
        {
            return find_center(x,y,l);
        }
    }
    return x;
}

void cal_dis(int p, int x, ll cost, ll cntr)
{
    mp[cntr][x] = cost;
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y] || y==p)continue;
        cal_dis(x,y,cost+1,cntr);
    }
}

void decompose(int p, int x, int lev)
{
    find_size(p,x);
    x = find_center(p,x,sbz[x]);
    vis[x] = 1;
    rep(adj[x].size())
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        cal_dis(x,y,1,lev);
    }
    parent[x] = p;
    lvl[x] = lev;
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y])continue;
        decompose(x,y,lev+1);
    }
}

///Result part

ll res[M][2];
void init(int n)
{
    rep(n)res[i+1][0] = MAX;
}
void update_centroid(int p, int x)
{
    if(p==0)return;
    int dist = mp[lvl[p]][x];
    if(res[p][0]>dist)
    {
        res[p][0] = dist;
        res[p][1] = x;
    }
    update_centroid(parent[p],x);
}

ll query_centroid(int p, int x)
{
    if(p==0)return MAX;
    int dist = mp[lvl[p]][x];
    return min(dist+res[p][0],query_centroid(parent[p],x));
}
int main() {

    I_O;
    int n,m;
    SF2(n,m);
    int u,v;
    rep(n-1)
    {
        SF2(u,v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    decompose(0,1,0);
    init(n);
    update_centroid(1,1);
    int t;
    rep(m)
    {
        SF2(t,u);
        if(t==1)
        {
            update_centroid(u,u);
        }
        else
        {
            PFL(query_centroid(u,u));
        }
    }
    return 0;
}
///Centroid GCD Counting
///GCD counting
const int M = MM*2;
vi adj[M];

///Centroid part
int sbz[M],parent[M],vis[M];

void find_size(int p, int x)
{
    sbz[x] = 1;
    int sz = adj[x].size();
    int y;
    rep(sz)
    {
        y = adj[x][i];
        if(p==y || vis[y])continue;
        find_size(x,y);
        sbz[x] += sbz[y];
    }
}
ll find_center(int p, int x, int l)
{
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        if(sbz[y]>l/2)
        {
            return find_center(x,y,l);
        }
    }
    return x;
}
ll val[M],res[M];
set < int > st;
int frq[M];
void update(int p, int x, int gcd)
{
    st.insert(gcd);
    frq[gcd]++;
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        update(x,y,__gcd((ll)gcd,val[y]));
    }
}
void dfs(int p, int x,int cntr, int gcd)
{
    int sz = adj[x].size();
    res[gcd]++;
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        int gcc = __gcd((ll)gcd,val[y]);
        for(auto ss: st)
        {
            int gc = __gcd(gcc,ss);
            res[gc] += frq[ss];
        }
        dfs(x,y,cntr,gcc);
        if(x==cntr)
        {
            update(x,y,gcc);
        }
    }
}
void resett()
{
    for(auto x : st)
    {
        frq[x] = 0;
    }
    st.clear();
}

void decompose(int p, int x)
{
    find_size(p,x);
    x = find_center(p,x,sbz[x]);
    vis[x] = 1;
    dfs(p,x,x,val[x]);
    resett();
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y] )continue;
        decompose(x,y);
    }
}

///Centroid Decomposition (All pair distance) - Binary Lifting
const int M = 2*MM;
vi adj[M],adjj[M];
int sbz[M],parent[M],vis[M],lvl[M],N;
ll mp[22][M];
map < ll , ll > dist[M];
void find_size(int p, int x)
{
    sbz[x] = 1;
    int sz = adj[x].size();
    int y;
    rep(sz)
    {
        y = adj[x][i];
        if(p==y || vis[y])continue;
        find_size(x,y);
        sbz[x] += sbz[y];
    }
}
ll find_center(int p, int x, int l)
{
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        if(sbz[y]>l/2)
        {
            return find_center(x,y,l);
        }
    }
    return x;
}
vector < ll > msl[M],msr[M];
void cal_dis(int p, int x, ll cost, ll cntr)
{
    mp[lvl[cntr]][x] = cost;
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y] || y==p)continue;
        cal_dis(x,y,cost+dist[x][y],cntr);///change
    }
}
void decompose(int p, int x, int lev)
{
    find_size(p,x);
    x = find_center(p,x,sbz[x]);
    parent[x] = p;
    lvl[x] = lev;
    adjj[p].pb(x);
    vis[x] = 1;
    rep(adj[x].size())
    {
        int y = adj[x][i];
        if(y==p || vis[y])continue;
        cal_dis(x,y,dist[x][y],x);///change
    }
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(vis[y])continue;
        decompose(x,y,lev+1);
    }

}
int nnode, lt[M],rt[M];
void make_binary(int p, int x, int l, int r)
{
    if(r-l+1==0)return;
    if(r-l+1==1)
    {
        ///level assign krte hbe

        parent[adjj[p][r]] = x;
        lt[x] = adjj[p][r];

    }
    else if(r-l+1==2)
    {
        ///
        parent[adjj[p][l]] = x;
        lt[x] = adjj[p][l];
        parent[adjj[p][r]] = x;
        rt[x] = adjj[p][r];

    }
    else if(r-l+1==3)
    {
        ///
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        lt[x] = nnode;
        make_binary(p,nnode,l,l+1);
        parent[adjj[p][r]] = x;
        rt[x] = adjj[p][r];
    }
    else
    {
        int mid = (l+r)/2;
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        lt[x] = nnode;
        make_binary(p,nnode,l,mid);
        ++nnode;
        lvl[nnode] = lvl[x];
        parent[nnode] = x;
        rt[x] = nnode;
        make_binary(p,nnode,mid+1,r);
    }
}
void lift_to_binary(int x)
{
    int sz = adjj[x].size();
    make_binary(x,x,0,sz-1);
    for(auto y :adjj[x])
    {
        lift_to_binary(y);
    }
}

void dfs(int p, int x, int lev, int side)
{
    if(x==0)return;
    if(x<=N)
    {
        if(side==1)
        {
            msl[p].pb(mp[lev][x]);
        }
        else
        {
            msr[p].pb(mp[lev][x]);
        }
    }
    dfs(p,lt[x],lev,side);
    dfs(p,rt[x],lev,side);
}
void traverse_binary_tree(int x)
{
    if(x==0)return;
    if(x<=N)
    msl[x].pb(0);
    if(x<=N)
    msr[x].pb(0);
    dfs(x,lt[x],lvl[x],1);
    dfs(x,rt[x],lvl[x],2);
    sort(msl[x].begin(),msl[x].end());
    sort(msr[x].begin(),msr[x].end());
    traverse_binary_tree(lt[x]);
    traverse_binary_tree(rt[x]);

//    cout<<"start ---->"<<endl;
//    cout<<"Node = "<<x<<endl;
//    cout<<"Values are: "<<endl;
//    cout<<"Left: "<<endl;
//    for(auto z:msl[x])cout<<z<<" ";
//    cout<<endl;
//    cout<<"Right: "<<endl;
//    for(auto z:msr[x])cout<<z<<" ";
//    cout<<endl;
//    cout<<"<-----end "<<endl<<endl<<endl;
}
///Result part

ll res;
ll query_centroid(int p, int x, ll sbnd, ll l)
{
    ll ans = 0;
    while(x!=0)
    {
        ll dst = mp[lvl[x]][p];
        if(rt[x]==sbnd && msl[x][0]<=l-dst)
        {
            ll sum = upper_bound(msl[x].begin(),msl[x].end(),l-dst) - msl[x].begin();
            ans += sum;
        }
        if(lt[x]==sbnd && msr[x][0]<=l-dst)
        {
            ll sum = upper_bound(msr[x].begin(),msr[x].end(),l-dst) - msr[x].begin();
            ans += sum;
        }
        sbnd = x;
        x = parent[x];
    }
    ll sum = upper_bound(msl[p].begin(),msl[p].end(),l) - msl[p].begin();
    ans += sum;
    sum = upper_bound(msr[p].begin(),msr[p].end(),l) - msr[p].begin();
    ans += sum;
    ans--;
    return ans;
}
int main() {

    I_O;
    int n,m;
    SF2(n,m);
    N = n;
    nnode = n;
    int u,v;
    ll c;
    rep(n-1)
    {
        SF2(u,v);
        SFL(c);
        adj[u].pb(v);
        adj[v].pb(u);
        dist[u][v] = c;
        dist[v][u] = c;
    }
    decompose(0,1,0);
    lift_to_binary(adjj[0][0]);
    traverse_binary_tree(adjj[0][0]);
    ll l;
    while(m--)
    {
        SF(v);
        SFL(l);
        PFL(query_centroid(v, v, v, l));
    }
    return 0;
}

///STRING

///KMP
const int M = MM*10;
char s[M], p[M];
int n,m,b[M];
void kmpPreprocess()
{
    int i=0, j=-1;
    b[i]=j;
    while (i<m)
    {
        while (j>=0 && p[i]!=p[j]) j=b[j];
        i++; j++;
        b[i]=j;
    }
}
int kmpSearch()
{
    int i=0, j=0;
    int cnt = 0;
    while (i<n)
    {
        while (j>=0 && s[i]!=p[j]) j=b[j];
        i++; j++;
        if (j==m)
        {
            j=b[j];
            cnt++;
        }
    }
    return cnt;
}
int main() {

    I_O;
    int t,tt=1;
    SF(t);
    while(t--)
    {
        scanf("%s",s);
        scanf("%s",p);
        n = strlen(s);
        m = strlen(p);
        kmpPreprocess();
        int ans = kmpSearch();
        pc();
        PF(ans);
    }

    return 0;
}

///DOUBLE_HASH
string s;
string p;
ll sum[MM*10];
ll summ[MM*10];

ll mod = 1e9+9, prime = 13;
ll modd = 1e9+7, primee = 17;

ll pwr[MM*10];
ll mdin[MM*10];

ll pwrr[MM*10];
ll mdinn[MM*10];
ll get_hash(ll n, ll l)
{
    if(l>n)return -1;
    ll tot = sum[n] - sum[n-l];
    if(tot<0)tot+=mod;
    ll mdinv = mdin[n-l];
    tot *= mdinv;
    tot %= mod;
    return tot;
}
ll get_hashh(ll n, ll l)
{
    if(l>n)return -1;
    ll tot = summ[n] - summ[n-l];
    if(tot<0)tot+=modd;
    ll mdinv = mdinn[n-l];
    tot *= mdinv;
    tot %= modd;
    return tot;
}
int main()
{
    I_O;
    pwr[0] = 1;
    pwrr[0] = 1;
    for(int i=1;i<=1000000;i++)
    {
        pwr[i] = (pwr[i-1]*prime)%mod;

        pwrr[i] = (pwrr[i-1]*primee)%modd;
    }
    ll inv1 = mod_inverse(prime,mod);
    ll inv2 = mod_inverse(primee,modd);
    mdin[0] = mdinn[0] = 1;
    for(int i=1;i<=1000000;i++)
    {
        mdin[i] = (inv1*(mdin[i-1]))%mod;
        mdinn[i] = (inv2*(mdinn[i-1]))%modd;
    }
    int n, cnt = 0;
    cin>>n;
    ll mll = 1, mll2=1;
    REP(n)
    {
        cin>>s;
        ll hash_val = 0, ml = 1, cn = 0, mx = 0, ml2 = 1, hash_vall = 0;
        rep(s.size())
        {
            ll nw = s[i];
            hash_val += nw*ml;
            ml *= prime;
            hash_val %= mod;
            ml %= mod;

            hash_vall += nw*ml2;
            ml2 *= primee;
            hash_vall %= modd;
            ml2 %= modd;
            cn++;
            if(hash_val==get_hash(cnt, cn) && hash_vall==get_hashh(cnt,cn))
            {
                mx = cn;
            }
        }
        for(int i=mx;i<s.size();i++)
        {
            ll nw = s[i];
            p.pb(nw);
            cnt++;
            sum[cnt] = sum[cnt-1] + nw*mll;
            sum[cnt] %= mod;
            mll *= prime;
            mll %= mod;

            summ[cnt] = summ[cnt-1] + nw*mll2;
            summ[cnt] %= modd;
            mll2 *= primee;
            mll2 %= modd;
        }
    }
    cout<<p<<"\n";
    return 0;
}

///SUFFIXARRAY n*logn*logn
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

/// TRIE
const int M = MM;
int node[M][53] ,nnode,root;
int isword[MM];
string s;
void initialize( )
{
    root = nnode = 0;
    mem(isword);
    rep(52)
    {
        node[root][i] = -1;
    }
}
int value(char ch)
{
       if(isupper(ch)) return ch-'A';
       return ch-'a'+26;
}
void build()
{
    int l = SZ(s),now;
    now = root;
    rep(l)
    {
        s[i] = value(s[i]);
        if(node[now][s[i]]==-1)
        {
            node[now][s[i]] = ++nnode;
            REP(52)
            {
                node[nnode][j] = -1;
            }

        }
        now = node[now][s[i]];
    }
    isword[now]++;
}
ll query()
{
    int l = SZ(s),now;
    now = root;
    rep(l)
    {
        s[i] = value(s[i]);
        if(node[now][s[i]]==-1) return 0;
        now = node[now][s[i]];
    }
    return isword[now];
}
int main() {

    I_O;
    int n,t,tt=1;
    cin>>t;
    while(t--)
    {
        initialize();
        cin>>n;
        rep(n)
        {
            cin>>s;
            if(s.size()>3) sort(s.begin()+1,s.end()-1);
            build();
        }
        cout<<"Case "<<tt++<<":\n";
        int q;
        cin>>q;
        getline(cin,s);
        string p;
        while(q--)
        {
            ll ans = 1;
            getline(cin,s);
            stringstream ss(s);
            while(ss>>s)
            {
                if(s.size()>3) sort(s.begin()+1,s.end()-1);
                ans *= query();
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}

///AUTOMATA & APPLICATION
const int M = MM;
struct state
{
    int len, link,fpos;
    bool isclone;
    map < char , int > next;
    vector < int > inv_link;
} st[2*M];

int sz, last;
int cnt[2*M];
bool terminal[2*M];

void initialize()
{
    rep(sz+1)
    {
        st[i].next.clear();
        st[i].inv_link.clear();
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

void cal_terminal()
{
    int now = last;
    while(now!=-1)
    {
        terminal[now] = 1;
        now = st[now].link;
    }
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
            if(st[x].link==-1)continue;
            cnt[st[x].link] += cnt[x];
        }
        v[i].clear();
    }
}
ll max_match(int len)
{
    int now = 0;
    int mx = 0;
    rep(len)
    {
        now = st[now].next[s[i]-'a'];
        if( terminal[now] && cnt[now]>=3 )
        {
            mx = max(mx,i+1);
        }
    }
    return mx;
}
void cal_inv_link()
{
    for(int i=1;i<=sz;i++)
    {
        st[st[i].link].inv_link.pb(i);
    }
}
vi res;
///here, now = last_pos of pattern;
void find_occurences(int now)
{
    if(!st[now].isclone)res.pb(st[now].fpos);
    for(auto x : st[now].inv_link)
    {
        find_occurences(x);
    }
}
ll dp[M*2];
ll dist_sub(int n)
{
    if(dp[n]!=-1)return dp[n];
    ll tot = 1;
    for(auto it = st[n].next.begin();it!=st[n].next.end();it++)
    {
        if(it->second==0)continue;
        tot += dist_sub(it->second);
    }
    dp[n] = tot;
    return dp[n];
}
string lcs (string p) {

    int v = 0, l = 0, best = 0, bestpos = 0;
    for (int i = 0; i < p.size(); i++) {
        while (v && !st[v].next.count(p[i]-'a')) {
            v = st[v].link ;
            l = st[v].len ;
        }
        if (st[v].next.count(p[i]-'a')) {
            v = st[v].next[p[i]-'a'];
            l++;
        }
        if (l > best) {
            best = l;
            bestpos = i;
        }
    }
    return p.substr(bestpos - best + 1, best);
}

int lcp[M];
void cal_lcp_array(string s)
{
    int n = s.size();
    initialize();
    for(int i=n-1;i>=0;i--)
    {
        build_automata(s[i]);
        lcp[i+1] = st[st[last].link].len;
    }
}
int main() {

    sf("%s",s);
    initialize();
    int len = strlen(s);
    rep(len)build_automata(s[i]-'a');
    cal_inv_link();
    find_occurences(st[0].next[0]);
    for(auto x:res)cout<<x<<endl;
    return 0;
}
///DUET-I-AUTOMATA
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
///NUMBER THEORY

///Bitwise Seive
const int M = 100000100;
int mask[M/32];
int cnt;
int prime[5761482];
unsigned pcl[5761482];

void bitwise_seive()
{
    int add,x=0;
    prime[x++]=2;
    for(int i = 4; i<M; i+=2) mask[i/32]=(mask[i/32] | 1<<(i%32));
    int sq = sqrt(M);
    ll tot = 0;
    for(int i = 3; i<M; i+=2)
    {
        if(!(bool)(mask[i/32] & (1<<(i%32))))
        {
            prime[x++]=i;
            if(sq>=i)
            {
                add = i*2;
                for(int j = i*i; j<M; j+=add)
                    mask[j/32]=(mask[j/32] | 1<<(j%32)),tot++;
            }
        }

    }
    cnt=x;
    pcl[0] = prime[0];
    for(int i=1;i<cnt;i++) pcl[i] = pcl[i-1] * prime[i];
}
llu solve(int n)
{
    int idx = upper_bound(prime,prime+cnt,n) - prime;
    idx--;
    llu ans = pcl[idx];
    int sq = sqrt(n);
    for(int i=0;prime[i]<=sq;i++)
    {
        llu res = 1;
        ll pm = prime[i];
        while((long long)res*pm*pm<=n)
        {
            res *= pm;
        }
        ans *= res;
    }
    return ans;
}
int main() {

    bitwise_seive();
    int t,tt=1;
    SF(t);
    while(t--)
    {
        int n;
        SF(n);
        pc();
        pf("%u\n",solve(n));
    }

    return 0;
}
///stars and bars
/*
Given K variables, a1,a2,a3…aK and a value N, how many ways can we write
a1+a2+a3…aK=N, where a1,a2,a3…aK are non-negative integers?

heorem: For any pair of positive integers N and K, the number of K-tuples
of non-negative integers whose sum is N is equal to the binomial coefficient
(N+K-1) C (N).
*/
ll fact[MM];
ll a[MM];
int main() {
    I_O;
    fact[0] = 1;
    for(ll i=1;i<=100000;i++)
    {
        fact[i] = fact[i-1]*i;
        fact[i] %= MOD;
    }
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n,m,p,c;
        cin>>n>>m;
        mem(a);
        rep(m)
        {
            cin>>p>>c;
            a[p+1] = c;
        }
        a[0] = 1;
        a[n+1] = n;
        ll res = 1;
        int lst = 0, lval = 1;
        for(int i=1;i<=n+1;i++)
        {
            if(a[i])
            {
                int N = i - lst-1;
                int M = a[i] - lval+1;
                lval  = a[i];
                lst = i;
                if(M<=0)
                {
                    res = 0;
                    break;
                }
                int K = N+M-1;
                int L = N;
                int R = K - L;
                ll tot = (fact[R]*fact[L])%MOD;
                ll ans = fact[K] * mod_inverse(tot,MOD);
                ans %= MOD;
                res *= ans;
                res %= MOD;
            }
        }
        tc();
        cout<<res<<endl;
    }
    return 0;
}

///Miller Rabin prime factorization
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
#define MAXL (50000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))

int mark[MAXL];
int P[50000], Pt = 0;
void sieve() {
    register int i, j, k;
    SET(1);
    int n = 46340;
    for (i = 2; i <= n; i++) {
        if (!GET(i)) {
            for (k = n/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
            P[Pt++] = i;
        }
    }
}
long long mul(ull a, ull b, ull mod) {
    long long ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    }
    return ret;
}
void exgcd(ll x, ll y, ll &g, ll &a, ll &b) {
    if (y == 0)
        g = x, a = 1, b = 0;
    else
        exgcd(y, x%y, g, b, a), b -= (x/y) * a;
}
ll llgcd(ll x, ll y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    ll t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}
long long inverse(ll x, ll p) {
    ll g, b, r;
    exgcd(x, p, g, r, b);
    if (g < 0)	r = -r;
    return (r%p + p)%p;
}
ll mpow(ll x, ll y, ll mod) { // mod < 2^32
    ll ret = 1;
    while (y) {
        if (y&1)
            ret = (ret * x)%mod;
        y >>= 1, x = (x * x)%mod;
    }
    return ret % mod;
}
ll mpow2(ll x, ll y, ll mod) {
    ll ret = 1;
    while (y) {
        if (y&1)
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}
int isPrime(ll p) { // implements by miller-babin
    if (p < 2 || !(p&1))	return 0;
    if (p == 2)				return 1;
    ll q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))	q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);

        for (int i = 1; i < k && !b; i++) {

            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}
ll pollard_rho(ll n, ll c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = llgcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}
void factorize(int n, vector<ll> &f) {
    for (int i = 0; i < Pt && P[i]*P[i] <= n; i++) {
    	if (n%P[i] == 0) {
    		while (n%P[i] == 0)
    			f.push_back(P[i]), n /= P[i];
    	}
    }
    if (n != 1)	f.push_back(n);
}
void llfactorize(ll n, vector<ll> &f) {
    if (n == 1)
        return ;
    if (n < 1e+9) {
        factorize(n, f);
        return ;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return ;
    }
    ll d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}
int main() {
    sieve();
    int testcase;

    scanf("%d", &testcase);
    while (testcase--) {
        ll n;
        scanf("%lld", &n);
        vector<long long> f;
        map<long long, int> r;
        llfactorize(n, f);
        for (auto &x : f)
            r[x]++;

            cout<<endl;
        cout<<n<<endl;
        cout<<endl;
        for (auto it = r.begin(); it != r.end(); it++) {
            cout<<"Prime factors = "<<it->first<<endl;
            cout<<"Power = "<<it->second<<endl;
        }
        puts("");
    }
    return 0;
}

///Miller Rabin Primality Check
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using LL = long long;

LL mulmod(LL a, LL b, LL base) {
	LL rv = 0;
	a %= base;

	while (b) {
		if (b & 1) rv = (rv + a) % base;
		a = (a + a) % base;
		b /= 2;
	}
	return rv % base;
}

LL bpow(LL a, LL b, LL base) {
	LL rv = 1;
	while (b) {
		if (b & 1) rv = mulmod(rv, a, base);
		a = mulmod(a, a, base);
		b /= 2;
	}
	return rv % base;
}


bool Miller(LL p, int iteration) {
	if (p == 2) return true;
	if (p < 2) return false;
	if (p % 2 == 0) return false;


	LL s = p - 1;
	while (s % 2 == 0) s /= 2;

	for (int i = 0; i < iteration; i++) {
		LL a = rng() % (p - 1) + 1, temp = s;
		LL mod = bpow(a, temp, p);
		while (temp != p - 1 and mod != 1 and mod != p - 1) {
			mod = mulmod(mod, mod, p);
			temp = temp * 2;
		}
		if (mod != p - 1 and temp % 2 == 0) {
			return false;
		}
	}
	return true;
}

int main() {

    cout<<"Is prime "<<Miller(29996224275833LL,20)<<endl;
    return 0;
}
/// Matrix EXPO
ll mod;

ll poww(ll a, ll b)
{
    if(b==0)return 1;ll x=poww(a,b/2);x=x*x;if(b%2==1)x=x*a;return x;
}

struct matrix
{
    ll mat[2][2];
};

matrix matmul( matrix a, int n, matrix b, int m)
{
    matrix c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c.mat[i][j] = 0;
            for(int k=0;k<n;k++)
            {
                c.mat[i][j] = ( c.mat[i][j] + (a.mat[i][k] * b.mat[k][j] )) % mod;
            }
        }
    }
    return c;
}
matrix x;
matrix bigmod( ll p, matrix b)
{
    if( p==1 )return b;
    x = bigmod( p/2, b );
    x = matmul(x,2,x,2);
    if( p%2 )x = matmul( x, 2, b, 2 );
    return x;
}

int main() {

    matrix m,p,r;
    int t,tt=1;
    SF(t);
    while(t--)
    {
        ll a,b,n,md;
        SFL3(a,b,n);
        SFL(md);
        m.mat[0][0] = 0;
        m.mat[0][1] = 1;
        m.mat[1][0] = 1;
        m.mat[1][1] = 1;
        p.mat[0][0] = a;
        p.mat[1][0] = b;
        pc();
        mod = poww(10,md);
        if(n==0)PFL(a);
        else if(n==1)PFL(b);
        else
        {
            r = bigmod(n,m);
            r = matmul(r,2,p,1);
            PFL(r.mat[0][0] );
        }
    }
    return 0;
}

///DYNAMIC PROGRAMMING

///SIBLING DP
const int M = 205;
vi adj[M];
int cost[M][M],n,m;
int child[M], rt[M];
ll dp[M][M];

void find_sibling(int p, int x)
{
    bool flg = 0;
    int pre;
    for(auto y:adj[x])
    {
        if(y==p)continue;
        if(!flg)
        {
            child[x] = y;
            flg = 1;
        }
        else
        {
            rt[pre] = y;
        }
        pre = y;
        find_sibling(x,y);
    }
}

ll dpcall(int p, int x, int k)
{
    if(x==-1)return 0;
    ll &ret = dp[x][k];
    if(~ret)return ret;
    ret = MAX;
    //node er moddhe achi...ekhn ami chinta korbo, ei node k ami koto diye nibo...
    ll res = 1 + dpcall(x,child[x],m);
    ll ress = dpcall(p,rt[x],k);
    ret = min(ret,res+ress);
    ll rest = k - cost[p][x];
    for(int i=0;i<=rest;i++)
    {
        ret = min(ret,dpcall(x,child[x],i)+dpcall(p,rt[x],rest-i));
    }
    return ret;
}
int main() {

    I_O;
    //output
    int t, tt=1,u,v,c;
    cin>>t;
    while(t--)
    {
        SET(dp);
        SET(child);
        SET(rt);
        mem(cost);
        cin>>n>>m;
        rep(n-1)
        {
            cin>>u>>v>>c;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u][v] = cost[v][u] = c;
        }
        cost[0][1] = cost[1][0] = 101;
        find_sibling(0,1);
        ll res = dpcall(0,1,0);
        tc();
        cout<<res<<endl;
        rep(n+2)adj[i].clear();
    }
    return 0;
}

///SIBLING DP_DUET

int reset(int N,int pos){return N= N & ~(1<<pos);}
const int M = 2000;

ll dp[M][M], cost[M],rt[M],child[M];
vi adj[M];
int vis[M][M], cur;
void find_sibling(int p, int x)
{
    bool flg = 0;
    int pre = -1;
    for(auto y:adj[x])
    {
        if(y==p)continue;
        if(!flg)
        {
            child[x] = y;
            flg = 1;
            find_sibling(x,y);
        }
        else
        {
            rt[pre] = y;
            find_sibling(x,y);
        }
        pre = y;
    }
}
ll dpcall(int x, int mask)
{

    if(!mask) return 0;
    if(!x)return 2000;
    ll &ret = dp[x][mask];
    if(vis[x][mask]==cur)return ret;
    vis[x][mask] = cur;

    ret = dpcall(rt[x],mask);
    int msk = mask & ~(1<<cost[x]);
    ret = min(ret,1+dpcall(child[x],msk));
    for(int nmask = msk; nmask>=0; nmask = (nmask-1) & msk)
    {
        int xmask = nmask ^ msk;
        ret = min(ret,1+dpcall(child[x],nmask)+dpcall(rt[x],xmask));
        if(nmask==0)break;
    }
    return ret;
}
int main() {

    I_O;
    int n,m,t,tt=1;
    cin>>t;
    while(t--)
    {
        SET(dp);
        mem(rt);
        mem(child);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>cost[i];
            cost[i] -= 1;
            adj[i].clear();
        }
        rep(n-1)
        {
            int u,v;
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        find_sibling(0,1);
        ll ans , res = MAX;
        int msk = (1<<m)-1;
        cur++;
        for(int i=1;i<=n;i++)
        {
            ans = 1 + dpcall(child[i],msk & ~(1<<cost[i]));
            res = min(res,ans);
        }
        tc();
        cout<<n-res<<endl;
    }
    return 0;
}


/// SIBLING DP - Berland and Federalization
const int M = 405;
vi adj[M];
int n,m;
int child[M], rt[M];
ll dp[M][M];
int mp[M][M],par[M];

void find_sibling(int p, int x)
{
    par[x] = p;
    bool flg = 0;
    int pre,now;
    for(auto y:adj[x])
    {
        if(y==p)continue;
        if(!flg)
        {
            child[x] = y;
            flg = 1;
        }
        else
        {
            rt[pre] = y;
        }
        pre = y;
        find_sibling(x,y);
    }
}

ll dpcall(int p, int x, int k)
{
    ll &ret = dp[x][k];
    if(k==0 && x==0)
    {
        return ret = 0;
    }
    if(x==0)return ret = 1e3;
    if(~ret)return ret;
    ret = 1e3;
    ret = 1 + dpcall(p,rt[x],k);
    ll rest = k - 1;
    for(int i=0;i<=rest;i++)
    {
        ret = min(ret,dpcall(x,child[x],i)+dpcall(p,rt[x],rest-i));
    }
    return ret;
}
vi vec;
void sol_print(int p, int x, int res, int k)
{

    if(res==0)return;
    if(dp[rt[x]][k]+1==res)
    {
        vec.pb(x);
        sol_print(p,rt[x],res-1,k);
        return;
    }
    ll rest = k-1;
    for(int i=0;i<=rest;i++)
    {
        if(dp[child[x]][i]+dp[rt[x]][rest-i]==res)
        {
            sol_print(x,child[x],dp[child[x]][i],i);
            sol_print(p,rt[x],dp[rt[x]][rest-i],rest-i);
            return;
        }
    }
}
int main() {

    I_O;
    int t, tt=1,u,v,c;
    SET(dp);
    mem(child);
    mem(rt);
    cin>>n>>m;
    rep(n-1)
    {
        cin>>u>>v;
        mp[u][v] = mp[v][u] = i+1;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    find_sibling(0,1);
    ll mx = 1000, node = -1;
    for(int i=1;i<=n;i++)
    {
        ll res = (i==1?0:1) + dpcall(0,child[i],m-1);
        if(res<mx)
        {
            mx = res;
            node = i;
        }
    }
    if(node!=1)
    {
        mx--;
        vec.pb(node);
    }
    sol_print(node,child[node],mx,m-1);
    cout<<vec.size()<<endl;

    vector < int > ans;
    for(auto x:vec)
    {
        ans.pb(mp[x][par[x]]);
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
/// Vertex cover
 int M = 1005;
vi adj[M];
ll dp[M][2], vis[M];
ll dfs(int p, int x)
{
    dp[x][0] = 0;
    dp[x][1] = 1;
    vis[x] = 1;
    int sz = adj[x].size();
    rep(sz)
    {
        int y = adj[x][i];
        if(y==p)continue;
        dfs(x,y);
        dp[x][0] += max(dp[y][0],dp[y][1]);
        dp[x][1] += dp[y][0];
    }
    return max(dp[x][0],dp[x][1]);
}
int main()
{

    I_O;
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n,a,b,m;
        cin>>n>>m;
        rep(m)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        mem(vis);
        ll ans = 0;
        rep(n)
        {
            if(vis[i+1])continue;
            ans += dfs(i+1,i+1);
        }
        tc();
        cout<<ans<<endl;
        rep(n+2)adj[i].clear();
    }
    return 0;
}

///SOS_DP
void printbin(int n)
{
    vi v;
    while(n>0)
    {
        v.pb(n%2);
        n/=2;
    }
    while(v.size()<20)v.pb(0);
    reverse(v.begin(),v.end());
    for(auto x:v)cout<<x;
    cout<<endl;
}
int f[MM*50];
int a[MM*50];

int frq[MM*50];

unsigned int onesComplement(unsigned int n)
{
   int number_of_bits = 22;
   return ((1 << number_of_bits) - 1) ^ n;
}
int main()
{

    I_O;

    int n,mx=0;
    cin>>n;
    rep(n)
    {
        cin>>a[i];
    }
    int N = 22;
    SET(f);
    for(int i = 0; i<n; ++i)
    {
        f[a[i]] = a[i];
    }
    for(int i = 0; i < N; ++i) for(int mask = 0; mask < (1<<N); ++mask)
    {
        if((mask & (1<<i)) && f[mask^(1<<i)]!=-1)
        {
            f[mask] = f[mask^(1<<i)];
        }
    }
    rep(n)
    {
        cout<<f[onesComplement(a[i])]<<" ";
    }
    cout<<endl;

    return 0;
}

///SOS_DP REVERSE
unsigned int onesComplement(unsigned int n)
{
   int number_of_bits = 20;
   return ((1 << number_of_bits) - 1) ^ n;
}

int f[1<<25];
int frq[1<<21];
ll pwr[1<<21];
int main()
{

    I_O;
    pwr[0] = 1;
    for(int i=1;i<=(1<<20);i++)
    {
        pwr[i] = pwr[i-1]*2LL;
        if(pwr[i]>=MOD)pwr[i] -= MOD;
    }
    int n;
    ll a;
    cin>>n;
    rep(n)
    {
        cin>>a;
        frq[a]++;
    }
    int N = 20;

    for(int i=(1<<N)-1;i>=0;i--)
    {
        f[i] = frq[i];
    }
    for(int i = 0; i < N; ++i) for(int mask = (1<<N)-1; mask >=0; --mask)
    {
        if(!(bool)(mask & (1<<i)))
        {
            f[mask] += f[mask^(1<<i)];
        }

    }
    ll ans = 0;
    rep(1<<N)
    {
        if(__builtin_popcount(i)%2)
        {
            ans -= pwr[f[i]];
            if(ans<0) ans += MOD;
        }
        else
        {
            ans += pwr[f[i]];
            if(ans>=MOD) ans -= MOD;

        }
    }
    cout<<ans<<endl;
    return 0;
}

///SUBSET over graph + BITMASK
int f[1<<16];
int dp[1<<17];
int vis[1<<17],cur;

int dpcall(int mask)
{
    if(mask==0)return 0;
    int &ret = dp[mask];
    if(vis[mask]==cur)return ret;
    vis[mask] = cur;
    ret = MAX;
    for(int submask = mask; submask>0; submask = (submask-1)&mask)
    {
        if(f[submask]==0)continue;
        ret = min(ret,1+dpcall(submask^mask));
    }
    return ret;
}
int viss[15][1<<15];
vi adj[18];
void dfs(int u, int mask)
{
    if(viss[u][mask])return;
    f[mask] = 1;
    viss[u][mask] = 1;
    for(auto x:adj[u])
    {
        dfs(x, mask | 1<<x);
    }
}
int main()
{

    int t,tt=1;
    SF(t);
    while(t--)
    {
        int n,m;
        SF2(n,m);
        int u,v;
        rep(m)
        {
            SF2(u,v);
            u--;
            v--;
            adj[u].pb(v);
        }
        mem(f);
        mem(viss);
        for(int i=0;i<n;i++)
        {
            dfs(i,1<<i);
        }
        pc();
        cur++;
        PF(dpcall((1<<n)-1));
        rep(n+1)adj[i].clear();
    }
    return 0;
}

///TILLING DP
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
///DEARRANGMENT

ll dp[1005][1005];
ll nCr(int n, int r)
{
    if(n==r || r==0)return 1;
    ll &ret = dp[n][r];
    if(~ret)return ret;
    return ret = (nCr(n-1,r) + nCr(n-1,r-1)) % MOD;
}
ll fact[1005];
int main() {


    SET(dp);
    fact[0] = 1;
    for(ll i=1;i<=1000;i++) fact[i] = (fact[i-1]*i)%MOD;

    int t,tt=1;
    SF(t);
    while(t--)
    {
        ll n,m,k;
        SFL3(n,m,k);
        ll res = nCr(m,k) * (fact[n-k]);
        res %= MOD;
        int xr = 1;
        ll rest = n-k;
        for(int i=1;i<=m-k;i++)
        {
            if(xr)
            {
                res -= ((nCr(m,k)*nCr(m-k,i))%MOD)*fact[rest-i];
                res %= MOD;
                res += MOD;
                res %= MOD;
            }
            else
            {
                res += ((nCr(m,k)*nCr(m-k,i))%MOD)*fact[rest-i];
                res %= MOD;

            }
            xr ^= 1;
        }
        pc();
        PFL(res);
    }


    return 0;
}
///DIGIT DP - DISABLE THE WAND
string s,p;
int vis[31][31][31][7][3][2],n,cur;
pi dp[31][31][31][7][3][2];
ll st, ed, mxone, ideal, k;
ll pwr[35];
pi dpcall(int id, int mOne, int iCnt, int md7, int md3, int ok)
{
    if(id==n)
    {
        if(mOne>mxone || iCnt>k || md7==0 || md3>0) return {0,0};
        return {0,1};
    }
    pi &ret = dp[id][mOne][iCnt][md7][md3][ok];
    int &vs = vis[id][mOne][iCnt][md7][md3][ok];
    if(vs==cur)return ret;

    vs = cur;
    ret = {0,0};
    if(ok)
    {
        if(p[id]=='0')
        {
            pi ans = dpcall(id+1,mOne,iCnt,md7,md3,ok);
            ret.first += ans.first;
            ret.second += ans.second;
        }
        else
        {
            pi ans = dpcall(id+1,mOne,iCnt+1,md7,md3,ok);
            ret.first += ans.first;
            ret.second += ans.second;
        }
        int pos = n-id-1;
        if(p[id]=='1')
        {
            pi ans = dpcall(id+1,mOne+1,iCnt,(pwr[pos]+md7)%7,(pwr[pos]+md3)%3,ok);
            ret.first += pwr[pos]*ans.second + ans.first;
            ret.second += ans.second;
        }
        else
        {
            pi ans = dpcall(id+1,mOne+1,iCnt+1,(pwr[pos]+md7)%7,(pwr[pos]+md3)%3,ok);
            ret.first += pwr[pos]*ans.second + ans.first;
            ret.second += ans.second;
        }
    }
    else
    {
        if(s[id]=='0')
        {
            if(p[id]=='0')
            {
                pi ans = dpcall(id+1,mOne,iCnt,md7,md3,ok);
                ret.first += ans.first;
                ret.second += ans.second;
            }
            else
            {
                pi ans = dpcall(id+1,mOne,iCnt+1,md7,md3,ok);
                ret.first += ans.first;
                ret.second += ans.second;
            }
        }
        else
        {
            if(p[id]=='0')
            {
                pi ans = dpcall(id+1,mOne,iCnt,md7,md3,1);
                ret.first += ans.first;
                ret.second += ans.second;
            }
            else
            {
                pi ans = dpcall(id+1,mOne,iCnt+1,md7,md3,1);
                ret.first += ans.first;
                ret.second += ans.second;
            }

            int pos = n-id-1;
            if(p[id]=='1')
            {
                pi ans = dpcall(id+1,mOne+1,iCnt,(pwr[pos]+md7)%7,(pwr[pos]+md3)%3,ok);
                ret.first += pwr[pos]*ans.second + ans.first;
                ret.second += ans.second;
            }
            else
            {
                pi ans = dpcall(id+1,mOne+1,iCnt+1,(pwr[pos]+md7)%7,(pwr[pos]+md3)%3,ok);
                ret.first += pwr[pos]*ans.second + ans.first;
                ret.second += ans.second;
            }

        }
    }

    return ret;
}
string fun(ll n)
{
    bitset < 31 > bt(n);
    string a = bt.to_string();

    return a;
}
int main() {
    pwr[0] = 1;
    for(int i=1;i<=32;i++) pwr[i] = pwr[i-1]*2LL;
    int t,tt=1;
    SF(t);
    while(t--)
    {
        SFL2(st,ed);
        SFL3(mxone,ideal,k);
        p = fun(ideal);
        cur++;
        s = fun(ed);
        n = s.size();
        ll ans = dpcall(0,0,0,0,0,0).first;

        cur++;
        st = max(0LL,st-1);
        s = fun(st);
        n = s.size();
        ll anss = dpcall(0,0,0,0,0,0).first;

        pc();
        PFL(ans-anss);
    }
    return 0;
}
///NQUEEN problem
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

///Iterative DP - Top secret task
int dp[2][155][11330];
int a[150];
int main()
{
    I_O;
    ll n,m,s;
    cin>>n>>m>>s;
    rep(n)cin>>a[i+1];
    int xr = 0;
    s = min(s,(n*(n+1)/2));
    for(int i=1;i<=m;i++)for(int j=0;j<=s;j++)dp[0][i][j] = MAX;
    for(int i=1;i<=m;i++)for(int j=0;j<=s;j++)dp[1][i][j] = MAX;
    dp[0][0][0] = 0;
    for(int i=1;i<=n;i++)
    {
        int nxr = xr^1;
        for(int j=1;j<=m;j++)
        {
            if(i<j)continue;
            int dist = i - j;
            for(int k=0;k<=s;k++)
            {
                dp[nxr][j][k] = dp[xr][j][k];
                if(k-dist>=0 && dp[xr][j-1][k-dist]!=MAX)
                {
                    dp[nxr][j][k] = min(dp[nxr][j][k],dp[xr][j-1][k-dist]+a[i]);

                }
            }
        }
        xr ^= 1;
    }
    int ans = MAX;
    for(int i=0;i<=s;i++)
    {
        if(dp[xr][m][i]!=MAX)ans = min(ans,dp[xr][m][i]);
    }
    cout<<ans<<endl;
    return 0;
}

///TUG OF WAR
const int M = 100010;

ll dp[M];
ll a[105];

int main()
{
    int t,tt=1;
    SF(t);
    while(t--)
    {
        int n;
        SF(n);
        ll sum = 0;
        rep(n)
        {
            SFL(a[i+1]);
            sum += a[i+1];
        }
        ll hf = sum/2 + sum%2;
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=hf;j>=a[i];j--)
            {
                dp[j] = dp[j] | (dp[j-a[i]]<<1LL);
            }
        }
        ll fst, scnd;
        ll pos = n/2;
        ll poss = pos + n%2;
        for(ll i=hf;i>=0;i--)
        {
            if((dp[i] & (1LL<<pos)) || (dp[i] & (1LL<<poss)))
            {
                fst = min(i,sum-i);
                scnd = max(i,sum-i);
                break;
            }
        }
        pc();
        pf("%lld %lld\n",fst,scnd);
        mem(dp);

    }
    return 0;
}
///LCS REVISITED
string s,p;
const int M = 1005;
int dp[M][M];
int way[M][M],n,m;
int precal[26][M];
int precall[26][M];
ll  lcs(int x, int y)
{
    int &ret = dp[x][y];
    if(x==n || y==m)return ret = 0;
    if(~ret)return ret;
    if(s[x]==p[y])return ret = 1 + lcs(x+1,y+1);
    return ret = max(lcs(x+1,y),lcs(x,y+1));
}
ll dpcall(int x, int y)
{
    if(x>=n || y>=m || dp[x][y]==0)return 1;
    int &ret = way[x][y];
    if(~ret)return ret;
    ret = 0;
    int nx,ny;
    for(int i=0;i<26;i++)
    {
        nx = precal[i][x];
        ny = precall[i][y];
        if(nx==MAX || ny==MAX)continue;
        if(dp[nx][ny]==dp[x][y])
        {
            ret += dpcall(nx+1,ny+1);
            if(ret>=1000007)ret-=1000007;
        }
    }
    return ret;
}
void precom()
{
    int sz = s.size();
    for(int j=sz;j>=0;j--)
    rep(26)
    {
        precal[i][j] = MAX;
    }
    for(int i=sz-1;i>=0;i--)
    {
        precal[s[i]-'a'][i] = i;
        for(int j=0;j<26;j++)
        {
            precal[j][i] = min(precal[j][i],precal[j][i+1]);
        }
    }
    sz = p.size();
    for(int j=sz;j>=0;j--)
    rep(26)
    {
        precall[i][j] = MAX;
    }
    for(int i=sz-1;i>=0;i--)
    {
        precall[p[i]-'a'][i] = i;
        for(int j=0;j<26;j++)
        {
            precall[j][i] = min(precall[j][i],precall[j][i+1]);
        }
    }
}
int main() {

    I_O;
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        SET(dp);
        SET(way);
        cin>>s>>p;
        n = s.size();
        m = p.size();
        precom();
        ll lc = lcs(0,0);
        tc();
        cout<<dpcall(0,0)<<endl;

    }

    return 0;
}

///Colored TSHIRT
ll pcl[17][17], frq[MM],dp[1<<16],n,m,a[MM];

void precal()
{
    mem(frq);
    mem(pcl);
    rep(n)
    {
        frq[a[i]]++;
        REP(m)
        {
            if(a[i]==j)continue;
            pcl[a[i]][j] += frq[j];
        }
    }
}
ll dpcall(int mask)
{
    if( mask+1 == 1<<m)return 0;
    ll &ret = dp[mask];
    if(~ret)return ret;
    ret = 1e15;
    rep(m)
    {
        int pos = (bool)(mask & 1<<i);
        if(pos)continue;
        ll tot = 0;
        REP(m)
        {
            pos = (bool)(mask & 1<<j);
            if(pos || i==j)continue;
            tot += pcl[i][j];

        }
        ret = min(ret,tot + dpcall(mask | 1<<i));
    }
    return ret;

}
int main() {

    int t,tt=1;
    SF(t);
    while(t--)
    {
        SFL2(n,m);
        rep(n)
        {
            SFL(a[i]);
            a[i]--;
        }
        SET(dp);
        precal();
        pc();
        PFL(dpcall(0));
    }


    return 0;
}
///LIS
int a[MM],dp[MM],res[MM];
int main() {

    int t,tt=1;
    SF(t);
    while(t--)
    {
        int n,m,q;
        SF2(n,q);
        rep(n)SF(a[i]);
        reverse(a,a+n);
        pf("Case %d:\n",tt++);
        while(q--)
        {
            SF(m);
            rep(n+1)dp[i] = -MAX;
            dp[0] = MAX;
            int mx = 0;
            rep(n)
            {
                int lw = 0, hi = n, mid, ans = -1;
                while(lw<=hi)
                {
                    mid = (lw+hi)/2;
                    if(dp[mid]>a[i])
                    {
                        ans = mid+1;
                        lw = mid+1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }
                dp[ans] = a[i];
                res[i] = ans;
                if(ans>=m)
                {
                    mx =max(mx,ans);
                }
            }
            if(mx)
            {
                vi lis;
                ll pre = -MAX;
                for(int i=n-1;i>=0 && m;i--)
                {
                    if(!m)break;
                    if(a[i]>pre && res[i]>=m)
                    {
                        lis.pb(a[i]);
                        mx--;
                        m--;
                        pre = a[i];
                    }
                }
//                reverse(lis.begin(),lis.end());
                bool flg = 0;
                for(auto x:lis)
                {
                    if(flg)pf(" ");
                    pf("%d",x);
                    flg = 1;
                }
                pf("\n");
            }
            else
            {
                pf("Impossible\n");
            }
            mem(res);
        }

    }
    return 0;
}

///HALLOWEEN_CUSTOME
vector < int > v;
int dp[105][105];
int dpcall(int l, int r)
{
    if(l>r)return 0;
    int &ret = dp[l][r];
    if(~ret)return ret;
    ret = 1 + dpcall(l+1,r);
    for(int i = l+1;i<=r;i++)
    {
        if(v[l]==v[i]) ret = min(ret,dpcall(l+1,i-1)+dpcall(i,r));
    }
    return ret;
}
int main() {

    int t,tt=1;
    SF(t);
    while(t--)
    {
        int n;
        SF(n);
        int a;
        rep(n)
        {
            SF(a);
            v.push_back(a);
        }
        SET(dp);
        pc();
        PF(dpcall(0,v.size()-1));
        v.clear();
    }
    return 0;
}
/*
2
4
1 2 1 2
7
1 2 1 1 3 2 1
*/

///GRAPH

///SCC-toposort
vi adj[20050],adjj[20005];
int vis[20005],par[20005];
int indeg[20005],outdeg[20005];
stack < int > st;

void toposort(int x)
{
    vis[x] = 1;
    for(auto y : adj[x])
    {
        if(vis[y])continue;
        toposort(y);
    }
    st.push(x);
}
void scc(int x, int cmp)
{
    vis[x] = 1;
    par[x] = cmp;
    for(auto y : adjj[x])
    {
        if(vis[y])continue;
        scc(y,cmp);
    }
}

vi nadj[500];
int main() {

    I_O;
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m;
        rep(m)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adjj[y].pb(x);
        }
        mem(vis);
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            toposort(i);
        }
        mem(vis);
        int cnt = 1;
        while(st.size())
        {
            x = st.top();st.pop();
            if(vis[x])continue;
            scc(x,cnt);
            cnt++;
        }
        for(int i=1;i<=n;i++)
        {
            for(auto x:adj[i])
            {
                if(par[i]==par[x])continue;
                nadj[par[i]].pb(par[x]);
            }
        }
        for(int i=1;i<cnt;i++)
        {
            cout<<i<<" -> ";
            for(auto x:nadj[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }

        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            adjj[i].clear();
            nadj[i].clear();
        }
    }

    return 0;
}

///BPM-Kuhn
const int M = 1005;
ll a[M],b[M];
int lf[M], rt[M];
vi adj[M];
bool vis[M];
bool kuhn(int x)
{
    for(auto y : adj[x])
    {
        if(vis[y])continue;
        vis[y] = 1;
        if(rt[y]==-1 || kuhn(rt[y]))
        {
            rt[y] = x;
            lf[x] = y;
            return true;
        }
    }
    return false;
}
int bpm(int n)
{
    SET(lf);
    SET(rt);
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        mem(vis);
        if(kuhn(i))cnt++;
    }
    return cnt;
}
string s[25];
int n,m;
int build_graph()
{

    int u,v;
    rep(m)
    {
        cin>>u>>v;
        adj[u].pb(v);
    }
    int match = bpm(n);
    rep(n+1)adj[i].clear();
    return n - match;
}
int main() {

    I_O;
    int t,tt=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        tc();
        cout<<build_graph()<<endl;
    }
    return 0;
}

///BPM-HOPCROFTKARP
const int M = MM;
int n,m;
int rt[M],lf[M], vis[M],lvl[M];
vi adj[M];

bool dfs(int x)
{
    vis[x] = 1;
    for(auto y:adj[x])
    {
        if(lf[y]==-1 || (!vis[lf[y]] && lvl[lf[y]]>lvl[x] && dfs(lf[y])))
        {
            rt[x] = y;
            lf[y] = x;
            return true;
        }
    }
    return false;
}

ll hopcroft()
{
    SET(rt);
    SET(lf);
    ll res = 0;
    while(true)
    {
        queue < int > q;
        SET(lvl);
        for(int i=1;i<=n;i++)
        {
            if(rt[i]==-1)
            {
                lvl[i] = 0;
                q.push(i);
            }
            else
            {
                lvl[i] = -1;
            }
        }
        while(q.size())
        {
            int x = q.front(); q.pop();
            for(auto y:adj[x])
            {
                if(lf[y]!=-1 && lvl[lf[y]]==-1)
                {
                    q.push(lf[y]);
                    lvl[lf[y]] = lvl[x] + 1;
                }
            }
        }
        mem(vis);
        ll sum = 0;
        for(int i=1;i<=n;i++)
        {
            if(rt[i]==-1 && dfs(i))sum++;
        }
        if(!sum)break;
        res += sum;

    }
    rep(n+2)adj[i].clear();
    return res;
}


int main() {

    I_O;
    int p;
    SF3(n,m,p);
    int u,v;
    rep(p)
    {
        SF2(u,v);
        adj[u].pb(v+n);
    }
    PFL(hopcroft());

    return 0;
}

///MAXFLOW_DINIC

const int M = 30005;
struct edge
{
    ll to,rev,flow,cap;
};
vector < edge > adj[M];
int lvl[5005], source, sink,N, ptr[5005];
void create_graph(ll u, ll v, ll Cap)
{
    edge x = {v,(ll)adj[v].size(),0LL,Cap};
    edge y = {u,(ll)adj[u].size(),0LL,Cap};///Cap = 0 when edge is directed.
    adj[u].pb(x);
    adj[v].pb(y);
}
bool make_level_graph(int s, int d)
{
    rep(N+1)lvl[i] = 0;
    queue < int > q;
    q.push(s);
    lvl[s] = 1;
    while(q.size())
    {
        int x = q.front();
        q.pop();
        int sz = adj[x].size();
        rep(sz)
        {
            int y = adj[x][i].to;
            ll cap = adj[x][i].cap - adj[x][i].flow;
            if(!lvl[y] && cap>0)
            {
                lvl[y] = lvl[x] + 1;
                q.push(y);
            }
        }
    }
    if(lvl[d])return 1;
    else return 0;
}
ll send_flow(int x, ll mn)
{
    if(!mn)return 0;
    if(x==sink)return mn;
    int sz = adj[x].size();
    for(int i = ptr[x];i<sz;i++,ptr[x]++)
    {
        int y = adj[x][i].to;
        ll cap = adj[x][i].cap - adj[x][i].flow;
        if(lvl[y] == lvl[x]+1 && cap>0)
        {
            ll flow = send_flow(y,min(mn,cap));
            if(flow>0)
            {
                adj[x][i].flow += flow;
                adj[y][adj[x][i].rev].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}
ll dinic()
{
    ll res = 0;
    while(make_level_graph(source,sink))
    {
        rep(N+1)ptr[i] = 0;
        while(ll flow = send_flow(source,MAX))
        {
            res += flow;
        }
    }
    return res;
}
void Reset(int n)
{
    rep(n+2)adj[i].clear();
}
int main() {

    I_O;

    int n,k;
    SF(n);
    N = n;
    SF(k);
    source = 1;
    sink = n;
    int u,v,c;
    rep(k)
    {
        SF3(u,v,c);
        create_graph(u,v,c);
    }
    PFL(dinic());
    return 0;
}



