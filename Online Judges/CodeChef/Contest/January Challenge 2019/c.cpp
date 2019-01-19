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

const int maxn = 2e5 + 5;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int a[maxn], b[maxn];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d",&b[i]);
	}
	set<int> s1,s2;
	vii v1,v2;
	for(i=0;i<n;i++){
		if(s1.count(a[i])){
			continue;
		}else{
			v1.pb(ii(a[i],i));
			s1.insert(a[i]);
			// s1.insert(ii(a[i], i));
		}
	}
	for(i=0;i<m;i++){
		if(s2.count(b[i])){
			continue;
		}else{
			v2.pb(ii(b[i],i));
			s2.insert(b[i]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int ukuran1 = v1.size(), ukuran2 = v2.size();
	set<int> s;
	int cnt = 0;

	if(ukuran1 < ukuran2){
		
		for(j=0;j<ukuran2;j++){
			int sum = v1[0].first + v2[j].first;
			printf("%d %d\n",v1[0].second, v2[j].second);
			cnt++;
			s.insert(sum);
		}
		for(i=1;i<ukuran1;i++){
			for(j=max(0,ukuran2-5);j<ukuran2;j++){
				int sum = v1[i].first + v2[j].first;
				if(s.count(sum)){continue;}
				printf("%d %d\n",v1[i].second, v2[j].second);
				
				cnt++;
				if(cnt == (n+m-1)){return 0;}
				s.insert(sum);		
			}
		}
	}else{
		for(j=0;j<ukuran1;j++){
			int sum = v1[j].first + v2[0].first;
			// printf("halo sum: %d\n",sum);
			printf("%d %d\n",v1[j].second, v2[0].second);
			cnt++;
			s.insert(sum);
		}
		for(i=1;i<ukuran2;i++){
			for(j=max(0,ukuran1-5);j<ukuran1;j++){
				int sum = v1[j].first + v2[i].first;
				if(s.count(sum)){continue;}
				printf("%d %d\n",v1[j].second, v2[i].second);
				
				cnt++;
				if(cnt == (n+m-1)){return 0;}
				s.insert(sum);		
			}
		}
	}
	
	return 0;
};