#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv) {
    int res;
    Matrix* A = readFromFile(argv[1]);
    Matrix* b = readFromFile(argv[2]);
    Matrix* x;

    if (A == NULL)
        return -1;
    if (b == NULL)
        return -2;
    printToScreen(A);
    printToScreen(b);

    res = eliminate(A,b);
    if (res != 0) {
        if (res == 1)
            fprintf(stderr,
                    "Błąd! Macierz A jest osobliwa, wystąpiło dzielenie "
                    "przez zero\n");
        if (res == 2)
            fprintf(stderr,
                    "Błąd! Podane macierze mają błędne rozmiary\n");

        freeMatrix(A);
        freeMatrix(b);
        return EXIT_FAILURE;
    }

    x = createMatrix(b->r, 1);
    if (x != NULL) {
        res = backsubst(x, A, b);
        if (res != 0) {
            if (res == 1)
                fprintf(stderr,
                        "Błąd! Na diagonali wystąpił element równy zero, "
                        "powodujący dzielenie przez zero\n");
            if (res == 2)
                fprintf(stderr,
                        "Błąd! Podane macierze mają błędne rozmiary\n");

            freeMatrix(A);
            freeMatrix(b);
            freeMatrix(x);
            return EXIT_FAILURE;
        }

        printToScreen(x);
        freeMatrix(x);
    } else {
        fprintf(stderr, "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
    }

    freeMatrix(A);
    freeMatrix(b);

    return 0;
}
