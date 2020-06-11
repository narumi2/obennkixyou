#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void ave(FILE *FIN, FILE *FOUT) {
    int x, y=0, z=0;
    while(fscanf(FIN, "%d", &x) != EOF) 
    {
        y = x + y;
        z++;
    }
    fprintf(FOUT, "%f", (double)y / z);
}

int main(void) {
    FILE *numbers_from;
    FILE *calculated_avegage_dest;

    if ((numbers_from = fopen("numbers.txt", "r")) == NULL || (calculated_avegage_dest = fopen("average_of_numbers.txt", "w")) == NULL) {
        printf("Error: could't open file.");
        return 1;
    }

    ave(numbers_from, calculated_avegage_dest);

    if (fclose(numbers_from) == EOF || fclose(calculated_avegage_dest) == EOF) {
        printf("Error: could't open file.");
        return 1;
    }

    return 0;
}