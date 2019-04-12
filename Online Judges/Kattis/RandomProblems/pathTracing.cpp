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
	int x = 0, y = 0,i,j;
	vii listKoor;
	listKoor.pb(ii(x,y));
	string listKata[550];
	int cnt = 0;
	string kata;
	int minimX = inf, minimY = inf;
	while(cin>>kata) {
		listKata[cnt++] = kata;
		if(kata == "down"){
			x++;
		}else if(kata == "left") {
			y--;
		}else if(kata == "right"){
			y++;
		}else if(kata == "up"){
			x--;
		}
		listKoor.pb(ii(x,y));
		minimX = min(minimX, x);
		minimY = min(minimY, y);
	}
	// printf("x: %d y; %d\n",x,y);
	int addX = 0, addY = 0;
	if(minimX < 0){addX += -minimX;}
	if(minimY < 0){addY += -minimY;}
	char map[550][550];
	for(i=0;i<550;i++){
		for(j=0;j<550;j++){
			map[i][j] = ' ';
		}
	}
	int awalX = inf, awalY = inf, akhirX = -inf, akhirY = -inf;
	for(i=0;i<listKoor.size();i++){
		ii koor = listKoor[i];
		int a = koor.first, b = koor.second;
		a += addX, b += addY;
		awalX = min(awalX, a);
		awalY = min(awalY, b);
		akhirX = max(akhirX, a);
		akhirY = max(akhirY, b);
		// printf("a: %d b: %d\n",a,b);
		if(i == 0){
			map[a][b] = 'S';
		}else if(i == listKoor.size() - 1){
			map[a][b] = 'E';
		}else{
			map[a][b] = '*';
		}
		// printf("map[%d]\n", );
	}
	
	
	// printf("%d %d %d %d\n",awalX, akhirX, awalY, akhirY);
	int tinggi = akhirX - awalX + 1, lebar = akhirY - awalY + 1;
	ii pertama = listKoor[0];
	int a = pertama.first, b = pertama.second;
	a += addX, b += addY;
	map[a][b] = 'S';
	for(i=0;i<lebar+2;i++){printf("#");}
	printf("\n");
	for(i=awalX;i<=akhirX;i++){
		printf("#");
		for(j=awalY;j<=akhirY;j++){
			printf("%c",map[i][j]);
		}
		printf("#\n");
	}
	for(i=0;i<lebar+2;i++){printf("#");}
	printf("\n");
	
	// if(x < 0 || y < 0){
	// 	int minim = min(x,y);
	// 	x += minim; y += minim;
	// 	awalX += minim; awalY += minim;
	// }


	return 0;
};