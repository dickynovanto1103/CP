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

vii p;
vii sortX, sortY;

bool cmp(ii a, ii b){
	if(a.second == b.second){return a.first < b.first;}
	return a.second < b.second;
}

// bool isExist(ii a, ii b){
// 	int minimX = min(a.first, b.first);
// 	int maksX = max(a.first, b.first);
// 	int minimY = min(a.second, b.second);
// 	int maksY = max(a.second, b.second);
// 	a = ii(minimX, minimY), b = ii(maksX, maksY);
// 	//cari ada ga lingkaran yang lebih besar
// 	int idx1 = lower_bound(sortX.begin(), sortX.end(), ii(a.first, b.first)) - sortX.begin();
// 	ii satu, dua;
// 	if(idx1 == 0){return false;}
// 	else{
// 		idx1--;
// 		satu = sortX[idx1];
// 	}
// 	int idx2 = 

// }

bool isValidKurang(ii a, ii b, ii c){
	int minimX = min(c.first, b.first);
	int maksX = max(c.first, b.first);
	int minimY = min(c.second, b.second);
	int maksY = max(c.second, b.second);
	b = ii(minimX, minimY), c = ii(maksX, maksY);
	if(a.first <= b.first && a.second <= b.second){return true;}
	return false;
}
bool isValidLebih(ii a, ii b, ii c){
	int minimX = min(c.first, b.first);
	int maksX = max(c.first, b.first);
	int minimY = min(c.second, b.second);
	int maksY = max(c.second, b.second);
	b = ii(minimX, minimY), c = ii(maksX, maksY);
	if(a.first >= c.first && a.second >= c.second){return true;}
	return false;
}
bool isValid(ii a, ii b){
	if(a.first == b.first || a.second == b.second){return false;}
	return true;
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p.pb(ii(x,y));
	}
	
	sortX = p; sortY = p;
	sort(sortX.begin(), sortX.end()); sort(sortY.begin(), sortY.end(), cmp);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			ii satu = sortX[i], dua = sortX[j];
			if(!isValid(satu, dua)){continue;}
			// printf("i; %d j: %d\n",i,j);
			// printf("satu: %d %d dua: %d %d\n",satu.first, satu.second, dua.first, dua.second);
			int cntKurang = 0, cntLebih = 0;
			vi listKurang, listLebih;
			for(int k=0;k<n;k++){
				if(k != i && k!=j){
					// printf("sort[%d]: %d %d\n",k,sortX[k].first,sortX[k].second);
					if(isValidKurang(sortX[k], satu, dua)){
						cntKurang++;
						listKurang.pb(sortX[k]);
					}
					if(isValidLebih(sortX[k], satu, dua)){
						cntLebih++;
						listLebih.pb(sortX[k])
					}
					if(cntKurang >= 1 && cntLebih >= 1){printf("YA\n"); return 0;}
				}
			}
			for(int k=0;k<listKurang.size();k++){
				for(int l=0;l<listLebih.size();l++){
					if(listKurang[k].first == listLebih)
				}
			}
			// printf("cntKurang: %d cntLebih: %d\n",cntKurang, cntLebih);
		}
	}
	printf("TIDAK\n");
	return 0;
	// for(i=1;i<n-1;i++){
	// 	int x = sortX[i].first, y = sortX[i].second;
	// 	//cari point terdekat ke 4 kuadran
	// 	ii a = ii(x,y),b = ii(x,y),c = ii(x,y), d= ii(x,y);
	// 	int idx1 = lower_bound(sortX.begin(), sortX.end(), ii(x,y+1)) - sortX.begin();
	// 	if(idx1 < n){
	// 		a = sortX[idx1];
	// 	}
	// 	int idx2 = lower_bound()

	// }
	return 0;
};