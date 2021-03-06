#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
#define endl '\n'
#define _ixvii0iv
using namespace std;
const int maxn = 1e6+2333;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int>G[2333],E[2333];
char a[2333];
bool visp[2333][2333];
bool visq[2333][2333];
int dfs1(int x){
    for(int i =0;i<G[x].size();i++){
        int v =G[x][i];
        //dbg(v);
        if(visp[x][v]==1){
            for(int j=0;j<G[v].size();j++){
                int s = G[v][j];
                //dbg(visp[v][s]);
                if(visp[x][s]==0){
                    return false;
                }
            }
        }
    }
    return true;
}
int dfs2(int x){
    for(int i =0;i<E[x].size();i++){
        int v =E[x][i];
        //dbg(v);
        if(visq[x][v]==1){
            for(int j=0;j<E[v].size();j++){
                int s = E[v][j];
            //    bg(s);
                if(visq[x][s]==0){
                    return false;
                }
            }
        }
    }
    return true;
}
void solve(){
    int n = Read();
    //MEM(head,-1);
    for(int i=1;i<=n;i++){
        G[i].clear();
        E[i].clear();
    }
    CLR(visq);
    CLR(visp);
    for(int i=0;i<n;i++){
        scanf("%s",a);
        for(int j=0;j<n;j++){
            if(a[j]=='P')
            {
                G[i+1].PB(j+1);
                visp[i+1][j+1]= 1;
            }
            else if(a[j]=='Q'){
                E[i+1].PB(j+1);
                visq[i+1][j+1] = 1;
            }
        }
    }
    int fg = 0;
    for(int i=1;i<=n;i++){
    //cout << dfs1(i) << " " << dfs2(i) << endl;
        if(!dfs1(i)||!dfs2(i)) {
            fg = 1;
    //        cout << i << endl;
            break;
        }
    }
    if(fg)puts("N");
    else puts("T");

    /*show me your code*/
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
