#define ALPHABET_LEN 26

struct trie_node {
	struct trie_node *children[ALPHABET_LEN];
	int is_terminal;
};

