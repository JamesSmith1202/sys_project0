#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers.h"

//to find where each letter is in the array
int char_index(char a) {
    return a - 97; //lowercase chars start at 97
}

//add songs in order based on artist name and song
void add_song(struct song_node *arr[], char *name, char *artist) {
    arr[char_index(artist[0])] = insert_order(arr[char_index(artist[0])], artist, name); 
    printf("%s by %s has been added!\n", name, artist);
}

//search for first song by specified artist
struct song_node *search_artist_arr(struct song_node *arr[], char *artist) {
    return search_artist(artist, arr[char_index(artist[0])]);
}

//search for specified song by specified artist
struct song_node *search_song_arr(struct song_node *arr[], char *artist, char *name) {
    return search_song(arr[char_index(artist[0])], artist, name);
}

//print all songs with artists starting with specified letter
void print_letter(struct song_node *arr[], char a) {
    print_list(arr[char_index(a)]);
}

//print all songs by specified artist
void print_artist(struct song_node *arr[], char *artist) {
    struct song_node *start = search_artist(artist, arr[char_index(artist[0])]);
    while (start && (strcmp(start -> artist, artist) == 0)) {
        printf("Song: %s | ", start -> name);
        start = start -> next;
    }
    printf("\n");
}

//print all songs by all artists
void print_arr(struct song_node *arr[]) {
    int i = 0;
    for (; i < 26; i++) {
        printf("%c:\t", i + 97);
        print_list(arr[i]);
    }
}

//get songs number of random songs
void shuffle(struct song_node *arr[], int songs) {
    struct song_node *rsong;
    for (; songs > 0; songs--) {
        rsong = 0;
        while (!rsong) {
            int letter = rand() % 26;
            rsong = get_random(arr[letter]);
        }
        printf("%s : %s | ", rsong -> artist, rsong -> name);
    }
    printf("\n");
}

//delete specified song from library
void delete_song(struct song_node *arr[], char *artist, char *name) {
    struct song_node *i;

    //deletes song from the letter of the artist in library
    i = remove_node(arr[char_index(artist[0])], artist, name);
    arr[char_index(artist[0])] = i;

    //if song doesn't exist
    if (!i) {
        printf("Song not found\n");
    }

    printf("Song was deleted\n");
}

//free entire library
void free_arr(struct song_node *arr[]) {
    int i = 0;
    
    //frees each list for each letter
    for (; i < 26; i++) {
        arr[i] = free_list(arr[i]); 
    }

    printf("Array has been freed\n");
}
