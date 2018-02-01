#include <bits/stdc++.h>

using namespace std;
#define inf 2000000000
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

vector<vi> vec;

int main(){
	int n,i,j;
	vi a;
	scanf("%d",&n);
	vec.assign(n,vi());
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil); a.pb(bil);
	}
	set<int> s;//mencatat headnya
	set<int>::iterator it;
	unordered_map<int,int> mapper;//untuk menyimpan index vector
	s.insert(inf);
	
	int cnt = 0;
	
	for(i=0;i<n;i++){
		int bil = a[i];
		//printf("bil: %d\n",bil);
		it = s.lower_bound(bil);
		if(*it==inf){
			if(it==s.begin()){//pertama banget
				vec[cnt].pb(bil);
				s.insert(bil);
				mapper[bil] = cnt;
				cnt++;
			}else{
				it--;
				int idx = mapper[*it];
				vec[idx].pb(bil);
				s.erase(it);
				s.insert(bil);
				mapper[bil] = idx;
			}
			
		}else{
			if(it==s.begin()){//yang ditunjuk setelah lower_bound ternyata awal dari set..harus pushback vec baru
				vec[cnt].pb(bil);
				s.insert(bil);
				mapper[bil] = cnt;
				cnt++;
			}else{
				it--;
				int idx = mapper[*it];
				s.erase(it);
				vec[idx].pb(bil);
				s.insert(bil);
				mapper[bil] = idx;
			}
		}
	}
	//printf("ukuran array: %d\n",cnt);
	for(i=0;i<cnt;i++){
		for(j=0;j<vec[i].size();j++){
			
			if(j){printf(" ");}
			printf("%d",vec[i][j]);
		}
		printf("\n");
	}
	return 0;
};