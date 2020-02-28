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
	int q,i,j;
	scanf("%d",&q);
	string st[3];
	for(i=0;i<200000;i++){
		if(i%3 == 0){
			st[0] += 'R';	
		}else if(i%3 == 1){
			st[0] += 'G';
		}else{
			st[0] += 'B';
		}
	}
	for(i=0;i<200000;i++){
		if(i%3 == 0){
			st[1] += 'G';	
		}else if(i%3 == 1){
			st[1] += 'B';
		}else{
			st[1] += 'R';
		}
	}
	for(i=0;i<200000;i++){
		if(i%3 == 0){
			st[2] += 'B';	
		}else if(i%3 == 1){
			st[2] += 'R';
		}else{
			st[2] += 'G';
		}
	}
	int pref[3][200000];
	while(q--){
		int n,k;
		scanf("%d %d",&n,&k);
		string s;
		cin>>s;

		for(i=0;i<3;i++){
			for(j=0;j<n;j++){
				pref[i][j] = 0;
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<n;j++){
				if(s[j] != st[i][j])	{
					pref[i][j] = 1;	
				}
				if(j){
					pref[i][j] += pref[i][j-1];
				}
			}
		}
		int minim = inf;
		for(i=0;i<3;i++){
			int kiri = 0, kanan = k-1;
			int ans = pref[i][kanan];
			minim = min(minim, ans);
			for(j=k;j<n;j++){
				int jawab = pref[i][j] - pref[i][j-k];
				// printf("jawab: %d\n",jawab);
				minim = min(minim, jawab);
			}
		}
		printf("%d\n",minim);
	}
	return 0;
};