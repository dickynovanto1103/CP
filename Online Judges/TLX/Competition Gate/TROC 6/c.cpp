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
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	string s;
	cin>>s;
	//tahap: 
	// 1. isi 0 dulu, tidak bersebelahan, 
	// 2. isi 1, isi 0 sisa, isi 1 sisa, 
	// 3. pop sampe tahap isi 0 sisa, isi 1 yang bolong tadi
	vi list0, list1;
	for(i=0;i<n;i++){
		if(s[i] == '1'){list1.pb(i+1);}
		else{list0.pb(i+1);}
	}
	set<int> set0;
	queue<int> q;
	vi list1Buang;
	vii ans;
	bool isVisited[100010];
	int cnt0Awal = 0;
	memset(isVisited, false, sizeof isVisited);
	for(i=0;i<list0.size();i++){
		int koor = list0[i];
		q.push(koor);
		isVisited[koor] = true;
		cnt0Awal++;
		// set0.insert(koor);
		ans.pb(ii(1,koor));
		if(i == list0.size() - 1) {
			//jangan compare
		}else{
			int next = list0[i+1];
			if(koor == next-1){
				i++;
			}
		}
	}
	//list1 yang bakal dibuang
	for(i=0;i<list1.size();i++){//pilih yang tidak bersebelahan dengan siapa"
		int koor = list1[i];
		if(isVisited[koor-1] || isVisited[koor+1]){
			
		}else{
			isVisited[koor] = true;
			ans.pb(ii(1,koor));
			q.push(koor);
			list1Buang.pb(koor);
			// printf("list1 push: %d\n",koor);
		}
	}

	int cnt0Akhir = 0;

	//isi 0 sisa
	// for(i=0;i<list0.size();i++){
	// 	int koor = list0[i];
	// 	if(!isVisited[koor]){
	// 		ans.pb(ii(1,koor));
	// 		q.push(koor);
	// 		isVisited[koor] = true;
	// 		cnt0Akhir++;
	// 	}
	// }
	//isi 1 sisa
	for(i=0;i<list1.size();i++){
		int koor = list1[i];
		if(!isVisited[koor]){
			ans.pb(ii(1,koor));
			q.push(koor);
			isVisited[koor] = true;
		}	
	}

	//buang 0 dan 1 
	while(cnt0Awal--){
		q.pop();
		ans.pb(ii(2,0));
		// printf("pop 0 awal\n");
	}
	// int ukuran1 = list1Buang.size();
	// while(ukuran1--){
	// 	q.pop();
	// 	ans.pb(ii(2,0));
	// 	// printf("pop 1 buang\n");
	// }
	// while(cnt0Akhir--){
	// 	q.pop();
	// 	ans.pb(ii(2,9));
	// 	// printf("pop 0 akhir\n");
	// }
	// ukuran1 = list1Buang.size();
	// for(i=0;i<ukuran1;i++){
	// 	int koor = list1Buang[i];
	// 	// printf("dipush: %d\n",koor);
	// 	ans.pb(ii(1,koor));
	// }
	printf("%d\n",(int)ans.size());
	for(i=0;i<ans.size();i++){
		if(ans[i].first == 2){
			printf("2\n");
		}else{
			printf("%d %d\n",ans[i].first, ans[i].second);
		}
	}
	return 0;
};