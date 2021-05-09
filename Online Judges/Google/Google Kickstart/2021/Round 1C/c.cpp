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

const int maxn = 100000;

int dist[maxn];

int binToInt(string s) {
	int bil = 0;
	int n = s.size();
	for(int i=0;i<n;i++){
		int angka = s[i] - '0';
		bil *= 2;
		bil += angka;
	}
	return bil;
}

string intToBinary(int bil) {
	string s;
	while(bil) {
		int mod = bil % 2;
		s += (mod + '0');
		bil /= 2;
	}
	if(s.size() == 0){
		return "0";
	}
	reverse(s.begin(), s.end());
	return s;
}

string notBinary(string s) {
	string ans;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i] == '0'){
			ans += '1';
		}else{
			ans += '0';
		}
	}
	return ans;
}

int main(){
	int tc,i,j;
	// printf("binToInt: %d\n", binToInt("000"));
	// printf("binToInt: %d\n", binToInt("0001"));
	// printf("binToInt: %d\n", binToInt("11111111"));
	// printf("intToBinary: %s\n", intToBinary(0).c_str());
	// printf("intToBinary: %s\n", intToBinary(1).c_str());
	// printf("intToBinary: %s\n", intToBinary(2).c_str());
	// printf("intToBinary: %s\n", intToBinary(3).c_str());
	// printf("intToBinary: %s\n", intToBinary(254).c_str());
	// printf("notBinary: %s\n", notBinary("0").c_str());
	// printf("notBinary: %s\n", notBinary("01").c_str());
	// printf("notBinary: %s\n", notBinary("10").c_str());
	// printf("notBinary: %s\n", notBinary("11").c_str());
	scanf("%d",&tc);
	for(int tt =1;tt<=tc;tt++){
		printf("Case #%d: ", tt);
		string s, e;
		cin>>s>>e;
		
		memset(dist, -1, sizeof dist);
		queue<int> q;
		int node = binToInt(s);
		q.push(node);
		dist[node] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			int kali2 = u * 2;
			if(kali2 < maxn && dist[kali2] == -1){
				dist[kali2] = dist[u] + 1;
				q.push(kali2);
			}

			string binary = intToBinary(u);
			string notNodeStr = notBinary(binary);
			int notNode = binToInt(notNodeStr);
			if(notNode < maxn && dist[notNode] == -1) {
				dist[notNode] = dist[u] + 1;
				q.push(notNode);
			}
		}

		int akhir = binToInt(e);
		if(dist[akhir] == -1){
			printf("IMPOSSIBLE\n");
		}else{
			printf("%d\n", dist[akhir]);
		}
	}
	
	return 0;
};