#include <stdio.h> 


int main() {
	char sentence[1024] = {0};

	printf("Enter what you need: ");

	scanf(" %s", sentence); 

	char symbol; 
	int count; 
	int digit_count; 
	int copy_count; 
	int adress = 0; 
	for(int i = 0; i < 1024 && sentence[i] != '\0'; i++){ // the loop for finding  same charachters

		count = 1;

		for(int j = i; j < 1024 && sentence[j] != '\0'; j++){ // from the defined place finding characters
			symbol = sentence[i];

			if(sentence[i] == sentence[j + 1]){ // counting the same numbers
				count++;
			}
			else {
				digit_count = 0;
				copy_count = count;
				while(copy_count != 0){ // computing the digits of the count
					copy_count /= 10;
					digit_count++;
				}
				for (int k = 1023; k >= digit_count + adress; k--) { // move right 
        				sentence[k] = sentence[k - digit_count];
    				}
				sentence[adress] = symbol; // giving the symbol 
				copy_count = count;
				for(int u = adress + digit_count; copy_count != 0; u--) { // put in a right position
					symbol = '0' + (copy_count % 10);
					sentence[u] = symbol;
					copy_count /= 10;
				}
				adress += digit_count + 1; // move to next
				i += digit_count + count - 1; 
			}
		}
	}
	sentence[adress] = '\0'; 
	printf("%s\n", sentence);
	return 0;
}
