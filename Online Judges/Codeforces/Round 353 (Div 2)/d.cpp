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
typedef pair<ii, int> iii;
typedef vector<ii> vii;

bool isValid(ii a){
	return a.first <= a.second;
}

set<iii> s;
set<iii>::iterator it;

void insertProcedure(int bawah, int atas, int bil) {
	ii calonKiri = ii(bawah, bil);
	ii calonKanan = ii(bil+1, atas);
	if(isValid(calonKiri)){
		s.insert(make_pair(calonKiri, bil));
	}
	if(isValid(calonKanan)){
		s.insert(make_pair(calonKanan, bil));
	}
}

int main(){
	int n,i,j;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		int bil;
		scanf("%d",&bil);
		if(i > 0){
			it = s.lower_bound(make_pair(ii(bil, 0), 0));
			iii front = *it;
			if(front.first.first == bil){
				int parent = front.second;
				int bawah = front.first.first, atas = front.first.second;
				printf("%d ",parent);
				insertProcedure(bawah, atas, bil);
				s.erase(it);
			}else{
				it--;
				front = *it;
				int parent = front.second;
				int bawah = front.first.first, atas = front.first.second;

				printf("%d ",parent);
				insertProcedure(bawah, atas, bil);
				s.erase(it);
			}
		}else{
			s.insert(make_pair(ii(1, bil), bil));
			s.insert(make_pair(ii(bil+1, inf), bil));
		}
	}
	printf("\n");
	return 0;
};