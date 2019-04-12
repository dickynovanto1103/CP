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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 550;

vector<vi> AdjList;

int dist[maxn][maxn];

void bfs(int nodeAwal) {
    queue<int> q;
    q.push(nodeAwal);
    dist[nodeAwal][nodeAwal] = 0;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(int i=0;i<AdjList[front].size();i++){
            int v = AdjList[front][i];
            if(dist[nodeAwal][v] == inf){
                dist[nodeAwal][v] = dist[nodeAwal][front] + 1;
                q.push(v);
            }
        }
    }
    
}

int main(){
    int n,i,j;
    FastSlowInput
    cin>>n;
    // scanf("%d",&n);
    
    string kata[maxn];
    AdjList.assign(maxn, vi());
    map<string, int> mapper;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            dist[i][j] = inf;
        }
    }

    for(i=0;i<n;i++){
        cin>>kata[i];
        mapper[kata[i]] = i;
    }

    for(i=0;i<n;i++){
        string awal;
        int d;
        cin>>awal>>d;
        int idx1 = mapper[awal];
        // printf("awal: ");cout<<awal<<endl;
        for(j=0;j<d;j++){
            string dum;
            cin>>dum;

            while(cin>>dum){
                int pjg = dum.length();

                if(dum[pjg-1] != ','){
                    // cout<<"dum: "<<dum<<endl;
                    int idx2 = mapper[dum];
                    AdjList[idx1].pb(idx2);
    
                    if(dum == awal){cout<<dum<<endl; return 0;}
                    break;
                }else{
                    dum.pop_back();
                    int idx2 = mapper[dum];
                    AdjList[idx1].pb(idx2);
     
                    if(dum == awal){cout<<dum<<endl; return 0;}
                }

            }
        }

    }

    // for(i=0;i<n;i++){
    //     printf("node %d:",i);
    //     for(j=0;j<AdjList[i].size();j++){
    //         printf(" %d",AdjList[i][j]);
    //     }
    //     printf("\n");
    // }

    for(i=0;i<n;i++){
        bfs(i);
    }
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         printf("%10d ",dist[i][j]);
    //     }
    //     printf("\n");
    // }
    int minim = inf;
    int idxMin, node;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i == j){continue;}
            if(minim > dist[i][j] + dist[j][i]){
                minim = dist[i][j] + dist[j][i];
                idxMin = i;
                node = i;
            }
        }
    }

    if(minim == inf){cout<<"SHIP IT\n"; return 0;}

    vi urutan;
    urutan.pb(idxMin);
    // printf("idxMin: %d minim: %d\n",idxMin, minim);
    queue<int> q;
    q.push(idxMin);
    int jarakHarapan = 1, sisa = minim - jarakHarapan;
    while(!q.empty()){
        int front = q.front(); q.pop();
        for(i=0;i<AdjList[front].size();i++){
            int v = AdjList[front][i];
            if(dist[idxMin][v] == jarakHarapan && dist[v][idxMin] == sisa){
                jarakHarapan++;
                sisa--;
                q.push(v);
                urutan.pb(v);
            }
        }
    }
    // sort(dist[idxMin], dist[idxMin] + n);

    
    // for(i=0;i<n;i++){
    //     printf("dist[%d][%d]: %d\n",idxMin, i, dist[idxMin][i]);
    //     if(dist[idxMin][i] == jarakHarapan && dist[i][idxMin] == sisa){
    //         jarakHarapan++;
    //         sisa--;
    //         printf("jarakHarapan: %d sisa: %d\n",jarakHarapan, sisa);
    //         urutan.pb(i);
    //         printf("dipush: %d\n",i);
    //     }
    // }
    // printf("halo\n");
    
    // if(ans.size() == 0){printf("SHIP IT\n"); return 0;}
    // reverse(ans.begin(), ans.end());
    // set<int> s;
    // for(i=0;i<ans.size();i++){
    //     s.insert(ans[i]);
    // }

    // sort(ans.begin(), ans.end());

    for(i=0;i<urutan.size();i++){
        int bil = urutan[i];
        if(i){cout<<" ";}
        cout<<kata[bil];
    }
    cout<<endl;

    return 0;
};