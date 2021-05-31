#include<stdio.h>
#include<stdlib.h>

struct tNode
{
    int data;
    struct tNode* left;
    struct tNode* right;
};


struct sNode
{
    struct tNode *t;
    struct sNode *next;
};


void push(struct sNode** top_ref, struct tNode *t);
struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);


void preorder(struct tNode *root)
{
    struct tNode *q,*current = root;
    struct sNode *s = NULL;
    while (1)
    {   printf("%d ",current->data);
        if(current->right != NULL){
            push(&s,current->right);
        }
        if(current->left != NULL){
            current = current->left;
            continue;
        }
        if(isEmpty(s))return;
        current = pop(&s);
    }
}

void inorder(struct tNode *root){
    struct tNode *current = root;
    struct sNode *s = NULL;
    while (1){
        while(current->left != NULL){
            push(&s,current);
            current = current->left;
        }
        while (current->right==NULL){
            printf("%d ",current->data);
            if(isEmpty(s))return;
            current = pop(&s);
        }
        printf("%d ",current->data);
        current = current->right;
    }
}

void postorder(struct tNode *root){
    struct tNode *q, *current = root;
    struct sNode *s = NULL;
    q = root;
    while (1){
        while(current->left != NULL){
            push(&s,current);
            current = current->left;
        }
        while (current->right==NULL || current->right == q){
            printf("%d ",current->data);
            q = current;
            if(isEmpty(s))return;
            current = pop(&s);
        }
        push(&s,current);
        current = current->right;
    }
}


void push(struct sNode** top_ref, struct tNode *t)
{

    struct sNode* new_tNode =
            (struct sNode*) malloc(sizeof(struct sNode));

    if(new_tNode == NULL)
    {
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }


    new_tNode->t = t;


    new_tNode->next = (*top_ref);


    (*top_ref) = new_tNode;
}

bool isEmpty(struct sNode *top)
{
    return (top == NULL)? 1 : 0;
}


struct tNode *pop(struct sNode** top_ref)
{
    struct tNode *res;
    struct sNode *top;

    if(isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

struct tNode* newtNode(int data) {
    struct tNode *tNode = (struct tNode *)
            malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}

int main()
{
    int choice;

    struct tNode *root = newtNode(50);

    root->left	 = newtNode(40);
    root->right	 = newtNode(60);


    root->left->left = newtNode(30);
    root->right->right = newtNode(70);

    root->left->left->left = newtNode(25);
    root->left->left->right = newtNode(35);
    root->right->right->left = newtNode(65);
    root->right->right->right = newtNode(80);

    root->left->left->left->left = newtNode(20);
    root->left->left->right->left = newtNode(33);
    root->left->left->right->right = newtNode(36);

    printf("1. for Pre_order traversal\n"
           "2. for In_order traversal\n"
           "3. for post_order tracersal\n"
           "Enter Your choice :- ");
    scanf("%d", &choice);
    switch (choice){
        case 1:{
            preorder(root);
            break;
        }
        case 2:{
            inorder(root);
            break;
        }
        case 3:{
            postorder(root);
            break;
        }
        default:{
            printf("Wrong Entry Try again.\n");
            main();
        }
    }
    return 0;
}