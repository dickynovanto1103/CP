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

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		vi v;
		int now = 1;
		int bakteri = 1;
		v.pb(bakteri);
		while(now < n){
			int maksVal = bakteri * 2;
			int selisih = n - now;
			if(selisih >= maksVal){
				bakteri = maksVal;
				v.pb(bakteri);
				now += maksVal;
			}else{
				bakteri = selisih;
				now += selisih;
				v.pb(bakteri);
			}
		}

		sort(v.begin(), v.end());
		
		

		// while(now < n){
		// 	int selisih = n - now;
		// 	int maksVal = 2*bakteri;
		// 	int maksDiv = bakteri;
		// 	for(i=1;i*i<=selisih;i++){
		// 		if(selisih % i == 0){
		// 			int div1 = i;
		// 			int div2 = selisih / i;
		// 			if(div1 <= maksVal) {
		// 				maksDiv = max(maksDiv, div1);
		// 			}
		// 			if(div2 <= maksVal){
		// 				maksDiv = max(maksDiv, div2);
		// 			}
		// 		}
		// 	}
		// 	// printf("selisih: %d maksVal: %d maksDiv: %d\n",selisih, maksVal, maksDiv);
		// 	now += maksDiv;
		// 	bakteri = maksDiv;
		// 	v.pb(bakteri);
		// 	// printf("now jadi: %d push bakteri: %d\n",now, bakteri);
		// }
		int ukuran = v.size();
		printf("%d\n",ukuran-1);
		for(i=0;i<ukuran-1;i++){
			if(i){printf(" ");}
			printf("%d",v[i+1] - v[i]);
		}
		printf("\n");
	}
	
	return 0;
};