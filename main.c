#include <stdio.h>
#include "functions.h"

int main(void)
{
	// Testing:
	struct trie_node *r = 0;
	static char *const fruits[] = {
	"apple",
	"banana",
	"cherry",
	"date",
	"elderberry",
	"fig",
	"grape",
	"honeydew",
	"kiwi",
	"lemon",
	"mango",
	"nectarine",
	"orange",
	"papaya",
	"quince",
	"raspberry",
	"strawberry",
	"tangerine",
	"watermelon"
	};
	int arr_len = sizeof(fruits) / sizeof(*fruits);
	int exit_code = 123;
	for (int i = 0; i < arr_len; ++i) {
		exit_code = add_key_trie(&r, fruits[i]);
	}
	exit_code = 123;
	exit_code = print_trie(r);

	exit_code = 123;
	exit_code = destroy_trie(&r);
	(void)exit_code;
	return 0;
}

