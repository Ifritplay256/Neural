#define debug 0

#include <stdio.h>
#include <math.h>

float input[] = {0.2, 0.1, 7.3};
float weights[] = {
    1.0, 1.0, // i1
    1.0, 1.0, // i2
    1.0, 1.0, // i3
    1.0, 1.0  // n1 and n2
};
float biases[] = {0.3, 0.5, 0.2};
float output[] = {0.0};

int layers[] = {2};

int input_count = sizeof(input) / sizeof(input[0]);
int weight_count = sizeof(weights) / sizeof(weights[0]);
int output_count = sizeof(output) / sizeof(output[0]);
int neurons_count = sizeof(biases) / sizeof(biases[0]) - sizeof(output) / sizeof(output[0]);
int layers_count = sizeof(layers) / sizeof(layers[0]);

float neurons_values [2];

float activation(float x){
    if (x < 0){
        return 0;
    }
    else{
        return x;
    }
}

void start_message(){
    printf("Starting program \n");
    printf("Inputs amount - %d         : stored as fp%ld \n", input_count, sizeof(input[0])*8);
    printf("Weights amount - %d        : stored as fp%ld \n", weight_count, sizeof(weights[0])*8);
    printf("Hidden Neurons amount - %d : stored as fp%ld \n", neurons_count, sizeof(biases[0])*8);
    printf("Output amount - %d         : stored as fp%ld \n", output_count, sizeof(output[0])*8);
    printf("\n");
    printf("Hidden layers - %d \n", layers_count);
    printf("Neurons per layer - %f \n", (float)(neurons_count / layers_count));
    printf("\n");
}

void state(char state_message []){
    if (debug){
        printf("%s \n", state_message);

        printf("----------------------\n");

        for (int n = 0; n < neurons_count; n++){
            printf("Neuron %d - %f \n", n, neurons_values[n]);
        }
        
        printf("----------------------\n");

        for (int o = 0; o < output_count; o++){
            printf("Output %d - %f \n", o, output[o]);
        }

        printf("----------------------\n");
    }
}

void run(){
    for (int n = 0; n < output_count; n++){
        output[n] = biases[neurons_count+n];
    }

    for (int n_c = 0; n_c < neurons_count; n_c++){
        neurons_values[n_c] = biases[n_c];
    }

    state("\n*Neurons values cleared:*");

    for (int n = 0; n < layers[0]; n++){
        for (int i = 0; i < input_count; i++){
            float value = input[i] * weights[i*layers[0]+n];
            neurons_values[n] += value;
        }
        neurons_values[n] = activation(neurons_values[n]);
    }

    state("\n*1Layer values calculated:*");

    for (int n = 0; n < output_count; n++){
        for (int i = 0; i < 2; i++){
            float value = neurons_values[i] * weights[i*layers[0]+n];
            output[n] += value;
        }
        output[n] = activation(output[n]);
    }

    state("\n*Output values calculated:*");
}

int main(){
    start_message();
    run();
    return 0;
}
