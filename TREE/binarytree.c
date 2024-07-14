#include<stdio.h>
#include<stdlib.h>
// check bst
// check binary tree is perfect tree or not
// given a key to check if it is present then display the level of it
struct tree {
    int data;
    struct tree *left, *right;
};

struct tree *root = NULL;

struct tree* create();
int preorder(struct tree *root);
int postorder(struct tree *root);
int inorder(struct tree *root);
int  checkbst(struct tree *);
int perfect(struct tree* root);
int depth(struct tree*root);
int isperfect(struct tree*root,int d,int level);
int  checkkey(struct tree*root,int key,int current);
void fibno(struct tree *root);
int isfib(int data);
int main() {
    root = create();
    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\npostorder Traversal\n");
    postorder(root);
    printf("\nInorder Traversal\n");
    inorder(root);
    if(checkbst(root));
     printf("Its bst\n");
    if(perfect(root))
     printf("\nIts perfect\n");
    else
     printf("\n its not perfect\n");

    int key;
    printf("Enter the key word to be searched and display the level\n");
    scanf("%d",&key);
    int level=checkkey(root,key,0);
   printf("The level in which it is present is %d\n",level);
   fibno(root);
}
void fibno(struct tree *root)
{
    if(root==NULL)
      return 0;
    if(isfib(root->data))
     printf("Is the fib %d\n",root->data);

     fibno(root->left);
     fibno(root->right);
}
int isfib(int data)
{
    if(data==0)
     return 1;
    int a=0,b=1,c;
    while(a<data)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return(a==data);
}
struct tree* create() {
    int x;
    struct tree *new;
    new = (struct tree *)malloc(sizeof(struct tree));

    printf("Enter the data(-1 to exit)\n");
    scanf("%d", &x);

    if (x == -1) {
        free(new); // Free the memory allocated for the unused node
        return NULL;
    }

    new->data = x;

    printf("Enter the left child of %d\n", x);
    new->left = create();

    printf("Enter the right child of %d\n", x);
    new->right = create();

    return new;
}

int preorder(struct tree *root) {
    if (root == NULL)
        return 0;

    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);

    return 0;
}
int postorder(struct tree *root)
{
    if(root==NULL)
     return(0);
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
    return (0);
}
int inorder(struct tree *root)
{
    if(root==NULL)
      return(0);
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    return(0);
}
int checkbst(struct tree*root)
{
   if(root==NULL)
    return 1;
  if(root->left!=NULL && root->data< root->left->data)
  {
       printf("\nIts not the bst\n");
       exit(0);
  }
  if(root->right!=NULL && root->data>root->right->data)
  {
       printf("\nIts not the bst\n");
       exit(0);
  }
  checkbst(root->left);
  checkbst(root->right);


}
int depth(struct tree*root)
{
    int d=0;
    while(root!=NULL)
    {
        root=root->left;
        ++d;
    }
    return(d);
}
int perfect(struct tree* root)
{
      int d=depth(root);
       return(isperfect(root,d,0));
}
int isperfect(struct tree*root,int d,int level)
{
      if(root==NULL)
        return 1;

    if(root->left==NULL && root->right==NULL)
    {
        return(d==level+1);
    }
    if(root->left==NULL || root->right==NULL)
       return 0;

    return isperfect(root->left,d,level+1) && isperfect(root->right,d,level+1);
}
 int  checkkey(struct tree*root,int key,int current)
{
    if(root==NULL)
     return 0;
    
    if(root->data==key)
     return current;
   int find= checkkey(root->left,key,current+1);
    if(find!=0)
      return find;
   find = checkkey(root->right,key,current+1);
   return find;     
}