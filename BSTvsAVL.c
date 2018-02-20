#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct bst{
char word[100];
struct bst *right;
struct bst *left;
};
typedef struct bst bst;

struct avl
{   char key[100];
    struct avl *left;
    struct avl *right;
    int height;
};
typedef struct avl avl;
double memory;

int height(struct avl *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int maxx(int a,int b)
{
    if(a<b)
        return a;
    else if(b<a)
        return b;

}
struct avl * minValueavl(struct avl* avl)
{
    struct avl* current = avl;

    while (current->left != NULL)
        current = current->left;

    return current;
}

void inorder(struct bst *rootbst);
struct bst* newbst(char item[]);
struct bst* insertbst(struct bst* bst, char key[]);
struct bst* deletebst(struct bst* rootbst, char key[]);
struct bst * minValuebst(struct bst* bst);

struct avl* newavl(char key[]);
struct avl *rightRotate(struct avl *y);
struct avl *leftRotate(struct avl *x);
int getBalance(struct avl *N);
struct avl* insert(struct avl* avl, char key[]);
void preOrder(struct avl *root);
struct avl* deleteavl(struct avl* root, char key[]);

int x;
int y;

void main(){
FILE *fp1,*fp2;

if(fp1=fopen("file1.txt","r"))
printf(" ");
else{
printf("file error");
exit(1);
}
char temp[100];
struct bst *rootbst = NULL;
clock_t begin = clock();

fscanf(fp1,"%s",temp);
rootbst=insertbst(rootbst,temp);

    while(!feof(fp1)){
        fscanf(fp1,"%s",temp);
        insertbst(rootbst,temp);

}

clock_t end = clock();

double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nAdding bst file1 time spent: %f seconds.\n",time_spent);
memory=72*sizeof(struct bst);
printf("Adding bst file1 memory usage:");
printf("%f byte.",memory);

fclose(fp1);

x=1;
//inorder(rootbst);

fp1=fopen("file1.txt","r");
begin = clock();

for(int k=0;k<10;k++){
    fscanf(fp1,"%s",temp);
    deletebst(rootbst,temp);
}
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nDeleting bst file1 time spent: %f seconds.",time_spent);
memory=10*sizeof(struct bst);
printf("\nDeleting bst file1 memory usage: %f byte.",memory);
fclose(fp1);
x=1;
//inorder(rootbst);

struct avl *root = NULL;
if(fp1=fopen("file1.txt","r"))
printf(" ");
else{
printf("file error");
exit(1);
}
char temp2[100];
fscanf(fp1,"%s",temp2);
root=insert(root,temp2);
begin = clock();
while(!feof(fp1)){
    fscanf(fp1,"%s",temp2);
    root=insert(root,temp2);
}
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nAdding avl file1 time spent %f seconds.",time_spent);
memory=72*sizeof(struct avl);
printf("\nAdding avl file1 memory usage %f byte.",memory);
fclose(fp1);
y=1;
//preOrder(root);

fp1=fopen("file1.txt","r");
begin = clock();

for(int k=0;k<10;k++){
    fscanf(fp1,"%s",temp);
    deleteavl(root,temp);
}
fclose(fp1);
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nDeleting avl file1 time spent : %f seconds.\n",time_spent);
memory=10*sizeof(struct avl);
printf("Deleting avl file1 memory usage : %f bytes.",memory);
y=1;
//preOrder(root);




if(fp2=fopen("file2.txt","r"))
printf(" ");
else{
printf("file error");
exit(1);
}
//char temp[100];
rootbst = NULL;
 begin = clock();
fscanf(fp2,"%s",temp);
rootbst=insertbst(rootbst,temp);
while(!feof(fp2)){
        fscanf(fp2,"%s",temp);
        insertbst(rootbst,temp);
}
 end = clock();
 time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nAdding bst file2 time spent: %f seconds.\n",time_spent);
memory=63*sizeof(struct bst);
printf("Adding bst file2 memory usage:");
printf("%f",memory);
printf(" byte.");

fclose(fp2);
x=1;
//inorder(rootbst);

fp1=fopen("file2.txt","r");
begin = clock();

for(int k=0;k<10;k++){
    fscanf(fp2,"%s",temp);
    deletebst(rootbst,temp);
}
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nDeleting bst file2 time spent: %f seconds.",time_spent);
memory=10*sizeof(struct bst);
printf("\nDeleting bst file2 memory usage: %f byte.",memory);
fclose(fp1);
x=1;
//inorder(rootbst);

root = NULL;
if(fp1=fopen("file2.txt","r"))
printf(" ");
else{
printf("file error");
exit(1);
}

fscanf(fp2,"%s",temp2);
root=insert(root,temp2);
begin = clock();
while(!feof(fp2)){
    fscanf(fp2,"%s",temp2);
    root=insert(root,temp2);
}
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\nAdding avl file2 time spent : %f seconds.",time_spent);
memory=63*sizeof(struct avl);
printf("\nAdding avl file2 memory usage : %f byte.\n",memory);
fclose(fp1);
y=1;
//preOrder(root);

fp2=fopen("file2.txt","r");
begin = clock();

for(int k=0;k<10;k++){
    fscanf(fp2,"%s",temp);
    deleteavl(root,temp);
}
fclose(fp2);
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Deleting avl file2 time spent : %f seconds.\n",time_spent);
memory=10*sizeof(struct avl);
printf("Deleting avl file2 memory usage : %f byte.\n",memory);
y=1;
//preOrder(root);

}


struct bst* insertbst(struct bst* bst, char key[])
{
    if (bst == NULL)
        return newbst(key);
    if (strcasecmp(key,bst->word) < 0)
        bst->left  = insertbst(bst->left, key);
    else if (strcasecmp(key,bst->word) > 0)
        bst->right = insertbst(bst->right, key);
    return bst;
}
struct bst* newbst(char item[])
{
    struct bst *temp =  (struct bst *)malloc(sizeof(struct bst));
    strcpy(temp->word,item);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct bst *rootbst)
{

    if (rootbst != NULL)
    {
        inorder(rootbst->left);
        printf("%d %s \n", x,rootbst->word);
        x++;
        inorder(rootbst->right);
    }

}
struct bst * minValuebst(struct bst* bst)
{
    struct bst* current = bst;

    while (current->left != NULL)
        current = current->left;

    return current;
}
struct bst* deletebst(struct bst* rootbst, char key[])
{

    if (rootbst == NULL) return rootbst;

    if (strcasecmp(key,rootbst->word)<0)
        rootbst->left = deletebst(rootbst->left, key);

    else if (strcasecmp(key,rootbst->word)>0)
        rootbst->right = deletebst(rootbst->right, key);

    else
    {
        if (rootbst->left == NULL)
        {
            struct bst *temp = rootbst->right;
            free(rootbst);
            return temp;
        }
        else if (rootbst->right == NULL)
        {
            struct bst *temp = rootbst->left;
            free(rootbst);
            return temp;
        }

        struct bst* temp = minValuebst(rootbst->right);

       strcpy(rootbst->word , temp->word);

        rootbst->right = deletebst(rootbst->right, temp->word);
    }
    return rootbst;
}

struct avl* newavl(char key[])
{
    struct avl* avl = (struct avl*)malloc(sizeof(struct avl));
    strcpy(avl->key,key);
    avl->left=NULL;
    avl->right=NULL;
    avl->height=1;
    return(avl);
}
struct avl *rightRotate(struct avl *y)
{
    struct avl *x = y->left;
    struct avl *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = maxx(height(y->left), height(y->right))+1;
    x->height = maxx(height(x->left), height(x->right))+1;
    return x;
}
struct avl *leftRotate(struct avl *x)
{
    struct avl *y = x->right;
    struct avl *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = maxx(height(x->left), height(x->right))+1;
    y->height = maxx(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(struct avl *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct avl* insert(struct avl* avl, char key[])
{

    if (avl == NULL)
        return(newavl(key));

    if (strcasecmp(key,avl->key)<0)
        avl->left  = insert(avl->left, key);
    else if (strcasecmp(key ,avl->key)>0)
        avl->right = insert(avl->right, key);
    else // Equal keys are not allowed in BST
        return avl;

    avl->height = 1 + maxx(height(avl->left),height(avl->right));

    int balance = getBalance(avl);

    if (balance > 1 && strcasecmp(key,avl->left->key)<0)
        return rightRotate(avl);

    // Right Right Case
    if (balance < -1 && strcasecmp(key,avl->right->key)>0)
        return leftRotate(avl);

    if (balance > 1 && strcasecmp(key,avl->left->key)>0)
    {
        avl->left =  leftRotate(avl->left);
        return rightRotate(avl);
    }

    if (balance < -1 && strcasecmp(key ,avl->right->key)<0)
    {
       avl->right = rightRotate(avl->right);
        return leftRotate(avl);
    }

    return avl;
}
void preOrder(struct avl *root)
{
    if(root != NULL)
    {
        printf("%d %s\n", y, root->key);
        y++;
        preOrder(root->left);
        preOrder(root->right);
    }
}
struct avl* deleteavl(struct avl* root, char key[])
{
    if (root == NULL)
        return root;

    if ( strcasecmp(key,root->key)<0 )
        root->left = deleteavl(root->left, key);

    else if(strcasecmp(key,root->key)>0 )
        root->right = deleteavl(root->right, key);
    else
    {
        // avl with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct avl *temp = root->left ? root->left : root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
        }
        else
        {

            struct avl* temp = minValueavl(root->right);

            strcpy(root->key,temp->key);

            root->right = deleteavl(root->right, temp->key);
        }
    }

    // If the tree had only one avl then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT avl
    root->height = 1 + maxx(height(root->left),height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
