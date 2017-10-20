#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "headers.h"

int main()
{
    printf("============================\nLINKED LIST TESTS\n ============================\n");

    printf("Intializing linked list with insert_front...\n\n");
    struct song_node *ll = insert_front(0, "j cole", "for whom the bell tolls");
    print_list(ll);
    printf("Adding nodes...\n");
    ll = insert_order(ll, "jay z", "ni**as in paris");
    print_list(ll);
    ll = insert_order(ll, "j cole", "g.o.m.d.");
    print_list(ll);
    ll = insert_order(ll, "jarren benton", "silence");
    print_list(ll);
    ll = insert_order(ll, "joyner lucas", "fym (feat. mystikal)");
    print_list(ll);
    ll = insert_order(ll, "jay rock", "hood gone love it (feat. kendrick lamar)");
    print_list(ll);
    ll = insert_order(ll, "joey bada$$", "temptation");
    print_list(ll);
    ll = insert_order(ll, "jay rock", "vice city (feat. black hippy)");
    print_list(ll);

    printf("------------------------------------\nTesting search_artist(joyner lucas)...\n");
    struct song_node *target = search_artist("joyner lucas", ll);
    printf("Target artist: %s song: %s \n", target->artist, target->name);

    printf("------------------------------------\nTesting search_song(jay rock, vice city (feat. black hippy))...\n");
    target = search_song(ll, "jay rock", "vice city (feat. black hippy)");
    printf("%p\n", target);
    printf("Target artist: %s song: %s \n", target->artist, target->name);

    printf("------------------------------------\nTesting get_random() 3 times...\n");
    srand(time(NULL)); //get the random seed
    target = get_random(ll);
    printf("Random artist: %s song: %s \n", target->artist, target->name);
    target = get_random(ll);
    printf("Random artist: %s song: %s \n", target->artist, target->name);
    target = get_random(ll);
    printf("Random artist: %s song: %s \n", target->artist, target->name);

    printf("------------------------------------\nTesting Remove Function...\n");
    printf("Removing Jarren Benton's Silence...\n");
    ll = remove_node(ll, "jarren benton", "silence");
    print_list(ll);

    printf("------------------------------------\nFreeing the linked list...\n");
    printf("Before...\n");
    print_list(ll);
    ll = free_list(ll);
    printf("After...\n");
    print_list(ll);
    printf("\n");


    printf("============================\nMUSIC LIBRARY TESTS\n ============================\n");
    printf("------------------------------------\nPopulating the array...\n");
    add_song(arr,"clique" ,"jay z");
    add_song(arr, "ultralight beam", "kanye west" );
    add_song(arr, "white iverson","post malone" );
    add_song(arr, "yeah right", "vince staples");
    add_song(arr, "norf norf","vince staples" );
    add_song(arr, "slippery", "migos");
    add_song(arr, "rockstar", "post malone");
    add_song(arr, "two", "lil uzi vert");
    add_song(arr, "no sleep leak", "lil uzi vert");
    add_song(arr, "the way life goes", "lil uzi vert");
    add_song(arr, "for real","lil uzi vert" );
    add_song(arr, "congratualtions","post malone" );
    add_song(arr, "pothole", "tyler the creator");
    add_song(arr, "boredom","tyler the creator" );
    add_song(arr, "ianahb","lil wayne" );
    add_song(arr, "moves","big sean" );
    printf("------------------------------------\nTesting print_arr...\n");
    print_arr(arr);
    printf("------------------------------------\nTesting print_letter...\n");
    print_letter(arr, 'l');
    printf("------------------------------------\nTesting print_artist...\n");
    print_artist(arr, "lil uzi vert");
    printf("------------------------------------\nTesting search_artist with vince staples...\n");
    target = search_artist_arr(arr, "vince staples");
    printf("Searched artist: %s First song: %s \n", target->artist, target->name);
    printf("------------------------------------\nTesting search_song with rockstar by post malone...\n");
    target = search_song_arr(arr, "post malone", "rockstar");
    printf("Artist: %s Song: %s \n", target->artist, target->name);
    printf("------------------------------------\nTesting shuffle: shuffling 5 songs...\n");
    shuffle(arr, 5);
    printf("------------------------------------\nTesting delete_song: deleting boredom by tyler the creator...\n");
    printf("before...\n");
    print_artist(arr, "tyler the creator");
    delete_song(arr, "tyler the creator", "boredom");
    printf("after....\n");
    print_artist(arr, "tyler the creator");
    printf("------------------------------------\nTesting free_arr...\n");
    printf("before...\n");
    print_arr(arr);
    free_arr(arr);
    printf("\nafter...\n");
    print_arr(arr);
    printf("============================\nEND OF TESTS\n ============================\n");
    return 0;
}