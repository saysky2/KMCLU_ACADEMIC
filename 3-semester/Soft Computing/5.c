#include <stdio.h>
#include <stdlib.h>
// Function to perform the Union operation on fuzzy sets
void fuzzy_union(float setA[], float setB[], int size) {
 float result[size];
 printf("Union of A and B: ");
 for (int i = 0; i < size; i++) {
 result[i] = (setA[i] > setB[i]) ? setA[i] : setB[i];
 printf("%.2f ", result[i]);
 }
 printf("\n");
}
// Function to perform the Intersection operation on fuzzy sets
void fuzzy_intersection(float setA[], float setB[], int size) {
 float result[size];
 printf("Intersection of A and B: ");
 for (int i = 0; i < size; i++) {
 result[i] = (setA[i] < setB[i]) ? setA[i] : setB[i];
 printf("%.2f ", result[i]);
 }
 printf("\n");
}
// Function to perform the Complement operation on a fuzzy set
void fuzzy_complement(float set[], int size) {
 float result[size];
 printf("Complement of A: ");
 for (int i = 0; i < size; i++) {
 result[i] = 1.0 - set[i];
 printf("%.2f ", result[i]);
 }
 printf("\n");
}
// Function to perform the Difference operation on fuzzy sets
void fuzzy_difference(float setA[], float setB[], int size) {
 float result[size];
 printf("Difference of A - B: ");
 for (int i = 0; i < size; i++) {
 result[i] = (setA[i] > setB[i]) ? setA[i] - setB[i] : 0.0;
 printf("%.2f ", result[i]);
 }
 printf("\n");
}
// Function to perform Cartesian product of two fuzzy sets to create a fuzzy relation
void fuzzy_cartesian_product(float setA[], float setB[], int sizeA, int sizeB) {
 printf("Fuzzy relation (Cartesian product):\n");
 for (int i = 0; i < sizeA; i++) {
 for (int j = 0; j < sizeB; j++) {
 printf("%.2f ", (setA[i] < setB[j]) ? setA[i] : setB[j]);
 }
 printf("\n");
 }
}
// Function to perform Max-Min composition on two fuzzy relations
void max_min_composition(float relation1[], float relation2[], int size) {
 printf("Max-Min composition (Fuzzy relation composition):\n");
 for (int i = 0; i < size; i++) {
 for (int j = 0; j < size; j++) {
 float max_min = 0;
 for (int k = 0; k < size; k++) {
 float min = (relation1[i * size + k] < relation2[k * size + j]) ? relation1[i * size + k]
: relation2[k * size + j];
 if (min > max_min) {
 max_min = min;
 }
 }
 printf("%.2f ", max_min);
 }
 printf("\n");
 }
}
int main() {
 float setA[] = {0.1, 0.3, 0.5, 0.7, 0.9};
 float setB[] = {0.2, 0.4, 0.6, 0.8, 1.0};
 int size = sizeof(setA) / sizeof(setA[0]);
 printf("Set A: ");
 for (int i = 0; i < size; i++) {
 printf("%.2f ", setA[i]);
 }
 printf("\n");
 printf("Set B: ");
 for (int i = 0; i < size; i++) {
 printf("%.2f ", setB[i]);
 }
 printf("\n\n");
 fuzzy_union(setA, setB, size);
 fuzzy_intersection(setA, setB, size);
 fuzzy_complement(setA, size);
 fuzzy_difference(setA, setB, size);
 printf("\n");
 fuzzy_cartesian_product(setA, setB, size, size);
 printf("\n");
 // Example fuzzy relations for demonstration
 float relation1[] = {0.4, 0.5, 0.3, 0.6, 0.7, 0.2, 0.8, 0.1, 0.9};
 float relation2[] = {0.7, 0.2, 0.8, 0.3, 0.6, 0.1, 0.9, 0.4, 0.5};
 int relation_size = sizeof(relation1) / sizeof(relation1[0]);
 max_min_composition(relation1, relation2, relation_size);
 return 0;
}