#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * link  ;

};
struct node * add_at_beg(int d ,struct node * head ){
struct node * temp  = malloc(sizeof(struct node)) ;
temp->data = d ;
temp->link = head ;
head = temp ;
return head ;


};


void bsort(struct node * head ){
struct node * ptr1 = head ;
struct node * ptr2 = head->link ;
while(ptr1->link!=NULL){
    while(ptr2!=NULL){
        if(ptr1->data>ptr2->data){
            int temp = ptr1->data ;
            ptr1->data  =ptr2->data ;
            ptr2->data = temp;

        }
ptr2=ptr2->link ;
    }
ptr2 =ptr1->link ;
ptr1=ptr1->link ;
}



}

int main()
{
struct node * head = malloc(sizeof ( struct node )) ;
head->data = 1 ;
head->link = NULL ;
head = add_at_beg(2,head) ;
head = add_at_beg(222,head) ;
head = add_at_beg(30,head) ;
head = add_at_beg(0,head) ;
struct node * ptr = head ;
while(ptr != NULL){
    printf("%d ", ptr ->data ) ;
    ptr = ptr->link  ;
}
printf("\n ");

ptr = head ;
bsort(head);
while(ptr != NULL){
    printf("%d ", ptr ->data ) ;
    ptr = ptr->link  ;
}



    return 0;
}
