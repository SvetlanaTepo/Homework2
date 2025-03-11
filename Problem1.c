#include <stdio.h> 

int main() {
	FILE *same_file = fopen("Problem1.c", "r"); // open the file

	if(same_file == NULL) { // check of the file

		perror("There is no available file to open");
		return 0;

	}
	char brackets; 
    int row = 1; 
    int column = 0; 

	while((brackets = fgetc(same_file)) != EOF) { // check the places of brackets

		column++;
		if(brackets == '\n') { // if there is a new line it goes to the next row
			row++;
			column = 0;
		}
		if(brackets == '{' || brackets == '}') //checkthe brackets
			printf("%c is in Row: %d, column: %d\n", brackets, row, column);

		}
	fclose(same_file);
    
	return 0;
}

