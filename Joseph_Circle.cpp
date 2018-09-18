#include<iostream>

using namespace std;


typedef class Joseph_Circle
{
    private:
    int data;
    int n,m;
    Joseph_Circle* next;
    Joseph_Circle* head;
    Joseph_Circle* tail;

    public:
    Joseph_Circle();
    Joseph_Circle(int m,int n);
    ~Joseph_Circle();
    void Push_Front(int data);
    void Create_Circle_List();
    void Print_List();
    void Remove_List(Joseph_Circle* nd);
    void show();
    
}node;
extern node* Head;
int main()
{
    int n,m;
    cin>>m>>n;
    Joseph_Circle jc(m,n);
    jc.Create_Circle_List();

    //jc.show();

    jc.Print_List();

    return 0;
}

Joseph_Circle::Joseph_Circle()
{
}

Joseph_Circle::Joseph_Circle(int m,int n)
{
    this->m=m;
    this->n=n;

    head=new node;
    head->data=1;
   
    tail=new node;
    tail->data=n;
    tail->next=head;
	head->next=tail;
}

Joseph_Circle::~Joseph_Circle()
{
}

void Joseph_Circle::Push_Front(int data)
{
    node* p=new node;
    p->data=data;
    p->next=head->next;
    head->next=p;
}
void Joseph_Circle::Create_Circle_List()
{
    int i;
    for(i=n-1;i>1;--i)
    {
        Push_Front(i);
    }
}
void Joseph_Circle::Remove_List(Joseph_Circle* nd)
{

    node* q=head;
    node* p=head->next;
	node* t=tail;
    int flag=0;

	if(t->data==p->data)
	{
		if(nd->data==tail->data)
		{
			delete tail;
			head->next=NULL;
		}
		if(nd->data==head->data)
		{
			head->data=tail->data;
			head->next=NULL;
			delete tail;
		}
		return;
	}

    while(1)
    {
        if(nd->data==p->data)
        {
            flag=1;
            break;
        }
		t=q;
        q=p;
        p=p->next;

    }
    if(1==flag)
    {
        if(p->data==tail->data)
        {
           tail->data=q->data;
		   t->next=tail;
            delete q;
        }
        else if(p->data==head->data)
        {
			node* g=head->next;
			head->data=head->next->data;
			head->next=g->next;
			delete g;
			
        }
        else
        {
            q->next=p->next;
            delete p;
        }
    }
    else cout<<"该数据不存在"<<endl;

}
void Joseph_Circle::Print_List()
{
    int cnt=1;
    node* q=head;
	node* p=NULL;

    while(1)
    {
		if(q->next==NULL)
        {
            cout<<head->data<<endl;
            break;
        }
        if(cnt==m)
        {
            if(q->next==tail) p=head;
			else p=q->next;
            cout<<q->data<<' ';
            Remove_List(q);
			cnt=1;
			q=p;
        }
		else
		{
			cnt++;
			q=q->next;
		}
    }
}
void Joseph_Circle::show()
{
	node* p=tail;
	Remove_List(p);
	node* q=head;
	if(head->next==NULL)
	{
		cout<<head->data<<endl;
	}
	else
	{
		while(q->data!=tail->data)
		{
			 cout<<q->data<<' ';
			q=q->next;
		}
	}
    cout<<endl;
}
