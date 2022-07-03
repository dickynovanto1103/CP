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
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		int n;
		scanf("%d",&n);
		int a[50001];
		int b[50001];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}

		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
		}

		int valid = true;
		for(int i=0;i<n;i++){
			if(b[i] > a[i]){
				valid = false;
				break;
			}
		}

		if(!valid){
			puts("NO");
			continue;
		}

		int selisih = -1;
		for(int i=0;i<n;i++){
			if(b[i] != 0){
				if(selisih == -1) {selisih = a[i] - b[i];}
				else{
					if(selisih != (a[i] - b[i])){
						valid = false;
						break;
					}
				}
			}
		}

		if(!valid){
			puts("NO");
			continue;
		}

		if(selisih == -1){puts("YES"); continue;}//b[i] = 0 semua

		int maxSelisih = 0;
		for(int i=0;i<n;i++){
			if(b[i] == 0){
				maxSelisih = max(maxSelisih, a[i] - b[i]);
			}
		}

		if(maxSelisih > selisih) {valid = false;}

		if(!valid){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	
	return 0;
};