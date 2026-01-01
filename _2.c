#include <stdio.h>
#include <math.h>

float weights[][][] = {
   {{2.0, 1.0, 1.0},
    {0.7, 1.0, 1.0},
    {1.0, 1.0, 1.0},},
   {{0.5, 1.0},
    {0.5, 1.0},},
   {{0.5},},
};

float weights_values[][][] = {
   {{2.0, 1.0, 1.0},
    {0.7, 1.0, 1.0},
    {1.0, 1.0, 1.0},},
   {{0.5, 1.0},
    {0.5, 1.0},},
   {{0.5},},
};

void run(){
    weights_values[][][] = {
    {{2.0, 1.0, 1.0},
        {0.7, 1.0, 1.0},
        {1.0, 1.0, 1.0},},
    {{0.5, 1.0},
        {0.5, 1.0},},
    {{0.5},},
    };
    /*
    for (int i = 0; i < sizeof(weights[0])/sizeof(weights[0][0]); i++){
        weights[0][i]
    };
*/    
}

int main(){
    printf("Program started");
    run();
    return 0;
}