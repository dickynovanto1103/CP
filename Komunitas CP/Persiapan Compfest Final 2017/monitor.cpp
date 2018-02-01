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
typedef pair<int,ii> iii;
typedef vector<ii> vii;

const int maxn = 501;

int main(){
	int n,m,k,q,i,j;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	vector<iii> listTriple;
	int a[maxn][maxn];
	int minim = inf, maks = -inf;
	for(i=0;i<q;i++){
		int x,y,t;
		scanf("%d %d %d",&x,&y,&t);
		listTriple.pb(mp(t,ii(x,y)));
		minim = min(minim,t); maks = max(maks,t);
	}
	
	//binser
	int kiri = minim, kanan = maks,mid,ans=-1;
	int target = k*k;
	
	int startRow = k-1;
	int startCol = k-1;
	while(kiri<=kanan){
		memset(a,0,sizeof a);
		int mid = (kiri+kanan)/2;
		for(i=0;i<q;i++){
			iii front = listTriple[i];
			int t = front.first, x = front.second.first, y = front.second.second;
			if(t<=mid){
				x--; y--;
				a[x][y] = 1;	
			}
			
		}
		
		//cari ada sejumlah k*k ga?
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(j>0){a[i][j]+=a[i][j-1];}
				if(i>0){a[i][j]+=a[i-1][j];}
				if(i>0 && j>0){a[i][j]-=a[i-1][j-1];}
			}
		}

		bool found = false;
		for(i=startRow;i<n;i++){
			for(j=startCol;j<m;j++){
				int bil1 = a[i][j];
				int rowSebelum = i-k, colSebelum = j-k;
				int bil2,bil3,bil4;
				if(colSebelum<0){bil2 = 0;}
				else{bil2 = a[i][j-k];}
				if(rowSebelum<0){bil3 = 0;}
				else{bil3 = a[i-k][j];}
				if(rowSebelum<0 || colSebelum<0){bil4 = 0;}
				else{bil4 = a[i-k][j-k];}

				int jawab = bil1 -bil2 - bil3 + bil4;
				
				if(jawab==target){found = true; break;}
				
			}
			if(found){break;}
		}
		if(found){
			ans = mid;
			kanan = mid-1;
		}else{
			kiri = mid+1;
		}

	}
	printf("%d\n",ans);
	return 0;
};