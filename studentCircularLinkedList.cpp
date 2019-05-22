#include<iostream>
using namespace std;
class node{
	public:
	string name,sex;
	int age;
	node* next;
};
class student{
	node* head;
	public: student()
	{
		head=NULL;
	}
	bool isEmpty()
	{
		if(head==NULL)
		{
			return true;
		}
		else
		return false;
	}
	public:
		void insert(string name,int age ,string sex,int pos);
		void view();
		void delt(string name);
		void search(string name);
};
void student::delt(string name)
{
	if(isEmpty())
	{
		cout<<"\nthe list is empty";
	}
	else
	{
		node*temp= head;
		node*back=NULL;
		do{
			if(temp->name==name)
			{
				if(back)//not the first elt
				{
					back->next=temp->next;
					delete  temp;
					cout<<"\nsuccefuly deleted";
				}
				else//deletle the first
				{
					if(temp->next!=head)//not the last
					{
						//head=temp->next;
						node* cnode=head;
						while(cnode->next!=head)
						{
						cnode=cnode->next;	
						}
						head=cnode->next=temp->next;
						delete temp;
						cout<<"\nsuccefuly deleted from the first place";
					}
					else
					{
						head=NULL;
						cout<<"\nsucefuly deleted the list will become empty";
						
					}
				}
				return;
			}
			else
			{
				back=temp;
				temp=temp->next;
			}
			
		}while(temp!=head);
		cout<<"\nthere is no record with such name";
	}
}
void  student::search(string name)
{
	if(isEmpty())
	{
		cout<<"\nthe list is empty";
	}
	else{
		node* temp=head;
		do{
			if(temp->name==name)
			{
				cout<<"\nName\tAge\tSex";
				cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
				return;
				
			}
			else temp=temp->next;
		}while(temp!=head);
		cout<<"\ndoesnt found in the list";
	}
}
void student::view()
{
	if(isEmpty())
	{
		cout<<"\nthe list empty";
		
	}
	else
	{
		node* temp=head;
		cout<<"\nName\tAge\tSEx";
		do{
			cout<<"\n"<<temp->name<<"\t"<<temp->age<<"\t"<<temp->sex;
			temp=temp->next;
			
		}while(temp!=head);
	}
}
void student::insert(string name,int age,string sex,int pos)
{
	node* newnode=new node;
	newnode->name=name;
	newnode->age=age;
	newnode->sex=sex;
	if(pos==0)
	{
		if(isEmpty())
		{
			head=newnode;
			newnode->next=head;
			cout<<"\nsucefuly stored in intial place";
		}
		else
		{
			newnode->next=head;
		//	head=newnode;	
			node* temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			head=temp->next=newnode;
			cout<<"\nsucefuly stored in intial place\t"<<head->name;
		}
	}
	else if(pos>0)
	{
		node*temp=head;
		int i=1;
		while(temp->next!=head && i!=pos)
		{
			temp=temp->next;
			i++;
		}
		if(i==pos)
		{
			if(temp->next==head)//insert at last
			{
				newnode->next=head;
				temp->next=newnode;
				cout<<"\nsucefully inserted in the last element";
				
			}
			else//insert in the middle
			{
				newnode->next=temp->next;
				temp->next=newnode;
				cout<<"\nsuccefuly inserted in the middle";
				
			}
			
		}
		else
		{
			cout<<"\nthe request postion is out of range";
		}
		
		
	}
	else
	{
		cout<<"\ninvalid postion requested";
	}
}
int main()
{
	int choice;
	student su;
	string name,sex;
	int age,pos;
	do{
		cout<<"\n=============Student Managment  =================";
		cout<<"\n1.insert";
		cout<<"\n2.view";
		cout<<"\n3.search";
		cout<<"\n4.delete";
		cout<<"\n5exit";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter name";
				cin>>name;
				cout<<"\nEnter age";
				cin>>age;
				cout<<"\nEnter sex";
				cin>>sex;
				cout<<"\nenter postion";
				cin>>pos;
				su.insert(name,age,sex,pos);
				break;
			case 2:
				su.view();
				break;
			case 3:
				cout<<"\nEnter Name";
				cin>>name;
				su.search(name);
				break;
			case 4:
				cout<<"\nEnter name";
				cin>>name;
				su.delt(name);
				break;		
		}
	
		
	}while(choice!=5);
	
	return 0;
}
