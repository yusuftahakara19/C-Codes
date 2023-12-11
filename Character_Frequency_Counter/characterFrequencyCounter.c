#include <stdio.h>


int isAlphabetic(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32;// 32 = ('a' - 'A')
    } else {
        return ch;
    }
}

int main() {
    char paragraph[1000];
    int sentence_count = 0, word_count = 0, letter_count = 0, i, j;
    int letter_freq[26] = {0}; // Array to store frequencies

    printf("Bir metin veriniz:\n");
    fgets(paragraph, sizeof(paragraph), stdin);
	i = 0;
	while(paragraph[i] != '\0'){
		 if (isAlphabetic(paragraph[i])) {
            letter_count++;
			// Convert uppercase to lowercase and calculate the index
            int index = toLowerCase(paragraph[i]) - 'a';
            letter_freq[index]++;
        } else if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?') {
            sentence_count++;
        }
        i++;
	}


	word_count = 0; 
   i = 0;
	while(paragraph[i] != '\0'){
    if (paragraph[i] == ' ' || paragraph[i] == '\n' || paragraph[i] == '\t') {
		// Checking for multiple spaces
        if (paragraph[i + 1] != ' ' && paragraph[i + 1] != '\n' && paragraph[i + 1] != '\t') {
            ++word_count;
        }
    }
        i++;
    }
    


    

    printf("\nCumle sayisi: %d\n", sentence_count);
    printf("Kelime sayisi: %d\n", word_count);
    printf("Harf sayisi: %d\n", letter_count);

    for (i = 0; i < 26; i++) {
        if (letter_freq[i] > 0) {
            printf("%c %d ", 'a' + i, letter_freq[i]);
            for (j = 0; j < letter_freq[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}

