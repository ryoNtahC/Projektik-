#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

int zostatok;
char zoznam_uctov;

int napis()

{
    cout << "    I                                                             I             " << endl;
    cout << "  aaaaa       aaaaaa    aaaaaa   a     a  a   a   aaaaaa        aaaaa           " << endl;
    cout << " a  I  a      a     a  a      a  aa    a  a  a   a      a      a  I  a          " << endl;
    cout << " a  I         a     a  a      a  a a   a  a a    a      a      a  I             " << endl;
    cout << "  aaaaa       aaaaaa   aaaaaaaa  a  a  a  aa     aaaaaaaa       aaaaa           " << endl;
    cout << "    I  a      a     a  a      a  a   a a  a a    a      a         I  a          " << endl;
    cout << " a  I  a      a     a  a      a  a    aa  a  a   a      a      a  I  a          " << endl;
    cout << "  aaaaa       aaaaaa   a      a  a     a  a   a  a      a       aaaaa           " << endl;
    cout << "    I                                                             I             " << endl;
    cout << endl;
    cout << endl;
    return 0;
}

void main()
{
    string main_menu[3] = { "1.Vytvorit ucet", "2.Ukazat vsetky ucty","3.Quit" };
    int volba_zaciatok;
    string meno;
    string admin = "Jozko";
    string admin_kontrola;

    while (true)
    {
        napis();
        for (int i = 0; i < 3; i++)
        {
            cout << main_menu[i] << endl;

        }

        cout << "Vyber si moznost: " << endl;
        cin >> volba_zaciatok;

        if (volba_zaciatok == 1)
        {
            system("CLS");
            napis();
            int volba_c1;



            ofstream ZoznamUctov("ZoznamUctov.txt", ios_base::app);
            ZoznamUctov << "Meno                      " << "Id                      " << "Pin                      " << "Zostatok" << endl;
            srand(time(NULL));
            int id[8] = {};
            string meno;


            int pin;


            cout << "Zadaj svoje meno(Spolu a bez medzier): ";
            cin >> meno;
            cout << "Zadaj svoj PIN(4-ciferne cislo nezacinajuce sa nulou): ";
            cin >> pin;
            if (pin < 1000) {
                cout << "Zadaj prosim PIN nezacinajuci sa nulou. Dakujem :)";
                cin >> pin;
            }
            else if (pin > 9999) {
                cout << "Zadaj prosim stvorciferny PIN. Dakujem :)";
                cin >> pin;
            }
            cout << "Zadaj svoj pociatocny zostatok: ";
            cin >> zostatok;
            if (zostatok <= 0) {
                cout << "Nemozes zalozit ucet bez zakladneho vkladu a nemozes vlozit zapornu sumu penazi, zadaj realnu sumu.";
                cin >> zostatok;
            }
            cout << endl;
            ofstream MojaFile(meno + ".txt");
            for (int i = 0; i < 8; i++)
                id[i] = 1 + (rand() % 8) + 1;
            for (int j = 0; j < 8; j++) {
                cout << id[j];
            }
            ZoznamUctov.open("ZoznamUctov.txt");
            ZoznamUctov << meno << "                      " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << "                      " << pin << "                      " << zostatok << endl;
            ZoznamUctov.close();
            cout << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "PIN:" << pin;
            MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl << endl;

            string menu_c2[3] = { "1.Vlozit peniaze", "2.Vybrat peniaze", "3.Back" };
            cout << endl;
            system("CLS");
            napis();

            while (true)
            {
                for (int i = 0; i < 3; i++)
                {
                    cout << menu_c2[i] << endl;

                }

                cout << "Vyber si moznost: " << endl;
                cin >> volba_c1;

                if (volba_c1 == 1)
                {
                    system("CLS");
                    napis();
                    int zadaj;
                    cout << "Zadaj kolko chces vlozit: ";
                    cin >> zadaj;
                    zostatok = zostatok + zadaj;
                    MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl;
                    cout << zostatok;
                    cout << endl;

                }

                if (volba_c1 == 2)
                {
                    system("CLS");
                    napis();
                    int zadaj;
                    cout << "Zadaj kolko chces vybrat: ";
                    cin >> zadaj;

                    if (zostatok < zadaj)
                    {
                        cout << "Na svojom ucte nemas dostatok penazi" << endl;
                    }
                    else
                    {
                        zostatok = zostatok - zadaj;
                        MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl << endl;
                        cout << zostatok;
                        cout << endl;


                    }


                }

                if (volba_c1 == 3)
                {
                    system("CLS");
                    ZoznamUctov.open("ZoznamUctov.txt");
                    ZoznamUctov << meno << "                      " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << "                      " << pin << "                      " << zostatok << endl;
                    ZoznamUctov.close();
                    break;
                    system("CLS");

                }
            }




        }

        else if (volba_zaciatok == 2)
        {
            system("CLS");
            napis();
            cout << "Zadaj adminske heslo: ";
            cin >> admin_kontrola;
            cout << endl;

            if (admin_kontrola == admin)
            {
                cout << "heslo je spravne" << endl;
                cout << "prehlad vsetkych uctov" << endl;
                cout << endl;




            }
            else
            {
                cout << "Smola heslo je nespravne" << endl;
                cout << endl;

            }


        }
        else if (volba_zaciatok == 3)
        {
            system("CLS");
            napis();
            cout << "Vytvorili: Matus Budos, Timotej Dolnik a Stanislav Chabrecek";
            cout << endl;
            break;

        }
    }

}

