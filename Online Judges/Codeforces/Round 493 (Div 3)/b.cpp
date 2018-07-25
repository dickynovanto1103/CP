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
	string kata1, kata2;
	cin>>kata1>>kata2;
	int pjg1 = kata1.length(), pjg2 = kata2.length();
	int minim = min(pjg1,pjg2);
	int idx1 = pjg1-1, idx2 = pjg2-1;
	for(int i=minim-1;i>=0;i--){
		idx1 = kata1.length() - 1, idx2 = kata2.length()-1;
		if(kata1[idx1] != kata2[idx2]){
			break;
		}else{
			kata1.pop_back(); kata2.pop_back();
		}
	}
	int ans = kata1.length() + kata2.length();
	printf("%d\n",ans);
	return 0;
};