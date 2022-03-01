#include <iostream>
using namespace std;

struct Data{
	int data;
	
	Data *next;
};

Data *head, *tail, *cur, *newNode, *del, *after ;

void createSingleLinkedList(int data){
	head = new Data();
	head->data = data;
	head->next = NULL;
	tail = head;
}

void insertFirst(int data){
	newNode = new Data();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

void insertLast(int data){
	newNode = new Data();
	newNode->data = data;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}


void insertAfter(int data, int posisi){
	newNode = new Data();
	newNode->data = data;
	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;

}

void deleteFirst(){
	del = head;
	head = head->next;
	delete del;
}

void deleteLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}

void deleteAfter(int posisi){
	int nomor = 1;
	cur = head;
	while(nomor <= posisi){
		if(nomor == posisi -1){
			after = cur;
		}
		if(nomor == posisi){
			del = cur;
		}
		del = cur->next;
		nomor++;
	}
	after->next = cur->next->next;
	delete del;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout<<"Data : "<<cur->data<<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList(1);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst(6);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast(12);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter(21, 3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter(28, 4);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	return 0;

}
