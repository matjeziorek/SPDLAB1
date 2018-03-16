#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <new>
using namespace std;

class zadanie
{
public:
    int r;
    int p;
    int q;
    zadanie(int tr,int tp,int tq);
};

zadanie::zadanie(int tr, int tp, int tq)
{
    r = tr;
    p = tp;
    q = tq;
}

class lista_zadan
{
public:
    vector <zadanie> zadania;
    int liczba_zadan;
    //int *permutacje;
    void C_max();
    void posortuj_poR();
    void printRPQ(int size);
    void permute(int k,int size);
    bool wczytaj_zadania();
};

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

bool lista_zadan::wczytaj_zadania()
{
    zadania.clear();
    string nazwa;
    fstream plik;
    int tmp_r, tmp_p, tmp_q;
    int tmp;
    cout << "Podaj nazwe pliku: ";
    cin >> nazwa;
    nazwa+= ".txt";
    cout << nazwa << endl;
    plik.open(nazwa.c_str());
    if(!plik.good())
    {
        cout << "Blad.";
        return false;
    }
    plik >> liczba_zadan;
    plik >> tmp;
    for(int i = 0; i < liczba_zadan; i++)
    {
        plik >> tmp_r >> tmp_p >> tmp_q;
        zadania.push_back(zadanie(tmp_r,tmp_p,tmp_q));
    }
    //permutacje = new int[liczba_zadan];
    /*for(int i = 0; i < liczba_zadan; i++)
    {
        permutacje[i] = i+1;
    }*/
    return true;
}

void lista_zadan::C_max()
{
    int t = 0;
    int c_max = 0;

    for (int i = 0; i < liczba_zadan; i++)
    {
        t = max(zadania[i].r, t) + zadania[i].p;
        c_max = max(c_max,t+zadania[i].q);
    }
    cout << "C_max " << c_max << " t:" << t << endl;
}

void lista_zadan::posortuj_poR()
{
    this->wczytaj_zadania();
    for(int i = 0; i < liczba_zadan - 1; i++)
    {
        for(int j = 0; j < liczba_zadan - 1; j++)
        {
            if(zadania[j].r > zadania[j+1].r)
            {
                swap(zadania[j].r,zadania[j+1].r);
                swap(zadania[j].p,zadania[j+1].p);
                swap(zadania[j].q,zadania[j+1].q);
                swap(permutacje[j],permutacje[j+1]);
            }
        }
    }
    this->C_max();
    string nazwa;
    fstream plik;
    cout << "Podaj nazwe pliku do zapisu permutacji: ";
    cin >> nazwa;
    nazwa+= ".txt";
    cout << nazwa << endl;
    plik.open(nazwa.c_str());
    if(!plik.good())
    {
        cout << "Blad.";
    }
    plik<<liczba_zadan<<" 3"<<endl;
    for(int i = 0; i < liczba_zadan; i++)
    {
        plik << zadania[i].r << " "<< zadania[i].p<< " "<<zadania[i].q<<endl;
    }
    plik.close();


    zadania.clear(); // aby wczytaj kolejny plik
}

void lista_zadan::printRPQ(int size)
{
    int i;
    //cout<<"Permutacja nr: "<<iloscPermutacji+1<<endl;
    for (i=0; i<size; i++)
    {
        cout << zadania[i].r << ":"<< zadania[i].p<< ":"<<zadania[i].q<<endl;

    }
    //iloscPermutacji++;
    cout << endl;

    return;
}

void lista_zadan::permute(int k,int size)
{
    int i;

    if (k==0)
    {
        this->printRPQ(size);
        this->C_max();
    }

    else
    {
        for (i=k-1; i>=0; i--)
        {

            swap(zadania[i].r,zadania[k-1].r);
            swap(zadania[i].p,zadania[k-1].p);
            swap(zadania[i].q,zadania[k-1].q);
            permute(k-1,size);
            swap(zadania[i].r,zadania[k-1].r);
            swap(zadania[i].p,zadania[k-1].p);
            swap(zadania[i].q,zadania[k-1].q);
        }
    }
    return;
}


int main()
{
    lista_zadan lista;
    for(int i = 0; i < 3; i++)
    {
        cout << "Po posorotwaniu po R: " << endl;
        lista.posortuj_poR();
        lista.permute(lista.liczba_zadan,lista.liczba_zadan);

    }



    return 0;
}
