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

vector<vi> AdjList1,AdjList2;

bool isIsomorphic(int n1, int n2)
{
    int ukuran1 = AdjList1[n1].size(), ukuran2 = AdjList2[n2].size();
    // printf("n1: %d n2: %d ukuran1: %d ukuran2: %d\n",n1,n2,ukuran1,ukuran2);
 if (ukuran1==0 && ukuran2==0){return true;}
 if (ukuran1==0 || ukuran2==0){return false;} //salah satu ga 0
 
 bool ans = false;
 if(ukuran1 == 1) {
    if(ukuran2==1){
        ans = ans || (isIsomorphic(AdjList1[n1][0], AdjList2[n2][0]));
    }else if(ukuran2==2){
        // printf("masuk sini n1: %d n2: %d\n",n1,n2);
        ans = ans || ((isIsomorphic(AdjList1[n1][0], AdjList2[n2][0])) && isIsomorphic(AdjList1[n1][0], AdjList2[n2][1]));
    }
 }else if(ukuran1==2) {
    if(ukuran2==1) {
        ans = ans || ((isIsomorphic(AdjList1[n1][0], AdjList2[n2][0])) && isIsomorphic(AdjList1[n1][1], AdjList2[n2][0]));
    }else if(ukuran2==2){
        ans = ans || (isIsomorphic(AdjList1[n1][0],AdjList2[n2][0]) && isIsomorphic(AdjList1[n1][1],AdjList2[n2][1])) ||
        (isIsomorphic(AdjList1[n1][0],AdjList2[n2][1]) && isIsomorphic(AdjList1[n1][1],AdjList2[n2][0]));       
    }
 }
 return ans;
 
}
 
const int maxn = 1e5 + 5;

int main()
{
    int n,i,j,tc;
    scanf("%d",&tc);
    while(tc--){
        int parent[maxn];
        scanf("%d",&n);
        AdjList1.assign(n+1,vi()); AdjList2.assign(n+1,vi());
        int root1, root2;
        for(i=1;i<=n;i++){
            scanf("%d",&parent[i]);
            if(parent[i]!=0){
                AdjList1[parent[i]].pb(i);
            }else{
                root1 = i;
            }
        }

        for(i=1;i<=n;i++){
            scanf("%d",&parent[i]);
            if(parent[i]!=0){
                AdjList2[parent[i]].pb(i);
            }else{
                root2 = i;
            }
        }

        // printf("root1: %d root2: %d\n",root1,root2);
        if (isIsomorphic(root1, root2)){printf("1\n");}
        else{printf("0\n");}

        AdjList2.clear(); AdjList1.clear();
    }
    
 
    return 0;
}
