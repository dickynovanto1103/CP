#include <iostream>
#include <cstddef>
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
    	Node* insert(Node *head,int data)
      {
          Node* titik = new Node(data);

          Node* awal = head;
          if(head==NULL){
          	return titik;
          }else{
          	while(head->next!=NULL){
          		head = head->next;
          	}
          	head->next = titik;
          	return awal;
          }
          //Complete this method
          //printf("masuk sini\n");
          /*if(head==NULL){
          	
          	Node* coba = new Node(data);

          	start = coba;
          	//printf("test masuk\n");
          	return coba;
          }*/
          
          /*while(head!=NULL){
          	//printf("data: %d\n",head->data);
          	head = head->next;
          }
          //printf("udah NULL\n");
          //Node* coba = new Node(data);
          head = coba;
          
	      	
	      	
	      	
          return awal;*/
      }
       void display(Node *head)
      {
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
        //printf("data input: %d\n",data);
        head=mylist.insert(head,data);
        
    }	
	mylist.display(head);
		
}