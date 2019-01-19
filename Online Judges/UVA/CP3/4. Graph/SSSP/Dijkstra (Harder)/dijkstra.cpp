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

	vector<vector<pair<int,int> > > AdjacencyList;
	int distance[100000];

	AdjacencyList.assign(100000, vector<pair<int,int> >());
	for(int i=0;i<100000;i++){
		distance[i] = 1000000000; //inisialisasi dengan 1 milyar (angka yang sangat besar)
	}

	priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	int nodeAwal = 0;
	distance[nodeAwal] = 0;
	pq.push(make_pair(distance[nodeAwal], nodeAwal));

	while(!pq.empty()){
		pair<int,int> front = pq.top(); pq.pop();
		int jarak = front.first, vertex = front.second;

		if(jarak <= distance[vertex]) {
			for(int i = 0; i < AdjacencyList[vertex].size(); i++) {
				pair<int,int> tetangga = AdjacencyList[vertex][i];
				int edgeWeight = tetangga.second, vertexTetangga = tetangga.first;

				if(distance[vertex] + edgeWeight < distance[vertexTetangga]){
					distance[vertexTetangga] = distance[vertex] + edgeWeight;
					pq.push(make_pair(distance[vertexTetangga], vertexTetangga));
				}

			}	
		}
		
	}



	return 0;
};