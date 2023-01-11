#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
using namespace std;

int zostatok;
char zoznam_uctov;


int napis()

{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,6);
    cout  << "              I                                                             I   " << endl;
    cout  << "            aaaaa       aaaaaa    aaaaaa   a     a  a   a   aaaaaa        aaaaa " << endl;
    cout  << "           a  I  a      a     a  a      a  aa    a  a  a   a      a      a  I  a" << endl;
    cout  << "           a  I         a     a  a      a  a a   a  a a    a      a      a  I   " << endl;
    cout  << "            aaaaa       aaaaaa   aaaaaaaa  a  a  a  aa     aaaaaaaa       aaaaa " << endl;
    cout  << "              I  a      a     a  a      a  a   a a  a a    a      a         I  a" << endl;
    cout  << "           a  I  a      a     a  a      a  a    aa  a  a   a      a      a  I  a" << endl;
    cout  << "            aaaaa       aaaaaa   a      a  a     a  a   a  a      a       aaaaa " << endl;
    cout  << "              I                                                             I   " << endl;
    cout << endl;
    cout << endl;
    return 0;
}

int main()
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
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 7);
            cout << "                        " << main_menu[i] << endl;

        }
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 7);

        cout <<"                        " << "Vyber si moznost: "<< endl;
        cout << "                        ";
        cin >> volba_zaciatok;

        if (volba_zaciatok == 1)
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 7);
            system("CLS");
            napis();
            int volba_c1;



            ofstream ZoznamUctov("ZoznamUctov.txt", ios_base::app);
            srand(time(NULL));
            int id[8] = {};
            string meno;


            int pin;

            
            SetConsoleTextAttribute(h, 7);

            cout << "                        " << "Zadaj svoje meno(Spolu a bez medzier): ";
            cin >> meno;
            cout << "                        " << "Zadaj svoj PIN(4-ciferne cislo nezacinajuce sa nulou): ";
            cin >> pin;
            if (pin < 1000) {
                
                SetConsoleTextAttribute(h, 7);
                cout << "                        " << "Zadaj prosim PIN nezacinajuci sa nulou. Dakujem :)" << endl;
                cout << "                        ";
                cin >> pin;
                
            }
            else if (pin > 9999) {
                
                SetConsoleTextAttribute(h, 7);
                cout << "                        " << "Zadaj prosim stvorciferny PIN. Dakujem :)";
                cin >> pin;
            }
            cout << "                        " << "Zadaj svoj pociatocny zostatok: ";
            cin >> zostatok;
            if (zostatok <= 0) {
                
                SetConsoleTextAttribute(h, 7);
                cout << "                        " << "Nemozes zalozit ucet bez zakladneho vkladu a nemozes vlozit zapornu sumu penazi, zadaj realnu sumu.";
                cin >> zostatok;
            }
            cout << endl;
            ofstream MojaFile(meno + ".txt");
            for (int i = 0; i < 8; i++)
                id[i] = 1 + (rand() % 8) + 1;
            for (int j = 0; j < 8; j++) {
                SetConsoleTextAttribute(h, 7);
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
                SetConsoleTextAttribute(h, 7);
                for (int i = 0; i < 3; i++)
                {
                    SetConsoleTextAttribute(h, 7);
                    cout << "                        " << menu_c2[i] << endl;

                }

                cout << "                        " << "Vyber si moznost: " << endl;
                cout << "                        ";
                cin >> volba_c1;

                if (volba_c1 == 1)
                {
                    system("CLS");
                    napis();
                    int zadaj;
                    SetConsoleTextAttribute(h, 7);
                    cout << "                        " << "Zadaj kolko chces vlozit: " << endl;
                    cout << "                        ";
                    cin >> zadaj;
                    cout << endl;
                    zostatok = zostatok + zadaj;
                    MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl;
                    cout <<"                        " << zostatok << endl;
                    cout << endl;
                    

                }

                if (volba_c1 == 2)
                {

                    system("CLS");
                    napis();
                    int zadaj;
                    SetConsoleTextAttribute(h, 7);
                    cout << "                        " << "Zadaj kolko chces vybrat: "<<endl;
                    cout << "                        ";
                    cin >> zadaj;

                    if (zostatok < zadaj)
                    {
                        SetConsoleTextAttribute(h, 7);
                        cout << endl;
                        cout << "                        " << "Na svojom ucte nemas dostatok penazi" << endl;
                        cout << endl;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, 7);
                        zostatok = zostatok - zadaj;
                        MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl << endl;
                        cout << endl;
                        cout << "                        " << zostatok << endl ;
                        cout << endl;


                    }


                }

                if (volba_c1 == 3)
                {
                    SetConsoleTextAttribute(h, 7);
                    system("CLS");
                    ZoznamUctov.open("ZoznamUctov.txt", ios::app);
                    ZoznamUctov << meno << "                    " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << "                      " << pin << "                      " << zostatok << endl;
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
            SetConsoleTextAttribute(h, 7);
            cout << "                        " << "Zadaj adminske heslo: " << endl;
            cout << "                        ";
            cin >> admin_kontrola;
            cout << endl;

            if (admin_kontrola == admin)
            {
                
                system("CLS");
                napis();

                ifstream ZoznamUctov1("ZoznamUctov.txt");

                string myText;

                   



                int zasa_volba;
                string choice[1] = { "Pre navrat do menu zmackni 1: ", };
                SetConsoleTextAttribute(h, 10);
                cout << "                        " << "heslo je spravne" << endl << endl;
                while (getline(ZoznamUctov1, myText)) {
                    SetConsoleTextAttribute(h, 7);

                    cout << myText << endl;

                }

                for (int i = 0; i < 1; i++)
                {
                    SetConsoleTextAttribute(h, 7);
                    cout << endl;
                    cout << "                        " << choice[i];


                }

                cin >> zasa_volba;


                if (zasa_volba = 1)
                {
                    SetConsoleTextAttribute(h, 7);
                    system("CLS");
                    napis();
                    system("CLS");
                    continue;
                    

                }

        

                else
                {
                    SetConsoleTextAttribute(h, 7);
                    cout << "                        " << "zadal si neplatnu moznost" << endl;
                    break;


                }


                cout << endl;
                




            }
            else
            {
                system("CLS");
                SetConsoleTextAttribute(h, 4);
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                        " << "Smola heslo je nespravne" << endl;
                cout << endl;
                break;

            }


        }
        else if (volba_zaciatok == 3)
        {
        
            system("CLS");
            napis();
            SetConsoleTextAttribute(h, 3);
            cout << "                        " << "Vytvorili: Matus Budos, Timotej Dolnik a Stanislav Chabrecek";
            cout << endl;
            SetConsoleTextAttribute(h, 7);
            break;

   
        }


    }

}

