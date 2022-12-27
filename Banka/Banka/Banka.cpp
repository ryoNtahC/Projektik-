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

        cout << "Vyber si moznos: " << endl;
        cin >> volba_zaciatok;

        if (volba_zaciatok == 1)
        {
            system("CLS");
            
            cout << "Zadaj svoje meno: ";
            cin >> meno;
            cout << endl;
            




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
            cout << "Zadaj adminské heslo: ";
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
            cout << "Vytvorili: Matš Budos, Timotej Dolnik a Stanislav Chabrecek";
            cout << endl;
            break;

        }
    }
    
}

