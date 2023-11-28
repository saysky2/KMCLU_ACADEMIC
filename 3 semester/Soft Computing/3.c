#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INPUT_SIZE 4
#define NUM_PATTERNS 3
#define THRESHOLD 0.1
#define MAX_EPOCHS 10000
float patterns[NUM_PATTERNS][INPUT_SIZE] = {
 {-1, 1, -1, 1},
 {1, 1, 1, -1},
 {-1, -1, -1, 1}
};
float testPatterns[3][INPUT_SIZE] = {
 {-1, 1, -1, 1}, // Ax
 {1, 1, 1, 1}, // Ay
 {-1, -1, -1, -1} // Az
};
// Function to calculate the dot product of two arrays
float dot_product(float *inputs, float *weights, int input_size) {
 float result = 0.0;
 for (int i = 0; i < input_size; i++) {
 result += inputs[i] * weights[i];
 }
 return result;
}
// Function to train the autocorrelator network
void train_autocorrelator(float inputs[][INPUT_SIZE], float *weights, int input_size, int
num_patterns) {
 int epoch, patternIdx;
 bool weightChanged;
 float error, totalError;
 for (epoch = 0; epoch < MAX_EPOCHS; epoch++) {
 weightChanged = false;
 totalError = 0.0;
 for (patternIdx = 0; patternIdx < num_patterns; patternIdx++) {
 float *currentPattern = inputs[patternIdx];
 float prediction = dot_product(currentPattern, weights, input_size);
 error = prediction - currentPattern[0]; // Autocorrelation learning rule
 for (int j = 0; j < input_size; j++) {
 weights[j] -= THRESHOLD * error * currentPattern[j];
 }
 totalError += error * error;
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
// Function to test the autocorrelator network
void test_autocorrelator(float testInputs[][INPUT_SIZE], float *weights, int input_size, int
num_tests) {
 for (int i = 0; i < num_tests; i++) {
 float prediction = dot_product(testInputs[i], weights, input_size);
 printf("Test Pattern %d: Prediction = %f\n", i+1, prediction);
 }
}
int main() {
 float weights[INPUT_SIZE] = {0}; // Initialize weights to zero
 printf("Training the autocorrelator...\n");
 train_autocorrelator(patterns, weights, INPUT_SIZE, NUM_PATTERNS);
 printf("\nTesting the autocorrelator with test patterns...\n");
 test_autocorrelator(testPatterns, weights, INPUT_SIZE, 3);
 return 0;
}