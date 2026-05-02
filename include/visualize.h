#ifndef VISUALIZE_H
#define VISUALIZE_H

#define VISUALIZE(arr,size, intervalInSeconds) \
    do { \
            write(STDOUT_FILENO, "\033[H", 3); /* Move cursor to the top-left corner */ \
            visualizeArray(arr, size); \
            printf("\n"); \
            usleep(intervalInSeconds * 1000000); \
    } while(0)

int findMax(int *array, int size);
void visualizeArray(int *array, int size);

#endif // VISUALIZE_H