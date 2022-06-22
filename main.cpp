#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <algorithm>
#include <ctime>

using namespace std;

string To_string(int x);
string removeSpaces(string &str);
void input();
void cauta();
void edit();
void afisareTOT();
void operatii();

struct aliment
{
    int IDalim;
    string nume,anveg,categ;
    float nec,pprot,plip,pglu,pcal;
};

struct totalim
{
    float tprot=0,tlip=0,tglu=0,tcal=0;
};

struct grupatot
{
    string categ;
    float lapte=0,carne=0,oua=0,grasimiA=0, grasimiV=0, cerealifere=0, cartofi=0, legume=0, fructe=0, zahar=0;
};

int main()
{
    system ("COLOR FC");
    system("cls");
    system("title ItalyHorse45 Baza de date aliment");
    //system("colr 0f");
    cout<<"Alegeti optiunea dorita"<<endl;
    cout<<"1. Introduceti un nou aliment in baza de date."<<endl;
    cout<<"2. Cautati un aliment dupa ID."<<endl;
    cout<<"3. Editati un aliment deja existent."<<endl;
    cout<<"4. Afisati toate alimentele."<<endl;
    cout<<"5. Incepeti "<<endl;
    cout<<"6. Iesire program."<<endl;

    int alg;
    cin>>alg;
    switch (alg)
    {
    case 1:
        input();
        break;
    case 2:
        cauta();
        break;
    case 3:
        edit();
        break;
    case 4:
        afisareTOT();
        break;
    case 5:
        operatii();
    }

    return 0;
}

string To_string(int x)
{
    string r;
    int v[16],n=0,i=1,j;
    while(x)
    {
        v[++n]=x%10;
        x/=10;
    }
    j=n;
    while(i<j)
    {
        swap(v[i],v[j]);
        i++;
        j--;
    }
    for(i=1; i<=n; i++)
        r=r+char(v[i]+'0');
    return r;
}

string removeSpaces(string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void input()
{
    system("cls");
    aliment a;

    cout<<"Introduceti numele alimentului:"<<'\n';
    cin.ignore();
    getline(cin,a.nume);
    cout<<endl;

    cout<<"Introduceti un ID pentru aliment:";
    cin>>a.IDalim;
    cout<<endl;


    cout<<"Introduceti procentul partii necomestibile:";
    cin>>a.nec;
    cout<<endl;

    cout<<"Introduceti procentul proteinelor:";
    cin>>a.pprot;
    cout<<endl;

    cout<<"Introduceti procentul lipidelor:";
    cin>>a.plip;
    cout<<endl;

    cout<<"Introduceti procentul glucidelor:";
    cin>>a.pglu;
    cout<<endl;

    cout<<"Introduceti procentul caloriilor:";
    cin>>a.pcal;
    cout<<endl;

    cout<<"Introduceti 1 daca este un aliment de origine animala sau 0 daca este de origine vegetala:";
    cin>>a.anveg;
    cout<<endl;

    cout<<"Incadrati alimentul intr-o grupa alimentara introducand litere dupa cum urmeaza:"<<endl;
    cout<<"Tastati LA daca alimentul face parte din Lapte/Branzeturi"<<endl;
    cout<<"Tastati PC daca alimentul face parte din Carne/Preparate"<<endl;
    cout<<"Tastati OU daca alimentul face parte din OUA"<<endl;
    cout<<"Tastati GA daca alimentul face parte din Grasimi Animale"<<endl;
    cout<<"Tastati GV daca alimentul face parte din Grasimi Vegetale"<<endl;
    cout<<"Tastati CE daca alimentul face parte din Produse Cerealifere"<<endl;
    cout<<"Tastati CA daca alimentul face parte din Cartofi"<<endl;
    cout<<"Tastati LE daca alimentul face parte din Legume"<<endl;
    cout<<"Tastati FR daca alimentul face parte din Fructe"<<endl;
    cout<<"Tastati ZA daca alimentul face parte din Zahar"<<endl;

    cin>>a.categ;

    a.nume = removeSpaces(a.nume);

    string nume2=a.nume;

    char * cstr = new char [nume2.length()+1];
    strcpy (cstr, nume2.c_str());

    string hai=cstr;

    hai.append(".txt");

    /*
        ofstream fisierID;
        fisierID.open("fisierID.txt", std::ios_base::app);
        fisierID <<hai<<endl;
        fisierID.close();
    */

    ofstream alimentnou(hai.c_str());
    alimentnou<< a.IDalim<<' '<<a.nume<<' '<<a.nec<<' '<<a.pprot<<' '<<a.plip<<' '<<a.pglu<<' '<<a.pcal<<' '<<a.anveg<<' '<<a.categ;
    alimentnou.close();
    main();
}

void cauta()
{

    system("COLOR 6A");
    system("cls");

    aliment a;
    int aux;

    cout<<"Introd numele dorit:"<<endl;
    cin.ignore();
    getline(cin, a.nume);

    a.nume = removeSpaces(a.nume);

    string nume2= a.nume;
    char * cstr = new char [nume2.length()+1];
    strcpy (cstr, nume2.c_str());
    string hai=cstr;


    fstream file;
    string filename;
    filename = hai.append(".txt");
    file.open(filename.c_str());

    while (file >> aux >> a.nume >> a.nec >> a.pprot >> a.plip >> a.pglu >> a.pcal >> a.anveg >> a.categ)
    {
        cout<<"ID-ul este:"<<aux<<endl;
        cout<<"Partea necomestibila:"<<a.nec<<endl;
        cout<<"Procentul de proteine este:"<<a.pprot<<endl;
        cout<<"Procentul de lipide este:"<<a.plip<<endl;
        cout<<"Procentul de glucide este:"<<a.pglu<<endl;
        cout<<"Procentul de calorii este:"<<a.plip<<endl;
        if(a.anveg=="1")
            cout<<"Aliment de origine animala"<<endl;
        else
            cout<<"Aliment de origine vegetala"<<endl;

        if(a.categ=="LA" or a.categ=="La" or a.categ=="lA" or a.categ=="la")
            cout<<"Alimentul este din categoria Lapte/Branzeturi" <<endl;
        if(a.categ=="PC" or a.categ=="Pc" or a.categ=="pC" or a.categ=="pc")
            cout<<"Alimentul este din categoria Carne/Preparate" <<endl;
        if(a.categ=="OU" or a.categ=="Ou" or a.categ=="oU" or a.categ=="ou")
            cout<<"Alimentul este din categoria Oua" <<endl;
        if(a.categ=="GA" or a.categ=="Ga" or a.categ=="gA" or a.categ=="ga")
            cout<<"Alimentul este din categoria Grasimi Animale" <<endl;
        if(a.categ=="GV" or a.categ=="Gv" or a.categ=="gV" or a.categ=="gv")
            cout<<"Alimentul este din categoria Grasimi Vegetale" <<endl;
        if(a.categ=="CE" or a.categ=="Ce" or a.categ=="cE" or a.categ=="ce")
            cout<<"Alimentul este din categoria produse Cerealifere" <<endl;
        if(a.categ=="CA" or a.categ=="Ca" or a.categ=="cA" or a.categ=="ca")
            cout<<"Alimentul face parte din Cartofi" <<endl;
        if(a.categ=="LE" or a.categ=="Le" or a.categ=="lE" or a.categ=="le")
            cout<<"Alimentul este din categoria Legume" <<endl;
        if(a.categ=="FR" or a.categ=="Fr" or a.categ=="fR" or a.categ=="fr")
            cout<<"Alimentul face parte din Fructe" <<endl;
        if(a.categ=="ZA" or a.categ=="Za" or a.categ=="zA" or a.categ=="za")
            cout<<"Alimentul este din categoria Zahar" <<endl;
        else
            cout<<"Categoria alimentului nu a putut fi gasita"<<endl;


        string rasp;
        cout<<"Doriti sa cautati inca un aliment? [Da/Nu]";
        cin>>rasp;

        if(rasp=="Da" or rasp=="da" or rasp=="DA")
        {
            cauta();
        }
        else
        {
            system("pause");
            main();
        }
    }
}
void edit()
{

}

void afisareTOT()
{

}

void operatii()
{
    system("cls");

    ofstream save;
    save.open("save.txt",ios::out | ios::app );
    time_t now=time(0);
    char* dt = ctime(&now);
    save << "***************************************************"<<endl;
    save << "****************************************************"<<endl;
    save <<"*****  SALVAREA DIN DATA SI ORA: " << dt <<"*********"<<endl;


    aliment a;
    grupatot alsep;
    totalim an,ve;

    cout<<"Introduceti numele alimentului:"<<endl;
    cin.ignore();

    while( getline(cin, a.nume) && a.nume!="9")
    {
         ifstream intrare,intrare2;
            intrare.open("transformari.txt");
            intrare2.open("procente.txt");

        string pastr;
        pastr=a.nume;


        save<< "Numele alimentului = " <<a.nume<<endl;
        a.nume = removeSpaces(a.nume);
        string hai=a.nume.append(".txt");
        ifstream fisier;
        fisier.open(hai.c_str());

        float q, cant, prot, lip, glu, cal;
        int aux;

        if(fisier >> aux >> a.nume >> a.nec >> a.pprot >> a.plip >> a.pglu >> a.pcal >> a.anveg >> a.categ )
        {
            cout<<"Aliment gasit"<<endl;
            save<<"Aliment gasit"<<endl;


            cout<<"Introduceti cantitatea dorita:";
            save<<"Introduceti cantitatea dorita: ";

            cin>>q;  //ADAUGA VARIABILA q
            save<<q<<endl;

            cant=q*(1-(a.nec/100)); //ADAUGA VARIABILA cant

            prot=cant*(a.pprot/100);
            lip=cant*(a.plip/100);
            glu=cant*(a.pglu/100);
            cal=cant*(a.pcal/100);//ADAUGA VARIABILELE prot , lip , glu , cal,

            if(a.anveg=="1")
            {
                an.tprot+=prot;
                an.tlip+=lip;
                an.tglu+=glu;
                an.tcal+=cal;
            }
            else
            {
                ve.tprot+=prot;
                ve.tlip+=lip;
                ve.tglu+=glu;
                ve.tcal+=cal;
            }

            string cuvant;
            int nr,pos,cnt;
            cnt=0;

             while(getline(intrare, cuvant) && intrare2>>nr)
             {
                 if ( (pos=cuvant.find(pastr)) != -1 )
                 {
                     cuvant=cuvant.substr(++pos);
                     cout<<"Alimentul a fost identificat si urmeaza TRANSFORMAREA"<<endl;
                    save<<"Alimentul a fost identificat si urmeaza TRANSFORMAREA"<<endl;
                    cnt++;

                    if(a.categ=="LA" or a.categ=="La" or a.categ=="lA" or a.categ=="la")
                    {
                        alsep.lapte+=(nr*cant)/100;
                        cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                        save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                    }

            if(a.categ=="PC" or a.categ=="Pc" or a.categ=="pC" or a.categ=="pc")
            {
                alsep.carne+=(nr*cant)/100;
                cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
            }

            if(a.categ=="OU" or a.categ=="Ou" or a.categ=="oU" or a.categ=="ou")
                {
                    alsep.oua+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }
            if(a.categ=="GA" or a.categ=="Ga" or a.categ=="gA" or a.categ=="ga")
               {
                    alsep.grasimiA+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
               }
            if(a.categ=="GV" or a.categ=="Gv" or a.categ=="gV" or a.categ=="gv")
                {
                    alsep.grasimiV+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }
            if(a.categ=="CE" or a.categ=="Ce" or a.categ=="cE" or a.categ=="ce")
               {
                    alsep.cerealifere+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;

               }
            if(a.categ=="CA" or a.categ=="Ca" or a.categ=="cA" or a.categ=="ca")
                {
                    alsep.cartofi+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }
            if(a.categ=="LE" or a.categ=="Le" or a.categ=="lE" or a.categ=="le")
                {
                    alsep.legume+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                    save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }
            if(a.categ=="FR" or a.categ=="Fr" or a.categ=="fR" or a.categ=="fr")
                {
                    alsep.fructe+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                    save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }
            if(a.categ=="ZA" or a.categ=="Za" or a.categ=="zA" or a.categ=="za")
                {
                    alsep.zahar+=(nr*cant)/100;
                    cout<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                    save<<"CALCUL TRANSFORMARE: "<< cant << " x " << nr <<"%"<<" = " << (nr*cant)/100<<endl;
                }



                 }
             }

             if(cnt==0)
             {
                 if(a.categ=="LA" or a.categ=="La" or a.categ=="lA" or a.categ=="la")
                alsep.lapte+=cant;
            if(a.categ=="PC" or a.categ=="Pc" or a.categ=="pC" or a.categ=="pc")
                alsep.carne+=cant;
            if(a.categ=="OU" or a.categ=="Ou" or a.categ=="oU" or a.categ=="ou")
                alsep.oua+=cant;
            if(a.categ=="GA" or a.categ=="Ga" or a.categ=="gA" or a.categ=="ga")
                alsep.grasimiA+=cant;
            if(a.categ=="GV" or a.categ=="Gv" or a.categ=="gV" or a.categ=="gv")
                alsep.grasimiV+=cant;
            if(a.categ=="CE" or a.categ=="Ce" or a.categ=="cE" or a.categ=="ce")
                alsep.cerealifere+=cant;
            if(a.categ=="CA" or a.categ=="Ca" or a.categ=="cA" or a.categ=="ca")
                alsep.cartofi+=cant;
            if(a.categ=="LE" or a.categ=="Le" or a.categ=="lE" or a.categ=="le")
                alsep.legume+=cant;
            if(a.categ=="FR" or a.categ=="Fr" or a.categ=="fR" or a.categ=="fr")
                alsep.fructe+=cant;
            if(a.categ=="ZA" or a.categ=="Za" or a.categ=="zA" or a.categ=="za")
                alsep.zahar+=cant;
             }


            cout<<"Cantitatea comestibila este: "<<cant<<endl;
            cout<<"Proteinele pentru cantitatea data sunt "<<prot<<endl;
            cout<<"Lipidele pentru cantitatea data sunt "<<lip<<endl;
            cout<<"Glucidele pentru cantitatea data sunt "<<glu<<endl;
            cout<<"Caloriile pentru cantitatea data sunt "<<cal<<endl;
            if(a.anveg=="1")
                cout<<"Aliment de origine animala"<<endl;
            else
                cout<<"Aliment de origine vegetala"<<endl;

            if(a.categ=="LA" or a.categ=="La" or a.categ=="lA" or a.categ=="la")
                cout<<"Alimentul este din categoria Lapte/Branzeturi" <<endl;
            if(a.categ=="PC" or a.categ=="Pc" or a.categ=="pC" or a.categ=="pc")
                cout<<"Alimentul este din categoria Carne/Preparate" <<endl;
            if(a.categ=="OU" or a.categ=="Ou" or a.categ=="oU" or a.categ=="ou")
                cout<<"Alimentul este din categoria Oua" <<endl;
            if(a.categ=="GA" or a.categ=="Ga" or a.categ=="gA" or a.categ=="ga")
                cout<<"Alimentul este din categoria Grasimi Animale" <<endl;
            if(a.categ=="GV" or a.categ=="Gv" or a.categ=="gV" or a.categ=="gv")
                cout<<"Alimentul este din categoria Grasimi Vegetale" <<endl;
            if(a.categ=="CE" or a.categ=="Ce" or a.categ=="cE" or a.categ=="ce")
                cout<<"Alimentul este din categoria produse Cerealifere" <<endl;
            if(a.categ=="CA" or a.categ=="Ca" or a.categ=="cA" or a.categ=="ca")
                cout<<"Alimentul face parte din Cartofi" <<endl;
            if(a.categ=="LE" or a.categ=="Le" or a.categ=="lE" or a.categ=="le")
                cout<<"Alimentul este din categoria Legume" <<endl;
            if(a.categ=="FR" or a.categ=="Fr" or a.categ=="fR" or a.categ=="fr")
                cout<<"Alimentul face parte din Fructe" <<endl;
            if(a.categ=="ZA" or a.categ=="Za" or a.categ=="zA" or a.categ=="za")
                cout<<"Alimentul este din categoria Zahar" <<endl;
            else
                cout<<"Categoria alimentului nu a putut fi gasita"<<endl;
                ///////////////////////////////////////////////////////////////////////////////////////////////

            save<<"Cantitatea comestibila este: "<<cant<<endl;
            save<<"Proteinele pentru cantitatea data sunt "<<prot<<endl;
            save<<"Lipidele pentru cantitatea data sunt "<<lip<<endl;
            save<<"Glucidele pentru cantitatea data sunt "<<glu<<endl;
            save<<"Caloriile pentru cantitatea data sunt "<<cal<<endl;
            if(a.anveg=="1")
                save<<"Aliment de origine animala"<<endl;
            else
                save<<"Aliment de origine vegetala"<<endl;

            if(a.categ=="LA" or a.categ=="La" or a.categ=="lA" or a.categ=="la")
                save<<"Alimentul este din categoria Lapte/Branzeturi" <<endl;
            if(a.categ=="PC" or a.categ=="Pc" or a.categ=="pC" or a.categ=="pc")
                save<<"Alimentul este din categoria Carne/Preparate" <<endl;
            if(a.categ=="OU" or a.categ=="Ou" or a.categ=="oU" or a.categ=="ou")
                save<<"Alimentul este din categoria Oua" <<endl;
            if(a.categ=="GA" or a.categ=="Ga" or a.categ=="gA" or a.categ=="ga")
                save<<"Alimentul este din categoria Grasimi Animale" <<endl;
            if(a.categ=="GV" or a.categ=="Gv" or a.categ=="gV" or a.categ=="gv")
                save<<"Alimentul este din categoria Grasimi Vegetale" <<endl;
            if(a.categ=="CE" or a.categ=="Ce" or a.categ=="cE" or a.categ=="ce")
                save<<"Alimentul este din categoria produse Cerealifere" <<endl;
            if(a.categ=="CA" or a.categ=="Ca" or a.categ=="cA" or a.categ=="ca")
                save<<"Alimentul face parte din Cartofi" <<endl;
            if(a.categ=="LE" or a.categ=="Le" or a.categ=="lE" or a.categ=="le")
                save<<"Alimentul este din categoria Legume" <<endl;
            if(a.categ=="FR" or a.categ=="Fr" or a.categ=="fR" or a.categ=="fr")
                save<<"Alimentul face parte din Fructe" <<endl;
            if(a.categ=="ZA" or a.categ=="Za" or a.categ=="zA" or a.categ=="za")
                save<<"Alimentul este din categoria Zahar" <<endl;
            else
                save<<"Categoria alimentului nu a putut fi gasita"<<endl;

        }
        else
        {
            cout<<"Nu s-a putut gasi niciun aliment cu numele " << a.nume <<endl;
            save<<"Nu s-a putut gasi niciun aliment cu numele " << a.nume <<endl;

        }
        cout<<endl;
        cout<<endl;
        cout<<"**************************************"<<endl;
        cout<<"TOTAL CALORII : " << ve.tcal + an.tcal << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL PROTEINE ANIMALE : " << an.tprot << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL PROTEINE VEGETALE : " << ve.tprot << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL Proteine (animale + vegetale) :" << an.tprot + ve.tprot << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL LIPIDE ANIMALE : " << an.tlip << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL LIPIDE VEGETALE : " << ve.tlip << endl;
        cout<<endl;
        cout<<endl;
        cout<<"TOTAL Lipide (animale + vegetale) :" << an.tlip + ve.tlip << endl;
          cout<<endl;
        cout<<endl;
        cout<<"TOTAL GLUCIDE : " << ve.tglu + an.tglu << endl;
        cout<<endl;
        cout<<endl;
        /////////////////////////////////////////////////////////////////////////////////////////////////
        save<<endl;
        save<<endl;
        save<<"**************************************"<<endl;
        save<<"TOTAL CALORII : " << ve.tcal + an.tcal << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL PROTEINE ANIMALE : " << an.tprot << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL PROTEINE VEGETALE : " << ve.tprot << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL Proteine (animale + vegetale): " << an.tprot + ve.tprot << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL LIPIDE ANIMALE : " << an.tlip << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL LIPIDE VEGETALE : " << ve.tlip << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL Lipide (animale + vegetale): " << an.tlip + ve.tlip << endl;
        save<<endl;
        save<<endl;
        save<<"TOTAL GLUCIDE : " << ve.tglu + an.tglu << endl;
        save<<endl;
        save<<endl;



        string rasp;
        cout<<"Doriti sa afisati totalul pe grupe de alimente? [Da/Nu]"<<endl;
        save<<"Doriti sa afisati totalul pe grupe de alimente? [Da/Nu]"<<endl;
        cin>>rasp;
        save << rasp <<endl;

        if(rasp=="Da" or rasp=="da" or rasp=="DA" or rasp=="dA")
        {
            cout<<"Totalul de Lapte/Branzeturi este: "<< alsep.lapte<<endl;
            cout<<"Totalul de Carne/Preparate este: "<< alsep.carne<<endl;
            cout<<"Totalul de Oua este: "<< alsep.oua<<endl;
            cout<<"Totalul de Grasimi Animale este: "<< alsep.grasimiA<<endl;
            cout<<"Totalul de Grasimi Vegetale este: "<< alsep.grasimiV<<endl;
            cout<<"Totalul de Grasimi (animale+vegetale) este: "<< alsep.grasimiA + alsep.grasimiV <<endl;
            cout<<"Totalul de Produse cerealifere este: "<< alsep.cerealifere <<endl;
            cout<<"Totalul de Cartofi este: "<< alsep.cartofi <<endl;
            cout<<"Totalul de Legume este: "<< alsep.legume <<endl;
            cout<<"Totalul de Fructe este: "<< alsep.fructe<<endl;
            cout<<"Totalul de Zahar este: "<< alsep.zahar<<endl;
            //////////////////////////////////////////////////////////////////////////////////////////////////
            save<<"Totalul de Lapte/Branzeturi este: "<< alsep.lapte<<endl;
            save<<"Totalul de Carne/Preparate este: "<< alsep.carne<<endl;
            save<<"Totalul de Oua este: "<< alsep.oua<<endl;
            save<<"Totalul de Grasimi Animale este: "<< alsep.grasimiA<<endl;
            save<<"Totalul de Grasimi Vegetale este: "<< alsep.grasimiV<<endl;
            save<<"Totalul de Grasimi (animale+vegetale) este: "<< alsep.grasimiA + alsep.grasimiV <<endl;
            save<<"Totalul de Produse cerealifere este: "<< alsep.cerealifere <<endl;
            save<<"Totalul de Cartofi este: "<< alsep.cartofi <<endl;
            save<<"Totalul de Legume este: "<< alsep.legume <<endl;
            save<<"Totalul de Fructe este: "<< alsep.fructe<<endl;
            save<<"Totalul de Zahar este: "<< alsep.zahar<<endl;
        }

        cout<<"**************************************"<<endl;
        save<<"**************************************"<<endl;

        cout<<"Puteti introduce alt aliment sau apasati tasta 9 pentru a iesi"<<endl;
        save<<"Puteti introduce alt aliment sau apasati tasta 9 pentru a iesi"<<endl;
        cin.ignore();

        intrare.close();
        intrare2.close();
        fisier.close();

    }

    save << "**********************************************"<<endl;
    save << "***********************************************"<<endl;
    save << "**********************************************"<<endl;
    save << "*********************************************"<<endl;
    cout<<endl;
    save<<endl;

    save.close();
    cin.get();


    system("pause");
    main();
}




/*
Color Codes:
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White
*/
