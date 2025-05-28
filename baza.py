import ctypes
import os

# Załaduj bibliotekę dynamiczną
_lib_name = "libbaza.so"  # Jeśli Windows: "baza.dll"
_lib_path = os.path.join(os.path.dirname(__file__), _lib_name)
baza = ctypes.CDLL(_lib_path)

# Definicja typów funkcji
baza.biblioteka_set_cpu_usage.argtypes = [ctypes.c_int]
baza.biblioteka_set_cpu_usage.restype = None

baza.biblioteka_init_data.argtypes = [ctypes.c_int, ctypes.c_int]
baza.biblioteka_init_data.restype = None

baza.biblioteka_compute.argtypes = []
baza.biblioteka_compute.restype = None

baza.biblioteka_get_last_duration.argtypes = []
baza.biblioteka_get_last_duration.restype = ctypes.c_double

baza.biblioteka_get_max_sum_result.argtypes = []
baza.biblioteka_get_max_sum_result.restype = ctypes.c_int

baza.biblioteka_get_num_threads.argtypes = []
baza.biblioteka_get_num_threads.restype = ctypes.c_int

# Przykładowy interfejs Python
def ustaw_cpu(percent):
    baza.biblioteka_set_cpu_usage(percent)

def inicjalizuj_dane(n, seed):
    baza.biblioteka_init_data(n, seed)

def oblicz():
    baza.biblioteka_compute()

def czas_obliczen():
    return baza.biblioteka_get_last_duration()

def max_suma():
    return baza.biblioteka_get_max_sum_result()

def liczba_watkow():
    return baza.biblioteka_get_num_threads()