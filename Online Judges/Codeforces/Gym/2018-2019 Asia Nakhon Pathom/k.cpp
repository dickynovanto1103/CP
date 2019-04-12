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

const int maxn = 1e6 + 6;

int bit[maxn];
int LOGN = log2(1e6);

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	
	for(int i=LOGN; i>=0; i--)
	{
		if(pos + (1 << i) < 1000000 and sum + bit[pos + (1 << i)] < v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; // +1 because 'pos' will have position of largest value less than 'v'
}

void update(int idx, int val) {
	int i;
	for(i=idx;i<=1000000;i+=(i&-i)){
		bit[i] += val;
	}
}

int main(){
	int tc,i,j,q;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		memset(bit, 0, sizeof bit);
		printf("Case %d:\n",tt);
		scanf("%d",&q);
		priority_queue<ii, vii, greater<ii> > pq;
		for(i=0;i<q;i++){
			int op;
			scanf("%d",&op);
			if(op == 1){
				int awal, akhir, val;
				scanf("%d %d %d",&awal,&val,&akhir);
				pq.push(ii(akhir, val));
				update(val, 1);
			}else{
				int awal, k;
				scanf("%d %d",&awal,&k);
				// printf("awal: %d k: %d\n",awal, k);
				while(!pq.empty()){
					ii front = pq.top();
					int bil = front.second;
					int waktu = front.first;
					// printf("bil: %d waktu: %d\n",bil, waktu);
					if(waktu < awal){
						update(bil, -1);
						// printf("yang dipop: %d\n",bil);
						pq.pop();
					}else{
						break;
					}
					
					
				}
				if(k > (int)pq.size()){printf("-1\n"); continue;}
				int ans = bit_search(k);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
};