#ifndef FUNCTIONS_H
#define FUNCTIONS_H

enum {
	INVALID_INPUT = -2,
	MALLOC_ERROR = -1,
	SUCCESS = 0,
	NO_SUCCESS = 1,
};

struct trie_node;

int add_key_trie(struct trie_node **root_adr, char *key);

int destroy_trie(struct trie_node **root_adr);

int print_trie(struct trie_node *root);

#endif

