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
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	char arr[26];
	for(i=0;i<26;i++){
		arr[i] = i + 'a';
		// printf("arr[%d]: %c\n",i,arr[i]);
	}
	string kata1, kata2;
	cin>>kata1>>kata2;
	string tempKata1 = kata1;
	string ans = "";

	int pengali = 0;
	int nilai[400];
	int idx = inf;
	bool sudahNegatif = false;
	while(!sudahNegatif){
		string temp = "";
		idx = m-n-pengali*n;
		int idxAwal = 0;
		if(idx < 0){
			int selisih = 0 - idx;
			idxAwal = selisih;
			idx = 0;
			sudahNegatif = true;
		}
		for(i=idxAwal;i<idxAwal + n;i++){
			char b = kata2[idx], a = kata1[i];
			int nilai1 = b-'a', nilai2 = a - 'a';
			int k = ((b - 'a') - (a - 'a')) % 26;
			if(k < 0){k += 26;}
			nilai[idx] = k;
			temp += k + 'a';
			idx++;
		}
		ans = temp + ans;
		kata1 = temp + kata1;
		pengali++;
	
		if(ans.length() > m){break;}
	}
	ans += tempKata1;
	int pjg = ans.length();

	int idxAwal = pjg - m;
	for(i=idxAwal;i<pjg;i++){
		printf("%c", ans[i]);
	}
	printf("\n");

	return 0;
};