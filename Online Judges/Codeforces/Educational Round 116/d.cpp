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
#define RED 1
#define BLUE 2
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vi> a;
vector<vi> prefMin, prefMax, suffMin, suffMax;

void genPrefSuff(int n, int m) {
	int i,j;
	for(i=0;i<n;i++){
		prefMin[i][0] = prefMax[i][0] = a[i][0];
		for(j=1;j<m;j++){
			prefMin[i][j] = min(prefMin[i][j-1], a[i][j]);
			prefMax[i][j] = max(prefMax[i][j-1], a[i][j]);
		}

		suffMin[i][m-1] = suffMax[i][m-1] = a[i][m-1];
		for(j=m-2;j>=0;j--){
			suffMin[i][j] = min(suffMin[i][j+1], a[i][j]);
			suffMax[i][j] = max(suffMax[i][j+1], a[i][j]);
		}
	}
}

int main(){
	int tc,n,m,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&n,&m);
		a.assign(n, vi(m, 0));
		prefMin.assign(n, vi(m, inf));
		prefMax.assign(n, vi(m, 0));
		suffMin.assign(n, vi(m, inf));
		suffMax.assign(n, vi(m, 0));
		

		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}

		genPrefSuff(n, m);
		int ansCol = -1;
		string ansStr;

		bool found = false;

		for(j=0;j<m-1;j++) {
			//binser
			int kiri = 1, kanan = 1e6, mid, ans = -1;
			while(kiri <= kanan) {
				mid = (kiri + kanan) / 2;
				// printf("kiri: %d kanan: %d mid: %d\n", kiri, kanan, mid);
				//mid = the border of minimum of red
				int numRed = 0, numBlue = 0;
				string color;
				for(i=0;i<n;i++){
					if(prefMin[i][j] >= mid) {
						numRed++;
						color += "R";
					}else{
						numBlue++;
						color += "B";
					}
				}

				if(numRed == n) {
					kiri = mid+1;
				}else if(numBlue == n) {
					kanan = mid - 1;
				}else{
					//validate di kanan
					int minBlue = inf;
					int maksRed = 0;
					for(i=0;i<n;i++){
						if(color[i] == 'B') {
							minBlue = min(suffMin[i][j+1], minBlue);	
						}else{
							maksRed = max(suffMax[i][j+1], maksRed);
						}
					}

					if(minBlue > maksRed) {
						//found
						ans = mid;
						ansCol = j + 1;
						ansStr = color;
						found = true;
						break;
					}else{
						kanan = mid-1;
					}
				}
			}

			if(ans != -1){
				break;
			}
		}
		if(found) {
			cout<<"YES"<<endl;
			cout<<ansStr<< " "<<ansCol<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
};