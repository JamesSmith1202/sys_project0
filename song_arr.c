#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers.h"

int char_index(char a){
    return 97 - a;//lowercase chars start at 97
}

struct song_arr *add_song(struct song_arr *arr, char * artist, char * name){
    struct song_arr *new;
    if(!arr){
        new = (struct song_arr *)malloc(sizeof(struct song_arr));
        arr = new;
    }
    insert_order(*arr[char_index(artist[0])], artist, name);
    printf("%s by %s has been added!", name, artist);
    return arr;
}

struct song_node search_artist_arr(struct song_arr arr, char * artist){
    return search_artist(artist, arr[char_index(artist[0])]);
}

struct song_node search_song_arr(struct song_arr arr, char * artist, char * name){
    return search_song(arr[char_index(artist[0])], artist, name);
}

void print_letter(struct song_arr arr, char a){
    print_list(arr[char_index(a)]);
}

void print_artist(struct song_arr arr, char * artist){
    struct song_node start = search_artist(arr[char_index(artist[0])], artist);
    while(!strcmp(start->artist, artist)){
        printf("Song: %s | ", start->name);
        start = start->next;
    }
}

void print_arr(struct song_arr arr){
    int i = 0;
    for(;i<26;i++){
        print_list(arr[i]);
    }
}

void shuffle(struct song_arr arr, int songs)
{
    struct song_node * rsong;
    for (; songs > 0; songs--)
    {
        rsong = 0;
        while(!rsong){
        int letter = rand() % 26;
        rsong= get_random(arr[letter]);
        printf("%s : %s | ", rsong->artist, rsong->name);
    }
}

void delete_song(struct song_arr arr, char * artist, char * name){
    int i = remove_node(arr[char_index(artist[0])], artist, name);
    if(!i){
        printf("Song not found\n");
    }
    printf("Song was deleted\n");
}

void free_arr(struct song_arr arr){
    int i = 0;
    for(;i<26;i++){
        free_list(arr[i]);
    }
    printf("Array has been freed\n");
}