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
	int n,i,j;
	string a,b;
	scanf("%d",&n);
	cin>>a>>b;
	int ans = 0;
	for(i=0;i<(n-1);i++){
		if(a[i] == '1' && a[i+1] == '0' && b[i] == '0' && b[i+1] == '1'){
			swap(a[i], a[i+1]);
			ans++;
		}
		if(a[i] == '0' && a[i+1] == '1' && b[i] == '1' && b[i+1] == '0'){
			swap(a[i], a[i+1]);
			ans++;
		}
	}
	for(i=0;i<n;i++){
		if(a[i] != b[i]){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
};