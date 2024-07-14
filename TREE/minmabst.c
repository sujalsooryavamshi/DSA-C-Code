#include<stdio.h>
#include<stdlib.h>
struct bst{
    int data;
    struct bst *left;
    struct bst *right;
};
struct bst*insert(struct bst *root,int x);
struct bst*getnewnode(int x);
int min(struct bst *root);
int max(struct bst *root);
main()
{

    struct bst *root=NULL;
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,15);
    root=insert(root,40);
    root=insert(root,25);
    root=insert(root,7);
    root=insert(root,16);
    root=insert(root,35);
    int m=min(root);
    int l=max(root);
    printf("The min and max term from the bst are %d and %d",m,l);
}
struct bst*insert(struct bst *root,int x)
{
    
    if(root==NULL)
    {
     root=getnewnode(x);
    return root;
    }
    else if (x <=root->data)
    {
        root->left= insert(root->left,x);
    }
    else if(x>=root->data)
    {
        root->right= insert(root->right,x);
    }
    return(root);      
}
struct bst*getnewnode(int x)
{
    struct bst *new=(struct bst *)malloc(sizeof(struct bst));
    new->data=x;
    new->left=NULL;
    new->right=NULL;
    return(new);
      
}
int min(struct bst *root)
{
    if(root==NULL)
      return 0;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    int m=root->data;    
    return(m);
}
int max(struct bst *root)
{
    if(root==NULL)
      return(0);
    while(root->right!=NULL)
    {
        root=root->right;
    }
    int l=root->data;
    return(l);
}