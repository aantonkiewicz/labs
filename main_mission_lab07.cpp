#include <iostream>
#include <random>

using namespace std;

void utworz(int*& dane, int rozmiar)
{
    dane = new int[rozmiar];
}

void wypelnij(int* dane, int rozmiar, mt19937& generator)
{
    uniform_int_distribution<int> rozklad(-10, 10);
    for (int i = 0; i < rozmiar; ++i)
    {
        dane[i] = rozklad(generator);
    }
}

int obliczSume(const int* dane, int rozmiar)
{
    int suma = 0;
    for (int i = 0; i < rozmiar; ++i)
    {
        suma += dane[i];
    }
    return suma;
}

int policzUjemne(const int* dane, int rozmiar)
{
    int liczba = 0;
    for (int i = 0; i < rozmiar; ++i)
    {
        if (dane[i] < 0)
        {
            ++liczba;
        }
    }
    return liczba;
}

int pierwszyIndeksZera(const int* dane, int rozmiar)
{
    for (int i = 0; i < rozmiar; ++i)
    {
        if (dane[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

void usun(int*& dane)
{
    delete[] dane;
    dane = nullptr;
}

int main()
{
    int n;
    cout << "Podaj liczbe w przedziale (5-20): ";
    if (!(cin >> n))
    {
        cout << "Nieprawidlowa wartosc!" << endl;
        return 1;
    }

    if (n < 5 || n > 20)
    {
        cout << "Liczba musi byc w przedziale od 5 do 20!" << endl;
        return 1;
    }

    random_device rd;
    mt19937 generator(rd());

    int* dane = nullptr;
    utworz(dane, n);
    wypelnij(dane, n, generator);

    cout << "Pomiary:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "[" << i << "] " << dane[i] << endl;
    }

    cout << "Suma: " << obliczSume(dane, n) << endl;
    cout << "Ujemne pomiary: " << policzUjemne(dane, n) << endl;
    cout << "Pierwszy indeks zera: " << pierwszyIndeksZera(dane, n) << endl;

    usun(dane);
    return 0;
}