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
	int n,i,j;
	scanf("%d",&n);
	int a[9], b[9];
	int arr[9];
	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		arr[i] = i;
	}
	do{
		
		for(i=0;i<(1<<n);i++){
			vi listBil;
			for(j=0;j<n;j++){
				if((1<<j) & i){
					listBil.pb(0);
				}else{
					listBil.pb(1);
				}
			}

			bool valid = true;
			for(j=0;j<n-1;j++){
				int idx = arr[j];
				int next = arr[j+1];
				int a1 = a[idx], b1 = b[idx];
				if(listBil[j] == 0) {
					swap(a1,b1);
				}
				int c = a[next], d = b[next];
				if(listBil[j+1] == 0) {
					swap(c,d);
				}
				// if(arr[0] == 2 && arr[1] == 1 && arr[2] == 3 && arr[3] == 4 && arr[4] == 0){
				// 	printf("j: %d %d %d %d %d\n",j, a1,b1,c,d);
				// }
				if(b1 == c){

				}else{
					valid = false;
					break;
				}
			}
			if(valid){
				for(j=0;j<n;j++){
					printf("%d %c\n",arr[j]+1, listBil[j]==0 ? 'b' : 'a');
				}
				return 0;
			}
		}
	}while(next_permutation(arr, arr+n));
	printf("ga ada\n");
	return 0;
};