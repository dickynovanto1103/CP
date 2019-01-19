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
	scanf("%d",&n);
	string kata;
	cin>>kata;
	int cnt[3];
	memset(cnt, 0, sizeof cnt);
	for(i=0;i<n;i++){
		cnt[kata[i] - '0']++;
	}
	int harapan = n/3;
	for(i=0;i<3;i+=2){
		if(cnt[i] < harapan){
			//harus tambahin
			if(i == 0){

				for(j=0;j<n;j++){
					if(kata[j] == '1' && cnt[1] > harapan){
						cnt[1]--;
						kata[j] = '0';
						cnt[0]++;
						if(cnt[0] == harapan){break;}
					}else if(kata[j] == '2' && cnt[2] > harapan) {
						cnt[2]--;
						kata[j] = '0';
						cnt[0]++;
						if(cnt[0] == harapan){break;}
					}
				}
			}else if(i == 1) {
				for(j=0;j<n;j++){
					if(kata[j] == '2' && cnt[2] > harapan) {
						cnt[2]--;
						kata[j] = '1';
						cnt[1]++;
						if(cnt[1] == harapan){break;}
					}
				}
				for(j=n-1;j>=0;j--){
					if(kata[j] == '0' && cnt[0] > harapan) {
						cnt[0]--;
						kata[j] = '1';
						cnt[1]++;
						if(cnt[1] == harapan){break;}
					}
				}
			}else if(i == 2) {
				for(j=n-1;j>=0;j--){
					if(kata[j] == '0' && cnt[0] > harapan) {
						cnt[0]--;
						kata[j] = '2';
						cnt[2]++;
						if(cnt[2] == harapan){break;}
					}
				}
				for(j=n-1;j>=0;j--){
					if(kata[j] == '1' && cnt[1] > harapan) {
						cnt[1]--;
						kata[j] = '2';
						cnt[2]++;
						if(cnt[2] == harapan){break;}
					}
				}
			}
		}
	}

	for(i=1;i<3;i+=2){
		if(cnt[i] < harapan){
			//harus tambahin
			if(i == 0){

				for(j=0;j<n;j++){
					if(kata[j] == '1' && cnt[1] > harapan){
						cnt[1]--;
						kata[j] = '0';
						cnt[0]++;
						if(cnt[0] == harapan){break;}
					}else if(kata[j] == '2' && cnt[2] > harapan) {
						cnt[2]--;
						kata[j] = '0';
						cnt[0]++;
						if(cnt[0] == harapan){break;}
					}
				}
			}else if(i == 1) {
				for(j=0;j<n;j++){
					if(kata[j] == '2' && cnt[2] > harapan) {
						cnt[2]--;
						kata[j] = '1';
						cnt[1]++;
						if(cnt[1] == harapan){break;}
					}
				}
				for(j=n-1;j>=0;j--){
					if(kata[j] == '0' && cnt[0] > harapan) {
						cnt[0]--;
						kata[j] = '1';
						cnt[1]++;
						if(cnt[1] == harapan){break;}
					}
				}
			}else if(i == 2) {
				for(j=n-1;j>=0;j--){
					if(kata[j] == '0' && cnt[0] > harapan) {
						cnt[0]--;
						kata[j] = '2';
						cnt[2]++;
						if(cnt[2] == harapan){break;}
					}
				}
				for(j=n-1;j>=0;j--){
					if(kata[j] == '1' && cnt[1] > harapan) {
						cnt[1]--;
						kata[j] = '2';
						cnt[2]++;
						if(cnt[2] == harapan){break;}
					}
				}
			}
		}
	}

	cout<<kata<<endl;
	return 0;
};