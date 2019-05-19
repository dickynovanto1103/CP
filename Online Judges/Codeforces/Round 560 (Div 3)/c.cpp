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
	string s;
	scanf("%d",&n);
	cin>>s;
	int odd = 1;
	bool isprinted[200010];
	memset(isprinted, true, sizeof isprinted);
	int cntHapus = 0;
	for(i=0;i<n-1;i++){
		if(odd) {
			if(s[i] == s[i+1]){
				isprinted[i] = false;
				cntHapus++;
			}else{
				odd = 1 - odd;
			}
		}else{
			odd = 1 - odd;
		}
	}
	if((n - cntHapus )% 2 == 1){
		cntHapus++;
		for(i=n-1;i>=0;i--){
			if(isprinted[i]){isprinted[i] = false; break;}
		}
	}
	printf("%d\n",cntHapus);
	for(i=0;i<n;i++){
		if(isprinted[i]){printf("%c",s[i]);}
	}
	printf("\n");
	return 0;
};