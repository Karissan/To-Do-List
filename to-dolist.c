#define _GNU_SOURCE
#include <stdio.h>
#include <readline/readline.h>
#include <string.h>
#include <stdlib.h>

int get_option() {
	printf("\nTo-do list menu: \n");
	printf("(q)uit\n");
	printf("(a)dd an item\n");
	printf("(d)elete an item\n");
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
	char *(*list_items)[] = NULL;
	int list_size = 0;
	int response = 0;
	//char *(*pointer_to_delete)[] = NULL;
	FILE *file_handle;
	char *line;
	size_t len;
	ssize_t return_value;
	
	file_handle = fopen("/home/karissan/.todo", "r");
	if(file_handle) {
		while(1){
			line = NULL;
			len = 0;
			return_value = getline(&line, &len, file_handle);
			if(return_value == -1) {
				break;
			} else {
				char *(*old_list)[] = list_items;
				list_items = malloc(sizeof(char*) * (list_size + 1));
				memcpy(list_items, old_list, sizeof(char*) * list_size);
				line[return_value - 1] = '\0';
				(*list_items)[list_size] = line;
				list_size++;
			}
		}
		fclose(file_handle);
	}

	while (response != 1) {
		printf("\nItems: \n");
		for (int i = 0; i < list_size; i = i + 1) {
			printf("(%i) %s \n", i + 1, (*list_items)[i]);
		}
		response = get_option();
    
		if (response == 2) {
			// add an item here
			char *(*old_list)[] = list_items;
			list_items = malloc(sizeof(char*) * (list_size + 1));
			memcpy(list_items, old_list, sizeof(char*) * list_size);
			(*list_items)[list_size] = readline("text of to-do list:\n");
			list_size++;
		} else if (response == 3) {
			// code to delete item: ask user which item to delete, free dynamic memory, move other items to fill hole, subtract 1 from count
			char *user_input = readline("Enter number for item to delete\n");
			//converts input to integer
			int number = atoi(user_input);
			if (number < 1 || number > list_size) {
				printf("Error: Invalid input\n");
			} else {
				char *(*old_list)[] = list_items;
				list_items = malloc(sizeof(char*) * (list_size - 1));
				// * in the line below dereferences the pointer (gives back what the pointer points to)
				free((*old_list)[number - 1]);
				memcpy(*list_items, *old_list, sizeof(char*) * (number - 1));
				memcpy(*list_items + (number - 1), *old_list + number, sizeof(char*) * (list_size - number));
				free(old_list);
				list_size--;
			}
		} 
	}
	
	file_handle = fopen("/home/karissan/.todo", "w");
	for (int i = 0; i < list_size; i++) {
		fprintf(file_handle, "%s\n", (*list_items)[i]);
	} 
	fclose(file_handle);

	return 0;
}
