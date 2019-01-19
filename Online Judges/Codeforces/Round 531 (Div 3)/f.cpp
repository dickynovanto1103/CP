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

multiset<int> s[10010];
multiset<int>::iterator it;

int n,m;

bool cobaMaks(int mid) {
	printf("mid: %d\n",mid);
	int i,j;
	multiset<int> temp[10010];
	for(i=0;i<m;i++){temp[i] = s[i];}
	// for(it=temp[0].begin();it!=temp[0].end();it++){
	// 	printf("elemen: %d\n",*it);
	// }
	it = --temp[0].end();
	int first = *(it);

	temp[0].erase(it);
	// printf("first: %d\n",first);

	for(i=0;i<m;i++){
		// printf("i: %d\n",i);
		if(i == 0){
			for(j=0;j<n-1;j++){
				// printf("j: %d\n",j);
				//coba naik
				it = temp[i].lower_bound(first + mid);
				// printf("cari: %d\n",first+mid);
				if(it == temp[i].end()){
					//coba turun
					it = temp[i].lower_bound(first - mid);
					// printf("cari lagi: %d\n",first-mid);
					if(it == temp[i].end()){it--;}
					if(*it > (first - mid)){
						if(it!=temp[i].begin()){
							// printf("mundur\n");
							it--;	
						}else{
							return false;
						}
					}
				}
				first = *it;
				// printf("first jadi: %d\n",first);
				temp[i].erase(it);
				// printf("ukuran: %d\n",(int)temp[i].size());
				// for(it=temp[0].begin();it!=temp[0].end();it++){
				// 	printf("elemen sekarang: %d\n",*it);
				// }
				//coba turun			
			}
		}else{
			for(j=0;j<n;j++){
				// printf("j: %d\n",j);
				it = temp[i].lower_bound(first + mid);

				if(it == temp[i].end()){
					//coba turun
					it = temp[i].lower_bound(first - mid);
					if(it == temp[i].end()){it--;}
					if(*it > (first - mid)){
						if(it!=temp[i].begin()){
							it--;	
						}else{
							return false;
						}
					}
				}
				first = *it;
				temp[i].erase(it);
			}
		}
	}
	return true;
}

bool cobaMin(int mid) {
	int i,j;
	printf("mid min: %d\n",mid);
	multiset<int> temp[10010];
	for(i=0;i<m;i++){temp[i] = s[i];}
	it = temp[0].begin();
	int first = *(it);
	printf("first: %d\n",first);
	temp[0].erase(it);
	for(i=0;i<m;i++){
		if(i == 0){
			for(j=0;j<n-1;j++){
				//coba naik
				it = temp[i].lower_bound(first + mid);
				printf("cari: %d\n", first+mid);
				if(it == temp[i].end()){
					//coba turun
					it = temp[i].lower_bound(first - mid);
					printf("cari lagi: %d\n",first - mid);
					if(it == temp[i].end()){
						printf("mundur karena akhir\n");
						it--;
					}
					if(*it > (first - mid)){
						if(it!=temp[i].begin()){
							printf("mundur\n");
							it--;	
						}else{
							return false;
						}
					}
				}
				first = *it;
				printf("first jadi: %d\n",first);
				temp[i].erase(it);
				//coba turun			
			}
		}else{
			for(j=0;j<n;j++){
				it = temp[i].lower_bound(first + mid);

				if(it == temp[i].end()){
					//coba turun
					it = temp[i].lower_bound(first - mid);
					if(it == temp[i].end()){it--;}
					if(*it > (first - mid)){
						if(it!=temp[i].begin()){
							it--;	
						}else{
							return false;
						}
					}
				}
				first = *it;
				temp[i].erase(it);
			}
		}
	}
	return true;
}

bool coba(int mid) {
	return cobaMaks(mid) || cobaMin(mid);
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			int bil;
			scanf("%d",&bil);
			s[j].insert(bil);
		}
	}
	int kiri = 0, kanan = 1e9 + 7, mid, ans;
	while(kiri <= kanan){
		mid = (kiri+kanan)/2;
		printf("kiri: %d kanan: %d\n",kiri, kanan);
		if(coba(mid)){
			ans = mid;
			kiri = mid+1;
		}else{
			kanan = mid-1;
		}
	}
	printf("%d\n",ans);
	return 0;
};