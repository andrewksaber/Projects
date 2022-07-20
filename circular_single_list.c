#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
 struct node * next ;

};
struct node *add_at_empty (int d ){
struct node * tail = malloc(sizeof(struct node)) ;
tail->data = d ;
tail->next = tail ;
return tail ;
};
struct node * add_at_beg(int d , struct node * tail ){
struct node * temp = malloc(sizeof(struct node) ) ;
temp->data =d ;
temp->next = tail->next ;
tail->next = temp;
return tail ;

};
struct node *add_at_end(int d ,struct node * tail ){

struct node * temp = malloc(sizeof(struct node)) ;
temp->data = d ;
temp->next = tail->next ;
tail->next = temp ;
tail = temp ;
return tail ;
};
void show(struct node * tail ){
struct node *ptr = tail->next ;
printf("\n");
do{
    printf("%d ",ptr->data);
    ptr=ptr->next ;
}while(ptr!=tail->next );

}
int list_size(struct node * tail){
int size=0 ;
struct node *ptr = tail->next ;
printf("\n");
do{
    size++;
    ptr=ptr->next ;
}while(ptr!=tail->next );

return size  ;
}
struct node * add_at_pos(int d , int pos , struct node *tail ){
if(pos==1){
    tail = add_at_beg(d,tail) ;
    return tail  ;
}
else if(pos ==list_size(tail)+1){
    tail = add_at_end(d,tail) ;
    return tail ;
}
else if(pos >list_size(tail)+1){
    printf("\n position doesn't exist ") ;
    return tail ;
}
else {
    pos-- ;
    struct node * ptr = tail->next  ;
struct node * temp = malloc(sizeof(struct node))  ;
temp->data = d ;
while(pos!=1){
    ptr =ptr->next ;
    pos -- ;
}
temp->next = ptr->next ;
ptr->next = temp ;
return tail ;

}
};
struct node * del_1st_node(struct node * tail ){
struct node * ptr   = tail ;
struct node * temp  = tail->next ;
ptr->next=ptr->next->next ;
free(temp) ;

return tail ;

};

struct node * del_last_node(struct node * tail ){
struct node *ptr = tail->next ;
while(ptr->next!= tail ){
    ptr = ptr->next ;
}
ptr->next = tail->next  ;
free(tail) ;
tail = ptr ;
return tail ;
};
int main()
{
struct node * tail = add_at_empty(1) ;
tail = add_at_beg(2,tail) ;
tail = add_at_end(4,tail) ;
tail = add_at_pos(22,1,tail ) ;
tail = add_at_pos(23,list_size(tail),tail ) ;

show(tail) ;
tail = del_1st_node(tail) ;
tail = del_last_node(tail)  ;
show(tail) ;

    return 0;
}
