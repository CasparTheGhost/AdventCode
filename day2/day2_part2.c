#include <stdio.h>

#define Rock 1
#define Paper 2
#define Scissors 3

//calc move score through ascii offset
int enemy_move_score(char enemy_move){
    return (enemy_move - 65) + 1;
}

int cheat(char enemy_move, char expected_result) {

    const int enemy_score = enemy_move_score(enemy_move);

    if (expected_result == 'Y')
        return 3 + enemy_score;

    switch (expected_result) {
        case 'X':
            switch (enemy_score) {
                case Rock:
                    return Scissors;
                case Scissors:
                    return Paper;
                case Paper:
                    return Rock;
            }
        case 'Z':
            switch (enemy_score) {
                case Rock:
                    return 6 + Paper;
                case Scissors:
                    return 6 + Rock;
                case Paper:
                    return 6 + Scissors;
            } 
    }
}

int main() {
    FILE *file;
    char chunk[3], enemy_move, expected_res;
    int total_score = 0;
    
    file = fopen("day2_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

    while (!feof(file)){
        fscanf(file, "%c %c\n", &enemy_move, &expected_res);
        total_score += cheat(enemy_move, expected_res);
    }
    
    printf("total score: %d", total_score);

    fclose(file);
    return 0;
}
