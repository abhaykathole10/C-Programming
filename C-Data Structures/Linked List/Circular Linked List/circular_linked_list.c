#include<stdio.h>
#include<stdlib.h>

//Structure declaration
struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;

void addatbegin(void);
void addatend(void);
void addatlocation(void);
int length(void);
void display(void);
void delete(void);

int main(){
    int ch, len;
    while(ch!=7){
        printf("\nCircular Linked List Operations\n");
        printf("1.add at begin\n2.add at end\n3.add at location\n4.length\n5.display\n6.delete\n7.Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: addatbegin();
                    break;
            case 2: addatend();
                    break;
            case 3: addatlocation();
                    break;
            case 4: len = length();
                    printf("\nThe length of list is %d\n", len);
                    break;
            case 5: display();
                    break;
            case 6: delete();
                    break;
            case 7: printf("Thank You\n");
                    break;
        }
    }
}
void addatbegin(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    if(root == NULL){
        root = temp;
        root->link = root;
    }
    else{
        struct node* p;
        p = root;
        while(p->link != root){
            p = p->link;
        }
        temp->link = root;
        p->link = temp;
        root = temp;
    }

}
void addatend(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &temp->data);

    if(root == NULL){
        root = temp;
        root->link = root;
    }
    else{
        struct node *p;
        p = root;
        while(p->link != root){
            p = p->link;
        }
        p->link = temp;
        temp->link = root;
    }
}
void addatlocation(){
    int loc, i=1;
    int s = length();

    printf("Enter location: ");
    scanf("%d", &loc);
    if(loc > s){
        printf("\nInvalid, there are only %d nodes\n", s);
    }
    else{
        struct node *temp, *p;
        temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = NULL;

        p = root;
        while(i != loc-1){
            p = p->link;
            i++;
        }
        temp->link = p->link;
        p->link = temp;
    }
}
int length(){
    struct node* temp;
    temp = root;
    int count = 0;

    if (root != NULL) {
        do {
            temp = temp->link;
            count++;
        } while (temp != root);
    }
    return count;
}
void display(){
    struct node* temp;
    temp = root;

    if(temp == NULL){
        printf("List is Empty\n");
    }
    else{
        while(temp->link != root){
            printf("%d --> ", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
}
void delete(){,
   int key;
   printf("Enter key: ");
   scanf("%d",&key);

   if (root == NULL){
        return;
   }
    // Find the required node
    struct node *curr = root, *prev;
    while(curr->data != key)
    {
        if (curr->link == root)
        {
            printf("\nNode not found");
            break;
        }

        prev = curr;
        curr = curr->link;
    }

    // Check if node is only node
    if (curr->link == root)
    {
        root = NULL;
        free(curr);
        return;
    }

    // If more than one node, check if
    // it is first node
    if (curr == root)
    {
        prev = root;
        while (prev->link != root){
            prev = prev->link;
        }
        root = curr->link;
        prev->link = root;
        free(curr);
    }

    // check if node is last node
    else if (curr->link == root && curr == root)
    {
        prev->link = root;
        free(curr);
    }
    else
    {
        prev->link = curr->link;
        free(curr);
    }
}