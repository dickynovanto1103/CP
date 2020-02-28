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
	int tc,i,j;
	scanf("%d",&tc);
	printf("tc: %d\n",tc);
	while(tc--){
		int n;
		printf("tc: %d\n",tc);
		scanf("%d",&n);
		printf("n: %d\n",n);
		char kar;
		int a,b;
		int dum;
		while(cin>>dum) {
			if(dum == 'c' || dum == 'q') {
				cin>>a>>b;
			}else{
				break;
			}
			cout<<kar<<" "<<a<<" "<<b<<endl;
		}
	}
	return 0;
};