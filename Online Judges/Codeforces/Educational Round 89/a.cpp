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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,a,b;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&a,&b);
		if(a > b){swap(a,b);}

		if(a == b){
			int ans = (a*2)/3;
			printf("%d\n",ans);
		}else{
			if(a*2 <= b){printf("%d\n",a);}
			else{
				int pengurangan = b-a;
				a -= pengurangan;
				b -= pengurangan;

				int ans = pengurangan;
				ans += (a*2)/3;
				printf("%d\n",ans);
			}
		}
	}
	
	return 0;
};