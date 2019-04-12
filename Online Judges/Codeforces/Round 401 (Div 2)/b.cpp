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
	int n,i,j;
	scanf("%d",&n);
	string kata1, kata2;
	cin>>kata1>>kata2;
	int cnt[10], temp[10];
	memset(cnt, 0, sizeof cnt);
	memset(temp, 0, sizeof temp);
	for(i=0;i<n;i++){
		int bil = kata2[i] - '0';
		cnt[bil]++;
		temp[bil]++;
	}
	//cara 1
	// multiset<int> s, temp;
	// multiset<int>::iterator it;
	// for(i=0;i<n;i++){
	// 	char kar = kata2[i];
	// 	s.insert(kar - '0');
	// }
	// temp = s;
	// int minim = 0;
	// for(i=0;i<n;i++){
	// 	char kar = kata1[i];
	// 	int bil = kar - '0';
	// 	it = s.lower_bound(bil);
	// 	if(it == s.end()){
	// 		minim++;
	// 		s.erase(s.begin());
	// 	}else{
	// 		s.erase(it);
	// 	}
	// }
	// s = temp;
	// int maks = 0;
	// for(i=0;i<n;i++){
	// 	char kar = kata1[i];
	// 	int bil = kar - '0';
	// 	it = s.upper_bound(bil);
	// 	if(it != s.end()){
	// 		maks++;
	// 		s.erase(it);
	// 	}else{
	// 		s.erase(s.begin());
	// 	}
	// }

	//cara 2
	int minim = 0;
	for(i=0;i<n;i++){
		int bil = kata1[i] - '0';
		bool found = false;
		for(j=bil;j<10;j++){
			if(cnt[j] > 0){
				found = true;
				
				cnt[j]--;
				break;
			}
		}
		if(!found){
			for(j=0;j<bil;j++){
				if(cnt[j] > 0){
					found = true;
					minim++;
					cnt[j]--;
					break;
				}
			}
		}
	}
	for(i=0;i<10;i++){
		cnt[i] = temp[i];
	}
	int maks = 0;
	for(i=0;i<n;i++){
		int bil = kata1[i] - '0';
		bool found = false;
		for(j=bil+1;j<10;j++){
			if(cnt[j] > 0){

				found = true;
				maks++;
				cnt[j]--;
				break;
			}
		}
		if(!found){
			for(j=0;j<=bil;j++){
				if(cnt[j] > 0){
					found = true;
					cnt[j]--;
					break;
				}
			}
		}
	}
	printf("%d\n%d\n",minim, maks);
	return 0;
};