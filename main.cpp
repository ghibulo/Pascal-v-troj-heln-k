#include <iostream>
//uloha na trenink s pointerama a C++

using namespace std;

//po kolika se bude zvetsovat zasobnik pro cisla v radku
#define BUFADD  5
/*
 vypocte dalsi radku s predchazejici, pripadne navysi bufer
 vstup1: predchozi - pole cisel predchozi radky
 vstup2: pocet_buf - dva int, obsahujici pocet cisel a velikost prostoru pro ukladani
 vystup: ukazatel na bufer s novou radkou
*/
int * dalsiRadka (int *predchozi, int *pocet_buf) {
    int *nova = predchozi;
    if (pocet_buf[0] == pocet_buf[1]) {
        pocet_buf[1]+=BUFADD;
        nova = new int[pocet_buf[1]];
    }

    int c1=predchozi[0]; //nevim esli pisu do noveho a tak si uchovavam
    int c2=1;            //pro dalsi vypocet v cyklu puvodni hodnoty
    for (int i=1 ;i< (pocet_buf[0]);i++) {
        c2 = predchozi[i];
        nova[i]=c1 + predchozi[i];
        c1=c2;
    }
    nova[0]=nova[pocet_buf[0]]=1;
    (pocet_buf[0])++;
    if (nova!=predchozi) delete[] predchozi; //pokud byl vytvoren novy bufer
    return nova;

}

void tiskniRadku(int * jakou, int pocet) {
    cout << "Pocet: "<< pocet << endl;
    for (int i=0;i<pocet;i++)
        cout << jakou[i] << " ";
    cout << endl;
}

int main()
{
    int r;
    cout << "Zadej cislo radku:" << endl;
    cin >> r;
    int *cisla = new int[2];
    cisla[0]=1;
    int pocetBuf[2] = {1,2}; //jedno cislo v dvouint buferu
    int * v = dalsiRadka(cisla,pocetBuf);
    for (int i=1;i<r;i++)  v = dalsiRadka(v,pocetBuf);
    cout << "buf: " << pocetBuf[1]<< endl;
    tiskniRadku(v,pocetBuf[0]);
    delete[] v;

    return 0;
}
