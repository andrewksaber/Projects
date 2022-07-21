#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * next  ;
};

struct node *add_at_empty(int d ){
struct node * tail = malloc(sizeof(struct node )) ;
tail->data =d;
tail->next = tail ;
return tail ;

};
struct node * add_at_beg(int d , struct node * tail ){
struct node * temp = malloc(sizeof(struct node)) ;
temp->data= d ;
temp->next = tail->next ;
tail->next = temp ;
return tail  ;
};
struct node * add_at_end(int d , struct node * tail ){
struct node * temp = malloc(sizeof(struct node )) ;
temp->data = d ;
temp->next = tail->next ;
tail->next = temp ;
tail = temp ;
return tail  ;

};
int list_size(struct node * tail ){
struct node * ptr = tail ->next ;
int size = 0  ;
do{
    size++;
ptr = ptr->next ;

}while(ptr!=tail->next) ;
return size ;

}
struct node * add_at_pos(int d , int pos ,struct node * tail ){
if(pos==1){
    tail = add_at_beg(d,tail) ;
    return tail ;
}
else if(pos==list_size(tail)+1){
    tail = add_at_end(d,tail);
    return tail ;
}
else if(pos>list_size(tail)+1){
    printf("\n position doesn't exist ") ;
    return tail ;
}
else {
    pos-- ;
    struct node *ptr  =tail->next ;
    struct node * temp = malloc(sizeof(struct node)) ;
    temp->data = d ;
    while(pos!=1){
        ptr = ptr->next ;
        pos--;
    }
temp->next = ptr->next ;
ptr ->next = temp ;
return tail ;


}

};
void show(struct node * tail ){
if(tail == NULL){
    printf("\n list is empty " ) ;
    return ;
}

else{
struct node * ptr = tail->next ;
printf("\n");
do{
    printf(" %d ",ptr->data) ;
    ptr=ptr->next ;
}while(ptr!=tail->next) ;

}
};

struct node * del_1st_node(struct node * tail ){
if(tail == NULL){
    printf("\n list is empty ") ;
    return tail  ;
}
else if (tail ->next ==NULL){
    free(tail);
    tail =NULL ;
    return tail ;
}
else {
struct node * del = tail ->next ;
tail->next = del->next  ;
free(del) ;
return tail ;

}
};

struct node * del_last_node(struct node * tail ){
if(tail == NULL){
    printf("\n list is empty " ) ;
    return tail ;
}
else if (tail ->next ==NULL){
    free(tail);
    tail =NULL ;
    return tail ;
}
else {
struct node *ptr = tail->next  ;
while(ptr->next!=tail) {
        ptr =ptr->next ;

}
ptr->next = tail->next ;
free(tail);
tail = ptr ;
return tail ;
}

};
struct node * del_at_pos(int pos ,struct node * tail){
if(pos==1){
    tail = del_1st_node(tail) ;
    return tail ;
}
else if(pos==list_size(tail)+1){
    tail = del_last_node(tail);
    return tail ;
}
else if(pos>list_size(tail)+1){
    printf("\n position doesn't exist ") ;
    return tail ;
}
else {

    pos -- ;
struct node * ptr = tail->next;
while(pos!=1){
    ptr = ptr->next ;
    pos --;
}
struct node *temp = ptr->next ;
ptr->next = temp->next ;
free(temp) ;
return tail ;


}


};

int search_element(int d , struct node * tail ){
int index =0 ;

if(tail->data ==d){
    index = list_size(tail) -1 ;
    return index  ;

}
else{
struct node * ptr = tail->next ;
while(ptr!=tail ){
    if(ptr->data == d ){
        return index ;
        break ;
    }
index++;
ptr = ptr->next ;
}


}
printf("\n element doesn't exist ") ;
return -1 ;
};

struct node * del_list(struct node * tail  ){
struct node * ptr  = tail;
int size = list_size(tail) ;
for(int i = 0 ; i<size ; i++){
    ptr = tail ;
    tail = tail->next ;
    free(ptr) ;
}
tail = NULL ;

return tail ;

};


struct node * reverse_list(struct node * tail ) {
struct node * ptr = tail->next ;
struct node * newtail = add_at_empty(ptr->data) ;
ptr = ptr->next ;
do{
newtail = add_at_beg(ptr->data ,newtail) ;
ptr = ptr->next ;

}while(ptr!=tail->next) ;

tail = del_list(tail);

return newtail ;

};





int main()
{
struct node * tail = add_at_empty(1) ;
tail =add_at_beg(25,tail ) ;
tail =add_at_beg(34,tail ) ;
tail = add_at_end(66,tail) ;
tail = add_at_pos(11,list_size(tail),tail) ;
tail  =add_at_pos(33,2,tail )  ;
show(tail) ;
tail  =reverse_list(tail) ;
show(tail );
    return 0;
}

