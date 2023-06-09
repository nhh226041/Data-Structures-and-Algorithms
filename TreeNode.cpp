#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int data; //data of each node
    struct treeNode *leftmost_child;
    struct treeNode *right_sibling;
}treeNode;
void preOrder(treeNode *r){
    //Root left right
    if(r==NULL) return;
    printf("%d ", r->data); //visit root
    treeNode *p = r->leftmost_child;
    // preOrder(p);
    while(p!=NULL){
        preOrder(p);
        p = p->right_sibling;
    }
}
void postOrder(treeNode *r){
    //left right root
    if(r==NULL) return;
    treeNode *p = r->leftmost_child;
    while(p != NULL){
        postOrder(p);
        p = p->right_sibling;
    }
    printf("%d ", r->data);
}
void inOrder(treeNode *r){
    //left root right
    if(r==NULL) return;
    treeNode *p = r->leftmost_child;
    inOrder(p);
    printf("%d ", r->data);//vist root
    if(p!=NULL) p =p->right_sibling;
    while(p!=NULL){
        inOrder(p);
        p = p->right_sibling;
    }
}
int countNodes(treeNode *r){
    if(r==NULL) return 0;
    int result = 0;
    result++;
    treeNode*p = r->leftmost_child;
    while(p!=NULL){
        result+=countNodes(p);
        p = p->right_sibling;
    }
    return result;
}
int countLeaves(treeNode *r){
    if(r==NULL) return 0; int result = 0;
    treeNode *p =  r->leftmost_child;
    if(p==NULL) return result++;
    while(p!=NULL){
        result+=countLeaves(p);
        p = p->right_sibling;
    }
    return result;
}
int main()
{
    // Test the code
    // Create a sample tree
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node1 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node2 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node3 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node4 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node5 = (treeNode *)malloc(sizeof(treeNode));

    root->data = 1;
    root->leftmost_child = node1;
    root->right_sibling = NULL;

    node1->data = 2;
    node1->leftmost_child = node2;
    node1->right_sibling = node3;

    node2->data = 3;
    node2->leftmost_child = NULL;
    node2->right_sibling = node4;

    node3->data = 4;
    node3->leftmost_child = node5;
    node3->right_sibling = NULL;

    node4->data = 5;
    node4->leftmost_child = NULL;
    node4->right_sibling = NULL;

    node5->data = 6;
    node5->leftmost_child = NULL;
    node5->right_sibling = NULL;

    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    return 0;
}
