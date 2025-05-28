# baza

## Opis

Projekt **baza** to biblioteka dynamiczna w C++ realizująca równoległe wyszukiwanie największej sumy podtablicy w losowo wygenerowanym wektorze liczb całkowitych. Obliczenia wykonywane są równolegle z wykorzystaniem OpenMP, a biblioteka pozwala sterować procentem wykorzystywanych zasobów CPU.

Biblioteka jest gotowa do użycia zarówno z poziomu programu w C++, jak i z poziomu Pythona (przez prosty wrapper).

---

## Funkcje biblioteki

- Losowe generowanie danych wejściowych (rozmiar i ziarno podaje użytkownik)
- Równoległe obliczenia największej sumy podtablicy (algorytm własny, oparty o Kadane'a)
- Możliwość ustawienia procenta użycia CPU (np. 30% dostępnych rdzeni)
- Pomiar czasu obliczeń
- Wykorzystanie std::vector jako głównej struktury danych
- Interfejs do wywołania funkcji z poziomu Pythona (przez ctypes)

---

## Szybki start

### 1. Kompilacja biblioteki dynamicznej

Linux:
```sh
g++ -fPIC -shared -o libbaza.so biblioteka.cpp -fopenmp
```
Windows:
```sh
g++ -shared -o baza.dll biblioteka.cpp -fopenmp
```

Upewnij się, że plik `libbaza.so` (lub `baza.dll`) znajduje się w tym samym folderze co plik `baza.py`.

---

### 2. Użycie w C++

Plik `main.cpp` prezentuje przykładowe użycie:  
```cpp
#include "biblioteka.h"

int main() {
    biblioteka_set_cpu_usage(50);         // 50% CPU
    biblioteka_init_data(1000000, 42);    // 1 mln danych, seed 42
    biblioteka_compute();

    std::cout << "Wynik: " << biblioteka_get_max_sum_result() << std::endl;
    std::cout << "Czas: " << biblioteka_get_last_duration() << " s\n";
    std::cout << "Wątki: " << biblioteka_get_num_threads() << std::endl;
}
```

---

### 3. Użycie w Pythonie

#### a) Wrapper `baza.py`  
Dodaj plik:
```python
import ctypes
import os

_lib_name = "libbaza.so"  # lub "baza.dll" na Windows
_lib_path = os.path.join(os.path.dirname(__file__), _lib_name)
baza = ctypes.CDLL(_lib_path)

baza.biblioteka_set_cpu_usage.argtypes = [ctypes.c_int]
baza.biblioteka_init_data.argtypes = [ctypes.c_int, ctypes.c_int]
baza.biblioteka_compute.argtypes = []
baza.biblioteka_get_last_duration.restype = ctypes.c_double
baza.biblioteka_get_max_sum_result.restype = ctypes.c_int
baza.biblioteka_get_num_threads.restype = ctypes.c_int

def ustaw_cpu(percent): baza.biblioteka_set_cpu_usage(percent)
def inicjalizuj_dane(n, seed): baza.biblioteka_init_data(n, seed)
def oblicz(): baza.biblioteka_compute()
def czas_obliczen(): return baza.biblioteka_get_last_duration()
def max_suma(): return baza.biblioteka_get_max_sum_result()
def liczba_watkow(): return baza.biblioteka_get_num_threads()
```

#### b) Przykład użycia w Pythonie:
```python
import baza

baza.ustaw_cpu(50)
baza.inicjalizuj_dane(1000000, 42)
baza.oblicz()

print("Maksymalna suma podtablicy:", baza.max_suma())
print("Czas obliczeń:", baza.czas_obliczen())
print("Liczba wątków:", baza.liczba_watkow())
```

---

## Pliki projektu

- `biblioteka.cpp`, `biblioteka.h` – kod biblioteki
- `main.cpp` – przykładowy program główny
- `baza.py` – wrapper do Pythona (dołącz samodzielnie, jeśli nie ma w repozytorium)
- `makefile` – uproszczony plik do kompilacji (opcjonalnie)
- `README.md` – ten plik

---

## Wymagania

- Kompilator C++ z obsługą OpenMP (np. g++, clang++)
- Python 3.x (do użycia wrappera)
- System Linux lub Windows

---

## Autor
Twój Nick/Imię
