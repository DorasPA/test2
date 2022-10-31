#include<iostream>
using namespace std;
class ArrayList{
	private:
		int element[100];
		int current;
		int last;
	public:
		ArrayList();
		bool isEmpty();
		bool isFull();
		int length();
		void append(int x);
		void insert(int x, int pos);
		void remove (int pos);
		void print();
};
ArrayList::ArrayList(){
	last=-1;
}
int ArrayList::length(){
	return last+1;
} 
bool ArrayList::isEmpty(){
	if(last==-1)
		return true;
	else
		return false;
}
bool ArrayList::isFull(){
	if (last==99) return true;
	else return false;
	
}
void ArrayList::append(int x){
	if(last<99){
		element[last+1]=x;
		last++;
	}
	else
		cout<<"List is full";
}
void ArrayList::print(){
	cout<<endl;
	for(int i=0;i<=last;i++)
		cout<<element[i]<<"\t";
}

void ArrayList::insert(int x, int pos){
	if (this->isFull()) cout<<"List is full";
	else{ 
		/*int a,b,i;
		a=element[pos]; last++;
		for (i=pos+1; i<=last; i++){
			b=element[i];
			element[i]=a;
			a=b;
		}*/
		last++;
		for (i=length; i>pos; i--){
			element[i]=element[i-1];
		}
		element[pos]=x;
	}
}

int ArrayList::remove(int pos){
	if(isEmpty()) cout<<"List is empty";
	else{ int a,b,i;
		last--;
		for (i=pos; i<=last; i++){
			element[i]=element[i+1];
		}
		element[pos]=x;
	}
}
int main(){
	ArrayList list;
	cout<<"Length is: "<<list.length()<<endl;
	if(list.isEmpty() == true)
		cout<<"list is empty"<<endl;
	else
		cout<<"list is not empty"<<endl;
	list.append(5);
	list.append(10);
	list.append(15);
	cout<<"Length is: "<<list.length()<<endl;
	list.print();
	list.append(100);
	list.print();
	list.insert(7,3);
	list.print();
}
