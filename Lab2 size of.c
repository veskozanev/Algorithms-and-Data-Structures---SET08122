#include <stdio.h>

int main() {
    size_t sizechar = sizeof(char);
    size_t sizeint = sizeof(int);
    size_t sizeshort = sizeof(short);
    size_t sizelong = sizeof(long);
    size_t sizearray = sizeof(int[2]);
    printf("Size of int %zu bytes. \n"
           "Size of char %zu bytes.\n"
           "Size of long %zu bytes.\n"
           "Size of array %zu bytes.\n"
           "Size of short %zu bytes", sizeint, sizechar, sizelong, sizearray, sizeshort);
    return 0;
}
