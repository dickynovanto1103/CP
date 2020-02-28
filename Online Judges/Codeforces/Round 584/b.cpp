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
	string s;
	cin>>s;
	int a[101], b[101];
	int ans = 0;
	for(i=0;i<n;i++){
		if(s[i] == '1'){ans++;}
	}

	for(i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}

	for(i=1;i<=1000;i++){
		for(j=0;j<n;j++){
			if(i == b[j]){
				s[j] = (s[j] == '0' ? '1' : '0');
			}else if(i > b[j]){
				int selisih = i - b[j];
				if(selisih % a[j] == 0){
					s[j] = (s[j] == '0' ? '1' : '0');
				}
			}
		}
		int cur = 0;
		for(j=0;j<n;j++){
			if(s[j] == '1'){cur++;}
		}
		ans = max(ans, cur);
	}
	printf("%d\n",ans);
	return 0;
};