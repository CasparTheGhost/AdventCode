#include <iostream>
#include <unordered_map>
#include <utility>
#include <string.h>


int compare(std::unordered_map<int, int> *ascii, char arr[2][30], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len + 1; j++) {
            if (arr[0][i] == arr[1][j]) {
                auto it = ascii->find((int)arr[0][i]);
                return it->second;
            }
        }      
    }
}

int main() {

    FILE* file;
    char chunk[60];
    char split_chunk[2][30];
    std::unordered_map<int, int> ascii;
    int count_prios = 0;

    file = fopen("day3_input_test.txt", "r");
    if (!file) {
        perror("Error opening file!");
        return 0;
    }

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
        int len = strlen(chunk) / 2;
        memcpy(split_chunk[0], chunk, len);
        split_chunk[0][len] = '\0';
        memcpy(split_chunk[1], chunk + len, len + 1);
        split_chunk[1][len] = '\0';
        count_prios += compare(&ascii, split_chunk, len);
    }

    printf("answer: %d", count_prios);

    fclose(file);

    return 0;
}