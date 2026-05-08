#include <stdlib.h>

#define ALPHABET_LEN 26

struct trie_node {
	struct trie_node *children[ALPHABET_LEN];
	int is_terminal;
};

struct trie_node *create_node(void)
{
	struct trie_node *new_node = malloc(sizeof(struct trie_node));
	if (!new_node) {
		return NULL;
	}
	for (int i = 0; i < ALPHABET_LEN; ++i) {
		new_node->children[i] = NULL;
	}
	new_node->is_terminal = 0;
	return new_node;
}

