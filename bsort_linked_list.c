struct node {
int data ; 
struct node * link ; 

};
int list_size(struct node * head ){
int size = 0 ; 
struct node * ptr = malloc(sizeof(struct node)) ; 
ptr = head ;

while (ptr!=NULL)
{
    size++ ; 
    ptr = ptr->link ; 
}
return size ; 





}
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

int main(){
struct node * head = malloc(sizeof(struct node )) ; 
head->data = 1 ;
head->link = NULL ; 



    return 0 ; 
}