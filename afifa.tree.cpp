#include <stdio.h>
#include <iostream.h>
#include <conio.h>

struct node{
int data;
node* LTree;
node* RTree;
};
node* root = NULL;

node* Insert(node* root, int);
int Search(node* root, int);
void InorderTraversal(node *root);
node* FindMin(node *root);
void PostorderTraversal(node *root);
node* getParent(node *root, int);
void PreorderTraversal(node *temp);
void DeleteNode(node *root, int num);
void degree(node *root, int a);

void main()
{
 int n,g,m;
 node *x;
 node *y;

 do
 {
  printf("Enter ur choice:\n1)INSERT\t2)SEARCH\t3)IN ORDER TRAVERSAL\t4)POST ORDER TRAVERSAL\t5)FIND MINIMUM NODE\t6)FIND PARENT NODE\t7)PREORDER TRAVERSAL\t8)DELETE NODE\t9)DEGREE OF NODE\n");
  scanf("%d", &n);
  switch (n)
  {
   case 1:
   printf("Enter no:");
   scanf("%d", &m);
   root = Insert(root, m);
   break;

   case 2:
   int l,m;
   printf("Enter no:");
   scanf("%d", &l);
   m=Search(root,l);
   getche();
   break;

   case 3:
   InorderTraversal(root);
   getche();
   break;

   case 4:
   PostorderTraversal(root);
   getche();
   break;

   case 5:
   x=FindMin(root);
   cout<<x->data;
   getche();
   break;

   case 6:
   printf("Enter number and its Parent will be displayed:");
   scanf("%d", &g);
   y=getParent(root,g);
   cout<<y->data;
   getche();
   break;

   case 7:
   PreorderTraversal(root);
   getche();
   break;

   case 8:
   int num;
   printf("Enter the number u want to delete\n");
   scanf("%d",&num);
   DeleteNode(root,num);

   case 9:
   int a;
   printf("Enter number and its degree will be displayed\n");
   scanf("%d",&a);
   degree(root,a);
   }
    }while(n!=0);

  }


 node* FindMin(node* curr)
{
   if(curr->LTree == NULL)
      return curr;
   else
      return FindMin(curr->LTree);
}


node* getParent(node* curr, int num)
{

  if((curr->LTree!=NULL) || (curr->RTree!=NULL) )
  {
  if((curr->LTree->data == num) || (curr->RTree->data == num))
      return curr;
   else if(num < curr->data)
      return getParent(curr->LTree, num);
   else if(num > curr->data)
      return getParent(curr->RTree, num);
   }
   else if(curr==NULL)
   cout<<"NOT FOUND";
}



node* Insert(node* temp, int num)
{
   	if ( temp == NULL )
   	{
   		temp = new node;
   		temp->data= num;
      	temp->LTree= NULL;
      	temp->RTree=NULL;
   	}
   	else if(num < temp->data)
      	temp->LTree = Insert(temp->LTree, num);
   	else if( num >= temp->data)
      	temp->RTree = Insert(temp->RTree,num);
   	return temp;
}

int Search(node* temp, int num)
{
	if(temp==NULL)
   		cout<<"Number not found";
         return 0;
    if(temp->data == num)
      		cout<<"Number found";
          return 1;
   if(temp->data > num)
          		Search(temp->LTree, num);
   if(temp->data < num)
   			Search(temp->RTree, num);
}


void InorderTraversal(node* temp)
{
	if(temp!=NULL)
   {
   		InorderTraversal(temp->LTree);
      	cout<<temp->data<<endl;
     	InorderTraversal(temp->RTree);
   }
}

void PostorderTraversal(node* temp)
{
	if(temp!=NULL)
   {
   		PostorderTraversal(temp->LTree);
      	PostorderTraversal(temp->RTree);
      	cout<< temp->data<<endl;
   }
}
void PreorderTraversal(node* temp)
{
    if(temp!=NULL)
   {
   		cout<<temp->data;
      	PreorderTraversal(temp->LTree);
      	PreorderTraversal(temp->RTree);
   }
}
void DeleteNode(node *temp, int num)
{	if (temp==NULL)
   	cout<<"Number not Found";
   else if((temp->data == num)) //node found
   {      node *parent, *min ;
          int number;
     // if number is found at a leaf node
     if((temp->LTree == NULL) && (temp->RTree == NULL))
     {
		parent=getParent(root,num);  //will return parent node
     	if(parent->LTree == temp)
     		parent->LTree = NULL;
     	else if (parent->RTree == temp)
         		parent->RTree = NULL;
              delete temp;
     }
     else if(((temp->LTree == NULL) && (temp->RTree != NULL)) || ((temp->LTree != NULL) && (temp->RTree == NULL)))
     {
     	parent = getParent(root,num); //will return parent node
		if(temp->LTree != NULL){
            		if(parent->LTree == temp)
     			parent->LTree = temp->LTree;
     	   	else if (parent->RTree == temp)
         			parent->RTree = temp->LTree;
        	 }
         	else if(temp->RTree != NULL){
			if(parent->LTree == temp)
     			parent->LTree = temp->RTree;
     	   	else if (parent->RTree == temp)
         			parent->RTree = temp->RTree;
         	}
		delete temp;
     }
//if node to be deleted has two children
else if((temp->LTree != NULL) && (temp->RTree != NULL))
     {
       min = FindMin(temp->RTree);  //will return the min. no. found in RTree
	  number = min->data;
       DeleteNode(temp->RTree, min->data);  //calling to itself recursively
       temp->data= number;
	 }
   } // end node found


   else if (num < temp->data)
   	DeleteNode(temp->LTree, num);   //calling to itself recursively
   else  //if (num > temp->data)
   	DeleteNode(temp->RTree, num); //calling to itself recursively
}
void degree(node *temp, int a) {
int q;
q=Search(root,a);
	node *temp1;
   temp1->data=a;
if(q==1)
{
   if((temp1->LTree != NULL) && (temp1->RTree != NULL))
   	printf("Node have degree 2");
   else if((temp->LTree != NULL) && (temp->RTree == NULL) || (temp->LTree == NULL) && (temp->RTree != NULL))
      printf("Node have degree 1");
   else if((temp->LTree == NULL) && (temp->RTree == NULL))
      printf("Node have degree 0");
}

}
