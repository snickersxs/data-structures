/*150115031
* Alperen BAYAR*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
char word[100];
struct node *next;

};
typedef struct node node;
typedef struct node* nodePtr;
typedef struct node** nodePtrPtr;

int insert(nodePtrPtr, char [] );
int add(nodePtrPtr header, char []);


int main(){
FILE *fp1,*fp2;
if(fp1=fopen("file1.txt","r"))
printf("");
else{
printf("file error");
exit(1);
}
if(fp2=fopen("file2.txt","r"))
printf("");
else{
printf("file error");
exit(1);
}
nodePtr list1;//words in text 1 alphabetically
nodePtr iter1;//list1 header
nodePtr list2;//words in text 2 alphabetically
nodePtr iter2;//list2 header
nodePtr list3;//n grams list
nodePtr iter3;//header list 3
nodePtr list4;//first text words not alphabetic  order
nodePtr iter4;//list4 header
nodePtr list5;//second text words not alphabetic  order
nodePtr iter5;//list5 header
nodePtr common;//2n grams list
nodePtr commoniter;//2n grams list header

char temp[1000];//variable for first text words alphabetically order
char temp2[1000];//second for first text words alphabetically order
char temp3[1000];//variable for first text words text order
char temp4[1000];//variable for second text words text order


list1=NULL;//file1s words saved by insert metdod.
while(!feof(fp1)){//insert method not save common words. save alphabetically
        fscanf(fp1,"%s",temp);
        insert(&list1,temp);
}
fclose(fp1);
iter1=list1;//list header

list2=NULL;//file2s words saved by insert metdod.
while(!feof(fp2)){
        fscanf(fp2,"%s",temp2);
        insert(&list2,temp2);
}
fclose(fp2);
iter2=list2;




list3=NULL;//this loop add common words to another list.
while(iter1!=NULL){
        while(iter2!=NULL){
            if(strcmp(iter1->word,iter2->word)==0){
            insert(&list3,iter1->word);
            }
            iter2=iter2->next;//ikinci metnin olduğu listede diğer kelimeye geçiyoruz birinci listedeki ilk kelimeyle kıyaslıyor.
        }
        iter1=iter1->next;//birinci metindeki diğer kelimeye geçiyor
        iter2=list2;// ikinci listenin tekrar başına gidiyor.
}
iter1=list1;//listeleri ekrana basmak için ilk elemana ulaşıyoruz
iter3=list3;

fp1=fopen("file1.txt","r");
fp2=fopen("file2.txt","r");

int x=0;//count words N grams
while(iter3!=NULL){
    x++;
    iter3=iter3->next;
}

iter3=list3;
printf("%d N-grams: \n",x);
while(iter3!=NULL){
    strtok(iter3->word,".");//nokta ve virgülü ekrana basmıyor
    strtok(iter3->word,",");
    printf("%s \n",iter3->word);//print n grams
    iter3=iter3->next;
}

list4=NULL;
while(!feof(fp1)){//ilk metindeki kelimeleri metindeki sırasıyla ekliyor. insert değil add metodu kullanmamın sebebi bu
    fscanf(fp1,"%s",temp3);
    add(&list4,temp3);
}
iter4=list4;

list5=NULL;
while(!feof(fp2)){//ikinci metindeki kelimeleri metindeki sırasıyla ekliyor. insert değil add metodu kullanmamın sebebi bu
    fscanf(fp2,"%s",temp4);
    add(&list5,temp4);
}
iter5=list5;

common=NULL;//2n gramsları bulan döngü. birinci metnin ilk iki kelimesiyle ikinci metnin ikili kelimelerini kıyaslıyor.
while(iter4->next!=NULL){//ikinci metin bittikten sonra birinci metindeki ikili değişiyor.
    while(iter5->next!=NULL){

            if(strcmp(iter4->word,iter5->word)==0&&strcmp(iter4->next->word,iter5->next->word)==0){

                             char common2n[1000];//common kelimeleri sakladığım değişken
                             strcpy(common2n,iter4->word);//listeyi bozmamak için başka yerde tutuyurm
                             strcat(common2n," ");//ilk kelimeden sonra bir boşluk
                             strcat(common2n,iter4->next->word);//sonraki kelimeyi ekle
                             insert(&common,common2n);


            }


        iter5=iter5->next;//ikinci metindeki ikiliyi değiştir.

    }
    iter4=iter4->next;//ilk metindeki ikiliyi değiştir.
    iter5=list5;//ikinci metinin başına git.
}


commoniter=common;//listenin başına gitmek için header.

int y=0;//2n grams sayısını belirleyen döngü
while(commoniter!=NULL){
    y++;
    commoniter=commoniter->next;
}

commoniter=common;
printf("\n\n%d 2N Grams:\n",y);
while(commoniter!=NULL){//2n gramsları yazan döngü
    printf("%s\n",commoniter->word);
    commoniter=commoniter->next;
}

return 1;
}

int insert(nodePtrPtr header, char x[]){//örnekteki kod


	nodePtr newNode, temp, prev;
	newNode=malloc(sizeof(node));
	strcpy(newNode->word,x);
	newNode->next=NULL;

	if (*header == NULL){
		*header=newNode;
}
	else {
		temp=*header;
		while (temp != NULL && strcasecmp(temp->word,newNode->word)<0) {
			prev=temp;
			temp=temp->next;

		}
		if (temp!=NULL && strcasecmp(temp->word,newNode->word)==0) {
			return 0;
		}
		if (temp!=NULL)
			newNode->next=temp;
		if (temp==*header)
			*header=newNode;
		else
			prev->next=newNode;
	}

	return 1;

}



int add(nodePtrPtr header, char x[]){//kelimeleri metindeki sırasıyla eklemek için kullandığım klasik add metodu

	nodePtr newNode, temp, prev;
	newNode=malloc(sizeof(node));
	strcpy(newNode->word,x);
	newNode->next=NULL;

	if(*header == NULL){
        *header = newNode;
    }
    else
    {
        temp = *header;
         while (temp->next != NULL) {
            temp = temp->next;
  }
  temp->next = newNode;
    }
	return 1;
}


