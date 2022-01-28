#include<stdio.h>
#include<stdlib.h>
struct bst
{ int item;
struct bst *lptr, *rptr;
};
typedef struct bst node;
node* insert(node *root)
{ node *new1, *cur = root, *prev= NULL;
new1 = (node *)malloc(sizeof(node));
printf("\nEnter The Element ");
scanf("%d",&new1->item);
new1->lptr = new1->rptr = NULL;
if (root == NULL)
return new1;
while(cur != NULL)
{ prev = cur;
cur = new1->item < cur->item ?
cur->lptr : cur->rptr;
}
if (new1->item < prev->item)
prev->lptr = new1;
else
prev->rptr = new1;
return root;
}
void inorder(node *root)
{ if (root != NULL)
{ inorder(root->lptr);
printf("%d\t", root->item);
inorder(root->rptr);
}
}
void preorder(node *root)
{ if (root != NULL)
{ printf("%d\t", root->item);
preorder(root->lptr);
preorder(root->rptr);
}
}
void postorder(node *root)
{ if (root != NULL)
{ postorder(root->lptr);
postorder(root->rptr);
printf("%d\t", root->item);
}
}
int FindMin(node *root)
{ node *cur = root;
if (root == NULL)
return -1;
while(cur->lptr != NULL)
cur = cur->lptr;
return cur->item;
}
node* Delete(node *root, int data)
{ node *temp; int min;
if (root == NULL)
{ printf("tree is empty\n");
return NULL;
}
// data is in the left sub tree.
if (data < root->item)
{ root->lptr = Delete(root->lptr, data);
return(root);
}
// data is in the right sub tree.
if (data > root->item)
{ root->rptr = Delete(root->rptr, data);
return(root);
}
// data is present but no children
if (root->lptr == NULL && root->rptr == NULL)
{ printf("deleted data %d",root->item);
free(root); root = NULL;
return(root);
}
// data is present but no right subtree
if (root->rptr == NULL)
{ temp = root->lptr;
printf("deleted data %d",root->item);
free(root); return(temp);
}
// data is present but no left subtree
if (root->lptr == NULL)
{ temp = root->rptr;
printf("deleted info %d",root->item);
free(root); return(temp);
}
// If both left and right subtree are present, find the min element
// in right subtree and place it in root node and call delete function
//for right subtree.
min = FindMin(root->rptr);
root->item = min;
root->rptr = Delete(root->rptr, min);
return(root);
}
node* search(node *root, int key)
{ node *cur = root;
if(root == NULL)
return NULL;
while(cur != NULL)
{ if(key == cur->item)
return cur;
if(key < cur->item)
cur = cur->lptr;
else
cur = cur->rptr;
}
return(cur);
}
int main()
{ int choice, key,n,i;
node *root = NULL, *temp, parent;
while(1)
{ printf("\n 1.Create");
printf("\n 2.Traverse the Tree in Pre, In,Post");
printf("\n 3.Search");
printf("\n 4.Delete an element from the Tree");
printf("\n 5.Exit");
printf("\nEnter your choice :"); scanf("%d",&choice);
switch (choice)
{ case 1: printf("\n enter no. of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
root = insert(root); break;
case 2: if (root == NULL)
printf("Tree Is Not Created");
else
{ printf("\nThe Inorder Traversal : ");
inorder(root);
printf("\nThe Preorder Traversal: ");
preorder(root);
printf("\nThe Postorder Traversal : ");
postorder(root);
} break;
case 3: printf("\n Enter Element to be searched :");
scanf("%d", &key);
temp = search(root, key);
if(temp == NULL)
printf("Element does not exists\n");
else
printf("\n The element %d found", temp->item);
break;
case 4: printf("\n Enter Element to be deleted :");
scanf("%d", &key);
root = Delete(root,key); break;
default: exit(0);
} } }