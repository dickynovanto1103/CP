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
	string kata1 = "pirpumsemoystoal";
	string kata2 = "marywasnosyagain";
	for(int i=0;i<26;i++){
		printf("%d -> %c\n",i, i + 'a');
	}
	int i,j;
	for(i=0;i<kata1.length();i++){
		char kar1 = kata1[i], kar2 = kata2[i];
		int nilai1 = kar1 - 'a', nilai2 = kar2 - 'a';
		int k = nilai1 - nilai2;
		if(k < 0){k += 26;}
		printf("k[%d]: %d\n",i,k);
	}
	return 0;
};