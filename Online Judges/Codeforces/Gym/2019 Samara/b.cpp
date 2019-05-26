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
	string kata[2];
	for(i=0;i<2;i++){
		cin>>kata[i];
	}
	n = kata[0].length();
	int satu = 0, dua = 0, both = 0, notBoth = 0;
	for(i=0;i<n;i++){
		if(kata[0][i] == '.' && kata[1][i] == '#'){dua++;}
		if(kata[0][i] == '#' && kata[1][i] == '#'){both++;}
		if(kata[0][i] == '.' && kata[1][i] == '.'){notBoth++;}
		if(kata[0][i] == '#' && kata[1][i] == '.'){satu++;}
	}
	string ans[2];
	ans[0] = kata[0];
	ans[1] = kata[1];
	if(satu > 0 && dua > 0 && both == 0){
		printf("NO\n");
	}else{
		int cnt = 0;
		printf("YES\n");
		// printf("%d %d %d %d\n", notBoth, satu, dua, both);
		for(i=0;i<notBoth;i++){
			ans[0][cnt] = '.';
			ans[1][cnt] = '.';
			cnt++;
		}
		for(i=0;i<satu;i++){
			ans[0][cnt] = '#';
			ans[1][cnt] = '.';
			cnt++;
		}
		for(i=0;i<both;i++){
			ans[0][cnt] = '#';
			ans[1][cnt] = '#';
			cnt++;
		}
		for(i=0;i<dua;i++){
			ans[0][cnt] = '.';
			ans[1][cnt] = '#';
			cnt++;
		}
		cout<<ans[0]<<endl<<ans[1]<<endl;
	}
	return 0;
};