#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define naik true
#define turun false
#define mp make_pair
#define pb push_back
#define pi acos(-1.0)
#define uint64 unsigned long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int maxn = 1e5 + 5;
int a[maxn];
bool isRecord[maxn];
int counter[maxn];

int main(){
	int n,i,j;
	
	scanf("%d",&n);
	set<int> s;
	set<int>::iterator it,it2,temp;
	for(i=0;i<n;i++){
		int input;
		scanf("%d",&input);
		it = s.lower_bound(input);
		if(it==s.end()){
			counter[input]--;
		}else{
			int bil = *it;
			it++;
			if(it==s.end()){//berarti bilangan yang paling besar adalah yg paling kanan, klo paling kanan diilangin, bakal jadi record
				counter[bil]++;
			}
		}
		s.insert(input);
	}
	int idx = 1;
	int maks = counter[1];
	for(i=2;i<=n;i++){
		//printf("counter[%d]: %d\n",i,counter[i]);
		if(counter[i]>maks){
			maks = counter[i];
			idx = i;
		}
	}
	printf("%d\n",idx);
	
	return 0;
};