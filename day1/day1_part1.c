#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    char chunk[10];
    long int max_calories = 0, curr_calories = 0;

    file = fopen("day1_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

    //reads until EOF
    while (fgets(chunk, 10, file)) {
        if (chunk[0] == '\n'){
            if (curr_calories > max_calories)
                max_calories = curr_calories;
            curr_calories = 0;
        }
        else 
            curr_calories += strtol(chunk, 0, 10);
    }

    if (curr_calories > max_calories)
        max_calories = curr_calories;

    printf("max calories: %ld", max_calories);
    fclose(file);

    return 0;
}