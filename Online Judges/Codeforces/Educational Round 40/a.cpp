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
	scanf("%d",&n);
	cin>>kata;
	for(i=0;i<(kata.length()-1);i++) {
		char kar1 = kata[i], kar2 = kata[i+1];
		if(kar1 == 'R') {
			if(kar2 == 'U'){
				kata.erase(i,1);
				kata[i] = 'D';
				i=-1;
			}
		}else if(kar1 == 'U') {
			if(kar2 == 'R') {
				kata.erase(i,1);
				kata[i] = 'D';
				i=-1;	
			}
		}
		// printf("i: %d kata jadi: ",i);
		// cout<<kata<<endl;
	}
	// cout<<kata<<endl;
	printf("%d\n",(int)kata.length());
	return 0;
};