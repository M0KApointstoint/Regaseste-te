#include <stdlib.h>
#include "functions.h"

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

int add_key_trie_helper(struct trie_node *node, char *key)
{
	if (!*key) {
		if (node->is_terminal) {
			return NO_SUCCESS;
		}
		node->is_terminal = 1;
		return SUCCESS;
	}
	int index = *key - 'a';
	if (!node->children[index]) {
		node->children[index] = create_node();
		if (!node->children[index]) {
			return MALLOC_ERROR;
		}
	}
	return add_key_trie_helper(node->children[index], key + 1);
}

int add_key_trie(struct trie_node **root_adr, char *key)
{
	if (!root_adr || !key || !*key) {
		return INVALID_INPUT;
	}
	if (!*root_adr) {
		*root_adr = create_node();
		if (!*root_adr) {
			return MALLOC_ERROR;
		}
	}
	return add_key_trie_helper(*root_adr, key);
}

