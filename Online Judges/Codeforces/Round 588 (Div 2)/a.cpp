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
	int a[4];
	int sum = 0;
	for(int i=0;i<4;i++){scanf("%d",&a[i]); sum += a[i];}
	sort(a,a+4);
	int tot = 0;
	int i,j;
	for(i=0;i<4;i++){
		if(a[i] == sum - a[i]){
			printf("YES\n");
			return 0;
		}
	}
	for(i=0;i<4;i++){
		for(j=i+1;j<4;j++){
			int tot = a[i] + a[j];
			if(tot == sum - tot){
				printf("YES\n");
				return 0;
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=i+1;j<4;j++){
			for(int k=j+1;k<4;k++){
				int tot = a[i] + a[j] + a[k];
				if(tot == sum - tot){
					printf("YES\n");
					return 0;
				}	
			}
			
		}
	}
	printf("NO\n");
	return 0;
};