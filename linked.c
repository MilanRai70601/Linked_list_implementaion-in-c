#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};

struct node *ptr,*start;
void create_node(){
    int value ;
    printf("Enter data to insert ");
    scanf("%d",&value);
    ptr= (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("memory is full\n");
        return;
    }
    ptr->data=value;
    ptr->next= NULL;
    if(start==NULL){
        start = ptr;
    printf("%d inserted succefully\n",value);        
    }else{
        printf("List is already created\n");
        free(ptr);
    }

}
void insert_beg(){
    int value ;
    printf("Enter data to insert ");
    scanf("%d",&value);
ptr= (struct node*)malloc(sizeof(struct node));
if(ptr==NULL){
    printf("memory is full");
    return ;
}
ptr->data=value;
ptr->next=start;
start= ptr;
printf("%d is inserted at beggining succedfully!\n",value);
    

}

void insert_last(){
    struct node *temp=start;
    if(start==NULL){
        printf("List is not created\n");
        return ;
    }
ptr= (struct node*)malloc(sizeof(struct node));
    int value ;
    printf("Enter data to insert ");
    scanf("%d",&value);
    while(temp->next!=NULL){
        temp=temp->next;
    }

temp->next=ptr;
ptr->data=value;
ptr->next=NULL;
printf("%d is insert at last succesfully!!\n",value);
    
}

void insert_random(){
    struct node *temp=start;
    int pos;
    int value ;
    printf("Enter data to insert ");
    scanf("%d",&value);    
    ptr= (struct node*)malloc(sizeof(struct node));

    printf("Enter position : ");
    scanf("%d",&pos);
    if(start ==NULL){
        printf("List is not created\n");
        return;

    }
    if(pos==1){
        ptr->data= value;
        ptr->next=start;
        start=ptr;
        printf("Node is inserted at 1 succefully!!\n");
        return;
        
    }
    for(int i = 1;i<pos-1 && temp!=NULL;i++){
  temp = temp->next;
    }
    if(temp==NULL){
        printf("List is short!!\n");
        return ;
    }
    ptr->next = temp->next;
    temp->next= ptr;
    ptr->data = value;
    printf("%d inserted at %d position \n",value,pos);
}

void delete_first(){
if(start==NULL){
    printf("List is empty\n");
    return;
}
struct node* temp = start;
start= start->next;
free(temp);
printf("first node is deleted succesfully!!\n");

}

void delete_last(){
 struct node* temp = start;
 struct node* prev;

   
    if(start==NULL){
    printf("List is empty");
    return;
}

 if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Last node deleted successfully!!\n");
        return;
    }
while(temp->next!=NULL){
prev= temp;
temp = temp->next;
}
prev->next=NULL;
free(temp);
printf("Last node is deleted succesfully!!\n");

}

void delete_random(){
    struct node* temp = start;
 struct node* prev;
 int pos;
   printf("Enter position : ");
    scanf("%d",&pos);
 if(start==NULL){
    printf("List is empty\n");
    return;
 }
    if(pos==1){
        struct node* temp= start;
        start=start->next;
        free(temp);
        printf("first node deleted succesfuly!!\n");
        return ;
    }
 
 for(int i=1;i<pos && temp!= NULL;i++){
    prev= temp;
    temp=temp->next;
 }
 if(temp==NULL){
    printf("List is short\n");
    return;
 }
 prev->next=temp->next;
 free(temp);
 printf("node deleted from %d postion\n",pos);

}

void display(){
    struct node* temp = start;
        if(start==NULL){
            printf("List is empty\n");
            return;
        }    
    while(temp!=NULL){

        printf("| %d | %p |",temp->data,temp->next);
        printf("->\n");
        temp=temp->next;
    }

}

void search(){
    struct node* temp = start;
    int value;
    int pos=1;
    printf("Enter value to search : ");
    scanf("%d",&value);
    if(start==NULL){
        printf("List is empty\n");
        return ;
    }
    while(temp!=NULL){
        if(temp->data==value){
            if(temp==start){
       printf("%d found at index 1(address: %p)\n",value,temp);
       return;
}
printf("%d found at position %d(adress:%p)\n",value,pos,temp);
return ;
        }
        pos+=1;
        temp=temp->next;
    }
printf("%d not found !!",value);
}

int main(){
    int choice;
    while(1){
        printf("======Linked list Menu========\n");
        printf("1.Create a node\n");
        printf("2.Insert at beggning\n");
        printf("3.Insert at last\n");
        printf("4.Insert at random \n");
        printf("5.Delete from first\n");
        printf("6.Delete from last\n");
        printf("7.Delete from random\n");
        printf("8.display\n");
        printf("9.Search\n");
        printf("10.exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            create_node();
            break;

            case 2:
            insert_beg();
            break;
           
            case 3:
            insert_last();
            break; 

            case 4:
            insert_random();
            break;
            
           case 5:
           delete_first();
           break;


            case 6:
            delete_last();
            break;


            case 7:
            delete_random();
            break;

            case 8:
            display();
            break;

            case 9:
            search();
            break;

            case 10:
            exit(0);
            break;

            default:
            printf("Invalid choice, Try again !!");
            break;


        }
    }
}