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

vector<vi> AdjList;
double val[155];

void dfs(int idx) {
    double nilai = val[idx];
    for(int i=0;i<AdjList[idx].size();i++){
        int v = AdjList[idx][i];
        val[v] += 0.5*nilai;
        dfs(v);
    }
}

int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    AdjList.assign(155,vi());
    string founder;
    
    for(i=0;i<155;i++){val[i] = 0;}
    map<string, int> mapper;
    cin>>founder;
    int cnt = 0;
    mapper[founder] = cnt++;
    val[0] = 1;
    for(i=0;i<n;i++){
        string anak, p1,p2;
        cin>>anak>>p1>>p2;
        if(mapper.find(anak) == mapper.end()){
            mapper[anak] = cnt++;
        }
        if(mapper.find(p1) == mapper.end()){
            mapper[p1] = cnt++;
        }
        if(mapper.find(p2) == mapper.end()){
            mapper[p2] = cnt++;
        }
        int idx1 = mapper[anak], idx2 = mapper[p1], idx3 = mapper[p2];
        AdjList[idx2].pb(idx1); AdjList[idx3].pb(idx1);
    }
    //dfs
    dfs(0);
    double maks = 0;
    string ans = "";
    for(i=0;i<m;i++){
        string org;
        cin>>org;
        int idx = mapper[org];
        if(maks < val[idx]){
            maks = val[idx];
            ans = org;
        }
    }
    // printf("halo\n");
    if(ans == ""){assert(false);}
    cout<<ans<<endl;
    return 0;
};