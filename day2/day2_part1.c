#include <stdio.h>

#define Rock 1
#define Paper 2
#define Scissors 3

//calc move score through ascii offset
int enemy_move_score(char enemy_move){
    return (enemy_move - 65) + 1;
}

int my_move_score(char my_move){
    return (my_move - 88) + 1;
}

int round_result(char enemy_move, char my_move) {

    const int enemy_score = enemy_move_score(enemy_move);
    const int my_score = my_move_score(my_move);

    if (my_score == enemy_score)
        return 3 + my_score;

    switch (enemy_score) {
        case Rock:
            switch (my_score) {
                case Scissors:
                    return my_score;
                case Paper:
                    return 6 + my_score;
            }
        case Paper:
            switch (my_score) {
                case Rock:
                    return my_score;
                case Scissors:
                    return 6 + my_score;
            }
        case Scissors:
            switch (my_score) {
                case Rock:
                    return 6 + my_score;
                case Paper:
                    return my_score;
            }
    }

    return 0;
}

int main() {
    FILE *file;
    char chunk[3], enemy_move, my_move;
    int total_score = 0;
    
    file = fopen("day2_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

    while (!feof(file)){
        fscanf(file, "%c %c\n", &enemy_move, &my_move);
        total_score += round_result(enemy_move, my_move);
    }
    
    printf("total score: %d", total_score);

    fclose(file);
    return 0;
}
