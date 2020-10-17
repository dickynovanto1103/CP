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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int a[100001];
int col[100001], row[100001];
bool done[100002];

int main(){
	int n,i,j;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<=100000;i++){
			col[i] = row[i] = 0;
			done[i] = false;
		}
		set<int> idx[3];
		set<int>::iterator it, it1, it2;

		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i] <= 2){
				idx[a[i]].insert(i);
			}
		}
		vii ans;
		bool valid = true;
		int row = 1;
		for(i=1;i<=n;i++){
			if(done[i]){continue;}
			if(a[i] == 0){

			}else if(a[i] == 1){
				ans.pb(ii(row, i));
				row++;
			}else if(a[i] == 2){
				//pasangkan dengan angka 1 di kanan
				it = idx[1].lower_bound(i);
				if(it == idx[1].end()){
					valid = false;
					break;
				}
				int nextIdx = *it;
				idx[1].erase(nextIdx);
				ans.pb(ii(row, i));
				ans.pb(ii(row, nextIdx));
				done[nextIdx] = true;
				done[i] = true;
				row++;
			}else{
				//pasangkan dengan angka 1 atau 2 di kanan
				it1 = idx[1].lower_bound(i);
				if(it1 == idx[1].end()){
					it2 = idx[2].lower_bound(i);
					if(it2 == idx[2].end()){
						valid = false;
						break;
					}else{
						int nextCol = *it2;
						idx[2].erase(nextCol);
						ans.pb(ii(row, i));
						ans.pb(ii(row, nextCol));
						ans.pb(ii(row+1, nextCol));
						row+=2;
						// done[nextCol] = true;
						// done[i] = true;
					}
				}else{
					int nextIdx1 = *it1;
					it2 = idx[2].lower_bound(i);
					if(it2 == idx[2].end()){
						idx[1].erase(nextIdx1);
						ans.pb(ii(row, i));
						ans.pb(ii(row, nextIdx1));
						ans.pb(ii(row+1, nextIdx1));
						row+=2;
						done[nextIdx1] = true;
					}else{
						int nextIdx2 = *it2;
						int minim = min(nextIdx1, nextIdx2);
						if(minim == nextIdx1) {
							idx[1].erase(nextIdx1);
							ans.pb(ii(row, i));
							ans.pb(ii(row, nextIdx1));
							ans.pb(ii(row+1, nextIdx1));
							row += 2;
							done[nextIdx1] = true;
						}else{
							idx[2].erase(nextIdx2);
							ans.pb(ii(row, i));
							ans.pb(ii(row, nextIdx2));
							ans.pb(ii(row+1, nextIdx2));
							row+=2;
						}
					}
				}
			}
		}
		if(!valid){
			printf("-1\n");
		}else{
			int n = ans.size();
			printf("%d\n",n);
			for(i=0;i<n;i++){
				printf("%d %d\n",ans[i].first, ans[i].second);
			}
		}
	}
	
	
	
	return 0;
};