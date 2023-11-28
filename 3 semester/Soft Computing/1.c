#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEARNING_RATE 0.1
#define THRESHOLD 0.2
#define MAX_EPOCHS 10000
// Function to calculate the dot product of two arrays
float dot_product(float *inputs, float *weights, int input_size) {
float result = 0.0;
for (int i = 0; i < input_size; i++) {
result += inputs[i] * weights[i];
}
return result;
}
// Function to train the perceptron
void train_perceptron (float inputs[][2], float *outputs, float *weights, int input_size, int
num_samples) {
int epoch;
bool weightChanged;
float error, totalError;
for (epoch = 0; epoch < MAX_EPOCHS; epoch++) {
weightChanged = false;
totalError = 0.0;
for (int i = 0; i < num_samples; i++) {
float prediction = dot_product(inputs[i], weights, input_size);
error = outputs[i] - prediction;
 if (error != 0.0) {
for (int j = 0; j < input_size; j++) {
weights[j] += LEARNING_RATE * error * inputs[i][j];
}
 weightChanged = true;
 }
 totalError += error * error;
 }
 if (!weightChanged) {
 printf("Training complete. Converged at epoch: %d\n", epoch + 1);
 break;
 }
 if (totalError < THRESHOLD) {
 printf("Training complete. Error is less than threshold at epoch: %d\n", epoch + 1);
 break;
 }
 }
 printf("Final weights: ");
 for (int i = 0; i < input_size; i++) {
 printf("%f ", weights[i]);
 }
 printf("\n");
}
int main() {
float inputs [4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
 float outputs[4] = {0, 0, 0, 1}; // OR gate outputs
 int num_samples = 4;
int input_size = 2;
 float weights[input_size];
 for (int i = 0; i < input_size; i++) {
 weights[i] = ((float)rand() / RAND_MAX) - 0.5; // Random initialization of weights
 }
 printf("Initial weights: ");
 for (int i = 0; i < input_size; i++) {
 printf("%f ", weights[i]);
 }
 printf("\n");
 train_perceptron(inputs, outputs, weights, input_size, num_samples);
 return 0;
}