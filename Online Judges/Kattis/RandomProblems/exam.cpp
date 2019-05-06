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
	int score,i,j;
	string a,b;
	scanf("%d",&score);
	cin>>a>>b;
	int n = a.length();
	int sama = 0, beda = 0;
	for(i=0;i<n;i++){
		if(a[i] != b[i]){beda++;}
		else{sama++;}
	}
	int ans = 0;
	int minim = min(score, sama);
	ans += minim;
	sama -= minim;
	score -= minim;
	if(sama == 0){
		//score ga 0
		beda-=score;
		ans += beda;
	}else{
		//sama ga 0
		// printf("ans: %d sama jd: %d beda: %d\n",ans,sama,beda);
		// ans -= sama;
		ans += beda;
	}
	printf("%d\n",ans);

	return 0;
};