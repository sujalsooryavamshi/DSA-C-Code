//check weather the binary is sum tree or not
#include<stdio.h>
#include<stdlib.h>
struct tree {
    int data;
    struct tree *left, *right;
};
struct tree *root=NULL;
struct tree* create();
int issumtree(struct tree *);
int sum(struct tree *);
main()
{
    root=create();
	if(issumtree(root))
	  printf("The given binary tree is the sum tree");
	else
	  printf("The given tree is not the sum tree");

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
int issumtree(struct tree *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
	  return 1;
	
	int ls=sum(root->left); // sum of the left sub tree
	int rs=sum(root->right); // sum of the right sub tree

	if(root->data==(ls+rs) && issumtree(root->left) && issumtree(root->right))
	 return 1;
 return 0;

}
int sum(struct tree *root)
{
	if(root==NULL)
	 return 0;
	return sum(root->left)+ root->data + sum(root->right);
}