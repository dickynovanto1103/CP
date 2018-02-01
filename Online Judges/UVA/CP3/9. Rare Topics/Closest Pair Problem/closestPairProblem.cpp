#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define unvisited -1
#define visited 1
#define eps 1e-9
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct Point{
	double x,y;
};
bool xcompare(Point a, Point b){return a.x < b.x;}
bool ycompare(Point a, Point b){return a.y < b.y;}

double bruteForce(Point px[], int n){
	int i,j;
	double minim = inf;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			double jarak = hypot(px[i].x - px[j].x, px[i].y - px[j].y);
			if(minim > jarak){minim = jarak;}
		}
	}
	return minim;
}

double closestStrip(Point strip[], int n, double d){
	double minim = d;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n && abs(strip[i].y - strip[j].y) < minim;j++){
			double jarak = hypot(strip[i].x - strip[j].x, strip[i].y - strip[j].y);
			if(minim > jarak){minim = jarak;}
		}
	}
	return minim;
}

double closestPair(Point px[], Point py[], int n){
	if(n<=3){
		return bruteForce(px,n);
	}
	//find the middle point
	int mid = n/2;
	Point midPoint = px[mid];

	//bagi point jadi 2..point yang terurut berdasarkan y..berdasarkan garis x midPoint
	Point pyleft[mid+5], pyright[mid+5];
	int left = 0, right = 0,i;
	for(i=0;i<n;i++){
		if(py[i].x <= midPoint.x){pyleft[left++] = py[i];}
		else{pyright[right++] = py[i];}
	}
	//klo sudah dibagi...hitung minimal jarak di 2 bagian itu
	double jarak1 = closestPair(px,pyleft,mid);
	double jarak2 = closestPair(px+mid, pyright, n-mid);

	double d = min(jarak1,jarak2);

	//buat array of Point strip yang menerima poin yang jaraknya kurang dari d dari midPoint
	int idx = 0;
	Point strip[n];
	for(i=0;i<n;i++){
		if(abs(py[i].x - midPoint.x) < d){strip[idx++] = py[i];}
	}
	return min(d,closestStrip(strip, idx, d));
}

int main() {
	int n,i;
	Point p[10010],px[10010],py[10010];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++){scanf("%lf %lf",&p[i].x, &p[i].y);}
		for(i=0;i<n;i++){px[i] = p[i]; py[i] = p[i];}
		sort(px,px+n,xcompare);
		sort(py,py+n,ycompare);
		double ans = closestPair(px,py,n);
		if(ans>=10000){printf("INFINITY\n");}
		else{printf("%.4lf\n",ans);}
	}
	return 0;
}