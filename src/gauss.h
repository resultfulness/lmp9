#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - zamiana zakończona sukcesem
 * Zwraca 1 - zamieniane indeksy poza rozmiarem macierzy
 * Zwraca 2 - macierze o nieprawidłowych rozmiarach
 */
int switch_rows(Matrix* mat, Matrix* b, int row_a, int row_b);
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 * Zwraca 2 - macierze o nieprawidłowych rozmiarach
 */
int eliminate(Matrix* mat, Matrix* b);

#endif
