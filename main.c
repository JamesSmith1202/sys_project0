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


    printf("------------------------------------\nMUSIC LIBRARY TESTS\n ------------------------------------\n");

    return 0;
}