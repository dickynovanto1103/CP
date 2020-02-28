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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	int dr[] = {1,0,-1,0};
	int dc[] = {0,1,0,-1};
	vi ans;
	int i,j;
	int sum = 0;
	// printf("%d\n",-1%-1);
	for(i=0;i<4;i++){
		// if(i){printf(" ");}
		if(dr[i] != 0){

			int nilai = y*dr[i];
			if(nilai > 0){
				ans.pb(nilai);
				sum += nilai;
				// printf("%d",nilai);
			}else{
				ans.pb(0);
				// printf("0");
			}
		}
		if(dc[i] != 0){
			int nilai = x * dc[i];
			if(nilai > 0){
				ans.pb(nilai);
				sum += nilai;
				// printf("%d",nilai);
			}else{
				ans.pb(0);
				// printf("0");
			}
		}
	}
	if(sum > n){printf("-1\n");}
	else{
		// printf("halo\n");
		// for(i=0;i<4;i++){
		// 	printf("%d ",ans[i]);
		// }
		// swap()
		// printf("\n");
		int sisa = n-sum;
		vi list0;
		// printf("sisa: %d\n",sisa);
		if(sisa % 2 == 0){
			int bagian = sisa / 2;
			// for(i=0;i<4;i++){
			// 	if(ans[i] > 0){
			// 		ans[i] += bagian;
			// 		i += 2;
			// 		i%=4;
			// 		ans[i] -= bagian;
			// 		found = true;
			// 		break;
			// 	}
			// }
			// if(!found){
			ans[0] += bagian;
			ans[2] += bagian;
			// }
			
			// swap(ans[0], ans[1]);
			// swap(ans[2], ans[3]);
			for(i=0;i<4;i++){
				if(i){printf(" ");}
				printf("%d",abs(ans[i]));
			}
			printf("\n");
		}else{
			printf("-1\n");
		}
		
	}

	
	
	return 0;
};