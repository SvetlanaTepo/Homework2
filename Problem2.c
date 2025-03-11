#include <stdio.h> 
#include <string.h>
int main(){

	FILE *csv_file = fopen("Thesample.csv", "r"); // open the file

	if(csv_file == NULL){ // checkif there is such a file

		perror("This file does not exist,sorry");
		return 0;
	}
	char line[1024] = {0}; // take each line 

	int column; 
	int column_count = 0; // counting the columns of csv file

	char search_value[1024] = {0}; // searching the value we are looking for

	char check_value[1024] = {0}; 

	fgets(line, sizeof(line), csv_file); 

	printf(" Enter the column and search value: ");

	scanf("%d %s", &column, search_value);  
	for(int i = 0; line[i] != '\0'; i++) { // getting the number of columns
                if(line[i] == ',')
                      column_count++;
        }
	if(column_count + 1 < column || column <= 0){ // checking the input 
                printf("invalid input\n");
                return 0;
        }

	printf("Column count: %d\n", column_count + 1);
       	while(fgets(line, sizeof(line), csv_file)){  // while there is something in our file it work in loop by taking each line
		column_count = 0; 

		for(int i = 0; line[i] != '\0'; i++){  // find the search value
			if(column_count + 1 == column){ // find  the column in which there is search value
				int k = i;
				int j = 0;
                                while(line[k] != ',' && line[k] != '\0' && line[k] != '\n'){ // input the value of the column in check value
					check_value[j] = line[k];
					j++;
					k++;
				}
				break;
                        }
			if(line[i] == ',') 
                                column_count++;	
		}
		if(strcmp(check_value, search_value) == 0)  // comparing the taken value and the searched
			printf("%s\n",line);
		for(int i = 0; check_value[i] != '\0'; i++) 
			check_value[i] = '\0';
	}
	fclose(csv_file); 
	return 0;
}
