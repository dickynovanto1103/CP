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

const int maxn = 5e4 + 4;

int a[maxn];
ll banyakInversi;

vi combine(vi& vec1, vi& vec2){
	int idx1 = 0, idx2 = 0;
	int i;
	bool ujung = false;
	vi ans;
	for(i=0;i<vec1.size();i++){
		idx1 = i;
		int bil = vec1[i];
		
		if(bil<vec2[idx2]){
			ans.pb(bil); continue;
		}
		while(bil>vec2[idx2]){
			ans.pb(vec2[idx2]);
			banyakInversi+=vec1.size()-i;
			idx2++;
			if(idx2==vec2.size()){ujung = true; break;}
		}
		if(ujung){break;}
		ans.pb(bil);
	}
	while(idx2<vec2.size()){
		ans.pb(vec2[idx2]);
		idx2++;
	}
	
	while(i<vec1.size()){
		ans.pb(vec1[i]);
		i++;
	}

	return ans;
}

vi merge_sort(int l, int r){
	if(l==r){
		vi vec;
		vec.pb(a[l]);
		return vec;
	}else{

		int mid = (l+r)/2;
		vi ans1 = merge_sort(l,mid);
		vi ans2 = merge_sort(mid+1,r);
		vi ans = combine(ans1,ans2);
		
		return ans;
	}
}

int main(){
	int tc,i,j,n;
	
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){scanf("%d",&a[i]);}
		int mid = (1+n)/2;
		banyakInversi = 0;
		vi ans = merge_sort(1,n);
		
		if(banyakInversi%2==0){printf("YA\n");}
		else{printf("TIDAK\n");}
	}
	return 0;
};