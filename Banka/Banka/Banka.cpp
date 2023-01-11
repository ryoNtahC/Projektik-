#include <iostream>    //Importovanie kniznic
#include <string>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
using namespace std;   //Zadefinovanie priestoru std

int zostatok;       //Definovanie globálnych premennych
char zoznam_uctov;


int napis()  //Funkcia na vypis loga banky

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

int main()  //Hlavna funkcia
{
 
    string main_menu[3] = { "1.Vytvorit ucet", "2.Ukazat vsetky ucty","3.Quit" };  //Pole s main menu
    int volba_zaciatok;  //Premenne
    string meno;
    string admin = "Jozko";
    string admin_kontrola;

    while (true) //Nekonecny while cyklus pre moznost opakovanej volby v menu
    {
        napis();  //Zavolanie funkcie napis
        for (int i = 0; i < 3; i++) //For cyklus pre vypis main menu
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

        if (volba_zaciatok == 1)  //Cast kodu, ktora sa vykona ak si uzivatel vyberie moznost 1
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 7);
            system("CLS"); //Vymzanie okna
            napis();
            int volba_c1;



            ofstream ZoznamUctov("ZoznamUctov.txt", ios_base::app); //Zapis do zoznamu uctov
            srand(time(NULL));
            int id[8] = {};
            string meno;


            int pin;

            
            SetConsoleTextAttribute(h, 7);

            cout << "                        " << "Zadaj svoje meno(Spolu a bez medzier): ";  //Zadavanie mena a PINu
            cin >> meno;
            cout << "                        " << "Zadaj svoj PIN(4-ciferne cislo nezacinajuce sa nulou): "; //Overenie zadaneho PINu
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
            cout << "                        " << "Zadaj svoj pociatocny zostatok: "; //Zadavanie pociatocneho zostatku
            cin >> zostatok;
            if (zostatok <= 0) {
                
                SetConsoleTextAttribute(h, 7);
                cout << "                        " << "Nemozes zalozit ucet bez zakladneho vkladu a nemozes vlozit zapornu sumu penazi, zadaj realnu sumu."; //Kontrola pociatocneho zostatku
                cin >> zostatok;
            }
            cout << endl;
            ofstream MojaFile(meno + ".txt"); //Vytvorenie suboru daneho uctu a zapisovanie udajov don
            for (int i = 0; i < 8; i++)
                id[i] = 1 + (rand() % 8) + 1; //Generovanie ID 
            for (int j = 0; j < 8; j++) {
                SetConsoleTextAttribute(h, 7);
                cout << id[j];
            }
            ZoznamUctov.open("ZoznamUctov.txt"); //Zapisovanie do zoznamu vsetkych uctov
            ZoznamUctov << meno << "                      " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << "                      " << pin << "                      " << zostatok << endl;
            ZoznamUctov.close();
            cout << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "PIN:" << pin;
            MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl << endl;

            string menu_c2[3] = { "1.Vlozit peniaze", "2.Vybrat peniaze", "3.Back" }; //Menu po vytvoreni uctu, s moznostou vkladu, ci vyberu hotovosti
            cout << endl;
            system("CLS");
            napis();

            while (true) // Nekonecny while cyklus pre menu po vytvoreni uctu
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

                if (volba_c1 == 1)  //Cast kodu, ktora sa vykona,ak si uzivatel zvoli moznost cislo 1
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

                if (volba_c1 == 2) //Cast kodu, ktora sa vykona, ak si uzivatel zvoli moznost cislo 2
                {

                    system("CLS");
                    napis();
                    int zadaj;
                    SetConsoleTextAttribute(h, 7);
                    cout << "                        " << "Zadaj kolko chces vybrat: "<<endl;
                    cout << "                        ";
                    cin >> zadaj;

                    if (zostatok < zadaj) //Kontrola, ci ma uzivatel na ucte dost penazi
                    {
                        SetConsoleTextAttribute(h, 7);
                        cout << endl;
                        cout << "                        " << "Na svojom ucte nemas dostatok penazi" << endl;
                        cout << endl;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, 7);
                        zostatok = zostatok - zadaj; //Prepis aktualneho zostatku po odcitani vyberu
                        MojaFile << "Meno: " << meno << endl << "Id: " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << endl << "Zostatok: " << zostatok << "€" << endl << "PIN: " << pin << endl << endl;
                        cout << endl;
                        cout << "                        " << zostatok << endl ;
                        cout << endl;


                    }


                }

                if (volba_c1 == 3) //Navrat do main menu, po zvoleni moznosti cislo 3
                {
                    SetConsoleTextAttribute(h, 7);
                    system("CLS");
                    ZoznamUctov.open("ZoznamUctov.txt", ios::app); //Otvorenie suboru ZoznamUctov.txt a zadefinovanie aby sa subor neprepisoval ale aby sa don dopisovalo
                    ZoznamUctov << meno << "                    " << id[0] << id[1] << id[2] << id[3] << id[4] << id[5] << id[6] << id[7] << "                      " << pin << "                      " << zostatok << endl;
                    ZoznamUctov.close();
                    break;
                    system("CLS");

                }

         

            }

        }

        else if (volba_zaciatok == 2) //Moznost, urcena pre adminov banky, po ktorej sa vypise zoznam vsetkych uctov
        {
           
            system("CLS");
            napis();
            SetConsoleTextAttribute(h, 7);
            cout << "                        " << "Zadaj adminske heslo: " << endl;
            cout << "                        ";
            cin >> admin_kontrola;
            cout << endl;

            if (admin_kontrola == admin) //Kontrola, ci sa zadane heslo rovna nastavenemu heslu
            {
                
                system("CLS");
                napis();

                ifstream ZoznamUctov1("ZoznamUctov.txt");

                string myText;
                   



                int zasa_volba;
                string choice[1] = { "Pre navrat do menu zmackni 1: ", };  //Moznost vratenia sa do main menu
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
                    SetConsoleTextAttribute(h, 7); //Else v pripade, ze by uzivatel zadal moznost, ktora neexistuje
                    cout << "                        " << "zadal si neplatnu moznost" << endl;
                    break;


                }


                cout << endl;
                




            }
            else //Else pre pripad, ze si uzivatel zvoli moznost 2, avsak zada nespravne heslo
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
        else if (volba_zaciatok == 3) //Ak si utivatel zvoli v main menu moznost 3, program vypise mena tvorcov a ukonci sa
        {
        
            system("CLS");
            napis();
            SetConsoleTextAttribute(h, 3);
            cout << "                        " << "Vytvorili: Matus Budos, Timotej Dolnik a Stanislav Chabrecek"; //Vypis mien tvorcov tohto programu
            cout << endl;
            SetConsoleTextAttribute(h, 7);
            break;

   
        }


    }

}

