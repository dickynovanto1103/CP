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
	clock_t begin = clock();
	int i,j,k;
	string s,t;
	scanf("%d",&k);

	cin>>s>>t;
	int x = s.length(), y = t.length();
	i = 0, j = 0;
	int waktu = 0;
	// x = 2000, y = 1999;
	int batas = 0;
	while(true){
		i++; i %= x;
		j++; j %= y;
		waktu++;
		if(i == 0 && j == 0){
			batas = waktu;
			break;
		}
	}
	// printf("batas: %d\n", );
	vi listBil;
	int tempK = k;
	// printf("batas: %d\n",batas);
	for(int tt=0;tt<batas;tt++){
		if(s[i] != t[j]){
			// printf("%d\n",tt);
			listBil.pb(tt);
			// printf("dipush: %d\n",tt);
			k--;
			if(k == 0){break;}
		}
		i++; i %= x;
		j++; j %= y;
	}
	if(listBil.size() == 0){
		while(k--){printf("-1\n");}
		return 0;
	}
	vector<ll> ans;
	int it = 0;

	while(true){
		// printf("halo\n");
		for(i=0;i<listBil.size();i++){
			ans.pb((ll)listBil[i] + ((ll)it*batas));
			if(ans.size() == tempK){goto here;}
		}
		it++;
	}
	here:
	int ukuran = ans.size();
	for(i=0;i<ukuran;i++){
		printf("%lld\n",ans[i]);
	}
	
	// while((double)(clock() - begin) / CLOCKS_PER_SEC < 1.8) {
	// 	if(s[i] != t[j]){
	// 		printf("%d\n",waktu);
	// 		k--;
	// 		if(k == 0){return 0;}
	// 	}
	// 	i++; i %= x;
	// 	j++; j %= y;
	// 	waktu++;
	// }
	// printf("k: %d\n",k);
	// while(k--){
	// 	printf("-1\n");
	// }

	return 0;
};