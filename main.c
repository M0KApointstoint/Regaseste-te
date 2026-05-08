#include <stdio.h>
#include "functions.h"

int main(void)
{
	printf("Hello, World!\n");
	// Testing:
	struct trie_node *r = 0;
	
	char *strings[] = {"a", "ab", "abc", "salut", "zebra", "qweqweqwe", "a", "abb", "abca"};
	int arr_len = sizeof(strings) / sizeof(*strings);
	int exit_code = 123;
	for (int i = 0; i < arr_len; ++i) {
		exit_code = add_key_trie(&r, strings[i]);
		printf("Exit code for adding the key %s is %d\n", strings[i], exit_code);
	}
	exit_code = 123;
	exit_code = destroy_trie(&r);
	printf("Exit code for destroying tree is %d\n", exit_code);
	exit_code = destroy_trie(&r);
	printf("Exit code for trying to destroy same destroyed tree is %d\n", exit_code);

	return 0;
}

