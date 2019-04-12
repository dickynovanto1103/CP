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
typedef pair<int,char> ic;
typedef vector<ii> vii;

void printArray(vector<int> a){
	// printf("a:");
	// for(int i=0;i<a.size();i++){
	// 	printf(" %d",a[i]);
	// }
	// printf("\n");
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	vi a(n);
	vi::iterator it;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k;
	scanf("%d",&k);
	int b[550];
	vii listSegment;
	int sum = 0;
	int awal = 0;
	for(i=0;i<k;i++){
		scanf("%d",&b[i]);
		if(awal >= n){printf("NO\n"); return 0;}
		for(j=awal;j<n;j++){
			sum += a[j];
			if(sum == b[i]){
				if(awal < j){
					listSegment.pb(ii(awal, j));
				}

				awal = j+1;
				sum = 0;
				break;
			}else if(sum > b[i]){
				printf("NO\n"); return 0;
			}
		}

	}
	if(awal < n){printf("NO\n"); return 0;}

	vector<pair<int,char> > ans;
	for(i=listSegment.size()-1;i>=0;i--){
		int awal = listSegment[i].first, akhir = listSegment[i].second;
		int maks = 0;
		for(j=awal;j<=akhir;j++){
			maks = max(maks, a[j]);
		}
		int idxStart = -1;
		bool keKiri = false;
		for(j=awal;j<=akhir;j++){
			if(a[j] == maks){
				if(j == awal){
					if(a[j] > a[j+1])
						idxStart = j;
				}else if(j == akhir){
					if(a[j] > a[j-1]){
						idxStart = j;
						keKiri = true;	
					}
					
				}else if(a[j] > a[j-1] || a[j] > a[j+1]) {
					idxStart = j;
					if(a[j] > a[j+1]){
						// printf("halo j: %d %d %d\n",j,a[j], a[j+1]);
						keKiri = false;
					}else if(a[j] > a[j-1]){
						keKiri = true;
					}
				}
			}
		}
		// printf("awal: %d akhir; %d idxStart: %d keKiri: %d\n",awal, akhir, idxStart, keKiri);
		if(idxStart == -1){printf("NO\n"); return 0;}
		else{

			int ukuran = akhir - awal + 1;
			int iterasi = ukuran - 1;
			if(!keKiri){
				//iterasi sebanyak
				while(idxStart < akhir) {
					ans.pb(ic(idxStart, 'R'));
					int bil = a[idxStart] + a[idxStart+1];
					it = a.begin() + idxStart;
					a.erase(it); a.erase(it);
					a.insert(it, bil);
					printArray(a);
					akhir--;
				}
				while(idxStart > awal) {
					it = a.begin() + idxStart;
					int bil = a[idxStart] + a[idxStart-1];
					ans.pb(ic(idxStart, 'L'));
					a.erase(it); a.erase(--it);
					a.insert(it, bil);
					printArray(a);
					akhir--;
					idxStart--;
				}
			}else{
				while(idxStart > awal) {
					ans.pb(ic(idxStart, 'L'));
					int bil = a[idxStart] + a[idxStart-1];
					it = a.begin() + idxStart;
					a.erase(it);
					a.erase(--it);
					a.insert(it, bil);
					printArray(a);
					akhir--;
					idxStart--;
				}
				while(idxStart < akhir) {
					int bil = a[idxStart] + a[idxStart+1];
					ans.pb(ic(idxStart, 'R'));
					it = a.begin() + idxStart;
					a.erase(it); a.erase(it);
					a.insert(it, bil);
					printArray(a);
					akhir--;
				}
			}
		}
		// printf("%d %d\n",listSegment[i].first,listSegment[i].second);
	}

	if(ans.size()){
		printf("YES\n");
		for(i=0;i<ans.size();i++){
			printf("%d %c\n",ans[i].first+1, ans[i].second);
		}
	}else{printf("YES\n");}

	return 0;
};