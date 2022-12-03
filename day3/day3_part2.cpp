#include <iostream>
#include <unordered_map>
#include <utility>
#include <string.h>


//compare each char in all strings and get the corresponding prio
int compare(std::unordered_map<int, int>* ascii, char arr[3][60]) {
    int arr_lengths[3];
    for (int i = 0; i < 3; i++) {
        arr_lengths[i] = strlen(arr[i]);
        //printf("len[%d] = %d\n", i, arr_lengths[i]);
    }
        
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < arr_lengths[0]; j++) {
            for (int l = 0; l < arr_lengths[1]; l++) {
                if (arr[i][j] == arr[1][l]) {
                    for (int m = 0; m < arr_lengths[2]; m++) {
                        if (arr[i][j] == arr[2][m]) {
                            auto it = ascii->find((int)arr[0][j]);
                            return it->second;
                        }
                    }
                }
            }
        }
    }
}

int main() {

    FILE* file;
    char chunk[60];
    char split_chunk[3][60];
    std::unordered_map<int, int> ascii;
    int group_idx = 1;
    int count_prios = 0;

    file = fopen("day3_input.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

    // loop through ascii table and assign corresponding priorities to the chars
    //first loop starts from small a and goes until z and the second loop starts with the capital A to Z
    int prio_abc = 1, prio_ABC = 27;
    for (int i = 97; i < 123; i++) {
        ascii.insert(std::make_pair(i, prio_abc));
        prio_abc++;
    }
    for (int i = 65; i < 91; i++) {
        ascii.insert(std::make_pair(i, prio_ABC));
        prio_ABC++;
    }

    //reads until EOF
    while (!feof(file)) {
        fscanf(file, "%s\n", &chunk);
        //Get half of line len
        int len = strlen(chunk);
        memcpy(split_chunk[group_idx - 1], chunk, len + 1);
        split_chunk[group_idx - 1][len] = '\0';
        //printf("chunk[%d] = %s\n", group_idx, split_chunk[group_idx - 1]);
        if (group_idx == 3) {
            count_prios += compare(&ascii, split_chunk);
            //printf("curr_prio = %d\n", count_prios);
            group_idx = 0;
        }

        group_idx++;
    }

    printf("answer: %d", count_prios);

    fclose(file);

    return 0;
}