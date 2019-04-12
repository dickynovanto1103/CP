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
#define FastSlowInput ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string kata1, kata2;
	cin>>kata1>>kata2;
	int pjg1 = kata1.length(), pjg2 = kata2.length();
	int cnt1[27], cnt2[27];
	memset(cnt1, 0, sizeof cnt1); memset(cnt2, 0, sizeof cnt2);
	int i,j;
	for(i=0;i<pjg1;i++){
		cnt1[kata1[i] - 'A']++;
	}
	for(i=0;i<pjg2;i++){
		cnt2[kata2[i] - 'A']++;
	}
	// sort(kata1.begin(), kata1.end()); sort(kata2.begin(), kata2.end());
	for(i=0;i<26;i++){
		if(cnt2[i] > cnt1[i]){printf("TIDAK\n"); return 0;}
	}
	printf("YA\n");
	// if(kata1.find(kata2) == -1){printf("TIDAK\n");}
	// else{printf("YA\n");}
	return 0;
};