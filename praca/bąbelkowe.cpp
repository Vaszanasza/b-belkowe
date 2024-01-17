 #include <iostream>
#include <cstdlib>
 #include <ctime>
using namespace std;

void wypelnijTab(int tablica[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        tablica[i] = rand() % 100;
    }
}

void drukujTab(int tablica[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << tablica[i] << " ";
    }
    cout << endl;
}

void sortowanie_babelkowe(int tablica[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                swap(tablica[j], tablica[j + 1]);
            }
        }
    }
}

void sortowanie_przez_scalanie(int tablica[], int poczatek, int koniec) {
    if (poczatek < koniec) {
        int srodek = poczatek + (koniec - poczatek) / 2;

        sortowanie_przez_scalanie(tablica, poczatek, srodek);
        sortowanie_przez_scalanie(tablica, srodek + 1, koniec);

        int* temp = new int[koniec - poczatek + 1];
        int i = poczatek, j = srodek + 1, k = 0;

        while (i <= srodek && j <= koniec) {
            if (tablica[i] <= tablica[j]) {
                temp[k++] = tablica[i++];
            } else {
                temp[k++] = tablica[j++];
            }
        }

        while (i <= srodek) {
           temp[k++] = tablica[i++];
        }

        while (j <= koniec) {
           temp[k++] = tablica[j++];
        }

        for (i = 0; i < k; ++i) {
            tablica[poczatek + i] = temp[i];
        }

        delete[] temp;
    }
}

int main() {
    const int n = 10;
    int tablica1[n], tablica2[n];

    wypelnijTab(tablica1, n);

    cout << "Tablica przed sortowaniem bąbelkowym:\n";
       drukujTab(tablica1, n);

    sortowanie_babelkowe(tablica1, n);

    cout << "Tablica po sortowaniu bąbelkowym:\n";
       drukujTab(tablica1, n);

    wypelnijTab(tablica2, n);

    cout << "Tablica przed sortowaniem przez scalanie:\n";
       drukujTab(tablica2, n);

    sortowanie_przez_scalanie(tablica2, 0, n - 1);

    cout << "Tablica po sortowaniu przez scalanie:\n";
       drukujTab(tablica2, n);

    return 0;
}