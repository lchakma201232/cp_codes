#include <stdio.h>
#include <random>

int nums[100];
struct node{
    int value;
    node *next;
};
void insert(node **head,int value){
    nums[value]++;
    node *current = *head;
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = new node;
    current->next->value = value;
    current->next->next = NULL;
}
int compare(int x,int y){
    if(nums[x]<nums[y]) return 1;
    else if(nums[x]==nums[y]){
        return y>x;
    }else{
        return 0;
    }
}
void bubbleSort(node **head){
    node *current = *head;
    int counter=0;
    while(current->next!=NULL && counter<10000){
        counter++;
        node *prev = current;
        while(current->next!=NULL){
            if(compare(current->value,current->next->value)){
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
            }
            current = current->next;
        }
        current = prev;
    }
}
void customOrder(node **head){
    bubbleSort(head);
}
int main(){
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    node *head=NULL;
    while(n--){
        int x=1+rand()%100;
        if(head==NULL){
            head=new node;
            head->value=x;
            head->next=NULL;
            nums[x]++;
        }else{
            insert(&head,x);
        }
    }
    customOrder(&head);
    while(head){
        printf("%d ",head->value);
        head=head->next;
    }
}