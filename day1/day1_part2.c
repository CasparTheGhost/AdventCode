#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long int best, second, third;
} Ranking;

void init_ranking(Ranking* ranking) {
    if (ranking) {
        ranking->best = 0;
        ranking->second = 0;
        ranking->third = 0;
    }
}

int update_ranking(Ranking* ranking, long int comparison) {
    if (ranking) {
        if (comparison > ranking->best) {
            long int old_best = ranking->best;
            long int old_second = ranking->second;
            ranking->best = comparison;
            ranking->second = old_best;
            ranking->third = old_second;
        }
        else if (comparison > ranking->second) {
            long int old_second = ranking->second;
            ranking->second = comparison;
            ranking->third = old_second;
        }
        else if (comparison > ranking->third) {
            ranking->third = comparison;
        }
    }
}

int main() {

    FILE *file;
    Ranking rank;
    char chunk[10];
    long int max_calories = 0, curr_calories = 0;

    file = fopen("day1_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

    init_ranking(&rank);

    //reads until EOF
    while (fgets(chunk, 10, file)) {
        if (chunk[0] == '\n'){
            update_ranking(&rank, curr_calories);
            curr_calories = 0;
        }
        else 
            curr_calories += strtol(chunk, 0, 10);
    }

    update_ranking(&rank, curr_calories);

    long int sum_of_top_3 = rank.best + rank.second + rank.third;

    printf("max calories: %ld", sum_of_top_3);
    fclose(file);

    return 0;
}