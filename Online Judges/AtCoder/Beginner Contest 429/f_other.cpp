#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rep(i,a,b) for(int i=a;i<b;++i)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define memory() cerr<<abs(&M2-&M1)/1024.0/1024<<" MB"<<endl
#define time() cerr<<endl<<"-------------Time:"<<1000.0*clock()/CLOCKS_PER_SEC<<"ms."<<endl

const ll INF=4e18;
int n,q;
string s[3];
struct Node{
    ll d[3][3];
    Node(){Rep(i,0,3)Rep(j,0,3)d[i][j]=INF;}
};
vector<Node>st;
Node mergeNode(const Node&L,const Node&R,int m){
    Node res;
    Rep(i,0,3)Rep(j,0,3){
        ll best=INF;
        Rep(t,0,3){
            if(s[t][m]=='.'&&s[t][m+1]=='.'){
                ll a=L.d[i][t],b=R.d[t][j];
                if(a<INF&&b<INF)best=min(best,a+1+b);
            }
        }
        res.d[i][j]=best;
    }
    return res;
}
Node makeLeaf(int c){
    Node res;
    Rep(i,0,3)Rep(j,0,3){
        bool ok=1;
        For(k,min(i,j),max(i,j))if(s[k][c]=='#'){ok=0;break;}
        res.d[i][j]=ok?abs(i-j):INF;
    }
    return res;
}
void build(int id,int l,int r){
    if(l==r){st[id]=makeLeaf(l);return;}
    int m=(l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    st[id]=mergeNode(st[id<<1],st[id<<1|1],m);
}
void upd(int id,int l,int r,int p){
    if(l==r){st[id]=makeLeaf(l);return;}
    int m=(l+r)>>1;
    if(p<=m)upd(id<<1,l,m,p);
    else upd(id<<1|1,m+1,r,p);
    st[id]=mergeNode(st[id<<1],st[id<<1|1],m);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    Rep(i,0,3){string t;cin>>t;s[i]=t;}
    cin>>q;
    st.assign(4*n+5,Node());
    build(1,0,n-1);
    while(q--){
        int r,c;cin>>r>>c;--r;--c;
        s[r][c]=(s[r][c]=='.'?'#':'.');
        upd(1,0,n-1,c);
        ll ans=st[1].d[0][2];
        cout<<(ans>=INF/2?-1:ans)<<'\n';
    }
}