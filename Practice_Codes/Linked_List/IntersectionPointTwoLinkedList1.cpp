#include<iostream>
#include<vector>
using namespace std;
class node
{
	public:
	int data;
	node* next;

	node(int d)
	{
		data =d;
		next = NULL;
	}
};
node* insertion(node* &head, int d)
{
	if(head==NULL)
	{
		head = new node(d);
		return head;
	}
	node* temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = new node(d);
	return head;
}
node* buildLL(node* & head, vector<int> input)
{
	//node* head = NULL;
	for(unsigned int i=0;i< input.size();i++)
	{
		head = insertion(head,input[i]);
	}
	return head;
}
int getlen(node* head)
{
	int count =0;
	while(head!=NULL)
	{
		head = head->next;
		count++;
	}
	return count;
}
int intersectionPoint(node* list1 ,int n1, node* list2, int n2)
{
	//find length of both the LL
	//int len1 = getlen(list1);
	//int len2 = getlen(list2);
	node* temp1 = NULL;
	node* temp2 = NULL;
	/// Comparison of length of LL
	if(n1>=n2)
	{
		temp1 = list1;
		temp2 = list2;
	}
	else
	{
		temp1 = list2;
		temp2 = list1;

	}
	///Move temp across the larger LL by absolute difference of length of LL
	for(int i=0;i<(abs(n1-n2));i++)
	{
		if(temp1==NULL)
		{
			return -1;
		}
		temp1 = temp1->next;
	}
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data==temp2->data)
		{
			return temp1->data;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	return -1;

}
void printLL(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
int main() {
	int n1, n2;
	vector<int> list1;
	vector<int> list2;
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		int no;
		cin>>no;
		list1.push_back(no);
	}
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		int no;
		cin>>no;
		list2.push_back(no);
	}
	node* head1 = NULL ;
	node* head2 = NULL;
	head1 = buildLL(head1, list1);
	head2 = buildLL(head2, list2);
	cout<<intersectionPoint(head1, n1,head2,n2);
	//printLL(head1);
	//printLL(head2);

	return 0;
}
