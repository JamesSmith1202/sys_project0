#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers.h"

//prints each element of list
void print_list(struct song_node *p) {
  while (p) { //while the pointer isnt null
    printf("%s : %s | ", p -> artist, p -> name);
    p = p -> next;
  }
  printf("NULL\n");
}

//inserts a song in front of list
struct song_node *insert_front(struct song_node *p, char *art, char *name) {
  struct song_node *new = (struct song_node *)malloc(sizeof(struct song_node));
  strcpy(new -> name, name);
  strcpy(new -> artist, art);
  new -> next = p; //set the new node's pointer to the original head
  return new;
}

//inserts nodes in order based on alpha of artist then song
struct song_node *insert_order(struct song_node *head, char *art, char *name) {
  //if new node comes before head, just insert at front
  if (!head || strcmp(head -> artist, art) > 0 || (strcmp(head -> artist, art) == 0 && 
      strcmp(head -> name, name) >= 0)) {
    return insert_front(head, art, name);
  }

  struct song_node *to_add = (struct song_node *)malloc(sizeof(struct song_node)); //create and fill the node to add
  strcpy(to_add -> name, name); //set to_add.name to name
  strcpy(to_add -> artist, art);
  struct song_node *original_head = head; //save the head for return statement

  //check for artist names
  while (head -> next && strcmp(head -> next -> artist, to_add -> artist) < 0) { 
    //while head -> next isnt null and artist name is before its place
    head = head -> next;
  }

  //check for song names
  while (head -> next && strcmp(head -> next -> name, to_add -> name) && 
	 strcmp(head -> next -> artist, to_add -> artist) == 0) { 
    //while head -> next isnt null and song is before its place
    head = head -> next;
  }

  to_add -> next = head -> next; //link the nodez
  head -> next = to_add;
  return original_head;
}

//returns first song in the list by specified artist
struct song_node *search_artist(char *artist, struct song_node *head) {
  while (head) {
    if (strcmp(head -> artist, artist) == 0) { 
      //if the node has the target artist return. since it is in order, it will return the first of the ll
      return head;
    }
    head = head -> next;
  }
  return 0;
}

//returns specified song name by specified artist
struct song_node *search_song(struct song_node *head, char *artist, char *name) {
  while (head) {
    if (strcmp(head -> artist, artist) == 0 && strcmp(head -> name, name) == 0) { 
      return head;
    }
    head = head -> next;
  }
  return 0;
}

//first counts length of list and then gets int between 0 and len of list, then iterates through list
struct song_node *get_random(struct song_node *head) {
  //if null, return the head node
  if(!head){
    return head;
  }
  struct song_node *counter_head = head;
  int len = 0;
  while (counter_head) { //get the length of the linked list
    len++;
    counter_head = counter_head -> next;
  }
  int random = rand() % len;
  for (; random > 0; random--) {
    head = head -> next;
  }
  return head;
}

//removes nodes based on specified artist and song, then returns start of list
struct song_node *remove_node(struct song_node *head, char *artist, char *name) {
  struct song_node *trail;
  struct song_node *original_head;

  //if the target node is the head, just remove and free
  if (strcmp(head -> artist, artist) == 0 && strcmp(head -> name, name) == 0){
    trail = head->next;
    free(head);
    return trail;
  }
  original_head = head;
  
  //if correct node, then link up left and right nodes, then free, and return head
  while (head -> next) {
    if (strcmp(head -> next -> artist, artist) == 0 && strcmp(head -> next -> name, name) == 0) {
      trail = head -> next -> next;
      free(head -> next);
      head -> next = trail;
      return original_head;
    }
    head = head -> next;
  }
  return 0;
}

//frees entire list by going through and freeing previous node
struct song_node *free_list(struct song_node *p) {
  struct song_node *old;
  while (p) {              
    old = p;     
    p = p -> next; 
    free(old);   
  }
  return 0;
}
