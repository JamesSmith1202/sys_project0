#include <stdio.h>
#include <stdlib.h>

void print_list(struct song_node *p){
    while(p){
        printf("%s : %s | ", p->name, p -> artist);
        p = p->next;
    }
    printf("NULL\n");
}

struct song_node * insert_front(struct song_node *p, char * art, char * name){
    struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
    new->name = name;
    new -> artist = art;
    new->next=p;
    return new; 
}

struct song_node * free_list(struct song_node *p){
    struct song_node *old;
    while(p){
        old = p;
        p = p->next;
        free(old);
    }
    return 0;
}

struct song_node * search_list(char * artist, char * song, struct song_node * lshead) {
  while (head) {
    if (head -> artist == artist && head -> name == song) {
      return head;
    }
    head -> next;
  }
  return 0;
}

struct song_node * search_artist(char * artist, struct song_node * head) {
  while (head) {
    if (head -> artist == artist) {
      return head;
    }
    head -> next;
  }
  return 0;
}

void insert_order(struct song_node *head, char *art, char *name) {
  struct song_node *to_add = (struct song_node*)malloc(sizeof(struct song_node));
  to_add->name = name;
  to_add->artist = art;
  struct song_node * temp = NULL;
  while (head) {
    if (strcmp(head -> artist, to_add -> artist) == 0 ) {
      if (strcmp(head -> name, to_add -> name) < 0) {
	to_add -> next = head;
	temp -> next = to_add;
      }
    }
    if (strcmp(head -> artist, to_add -> artist) < 0 ) {
      to_add -> next = head;
      temp -> next = to_add;
    }
    temp = head;
  }
}

int main(){
    struct song_node *linked = insert_front(NULL, 25);
    print_list(linked);
    printf("Adding more elements...\n");
    linked = insert_front(insert_front(insert_front(linked, 24), 23), 22);
    print_list(linked);
    printf("about to free...\n");
    free_list(linked);
    print_list(linked);
    return 0;
}
