#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

void createnode(struct node **,struct node **);
void display(struct node *);
void delete(struct node **);
void insert(struct node **);


int main()
{
    struct node *head=NULL;
    struct node *temp=NULL;
    
    int choice;
    while(1)
    {
        printf("1.CREATE NODE\n");
        printf("2.DISPLAY NODE\n");
        printf("3.DELETE NODE\n");
        printf("4.INSERT NODE\n");
        printf("5.EXIT\n");
        printf("ENTER CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            createnode(&head,&temp);
            break;
            case 2:
            display(head);
            break;
            case 3:
            delete(&head);
            break;
            case 4:
            insert(&head);
            case 5:
            break;
          
        }
    }
}

void createnode(struct node **headref,struct node **temp)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node ));
    
    printf("ENTER DATA : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    
    if(*headref==NULL)
    {
        *headref=newnode;
    }
    else
    {
        (*temp)->next=newnode;
    }
     *temp=newnode;
}

void display(struct node *headref)
{
    struct node *temp=headref;
    if(headref==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return;
    }
    while(temp->next!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);

}



void delete(struct node **headref)
{
    if(*headref==NULL)
    {
        printf("LINKEDLIST IS EMPTY");
    }
    struct node *temp=*headref;
      struct node *pre=NULL;
    int choice;
    while(1)
    {
        printf("1.DELETE FROM BEGINNING\n");
        printf("2.DELETE FROM SPECIFIC POSTION\n");
        printf("3.DELETE FROM END\n");
        printf("4.RETURN\n");
        printf("ENTER CHOICE \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            *headref=(*headref)->next;
            free(temp);
            break;
            
            case 2:
            int key;
            printf("ENTER THE KEY YOU WANT TO DELETE: ");
            scanf("%d",&key);
            while(temp->data!=key)
            { 
                pre=temp;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("KEY NOT FOUND ");
            }
            else{
                if(pre==NULL)
                {
                    free(temp);
                }
            }
            pre->next=temp->next;
            free(temp);
            break;
            
            case 3:
            while(temp->next!=NULL)
            {
                pre=temp;
                temp=temp->next;
            }
            pre->next=NULL;
            free(temp);
            break;
            
            case 4:
            return;
        }
    }
}


void insert(struct node **headref)
{
    if(*headref==NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    struct node *temp=*headref;
    struct node *pre;
    int key;
    int choice;
    while(1)
    {
        printf("1.INSERT AT BEGINNING\n");
        printf("2.INSERT BEFORE ELEMENT \n");
        printf("3.INSERT AT END\n");
        printf("4.RETURN TO MAIN MENU\n ");
        printf("ENTER CHOICE :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("ENTER DATA: ");
                scanf("%d",&newnode->data);
                newnode->next=temp;
                *headref=newnode;
                break;
                
            case 2:
            
               printf("ENTER DATA: ");
                scanf("%d",&newnode->data);
                newnode->next=NULL;
                printf("ENTER KEY ");
                scanf("%d",&key);
                 if (temp != NULL && temp->data == key) {
       
              newnode->next = temp;
              *headref = newnode;
                while(temp!=NULL &&  temp->data!=key)
                {
                    pre=temp;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    printf("KEY NOT FOUND");
                }
                newnode->next=temp;
                pre->next=newnode;
                break;
             
             case 3:
                printf("ENTER DATA: ");
                scanf("%d",&newnode->data);
                newnode->next=NULL;
                while(temp->next!=NULL)
                {

                    temp=temp->next;
                }
                temp->next=newnode;
                break;
           
           case 4:
                return;
            
        }
    }
}
}