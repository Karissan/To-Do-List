#include <stdio.h>
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>

int get_option() {
  printf("To-do list menu: \n");
  printf("(Q)uit\n");
  char* response = readline("Select an option: ");
  if (!strcmp(response, "q")) {
    free(response);
    return 1;
  } else {
    free(response);
    printf("Error: unknown option\n");
    return 0;
  }
}
int main(int argc, char **argv) {

  int response = 0;

  while (response != 1) {
    response = get_option();
  }

  return 0;
}
