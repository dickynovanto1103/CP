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

const int maxn = 2e5 + 5;

int main(){
	int n,a[maxn], ans[maxn];
	int tc,i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		string s;
		cin>>s;
		priority_queue<ii, vii, greater<ii> > pq, sisa;
		vi listBil;
		int bil = 0;
		int batas = -1;
		for(i=0;i<n;i++){
			a[i] = s[i] - '0';
			

			pq.push(ii(a[i], i));
			ans[i] = -1;
		}
		for(i=0;i<n;i++){
			if(bil > a[i]){
				int idx = upper_bound(listBil.begin(), listBil.end(), a[i]) - listBil.begin();
				batas = listBil[idx];
				break;
			}else{
				bil = a[i];
				listBil.pb(a[i]);
			}
		}
		int idx = -1;
		bool isTrue = true;
		while(!pq.empty()){
			ii front = pq.top(); pq.pop();
			int cur = front.second;

			if(cur > idx){
				if(front.first > batas){
					sisa.push(front);
					// printf("dipush ke sisa: %d %d\n",front.first, front.second);
				}else{
					idx = cur;
					ans[cur] = 1;	
					// printf("assigned cur: %d\n",cur);
				}
				
				// printf("cur: %d\n",cur);
			}else{
				sisa.push(front);
				// printf("dipush ke sisa: %d %d\n",front.first, front.second);
			}
			
		}
		idx = -1;
		while(!sisa.empty()){
			ii front = sisa.top(); sisa.pop();
			int cur = front.second;
			if(cur > idx){
				idx = cur;
				ans[cur] = 2;
			}else{
				isTrue = false;
				break;
			}
			
		}
		if(!isTrue){
			printf("-\n");
		}else{
			for(i=0;i<n;i++){
				assert(ans[i] != -1);
				printf("%d",ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
};