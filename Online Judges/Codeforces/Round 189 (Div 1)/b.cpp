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
#define debug if(false)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[100001];
	vi listBil;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans = 0;
	
	vi temp;
	int maks = a[0];
	temp.pb(a[0]);
	int cur = maks;
	bool adaHapus = false;
	int curAns = 0;
	int t[100001];
	memset(t, 0, sizeof t);

	for(i=0;i<n-1;i++){
		int bil1 = a[i], bil2 = a[i+1];
		// printf("i: %d curAns: %d\n",i, curAns);
		if(bil1 < bil2){
			if(bil2 > maks){
				t[bil2] = 0;
				temp.clear();
				temp.pb(bil2);
				maks = bil2;
				
				curAns = 1;
			}else{
				int back = temp.back();
				debug printf("bil2: %d back: %d\n",bil2, back);
				if(t[back] == 0){
					t[bil2] = 2;
				}else{
					if(back < bil2){
						t[bil2] = t[back] + 1;
					}else{
						if(curAns == 1){
							t[bil2] = ++curAns;
						}else{
							t[bil2] = t[back]+1;
						}
					}
					
					// t[bil2] = curAns;
				}
				curAns++;
				debug printf("t[%d]: %d\n",bil2,t[bil2]);
				// if(bil2 > back) {
				// 	t[bil2] = t[back]++;
				// }else{
				// 	if(temp.size() == 1){
				// 		t[bil2] = 2;
				// 		// curAns++;
				// 		// printf("sini curAns jd: %d\n", curAns);
				// 	}else{
				// 		t[bil]
				// 	}
				// }
				temp.pb(bil2);
			}
			
			adaHapus = false;
		}else{
			t[bil2] = 1;
			curAns = 1;
			adaHapus = true;
		}
	}
	for(i=1;i<=n;i++){
		debug printf("t[%d]: %d\n",i, t[i]);
		ans = max(ans, t[i]);
	}
	
	
	printf("%d\n",ans);
	return 0;
};