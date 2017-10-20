//structs
struct song_node { char name[256]; char artist[256]; struct song_node *next; };
struct song_arr * song_arr[27];

//linkedlist functions
void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node *insert_order(struct song_node *, char *, char *);
struct song_node * search_artist(char *, struct song_node *);
struct song_node *search_song(struct song_node *, char *, char *);
struct song_node *get_random(struct song_node *);
struct song_node *remove_node(struct song_node *, char *, char *);
struct song_node * free_list(struct song_node *);

//song_arr functions
int char_index(char);
struct song_node * add_song(struct song_arr *, char *, char *);
struct song_node * search_artist_arr(struct song_arr, char * );
struct song_node * search_song_arr(struct song_arr , char *, char *);
void print_letter(struct song_arr , char );
void print_artist(struct song_arr , char *);
void print_arr(struct song_arr );
void shuffle(struct song_arr , int);
void delete_song(struct song_arr, char *, char *);
void free_arr(struct song_arr);
