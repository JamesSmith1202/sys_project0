#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers.h"

int char_index(char a)
{
    return a - 97; //lowercase chars start at 97
}

void add_song(struct song_node *song_arr[], char *name, char *artist)
{
    song_arr[char_index(artist[0])] = insert_order(song_arr[char_index(artist[0])], artist, name); //needs to be song_node
    printf("%s by %s has been added!\n", name, artist);
}

struct song_node *search_artist_arr(struct song_node *song_arr[], char *artist)
{
    return search_artist(artist, song_arr[char_index(artist[0])]); //another
}

struct song_node *search_song_arr(struct song_node *song_arr[], char *artist, char *name)
{
    return search_song(song_arr[char_index(artist[0])], artist, name);
}

void print_letter(struct song_node *song_arr[], char a)
{
    print_list(song_arr[char_index(a)]); //another
}

void print_artist(struct song_node *song_arr[], char *artist)
{
    struct song_node *start = search_artist(artist, song_arr[char_index(artist[0])]); // another
    while (start && (strcmp(start->artist, artist) == 0))
    {
        printf("Song: %s | ", start->name);
        start = start->next;
    }
    printf("\n");
}

void print_arr(struct song_node *arr[])
{
    int i = 0;
    for (; i < 26; i++)
    {
        print_list(arr[i]); //another
    }
}

void shuffle(struct song_node *arr[], int songs)
{
    struct song_node *rsong;
    for (; songs > 0; songs--)
    {
        rsong = 0;
        while (!rsong)
        {
            int letter = rand() % 26;
            rsong = get_random(arr[letter]); //another
        }
        printf("%s : %s | ", rsong->artist, rsong->name);
    }
    printf("\n");
}

void delete_song(struct song_node *arr[], char *artist, char *name)
{
    struct song_node *i;
    i = remove_node(arr[char_index(artist[0])], artist, name); //another
    arr[char_index(artist[0])] = i;
    if (!i)
    {
        printf("Song not found\n");
    }
    printf("Song was deleted\n");
}

void free_arr(struct song_node *arr[])
{
    int i = 0;
    for (; i < 26; i++)
    {
        arr[i] = free_list(arr[i]); //another
    }
    printf("Array has been freed\n");
}
