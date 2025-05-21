// --------------------------------------------------------
// biblioteka.h - Nagłówek biblioteki z deklaracjami funkcji
// Projekt: Równoległe wyszukiwanie największej sumy podtablicy
// --------------------------------------------------------

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Ustaw procent wykorzystywanych zasobów CPU (np. 50 = połowa dostępnych rdzeni)
void biblioteka_set_cpu_usage(int percent);

// Wygeneruj dane losowe o zadanym rozmiarze (n) i ziarnie (seed)
void biblioteka_init_data(int n, int seed);

// Wykonaj obliczenia równoległe (największa suma podtablicy)
void biblioteka_compute();

// Zwróć czas trwania ostatnich obliczeń (w sekundach)
double biblioteka_get_last_duration();

// Zwróć wynik: największa suma podtablicy
int biblioteka_get_max_sum_result();

// Zwróć liczbę wątków użytych w obliczeniach
int biblioteka_get_num_threads();

#ifdef __cplusplus
}
#endif