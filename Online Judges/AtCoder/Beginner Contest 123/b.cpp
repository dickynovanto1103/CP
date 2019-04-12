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

int main(){
	int a[6];
	int i,j,n;
	for(i=0;i<5;i++){scanf("%d",&a[i]);}
	sort(a,a+5);
	int minim = inf;
	do{
		int time = 0;
		for(i=0;i<5;i++){
			if(time%10 == 0) {
				time += a[i];
			}else{
				int selisih = 10 - time%10;
				time+=selisih;
				time += a[i];
			}
		}
		minim = min(minim, time);
	}while(next_permutation(a,a+5));
	printf("%d\n",minim);
	return 0;
};