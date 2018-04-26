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

int a[16],b[16],c[16];
int n,k;

bool btck(int idx, vector<int> res){
	if(idx==n){
		if(res.size()!=k)
			return false;
		bool sama = true;
		for(int i=0;i<k;i++){
			if(res[i]!=b[i]){
				sama = false;
				break;
			}
		}
		if(sama)
			return 1;
		reverse(res.begin(), res.end());
		sama = true;
		for(int i=0;i<k;i++){
			if(res[i]!=b[i]){
				sama = false;
				break;
			}
		}
		return sama;
	}
	reverse(res.begin(), res.end());
	vector<int> temp(res);
	for(int i=idx;i<n && i-idx<k;i++){
		if(temp.size()<i-idx+1)
			temp.pb(a[i]);
		else
			temp[i-idx]+=a[i];
		bool benar=btck(i+1, temp);
		if(benar)
			return true;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", a+i);
	scanf("%d", &k);
	for(int i=0;i<k;i++)
		scanf("%d", b+i);
	std::vector<int> k;
	if(btck(0, k))
		puts("S");
	else
		puts("N");
	return 0;
};