#include "ceyhan.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    if (fprintf(stderr, "Ceyhan v%s\n", cey_version()) < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
