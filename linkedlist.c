#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };
void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

void print_list(struct node *p){
    while(p){
        printf("%d -> ", p->i);
        p = p->next;
    }
    printf("NULL\n");
}

struct node * insert_front(struct node *p, int num){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->i=num;
    new->next=p;
    return new; 
}

struct node * free_list(struct node *p){
    struct node *old;
    while(p){
        old = p;
        p = p->next;
        free(old);
    }
    return 0;
}

int main(){
    struct node *linked = insert_front(NULL, 25);
    print_list(linked);
    printf("Adding more elements...\n");
    linked = insert_front(insert_front(insert_front(linked, 24), 23), 22);
    print_list(linked);
    printf("about to free...\n");
    free_list(linked);
    print_list(linked);
    return 0;
}
