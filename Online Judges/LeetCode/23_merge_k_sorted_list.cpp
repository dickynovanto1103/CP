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
#define debug if(true)
typedef long long ll;
// typedef __int128_t lll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

  		priority_queue<ii, vector<ii>, greater<ii>> pq;
  		for(int i=0;i<lists.size();i++) {
  			ListNode* node = lists[i];
  			if(node == NULL) {continue;}
  			pq.push(ii(node->val, i));
  		}

  		ListNode* res = new ListNode(0);
  		ListNode* head = res;

  		
  		while(!pq.empty()) {
  			ii top = pq.top(); pq.pop();
  			// printf("top: %d %d\n", top.first, top.second);
  			res->next = new ListNode(top.first);
  			res = res->next;
  			lists[top.second] = lists[top.second]->next;
  			if(lists[top.second] != NULL) {
  				pq.push(ii(lists[top.second]->val, top.second));
  				// printf("insert: %d %d\n", lists[top.second]->val, top.second);
  			}
  		}

  		// puts("returning");
  		return head->next;
    }
};

ListNode* createListNode(vector<int> v) {
	if(v.size() == 0) {return NULL;}
	ListNode* res = new ListNode(v[0]);
	ListNode* head = res;
	
	for(int i=1;i<v.size();i++) {
		res->next = new ListNode(v[i]);
		res = res->next;
	}

	return head;
}

void printListNode(ListNode* list) {
	while(list != NULL){
		printf("%d ", list->val);
		list = list->next;
	}
	puts("");
}

void solve(){
	vector<int> v1 = {1,4,5};
	vector<int> v2 = {1,3,4};
	vector<int> v3 = {2,6};
	Solution sol;

	vector<ListNode*> v = {createListNode(v1), createListNode(v2), createListNode(v3)};
	printListNode(sol.mergeKLists(v));
	vector<ListNode*> empty;
	printListNode(sol.mergeKLists(empty));
}

int main(){
	int tc = 1;
	// scanf("%d",&tc);
	while(tc--){
		solve();
	}

	return 0;
};