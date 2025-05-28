// --------------------------------------------------------
// main.cpp - Program główny wykorzystujący bibliotekę
// Projekt: Równoległe wyszukiwanie największej sumy podtablicy
// Autor: Twój Nick/Imię
// --------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include "biblioteka.h" // Dołączenie nagłówka z deklaracjami funkcji biblioteki

int main(int argc, char* argv[]) {
    // Domyślne parametry algorytmu
    int data_size = 100000; // Rozmiar danych wejściowych (liczba elementów)
    int cpu_percent = 50;    // Procent dostępnych zasobów CPU do wykorzystania
    int seed = 42;           // Ziarno generatora liczb losowych

    // Obsługa parametrów z linii komend (opcjonalnie)
    if (argc > 1) data_size = std::atoi(argv[1]);
    if (argc > 2) cpu_percent = std::atoi(argv[2]);
    if (argc > 3) seed = std::atoi(argv[3]);

    // Ustawienie procentu zasobów CPU
    biblioteka_set_cpu_usage(cpu_percent);

    // Inicjalizacja danych losowych (wektor o zadanym rozmiarze)
    biblioteka_init_data(data_size, seed);

    // Wykonanie obliczeń (znalezienie maksymalnej sumy podtablicy)
    biblioteka_compute();

    // Wyświetlenie wyników
    std::cout << "Liczba watkow: " << biblioteka_get_num_threads() << std::endl;
    std::cout << "Maksymalna suma podtablicy: " << biblioteka_get_max_sum_result() << std::endl;
    std::cout << "Czas wykonywania: " << biblioteka_get_last_duration() << " sekundy" << std::endl;

    return 0;
}