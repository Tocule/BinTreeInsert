#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

void preOrder( struct node *root) {
  
	if( root == NULL ) 
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
  
}


struct node* insert(struct node* root,int data)
{
   struct node *temp,*prev,*ptr;
   temp=NULL;
   prev=NULL;
   ptr=NULL;
   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=data;
   ptr->left=ptr->right=NULL;
   if(root==NULL)
   {
       root=ptr;
   }
   else
   {
    temp=root;
    int flag;
    while(temp!=NULL)
    {
       if(temp!=NULL)
       {
       if((temp->data)>data)
       {
           prev=temp;
           temp=temp->left;
           flag=1;
       }
       }
       if(temp!=NULL)
       {
       if((temp->data)<data)
       {
           prev=temp;
           temp=temp->right;
           flag=0;
       }
       }
    }
       if(flag==1)
       {
           prev->left=ptr;
       }
       if(flag==0)
       {
           prev->right=ptr;
       }
   }
   return root;
}


int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
	preOrder(root);
    return 0;
}
