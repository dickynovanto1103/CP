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

struct pasangan{
	int idx;
	string kata1,kata2;
};

bool isLebihKecil(string &kata1, string &kata2){
	if(kata1.length() < kata2.length()){return true;}
	if(kata1.length() > kata2.length()){return false;}
	return kata1 < kata2; //leksikografis klo panjang sama
}

pasangan p[5010];

bool cmp(pasangan &a, pasangan &b){
	if(a.kata1 == b.kata1){return a.idx < b.idx;}
	return !isLebihKecil(a.kata1, b.kata1);
}

int main(){
	int n,i,j;
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		cin>>p[i].kata1>>p[i].kata2;
		if(!isLebihKecil(p[i].kata1, p[i].kata2)){
			swap(p[i].kata1, p[i].kata2);
		}
		p[i].idx = i;
	}
	// printf("sebelum diurutkan\n");
	// for(i=1;i<=n;i++){
	// 	cout<<p[i].kata1<<" "<<p[i].kata2<<" "<<p[i].idx<<endl;
	// }
	sort(p+1,p+n+1,cmp);
	// printf("setelah diurutkan\n");
	int ans[5010];
	for(i=1;i<=n;i++){
		ans[p[i].idx] = i;
		//cout<<p[i].kata1<<" "<<p[i].kata2<<" "<<p[i].idx<<endl;
	}
	for(i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
};