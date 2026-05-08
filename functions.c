#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define ALPHABET_LEN 26
#define BUFFER_LEN 100

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

// Might need it, who knows.
int has_children(struct trie_node *node)
{
	if (!node) {
		return 0;
	}
	for (int i = 0; i < ALPHABET_LEN; ++i) {
		if (node->children[i]) {
			return 1;
		}
	}
	return 0;
}

void destroy_trie_helper(struct trie_node *node)
{
	if (!node) {
		return;
	}
	for (int i = 0; i < ALPHABET_LEN; ++i) {
		destroy_trie_helper(node->children[i]);
	}
	free(node);
}

int destroy_trie(struct trie_node **root_adr)
{
	if (!root_adr || !*root_adr) {
		return INVALID_INPUT;
	}
	destroy_trie_helper(*root_adr);
	*root_adr = NULL;
	return SUCCESS;
}

void print_trie_helper(struct trie_node *node, char *buffer, int index)
{
	if (node->is_terminal) {
		buffer[index] = 0;
		printf("%s\n", buffer);
	}
	for (int i = 0; i < ALPHABET_LEN; ++i) {
		if (node->children[i]) {
			buffer[index] = i + 'a';
			print_trie_helper(node->children[i], buffer, index + 1);
		}
	}
}

int print_trie(struct trie_node *root)
{
	if (!root) {
		printf("The trie is empty!\n");
		return INVALID_INPUT;
	}
	char *buffer = malloc(BUFFER_LEN);
	if (!buffer) {
		return MALLOC_ERROR;
	}
	int start_buffer_index = 0; // Never use magical numbers!
	print_trie_helper(root, buffer, start_buffer_index);
	free(buffer);
	return SUCCESS;
}

