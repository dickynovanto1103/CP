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

int main(){
	int a[3],i,j;
	int minim = inf;
	for(i=0;i<3;i++){
		scanf("%d",&a[i]);
		minim = min(minim, a[i]);
	}
	int ans = 0;
	for(i=0;i<3;i++){
		if(a[i] != minim){
			int selisih = a[i] - minim;
			int loop = selisih / 3;
			ans += loop;
			a[i] -= (loop*3);
		}
	}
	// printf("minim: %d ans jd: %d\n",minim,ans);

	for(i=0;i<3;i++){
		if((a[i] - minim) == 2){
			if(a[i] >= 3){
				a[i] -= 3;
				ans++;	
			}
			
		}
	}
	int minimal = inf;
	for(i=0;i<3;i++){
		minimal = min(minimal, a[i]);
	}
	ans+=minimal;
	printf("%d\n",ans);
	return 0;
};