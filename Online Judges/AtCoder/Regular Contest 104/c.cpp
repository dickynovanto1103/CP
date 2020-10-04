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

int a[101], b[101];
bool vis[201];

bool fill(int n) {
	vii listFull;
	int i,j;
	//cari list komplit dulu yg udah ada info a[i], b[i] nya...fill the puzzle
	for(i=0;i<n;i++){
		if(a[i] != -1 && b[i] != -1) {
			listFull.pb(ii(a[i], b[i]));
		}
	}
	bool valid = true;
	for(i=0;i<listFull.size();i++) {
		ii pas = listFull[i];
		int awal = pas.first, akhir = pas.second;
		
		for(j=awal;j<akhir;j++){ //eksklusi di akhir karena pas di akhir dia keluar..jd ga perlu diperhitungkan
			//it's either (j, j + akhir - awal)...atau (j - (akhir - awal), j)
			bool found = false;

			for(int k=0;k<n;k++){
				if(a[k] == j && b[k] == (j + akhir - awal)) { //sudah kefill
					break;
				}
				if(a[k] == j && b[k] == -1){
					b[k] = j + akhir - awal;
					if(b[k] > 2*n){
						valid = false;
						break;
					}
					if(vis[b[k]]) {
						valid = false;
						break;
					}
					vis[b[k]] = true;
					found = true;
					break;
				} else if (a[k] == -1 && b[k] == (j + akhir - awal)){
					a[k] = j;
					if(vis[a[k]]) {
						valid = false;
						break;
					}
					vis[a[k]] = true;
					found = true;
					break;
				} else if(b[k] == j) {
					if(a[k] == (j - (akhir - awal))) {
						break;
					}else if(a[k] == -1){
						a[k] = j - (akhir - awal);
						if(a[k] < 1){
							valid =false;
							break;
						}
						if(vis[a[k]]) {
							valid = false;
							break;
						}
						vis[a[k]] = true;
						found = true;
						break;
					}else{ //kefill dengan value yg lain
						valid = false;
						break;
					}
				} else if(a[k] == (j - (akhir - awal))) {
					if(b[k] == j){
						break;
					}else if(b[k] == -1){
						b[k] = j;
						if(vis[b[k]]){
							valid = false;
							break;
						}
						vis[b[k]] = true;
						found = true;
						break;
					}
				}
			}

			if(!valid){
				break;
			}
			// if(!found){
			// 	//coba cari yang -1 -1 dan assign dengan either j, j + (akhir - awal) atau j - (akhir - awal), j
			// 	for(int k=0;k<n;k++){
			// 		if(a[k] == -1 && b[k] == -1){
			// 			if(j + (akhir - awal) <= 2*n && !vis[j] && !vis[j + (akhir - awal)]) {
			// 				a[k] = j; b[k] = j + (akhir - awal);
			// 				vis[a[k]] = true; vis[b[k]] = true;
			// 				found = true;
			// 				break;
			// 			}
			// 			if(j - (akhir - awal) >= 1 && !vis[j - (akhir - awal)] && !vis[j]){
			// 				a[k] = j - (akhir - awal); b[k] = j;
			// 				vis[a[k]] = true; vis[b[k]] = true;
			// 				found = true;
			// 				break;
			// 			}
			// 		}
			// 	}
			// 	if(!found){
			// 		valid = false;
			// 		break;
			// 	}
			// }
		}
		if(!valid){
			break;
		}
	}

	if(!valid){
		return false;
	}

	//fill in the remaining -1
	for(i=0;i<n;i++){
		if(a[i] == -1 && b[i] != -1){
			//coba cari yang terdekat 
			int val = b[i];
			bool found = false;
			for(j=val-1;j>=1;j--){
				if(!vis[j]){
					a[i] = j;
					vis[j] = true;
					found = true;
					break;
				}
			}
			if(!found){valid = false; break;}
		} else if(a[i] != -1 && b[i] == -1){
			int val = a[i];
			bool found = false;
			for(j=val+1;j<=2*n;j++){
				if(!vis[j]){
					b[i] = j;
					vis[j] = true;
					found = true;
					break;
				}
			}
			if(!found){valid = false; break;}
		}
	}

	return valid;
}

bool checkValidity(int n) {
	int i,j;
	bool valid = true;
	for(i=0;i<n;i++){
		if(a[i] != -1 && b[i] == -1) {
			int val = a[i];
			//cek apakah ada value yg lebih besar dari val
			bool found = false;
			for(j=val+1;j<=2*n;j++){
				if(!vis[j]){
					found = true;
					break;
				}
			}
			if(!found){
				valid = false;
				break;
			}
		} else if(a[i] == -1 && b[i] != -1) {
			int val = b[i];
			bool found = false;
			for(j=val-1;j>=1;j--){
				if(!vis[j]) {
					found = true;
					break;
				}
			}
			if(!found){
				valid = false;
				break;
			}
		}
	}
	return valid;
}

int main(){
	int n,i,j;
	
	while(scanf("%d",&n) !=EOF){
		memset(vis, false, sizeof vis);

		bool valid = true;
		for(i=0;i<n;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i] != -1){
				if(vis[a[i]]){
					valid =false;
				}
				vis[a[i]] = true;
			}

			if(b[i] != -1){
				if(vis[b[i]]){
					valid = false;
				}
				vis[b[i]] = true;
			}
			if(a[i] != -1 && b[i] != -1 && a[i] >= b[i]){
				valid = false;
			}
			if(b[i] == 1){
				valid = false;
			}
			if(a[i] == 2*n){
				valid = false;
			}
		}
		if(!valid){
			printf("No\n");
			continue;
		}

		valid = fill(n);
		if(!valid){
			printf("No\n");
			continue;
		}
		valid = checkValidity(n);

		if(valid){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
	
	return 0;
};