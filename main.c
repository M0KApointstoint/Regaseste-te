#include <stdio.h>
#include "functions.h"

int main(void)
{
	// Testing:
	struct trie_node *r = 0;

	static char * const s[] = {"a", "ab", "abc", "zebra", "qweqweqwe", "a"};
	int arr_len = sizeof(s) / sizeof(*s);
	int exit_code = 123;
	for (int i = 0; i < arr_len; ++i) {
		exit_code = add_key_trie(&r, s[i]);
	}
	exit_code = 123;
	exit_code = print_trie(r);

	exit_code = 123;
	exit_code = destroy_trie(&r);
	(void)exit_code;
	return 0;
}

