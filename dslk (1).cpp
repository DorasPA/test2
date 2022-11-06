#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	
};
struct list{
	node *head;
	node *tail;
	int size=0;
	list();
	node *createnode(int x);
	void addfirst(int x);
	void addlast(int x);
	void insert(int x, int pos);
	void removefirst();
	void removelast();
	void remove(int pos);
	void print();
};
list::list(){
	head=tail=NULL;
}
node *list::createnode(int x){
	node *p=new node();
	p->data=x;
	p->next=NULL;
	return p;

}
void list::addfirst(int x){
	node *p=createnode(x);
	if(head==NULL)
	head=tail=p;
	else{
	p->next=head;
	head=p;
	};
	size++;
}

void list::addlast(int x){
	node *p=createnode(x);
	if(head==NULL)
	head=tail=p;
	else{
		tail->next=p;
		tail=p;
	};
	size++;
}

void list::insert(int x, int pos){
	if(head==NULL) cout<<"List is empty";
	
	else{
		node *p=createnode(x);
		int dem;
		for (node *i=head; i!=NULL&&dem<pos; i=i->next){
			dem++;
			if (dem==pos-1)
			{ p->next=i->next;
				i->next=p;
			}
		}
	}
	size++;
}

void list::removefirst(){
	head=head->next;
	size--;
}

void list::removelast(){
	for(node *i=head; i!=NULL; i=i->next){
		if (i->next==tail) {tail=i; tail->next=NULL; break;}
	size--;
	}
}

void list::remove(int pos){
	if(head==NULL) cout<<"List is empty";
	
	else{
		int dem;
		for (node *i=head; i!=NULL&&dem<pos; i=i->next){
			dem++;
			if (dem==pos-1)
			{ 	node *p=i->next;
				i->next=p->next;
			}
		}
	}
	size--;
}

void list::print(){
	cout<<"Size:"<<size<<endl;
	for(node *i=head; i!=NULL; i=i->next)
	cout<<i->data<<"\t";
}
int main(){
	list l;
	l.addfirst(5);
	l.addfirst(10);
	l.addfirst(15);
	l.addfirst(20);
	l.addlast(100); //20 15 10 5 100

	l.insert(12,3);//20 15 12 10 5 100
	l.insert(50,4);
	l.remove(5);
	l.insert(17,7);
	l.print();
}
