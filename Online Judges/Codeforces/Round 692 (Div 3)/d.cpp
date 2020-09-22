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
	int a[200001];
	int color[200001];
	while(tc--){
		// printf("halo\n");
		scanf("%d",&n);
		set<int> s;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			s.insert(a[i]);
			color[i] = -1;
		}

		if(s.size() == 1){
			printf("1\n");
			for(i=0;i<n;i++){
				if(i){printf(" ");}
				printf("%d",1);
			}
			printf("\n");
		}else{
			if(n % 2 == 0){
				printf("2\n");
				for(i=0;i<n;i++){
					if(i){printf(" ");}
					if(i%2 == 1){printf("1");}
					else{printf("2");}
				}
				printf("\n");
			}else{
				bool adaSama = false;
				int idx1, idx2;
				for(i=0;i<n;i++){
					int next = (i + 1) % n;
					if(a[i] == a[next]){
						adaSama = true;
						color[i] = 1;
						color[next] = 1;
						idx1 = i, idx2 = next;
						break;
					}
				}
				if(!adaSama){
					printf("3\n");
					for(i=0;i<n;i++){
						if(i){printf(" ");}
						if(i == n-1){printf("3");}
						else if(i % 2 == 0){printf("1");}
						else{printf("2");}
					}
					printf("\n");
				}else{
					printf("2\n");
					int maks = max(idx1, idx2), minim = min(idx1, idx2);
					// printf("maks: %d minim: %d\n",maks, minim);
					if(minim == 0 && maks == n-1){
						for(i=minim+1;i<maks;i++){
							if(color[i-1] == 1){color[i] = 2;}
							else{color[i] = 1;}
						}
					}
					for(i=minim-1;i>=0;i--){
						if(color[i + 1] == 1){color[i] = 2;}
						else{color[i] = 1;}
					}
					for(i=maks+1;i<n;i++){
						if(color[i - 1] == 1){color[i] = 2;}
						else{color[i] = 1;}
					}
					for(i=0;i<n;i++){
						if(i){printf(" ");}
						printf("%d",color[i]);
					}
					printf("\n");
				}
			}
		}

	}
	
	return 0;
};