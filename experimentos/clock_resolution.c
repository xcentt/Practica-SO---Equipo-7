#include <stdio.h>
#include <time.h>

int main() {
    struct timespec res;

    // Medir resolución del reloj de tiempo real
    clock_getres(CLOCK_REALTIME, &res);
    printf("Resolución de CLOCK_REALTIME: %ld nanosegundos\n", res.tv_nsec);

    // Medir resolución del reloj monotónico
    clock_getres(CLOCK_MONOTONIC, &res);
    printf("Resolución de CLOCK_MONOTONIC: %ld nanosegundos\n", res.tv_nsec);

    return 0;
}
