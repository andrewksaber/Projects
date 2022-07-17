#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * prev ;
struct node *next ;


};
struct node * add_at_beg(int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp->data = d ;
temp->next= head ;
head->prev = temp ;
head =temp  ;

return head;
};
struct node * add_at_end(int d , struct node * ptr ){
struct node *temp = malloc(sizeof(struct node)) ;
temp ->data =d ;
temp->next = NULL ;
temp->prev = ptr ;
ptr ->next = temp ;
return temp  ;


};
void  add_end(int d , struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp ->data = d ;
temp->next= NULL;
struct node * ptr = head ;
while(ptr->next !=NULL) {
    ptr = ptr->next ;
}
ptr ->next = temp ;
temp->prev = temp ;



};
void add_at_empty(int d , struct node * head ){
head->data = d ;
head->next = NULL;
head->prev = NULL;


}
int main()
{
struct node * head = malloc(sizeof(struct node)) ;

add_at_empty(1, head) ;
 struct node * ptr = malloc(sizeof(struct node))  ;
ptr = head ;

 head = add_at_beg(5,head) ;
head = add_at_beg(66,head) ;
head = add_at_beg(33,head) ;
add_end(22,head) ;

ptr = head ;

while(ptr!=NULL){
    printf("%d ",ptr->data ) ;
    ptr = ptr->next ;

}


    return 0;
}
