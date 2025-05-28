import baza

baza.ustaw_cpu(50)                    # 50% zasobów CPU
baza.inicjalizuj_dane(1000000, 42)    # 1 mln elementów, seed 42
baza.oblicz()

print("Maksymalna suma podtablicy:", baza.max_suma())
print("Czas obliczeń:", baza.czas_obliczen(), "s")
print("Liczba wątków:", baza.liczba_watkow())