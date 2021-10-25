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
#define debug if(true)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int tc,i,j,n;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		printf("Case #%d: ",tt);

		scanf("%d",&n);
		string s[51];
		for(i=0;i<n;i++){
			cin>>s[i];
		}

		set<ii> st;

		int minimTambah = inf;
		int cntWay = 0;
		for(i=0;i<n;i++){
			bool onlyX = true;
			int cntKosong = 0;
			ii pas;
			for(j=0;j<n;j++){
				if(s[i][j] == 'O') {
					onlyX = false;
					break;
				}else if(s[i][j] == '.') {
					cntKosong++;
					pas = ii(i,j);
				}
			}
			if(onlyX) {
				if(cntKosong == 1 && st.find(pas) != st.end()) {
					continue;
				}
				st.insert(pas);

				if(minimTambah > cntKosong) {
					minimTambah = cntKosong;
					cntWay = 1;
				} else if(minimTambah == cntKosong) {
					cntWay++;
				}
			}
		}

		for(j=0;j<n;j++){
			bool onlyX = true;
			int cntKosong = 0;

			ii pas;
			for(i=0;i<n;i++){
				if(s[i][j] == 'O') {
					onlyX = false;
					break;
				}else if(s[i][j] == '.') {
					cntKosong++;
					pas = ii(i,j);
				}
			}
			if(onlyX) {
				if(cntKosong == 1 && st.find(pas) != st.end()) {
					continue;
				}
				st.insert(pas);

				if(minimTambah > cntKosong) {
					minimTambah = cntKosong;
					cntWay = 1;
				} else if(minimTambah == cntKosong) {
					cntWay++;
				}
			}
		}

		if(minimTambah == inf) {
			printf("Impossible\n");
		} else{
			printf("%d %d\n", minimTambah, cntWay);	
		}

		
	}
	
	return 0;
};