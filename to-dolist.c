#include <stdio.h>
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>

int get_option() {
  printf("\nTo-do list menu: \n");
  printf("(Q)uit\n");
  printf("(A)dd an item\n");
  printf("(D)elete an item\n");
  char* response = readline("Select an option: ");
  if (response) {
// check if readline returns null
    if (!strcmp(response, "q")) {
// if it didn't, run this
      free(response);
      return 1;
    } else if (!strcmp(response, "a")) {
	// code to add item
      free(response);
      return 2;
    } else if (!strcmp(response, "d")) {
	// code to delete item
      free(response);
      return 3;
    } else {
      printf("Error: unknown option: \"%s\"\n", response);
      free(response);
      return 0;
    }
  } else {
// if readline returns null, give same response as quit
    printf("\n");
// add new line after quitting
    return 1;
  }
}
int main(int argc, char **argv) {

  int response = 0;

  while (response != 1) {
    response = get_option();
  }

  return 0;
}
