#include <stdio.h>
#include <string.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
char refernceColor[40][40] = {""};
char actualColor[40][40] = {""};

int printColorMap() {

    int i = 0, j = 0, k = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            sprintf(actualColor[k],"%d | %s | %s\n", (i * 5 + j) + 1, majorColor[i], minorColor[j]);
            puts(actualColor[k++]);
        }
    }
    return i * j;
}

int referencePrintColorMap() {
    
    int i = 0, j = 0;
    for(i = 0; i < 25; i++) {
            sprintf(refernceColor[j++],"%d | %s | %s\n", i + 1, majorColor[i/5], minorColor[i%5]);
        }

    return i;
}

int testColorMap() {

    for(int i = 0; i < 25; i++)
    {
        if (strcmp(refernceColor[i], actualColor[i]) == 0)
        {
            continue;
        } else {
            printf("%s is misaligned\n", actualColor[i]);
            return -1;
        }
    }
    return 0;
}

int main() {
    int actualResult = printColorMap();
    int referenceResult = referencePrintColorMap();
    assert(actualResult == 25);
    assert(actualResult == referenceResult);
    assert(testColorMap() == 0);
    printf("All is well (maybe!)\n");
    return 0;
}