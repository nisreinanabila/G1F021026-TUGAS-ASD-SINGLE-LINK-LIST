#include<iostream>
using namespace std;

class node{
public:
   int data;
   node*next;
   node(int d){
      data=d;
      node*next= NULL;
   }
};
void insertAt(node*&head, int data){
   node*n= new node(data);
   n->next= head;
   head= n;
}
bool searchRecursive(node*head,int key){
   if(head==NULL){
      return false;
   }
   if(head->data==key){
      return true;
   }
   else{
      return searchRecursive(head->next, key);
   }
}
void printNode(node*head){
   while(head!=NULL){
      cout<<head->data<<"->";
      head=head->next;
   }
   cout<<endl;
}
int main(){
   node*head= NULL;
   insertAt(head,1);
   insertAt(head,6);
   insertAt(head,12);
   insertAt(head,21);
   insertAt(head,28);
   printNode(head);
   if(searchRecursive(head,7)){
      cout<<"present"<<endl;
   }
   else{
      cout<<"Not Present"<<endl;
   }
}
