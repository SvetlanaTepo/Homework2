#include <stdio.h> 	  

void reverse(char* string) {    // reversing the string

 	if (!string || *string == '\0') return;  // check for NULL

 	char *end = string; 

        while(*end) end++; //go once to the end

        end--; // getback to last char 
        
        while (string < end) {  // algorithm for reversing 

                *string = *string ^ *end;
                *end = *string ^ *end;
                *string = *string ^ *end;

                ++string;
                --end;
        }
}


int main() {
	char sentence[] = "Es im anush Hayastani arevaham barn em sirum, mer hin sazi voxbanvag, lacakumac barn em sirum, arnanman caxikneri u varderi buyry varman, u nairyan axjikneri hezachkun parn em sirum"; //our string
	
        printf("Original: %s\n", sentence);
	
        reverse(sentence);
	
        printf("Reversed: %s\n", sentence);

	printf("\n");

	char nothing[] = " ";
       
        printf("Original: %s\n", nothing);
       
        reverse(nothing);
       
        printf("Reversed: %s\n", nothing);

	printf("\n");

	char *null = NULL;
       
        printf("Original: %s\n", null);
        
        reverse(null);
        printf("Reversed: %s\n", null);

	return 0;
}

