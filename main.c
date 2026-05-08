#include <stdio.h>
#include "functions.h"

int main(void)
{
	printf("Hello, World!\n");
	// Testing:
	struct trie_node *r = 0;

	static char * const s[] = {"a", "ab", "abc", "zebra", "qweqweqwe", "a"};
	int arr_len = sizeof(s) / sizeof(*s);
	int exit_code = 123;
	for (int i = 0; i < arr_len; ++i) {
		exit_code = add_key_trie(&r, s[i]);
		printf("Exit code for adding key %s is %d\n", s[i], exit_code);
	}
	exit_code = 123;
	exit_code = print_trie(r);
	printf("Exit code for printing tree is %d\n", exit_code);

	exit_code = 123;
	exit_code = destroy_trie(&r);
	printf("Exit code for destroying tree is %d\n", exit_code);

	exit_code = 123;
	exit_code = print_trie(r);
	printf("Exit code for printing destroyed tree is %d\n", exit_code);
	return 0;
}

