#include <stdio.h>

int main() {
    FILE *file;
    int left_pair[2], right_pair[2];
    int overlapping_count = 0;
    
    file = fopen("day4_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }
    
    while (!feof(file)){
        fscanf(file, "%d-%d,%d-%d\n", &left_pair[0], &left_pair[1], &right_pair[0], &right_pair[1]);

        if (left_pair[1] >= right_pair[1] && right_pair[0] >= left_pair[0])
            overlapping_count++;
        else if (right_pair[1] >= left_pair[1] && left_pair[0] >= right_pair[0])
            overlapping_count++;
       
    }
    
    printf("total score: %d", overlapping_count);

    fclose(file);
    return 0;
}
