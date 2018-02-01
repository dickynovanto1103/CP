#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
#define pi acos(-1.0)
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

bool isVisited[5000010], isOccupied[5000010];
ii listPasanganID[5000010];
ll r,c,k,h;
ll dx[] = {0,1,0,-1};
ll dy[] = {-1,0,1,0};
/*set<int> listId;
set<int>::iterator it;*/
queue<ii> q;

void floodFill(int xawal, int yawal, string perintah){
	int i;
	q.push(ii(xawal,yawal));
	if(perintah=="atas"){
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int absis = front.first, ordinat = front.second;
			int id = ((((absis-1)*c + ordinat)*k + h)%(r*c)) + 1;	
			if(!isVisited[id]){
				isVisited[id] = true;
				for(i=0;i<2;i++){
					int x = absis+dx[i], y = ordinat+dy[i];
					if(x>=1 && x<=r && y>=1 && y<=c){
						q.push(ii(x,y));
					}
				}
			}
		}
	}else{
		while(!q.empty()){
			ii front = q.front(); q.pop();
			int absis = front.first, ordinat = front.second;
			int id = ((((absis-1)*c + ordinat)*k + h)%(r*c)) + 1;	
			if(!isVisited[id]){
				isVisited[id] = true;
				for(i=2;i<4;i++){
					int x = absis+dx[i], y = ordinat+dy[i];
					if(x>=1 && x<=r && y>=1 && y<=c){
						q.push(ii(x,y));
					}
				}
			}
		}
	}
	
	
}
vi ans;

int main() {
	int tc;
	ll i,j;
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld %lld %lld %lld",&r,&c,&k,&h);
		
		ll id;
		memset(isVisited,false,sizeof isVisited);
		memset(isOccupied,false, sizeof isOccupied);
		for(i=1;i<=r;i++){
			for(j=1;j<=c;j++){
				id = ((((i-1)*c + j)*k + h)%(r*c)) + 1LL;
				//listId.insert(id);

				listPasanganID[id] = ii(i,j);
				/*printf("yang diinsert: %d\n",id);
				printf("cek pasangan: %d %d\n",listPasanganID[id].first,listPasanganID[id].second);
				printf("yang diinput id:%d i: %d j: %d\n",id,i,j);*/
				if(i==1&&j==1){isOccupied[id]=true;}
				else if(i==r && j==c){isOccupied[id]=true;}
			}
		}
		/*printf("list id:");
		for(it=listId.begin();it!=listId.end();it++){
			printf(" %d",*it);
		}
		printf("\n");*/
		for(i=1;i<=r*c;i++){
			id = i;
			int x = listPasanganID[id].first, y = listPasanganID[id].second;
			//printf("id: %d yang diconsider x: %d y: %d\n",id,x,y);
			//id = ((((x-1)*c + y)*k + h)%(r*c)) + 1;
			if(!isVisited[id]){
				//printf("isOccupied[%d]\n", );
				isOccupied[id] = true;
				//printf("yang diambil x: %d y: %d\n",x,y);
				if(x+1<=r && y-1>=1){floodFill(x+1,y-1,"atas");}
				if(x-1>=1 && y+1<=c){floodFill(x-1,y+1,"bawah");}
				
			}
		}
		
		ll x = 1, y = 1;
		id = ((((x-1)*c + y)*k + h)%(r*c)) + 1;
		ans.pb(id);
		//printf("x: %d y: %d\n",x,y);
		while(true){
			for(i=1;i<3;i++){
				ll xbaru = x+dx[i], ybaru = y+dy[i];
				if(xbaru>=1 && xbaru<=r && ybaru>=1 && ybaru<=c){
					id = ((((xbaru-1)*c + ybaru)*k + h)%(r*c)) + 1;

					/*printf("xbaru: %d ybaru: %d id: %d\n",xbaru,ybaru,id);
					printf("r: %d c: %d\n",r,c);*/
					if(isOccupied[id]){
						ans.pb(id); x = xbaru; y = ybaru;
						//printf("berubah jd x: %d y: %d\n",x,y); 
						break;
					}	
				}
				
			}
			//printf("x sekarang: %d y sekarang: %d\n",x,y);
			if(x==r && y==c){break;}
		}
		//printf("akhir x : %d y : %d\n",x,y);
		int ukuran = ans.size();
		//printf("ukuran: %d\n",ukuran);
		if(ukuran<=200){
			for(i=0;i<ukuran;i++){printf("%07lld\n",ans[i]);}
		}else{
			for(i=0;i<100;i++){printf("%07lld\n",ans[i]);}
			for(i=ukuran-100;i<ukuran;i++){printf("%07lld\n",ans[i]);}
		}
		
		ans.clear();
	}
	return 0;
}