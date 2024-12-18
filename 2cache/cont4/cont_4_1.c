#include <stdio.h>
#include <string.h>

//made by: 2cache

int is_vowel(char symbol) {
    char vowel[12] = "aeiouyAEIOUY";
    for (int i = 0; i < 12; i++) {
        if (symbol - vowel[i] == 0) return 1;
    }
    return 0;
}

int is_accurate(char *string, int num_syl) {
    int counter = 0;
    int was_vowel = 0; // flag

    while (*(string + 1) != 0) {
        if (is_vowel(*string)) {
            if (was_vowel == 0) {
                counter++;
                was_vowel = 1;
            }
        }
        else was_vowel = 0;
        string++;
    }

    if ((was_vowel == 0) && is_vowel(*(string + 1))) { //!
        counter++;
    }
    if (counter == num_syl) return 1;

    else return 0;
}

int main(void) {
    int n = 0;

    scanf("%d", &n);

    char trash = '0';

    while ((trash = getchar()) && trash != EOF && trash != '\n'); // trash was made by Daniil Pavshinskiy

    int syllables[12001] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &syllables[i]);
    }

    while ((trash = getchar()) && trash != EOF && trash != '\n'); // trash was made by Daniil Pavshinskiy

    char input[120] = "";
    char answ[1010000] = ""; // 100 char max, 10^4 strings


    for (int i = 0; i < n; i++) {
        fgets(input, 102, stdin); //gets \n
        //printf("%d %s\n", i - 1, input);
        if (is_accurate(input, syllables[i])) strcat(answ, input);
    }

    printf("%s", answ);
    return 0;
}
