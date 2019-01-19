#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n),n){
		multiset<int> s;
		multiset<int>::iterator it,it2;
		long long sum = 0;
		while(n--){
			int k;
			scanf("%d",&k);
			while(k--){
				int bil;
				scanf("%d",&bil); 
				s.insert(bil);
			}
			
			it = s.begin(); it2 = --s.end();
			//printf("%d - %d\n",*it2, *it);
			sum+=(*it2 - *it);
			s.erase(it); s.erase(it2);
			//isi set dengan elemen queue;
			
		}
		printf("%lld\n",sum);
	}
	return 0;
}