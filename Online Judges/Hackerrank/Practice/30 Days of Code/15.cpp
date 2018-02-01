#include <iostream>
#include <cstddef>
#include <cstdio>
using namespace std;	
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public: 
    	Node* insert(Node *head,int data){
          //Complete this method
    		Node* current;
          if(head == NULL){
          	//printf("masuk sini\n");
          	Node bil(data);
          	//printf("terbentuk node\n");
          	head = &bil;
          	current = head;
          	//printf("assignment\n");
          	//head->data = data; head->next = NULL;
          }
          else{
          	//printf("masuk sinikah?\n");
              //iterasi sampai ketemu yg nextnya null

              while(head->next!=NULL){
              	printf("head next belum null\n");	
                  head = head->next;
                  if(head->next==NULL){printf("sudah null nextnya\n");}
                  else{printf("belum null nextnya\n");}
              }
              printf("head next null\n");
              //sudah di ujung
              Node bil(data);
              
              head->next = &bil;
          }
          return current;
      	}
        void display(Node *head){
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
        }
};
int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
        mylist.display(head);
    }	
	mylist.display(head);
		
}