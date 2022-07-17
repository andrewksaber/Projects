#include <stdio.h>
#include <stdlib.h>
struct node{
int data ;
struct node * next ;
struct node * prev  ;
} ;
struct node * add_at_beg(int d , struct node * head){
struct node * temp = malloc(sizeof(struct node))  ;
temp->data = d;
temp->next= head;
 head ->prev = temp ;
 head= temp ;
 return head;

};
void add_after(int pos , int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
struct node * ptr = head ;
temp->data = d;
 while(pos!= 1 ){
    ptr = ptr->next ;
    pos-- ;

}
temp->next = ptr ->next ;
temp->prev = ptr ;
ptr ->next = temp ;


}
void add_before(int pos , int d , struct node * head ){

struct node * temp = malloc(sizeof(struct node)) ;
struct node * ptr = head ;
temp->data = d;
pos--;
 while(pos!= 1 ){
    ptr = ptr->next ;
    pos-- ;

}
temp->next = ptr ->next ;
temp->prev = ptr ;
ptr ->next = temp ;




};

void add_at_empty(int d , struct node * head ){
head->data = d ;
head->next =NULL ;
head->prev = NULL;
}
void add_at_end(int d , struct node * head){
struct node * temp = malloc(sizeof(struct node)) ;
temp ->data= d ;
temp->next= NULL ;
struct node * ptr = head ;
while(ptr->next !=NULL){
    ptr = ptr->next  ;
}
ptr ->next = temp ;
temp->prev = ptr  ;
};

int main()
{
struct node * head  = malloc(sizeof(struct node ))  ;
add_at_empty(1,head) ;
head=add_at_beg(2,head) ;
head=add_at_beg(2,head) ;
head=add_at_beg(2,head) ;
add_at_end(5,head) ;

add_after(5,777,head) ;
add_before(5,666,head) ;
struct node*ptr = head;
while(ptr!=NULL){
    printf("%d ",ptr->data) ;
    ptr = ptr->next;


}

    return 0;
}
