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
typedef set<int> si;

vector<si> AdjList;

int main(){
	string kata;
	cin>>kata;
	string temp = kata;
	AdjList.assign(27,si());
	int i;
	
	set<int>::iterator it;
	
	sort(kata.begin(), kata.end());

	for(i=0;i<kata.length();i++) {
		char kar = kata[i];
		int idx = kar-'a';
		AdjList[idx].insert(i);
	}
	// for(i=0;i<26;i++){
	// 	printf("kar %c:",i+'a');
	// 	for(it = AdjList[i].begin();it!=AdjList[i].end();it++) {
	// 		printf(" %d",*it);
	// 	}
	// 	printf("\n");
	// }

	for(i=0;i<kata.length();i++) {
		char kar = kata[i];
		if(kar == temp[i]) {continue;}
		//cari karakter seharusnya

		char karSeharusnya = temp[i];
		// printf("kar: %c karSeharusnya: %c\n",kar,karSeharusnya);
		// it = AdjList[karSeharusnya-'a'].upper_bound(i);
		// if(it==AdjList[karSeharusnya-'a'].end()) {
		// 	printf("masuk sini gan\n");
		// 	continue;
		// }
		// int bil = *it;
		// printf("kar: %c karSeharusnya: %c bil: %d\n",kar,karSeharusnya,bil);
		// AdjList[karSeharusnya-'a'].erase(it);
		it = AdjList[karSeharusnya-'a'].upper_bound(i);
		int bil = *it;
		if(kar < karSeharusnya) {
			printf("%d %d\n",bil+1, i+1);
			//cari karSeharusnya di idx bil dan kar di idx i;
			set<int>::iterator it2;
			AdjList[karSeharusnya-'a'].erase(it);
			it2 = AdjList[kar-'a'].find(i);
			AdjList[kar-'a'].erase(it2);

			AdjList[karSeharusnya-'a'].insert(i);
			AdjList[kar-'a'].insert(bil);
			
			swap(kata[bil], kata[i]);
		}else{
			printf("%d %d\n",i+1, bil+1);

			set<int>::iterator it2;
			AdjList[karSeharusnya-'a'].erase(it);
			it2 = AdjList[kar-'a'].find(i);
			AdjList[kar-'a'].erase(it2);

			AdjList[karSeharusnya-'a'].insert(i);
			AdjList[kar-'a'].insert(bil);
			swap(kata[bil], kata[i]);
		}
	}

	return 0;
};