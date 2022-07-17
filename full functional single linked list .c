#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * link ;
};
struct node * add_at_end(int d ,struct node * ptr){
struct node * temp  = malloc(sizeof(struct node)) ;
temp ->data = d ;
temp->link= NULL ;
ptr->link = temp ;
return temp  ;


};
struct node * add_at_beg(int d ,struct node * head ){
struct node * temp = malloc(sizeof(struct node)) ;
temp ->data = d ;
temp->link = head ;
head = temp ;
return head ;
};
struct node * del_1st_node(struct node * head ){
if(head == NULL){
    printf("\n list is empty ")  ;
    return head  ;
}
else {

struct node * temp = head ;
head = head->link ;
free(temp) ;
return head ;
}
};
struct node * del_last_node(struct node * head ){
if(head == NULL){
    printf("\n list is empty ")  ;
    return head  ;
}
else if (head->link == NULL){
    free(head) ;
    head =NULL  ;
    return head ;
}
else {
    struct node * temp = head ;
    while(temp->link->link!=NULL){
        temp =temp->link ;
    }

free(temp->link) ;
temp->link = NULL ;
return head;


}


};
struct node * bsort(struct node *head ){
struct node * ptr = malloc(sizeof(struct node)) ;
ptr = head ;
int size = list_size(head) ;
int arr[size] ;
for(int i  =0 ; i<size ; i++){
    arr[i] = ptr->data ;
    ptr = ptr->link ;
}
for(int i = 0 ; i<size-1 ;i++){
    for(int j =i+1 ; j<size ;j++){
        if(arr[i]>arr[j]){
        int temp = arr[i] ;
        arr[i] = arr[j] ;
        arr[j] = temp ;
    }
}
}
ptr = head;
for(int i  =0 ; i<size ; i++){
   ptr->data  =arr[i];
    ptr = ptr->link ;
}
return head;
};


void del_particular(int pos , struct node *head) {
struct node * ptr = head  ;
pos-- ;
while(pos != 1){
    ptr =ptr->link ;
    pos-- ;
}
ptr ->link = ptr->link->link ;


};

struct node * del_list(struct node * head ){
struct node * ptr  = head  ;
while(head !=NULL){
    ptr = head ;
    head=head->link ;
    free(ptr) ;
}
head = NULL;
return head ;
};

int main()
{
struct node * head = malloc(sizeof(struct node )) ;
head->data = 1 ;
head->link = NULL ;
struct node * ptr = malloc(sizeof(struct node )) ;
ptr = head ;
ptr=add_at_end(2,ptr) ;
ptr=add_at_end(3,ptr) ;
ptr=add_at_end(4,ptr) ;
head = add_at_beg(7,head ) ;

head = add_at_beg(55,head ) ;
head = add_at_beg(36,head ) ;
ptr = head ;

while(ptr!=NULL){
    printf("%d ",ptr->data ) ;
    ptr =ptr->link  ;

}
 del_particular(5,head) ;

printf("\n ") ;
ptr = head ;
while(ptr!=NULL){
    printf("%d ",ptr->data ) ;
    ptr =ptr->link  ;

}
printf("\n ") ;
head =del_list(head) ;
ptr = head ;
if(head ==NULL){
    printf("\n list is empty ");
}
while(ptr!=NULL){
    printf("%d ",ptr->data ) ;
    ptr =ptr->link  ;

}



return 0;
}
