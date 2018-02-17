#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int graph[20][20];
char courselist[50][256];
int G[20][20],m,color_tab[10],i,j,n,a,b;
bool visited[5];
void startcoloring();
void Gr_coloring(int k,int n);

struct queue{
    int data;
    struct queue *next;
};

struct queue* first = NULL;
struct queue* last = NULL;

struct queue* createqueue(int x)
{
    struct queue* newqueue = (struct queue*)malloc(sizeof(struct queue));
    newqueue->data = x;
    newqueue->next = NULL;
    return newqueue;
}
void enQueue(int x)
{
    struct queue* newyqueue = createqueue(x);
    if(first == NULL)
    {
        first = newyqueue;
        last = newyqueue;
    }
    else
    {
        last->next = newyqueue;
        last = newyqueue;
    }
}
void deQueue()
{
    if(first == NULL)
    {
        printf("\n Your Queue is already empty please enqueue an item");
        return;
    }

    if(first->next == NULL)
    {
        first = NULL;
        last = NULL;
    }
    else
    {
        struct queue* secondqueue = first->next;
        free(first);
        first = secondqueue;
    }

}
bool isEmpty()
{
    if(first == NULL)
        return true;
    else
        return false;
}
int next()
{
    return first->data;
}
void Bfscolor(int root)
{
    int i;
    for(i = 0; i < 6; i++)
    {
        visited[i] = false;
    }
    visited[root]  = true;
    enQueue(root);
    printf("\nBFS order: ");
    while(isEmpty() == false)
    {

        root = next();
        printf("%d ", root);
        deQueue();
        for( i = 0; i < 7; i++)
        {
            if(visited[i] == false && graph[root][i] == 1)
            {
                visited[i] = true;
                enQueue(i);
            }
        }
    }
    printf("\n");
    startcoloring();
}
int readfile(FILE *fp1,char courselist[][256]){
    char word[200];
    char ch[200];
    int i=0;
    while (fgets(word, sizeof(word), fp1)){

        strcpy(ch,word);

        char *string;

        string = strtok(ch, ":");

        while (string != NULL) {


            string = strtok(NULL, ",");
            if (string != NULL) {
                strcpy(courselist[i],string);
                i++;
            }


        }

    }
    return 0;

}


int turnnumber(char x []){

    if(strstr(x,"BLAW203")!=NULL){
        return 1;
    }
    if(strstr(x,"CSE100")!=NULL){
        return 2;
    }
    if(strstr(x,"HIST111")!=NULL){
        return 3;
    }
    if(strstr(x,"MATH101")!=NULL){
        return 4;
    }
    if(strstr(x,"MATH259")!=NULL){
        return 5;
    }
    if(strstr(x,"STAT253")!=NULL){
        return 6;
    }
    return 0;
}

void create_graph() {
    int a=0;
    int b;
    while(strstr(courselist[a],"\n")==NULL){
        a++;
    }
    b=a;
    if(a==2){
        for(int x=0;x<2;x++){
            if(x==0){
                graph[turnnumber(courselist[x])][turnnumber(courselist[x+1])] = 1;
                graph[turnnumber(courselist[x])][turnnumber(courselist[x+2])] = 1;
                graph[turnnumber(courselist[x+1])][turnnumber(courselist[x])] = 1;
                graph[turnnumber(courselist[x+2])][turnnumber(courselist[x])] = 1;
            }
            if(x==1){
                graph[turnnumber(courselist[x])][turnnumber(courselist[x+1])] = 1;
                graph[turnnumber(courselist[x+1])][turnnumber(courselist[x])] = 1;
            }
        }
    }
    a++;
    while(strstr(courselist[a],"\n")==NULL){
        a++;
    }

    if(a-b==2){
        graph[turnnumber(courselist[a-1])][turnnumber(courselist[a])] = 1;
        graph[turnnumber(courselist[a])][turnnumber(courselist[a-1])] = 1;

    }
    else if(b-a==1){

    }
    b=a;
    a++;
    while(strstr(courselist[a],"\n")==NULL){
        a++;
    }
    if(a-b==2){
        graph[turnnumber(courselist[a-1])][turnnumber(courselist[a])] = 1;
        graph[turnnumber(courselist[a])][turnnumber(courselist[a-1])] = 1;

    }
    else if(b-a==1){

    }
    b=a;
    a++;

    while(strstr(courselist[a],"\n")==NULL){
        a++;
    }
    if(a-b==3){
        for(int x=0;x<2;x++){
            if(x==0){
                graph[turnnumber(courselist[a-2])][turnnumber(courselist[a-1])] = 1;
                graph[turnnumber(courselist[a-2])][turnnumber(courselist[a])] = 1;
                graph[turnnumber(courselist[a-1])][turnnumber(courselist[a-2])] = 1;
                graph[turnnumber(courselist[a])][turnnumber(courselist[a-2])] = 1;
            }
            if(x==1){
                graph[turnnumber(courselist[a-1])][turnnumber(courselist[a])] = 1;
                graph[turnnumber(courselist[a])][turnnumber(courselist[a-1])] = 1;
            }
        }
    }

}


void display() {
    int i, j;
    int n=6;
    printf("        BLAW203 CSE100 HIST11 MATH101 MATH259 STAT253\n");
    printf("        _______ ______ ______ _______ _______ _______");

    for (int i = 1; i <= n; i++) {
        if(i==1)
            printf("\nBLAW203|");
        if(i==2)
            printf("CSE100 |");
        if(i==3)
            printf("HIST111|");
        if(i==4)
            printf("MATH101|");
        if(i==5)
            printf("MATH259|");
        if(i==6)
            printf("STAT253|");


        for (j = 1; j <= n; j++)

            printf("%6d ", graph[i][j]);
        printf("\n");

    }

}

void startcoloring(){
    n=6;
    m=n-1;

    for(int x=0;x<=7;x++){
        for(int y=0;y<=7;y++){
            if(graph[x][y]==1){
                G[x][y]=1;
                G[y][x]=1;
            }

        }

    }
    Gr_coloring(1,n);
    for(i=1;i<=n;i++){
        if(i==1){
            printf("\nVertex%d(BLAW203) Color:=%d",i,color_tab[i]);
        }
        if(i==2){
            printf("\nVertex%d(CSE100) Color:=%d",i,color_tab[i]);
        }
        if(i==3){
            printf("\nVertex%d(HIST111) Color:=%d",i,color_tab[i]);
        }
        if(i==4){
            printf("\nVertex%d(MATH101) Color:=%d",i,color_tab[i]);
        }
        if(i==5){
            printf("\nVertex%d(MATH259) Color:=%d",i,color_tab[i]);
        }
        if(i==6){
            printf("\nVertex%d(STAT253) Color:=%d\n",i,color_tab[i]);
        }



    }
}
void Gen_Col_Value(int k,int n)
{
    while(1)
    {
        a=color_tab[k]+1;
        b=m+1;
        color_tab[k] = a%b;
        if(color_tab[k]==0) return;
        for(j=1;j<=n;j++)
        {
            if(G[k][j] && color_tab[k]==color_tab[j])
                break;
        }
        if(j==n+1) return;
    }
}
void Gr_coloring(int k,int n)
{
    Gen_Col_Value(k,n);
    if(color_tab[k]==0) return;
    if(k==n)  return;
    else Gr_coloring(k+1,n);
}

int main(){

    FILE *fp1;
    fp1 = fopen("project3.txt","r");
    readfile(fp1,courselist);
    create_graph();
    display();
    Bfscolor(1);

    printf("\n");
    int comma=0;
    for(int x=1;x<=3;x++){
        printf("Final Exam Period %d=>",x);
        comma=0;
        for(int n=1;n<11;n++){

            if(color_tab[n]==x){
                if(comma!=0)
                    printf(", ");
                if(n==1){
                    printf("BLAW203");
                }
                if(n==2){
                    printf("CSE100");
                }
                if(n==3){
                    printf("HIST111");
                }
                if(n==4){
                    printf("MATH101");
                }
                if(n==5){
                    printf("MATH259");
                }
                if(n==6){
                    printf("STAT253");
                }
                comma++;
            }
        }
        printf("\n");
    }




    return 0;
}







