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

string gen(int awal, int n){
	int i;
	string s;
	for(i=0;i<n;i++){
		s += (awal + '0');
		awal = 1 - awal;
	}
	return s;
}

int banyakReverse(string s, string satu, int n){
	bool prev = false;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i] != satu[i]){
			if(!prev){
				prev = true;
				cnt++;
			}
		}else{
			prev = false;
		}
	}
	return cnt;
}

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;
		string satu = gen(1, n), dua = gen(0, n);
		int awal = 0, akhir = 0, ans = inf;
		int ans1 = banyakReverse(s, satu, n), ans2 = banyakReverse(s, dua, n);
		printf("%d\n",min(ans1, ans2));
		
	}
	
	return 0;
};