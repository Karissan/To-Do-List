#include <stdio.h>
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>

int get_option(int list_size) {
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

  char *list_items[10] = {0};
  int list_size = 0;
  int response = 0;

  while (response != 1) {
    printf("\nItems: \n");
    for (int i = 0; i < list_size; i = i + 1) {
      printf("* %s \n", list_items[i]);
    }
    response = get_option(list_size);
    
    if (response == 2) {
     // add an item here
      if (list_size < 10) {
        list_items[list_size] = readline("text of to-do list:\n");
        list_size = list_size + 1;
      }
    }
  }

  return 0;
}
