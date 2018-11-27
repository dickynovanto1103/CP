#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

class UnionFind{
private: 
    vi rank,p,setSize;
    int numset,i;
public:
    UnionFind(int n){
        numset=n; setSize.assign(n,1); rank.assign(n,0); p.assign(n,0);
        for(i=0;i<n;i++){p[i]=i;}
    }

    int findSet(int i){return (p[i]==i) ? i : (p[i]=findSet(p[i]));}
    bool isSameSet(int i, int j){return findSet(i)==findSet(j);}
    void unionSet(int i, int j){
        if(!isSameSet(i,j)){
            numset--;
            int x=findSet(i), y=findSet(j);
            if(rank[x] > rank[y]){p[y]=x; setSize[x]+=setSize[y];}
            else{
                p[x]=y;
                setSize[y]+=setSize[x];
                if(rank[x]==rank[y]){rank[y]++;}
            }
        }
    }
    int numDisjointSet(){return numset;}
    int sizeSetOf(int i){return setSize[findSet(i)];}
};

int main(){
    int n,m,i,j;
    scanf("%d",&n);
    UnionFind UF(500010);
    // memset(isVisited, false, sizeof isVisited);
    // int temp = 100;
    // printf("findSet(%d): %d\n",temp,UF.findSet(temp) );
    int ans = 0;
    // int markedTrue = 0;
    int cnt[500010];
    memset(cnt, 0, sizeof cnt);
    set<int> temp;
    for(i=0;i<n;i++){
        scanf("%d",&m);
        int bil;
        int cntSudahAda = 0;
        vector<int> v;
        set<int> s;
        set<int>::iterator it;
        // printf("i: %d\n", i);
        for(j=0;j<m;j++){
            scanf("%d",&bil);
            // printf("bil awal: %d\n", bil);
            bil = UF.findSet(bil);
            v.pb(bil);
            s.insert(bil);
            // printf("yang mau diinsert bil; %d\n",bil );
            // if(isVisited[bil]){cntSudahAda++;}
        }
        if(s.size() == 1){
            if(UF.sizeSetOf(bil) == 1){
                if(temp.find(bil) == temp.end()){
                    ans++;
                    temp.insert(bil);
                }
            }
            continue;
        }
        for(it=s.begin();it!=s.end();it++){
            int id = *it;
            cnt[id] = 0;
        }
        int ukuran = v.size();
        for(i=0;i<ukuran;i++){
            int id = v[i];
            cnt[id]++;
        }
        bool isValid = true;
        for(it=s.begin();it!=s.end();it++){
            int id = *it;
            if(cnt[id] != UF.sizeSetOf(id)){
                isValid = false;
                break;
            }
        }
        if(isValid){
            int first = *s.begin();
            for(it=++s.begin();it!=s.end();it++){
                int id = *it;
                UF.unionSet(first,id);
            }
            ans++;
        }
        

    }
    printf("%d\n",ans);
    return 0;
};