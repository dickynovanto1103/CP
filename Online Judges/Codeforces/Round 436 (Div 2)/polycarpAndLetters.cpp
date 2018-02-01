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

int main(){
	int n,i,j;
	string kata;
	set<char> s;
	set<char>::iterator it;

	scanf("%d",&n);
	cin>>kata;
	int maks = 0, counter = 0;
	for(i=0;i<n;i++){

		if(kata[i]>=97 && kata[i]<=122){
			it=s.find(kata[i]);
			if(it==s.end()){
				s.insert(kata[i]);
				counter++;
				maks = max(maks,counter);
			}
		}else{
			counter = 0;
			s.clear();
		}
	}
	printf("%d\n",maks);
	return 0;
};