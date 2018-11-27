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

const int maxn = 4e5 + 5;

int a[maxn];

int main(){
	int n,q,k,i,j;
	scanf("%d %d %d",&n,&q,&k);

	for(i=400000;i<400000 + n;i++){
		scanf("%d",&a[i]);
	}
	int head = 400000, tail = 400000 + n-1;
	set<int> s;
	int cnt1 = 0;
	for(i=head;i<=tail;i++){
		if(a[i] == 0){
			if(cnt1 == 0){continue;}
			s.insert(cnt1);
			cnt1 = 0;
		}else{
			cnt1++;
		}
	}
	if(cnt1 != 0){
		s.insert(cnt1);
	}
	string kata;
	cin>>kata;
	for(i=0;i<q;i++){
		char kar = kata[i];
		if(kar == '?'){
			int elemenTerakhir = *(--s.end());
			printf("%d\n",min(elemenTerakhir, k));
		}else{
			
		}
	}

	return 0;
};