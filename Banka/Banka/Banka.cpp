#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;


void main()
{
    string main_menu[8] = { "1.Vytvorit ucet","2.Pozriet zostatok", "3.Vlozit peniaze ", "4.Vybrat peniaze", "5.Vymazat ucet", "6.Ukazat vsetky ucty","7.Quit" };
    int volba_zaciatok;
    string meno;
    string admin = "Jozko";
    string admin_kontrola;

    while (true)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << main_menu[i] << endl;



        }

        cout << "Vyber si moznos�: " << endl;
        cin >> volba_zaciatok;

        if (volba_zaciatok == 1)
        {
            system("CLS");
            
            ofstream ZoznamUctov("ZoznamUctov.txt");
            ZoznamUctov << "Meno                      " << "Id                      " << "Pin                      " << "Zostatok" << endl;
            srand(time(NULL));
            int id[8] = {};
            string meno;
            int zostatok = 200;
            int pin;


            cout << "Zadaj svoje meno(Spolu a bez medzier): ";
            cin >> meno;
            cout << "Zadaj svoj PIN(4-ciferne cislo nezacinajuce sa nulou): ";
            cin >> pin;
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
            MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "�" << endl << "PIN: " << pin << endl;
            




        }
        else if (volba_zaciatok == 2)
        {
            system("CLS");
            cout << "pozriet zostatok" << endl;
            cout << endl;
            

        }
        else if (volba_zaciatok == 3)
        {
            system("CLS");
            cout << "vlozit peniaze" << endl;
            cout << endl;
            
            

        }
        else if (volba_zaciatok == 4)
        {
            system("CLS");
            cout << "vybrat peniaze" << endl;
            cout << endl;
            
            

        }
        else if (volba_zaciatok == 5)
        {
            system("CLS");
            cout << "vymazat ucet" << endl;
            cout << endl;

            

        }
        else if (volba_zaciatok == 6)
        {
            system("CLS");
            cout << "Zadaj adminsk� heslo: ";
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
        else if (volba_zaciatok == 7)
        {
            system("CLS");
            cout << "Vytvorili: Mat� Budos, Timotej Dolnik a Stanislav Chabrecek";
            cout << endl;
            break;

        }
    }
    
}
