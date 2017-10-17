struct song_node { char name[256]; char artist[256]; struct song_node *next; };
void print_list(struct song_node *);
struct song_node * insert_front(struct song_node *, char *, char *);
struct song_node * free_list(struct song_node *);
struct song_node * search_list(char * , char *, struct song_node *);
void add_order(struct song_node * head, struct song_node * to_add);
struct song_node * search_artist(char * artist, struct song_node * head);
