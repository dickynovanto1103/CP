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
	int n,i,j;
	scanf("%d",&n);
	deque<int> d1, d2;
	for(i=0;i<n;i++){
		char kata[20];
		int el;
		scanf("%s %d",kata,&el);
		if(kata[0] == 'g'){
			//dapetin
			int idx = el;
			int ukuran1 = d1.size();
			if(idx >= ukuran1){
				idx-=ukuran1;
				printf("%d\n",d2[idx]);
			}else{
				printf("%d\n",d1[idx]);
			}
		}else if(kata[5] == 'b'){
			d2.push_back(el);
			if(d2.size() > d1.size()) {
				int front = d2.front(); d2.pop_front();
				d1.push_back(front);
			}
		}else if(kata[5] == 'f'){
			d1.push_front(el);
			int selisih = d1.size() - d2.size();
			if(selisih >= 2){
				int back = d1.back();
				d1.pop_back();
				d2.push_front(back);
			}
		}else if(kata[5] == 'm'){
			if(d1.size() > d2.size()) {
				d2.push_front(el);
			}else{
				d1.push_back(el);
			}
		}
	}

	return 0;
};