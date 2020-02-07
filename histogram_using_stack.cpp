#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
/*

*/
