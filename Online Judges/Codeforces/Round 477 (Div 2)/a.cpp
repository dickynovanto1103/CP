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

ii convertToHourAndMinute(int n){
	int h,m;
	h = n/60;
	n-=(h*60);
	m = n;
	return ii(h,m);
}

int main(){
	int n,i,j,s;
	ii halo = convertToHourAndMinute(359);
	// printf("%d %d\n", halo.first, halo.second);
	scanf("%d %d",&n,&s);
	int a[102];
	a[0] = 0;
	for(i=0;i<n;i++){
		int h,m;
		scanf("%d %d",&h,&m);
		a[i+1] = h*60 + m;
	}
	for(i=0;i<n;i++) {
		if(i==0){
			if(a[i+1]>=(s+1)){printf("%d %d\n",0,0); return 0;}
		}else{
			if((a[i+1] - a[i]) >= (2*s+2)){
				ii ans = convertToHourAndMinute(a[i] + s+1);
				printf("%d %d\n",ans.first, ans.second);
				return 0;
			}
		}
	}
	ii ans = convertToHourAndMinute(a[i] + s+1);
	printf("%d %d\n",ans.first, ans.second);
	return 0;
};