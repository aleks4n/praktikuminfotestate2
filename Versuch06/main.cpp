/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIII <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Student.h"


int main()
{

    Student student;
    std::vector<Student> studentenListe;

    char abfrage;

    //    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    //    std::cin >> abfrage;
    //    std::cin.ignore(10, '\n');
    //
    //    if (abfrage != 'j')
    //    {
    //        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
    //        studentenListe.push_back(student);
    //        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
    //        studentenListe.push_back(student);
    //        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
    //        studentenListe.push_back(student);
    //        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
    //        studentenListe.push_back(student);
    //        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wuellnerstr.9");
    //        studentenListe.push_back(student);
    //    }




    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelemente hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenbank Forwearts ausgeben" << std::endl
                  << "(4): Datenbank Rueckwaerts ausgeben" << std::endl
				  << "(5): Datenelement Loeschen" << std::endl
        		  << "(6): Datenelement hinzufugen" << std::endl
				  << "(7): Datenelement Vorne Loeschen" << std::endl
				  << "(8): Daten von eine Datei Lesen" << std::endl
                  << "(9): Daten sichern" << std::endl
				  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen

            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);

                    studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen



            case '2':
                {
                    if(!studentenListe.empty())
                    {
                       // student = studentenListe.dataFront();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                       studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben

            case '3':
            	 if(!studentenListe.empty())
            	                {
            	                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
            	                    for(Student student : studentenListe)
            	                        student.ausgabe();
            	                                    }
            	                else
            	                {
            	                    std::cout << "Die Liste ist leer!\n";
            	                }
                break;


            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;

            case '4':
                if(!studentenListe.empty())
                       {
                           std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                           for(auto iterator=studentenListe.rbegin();iterator!=studentenListe.rend();iterator++){
                               iterator->ausgabe();
                           }

                       }
                       else
                       {
                           std::cout << "Die Liste ist leer!"<< std::endl;
                       }

            break;


            case '5':{
                int eraseNummer = 0;
                     if(!studentenListe.empty())
                     {
                         std::cout << "Geben Sie die Stelle, die Sie loeschen moechten:" << std::endl;
                         std::cin >> eraseNummer;
                         int index = eraseNummer - 1;
                         studentenListe.erase(studentenListe.begin() + index);

                     }

                     else
                     {
                         std::cout << "Die Liste ist leer!"<< std::endl;;
                     }

            }break;


            case '6':{

                unsigned int matNr = 0;
                                       int insertNummer = 0;
                                       if(!studentenListe.empty())
                                       {
                                           std::cout << "An welche Stelle möchten Sie neues Element hinzufuegen?:" << std::endl;
                                           std::cin >> insertNummer;
                                           std::cin.ignore(10, '\n');
                                           int index = insertNummer - 1;


                                           std::string name = "";
                                           std::string geburtstag = "";
                                           std::string adresse = "";

                                           std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\n Name: ";
                                           getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                                           std::cout << "Geburtsdatum: ";
                                           getline(std::cin, geburtstag); //zeile einlesen

                                           std::cout << "Adresse: ";
                                           getline(std::cin, adresse);

                                           std::cout << "Matrikelnummer: ";
                                           std::cin >> matNr;
                                           std::cin.ignore(10, '\n');

                                           Student studentN(matNr, name, geburtstag, adresse);

                                           studentenListe.insert(studentenListe.begin() + index, studentN);
                                       }
                                       else
                                       {
                                           std::cout << "Die Liste ist Leer!\n\n";
                                       }

            }break;




            case '7':{

                if(!studentenListe.empty())
                   {
                       std::cout << "Loesche Erste Element" << std::endl;
                       studentenListe.erase(studentenListe.begin());
                   }

                   else
                   {
                       std::cout << "Die Liste ist Leer!\n";
                   }

            }break;



            case '8':{
            	std::string dateiName = "";
            	                std::cout << "Geben Sie den Namen von Datei ein: ";
            	                std::cin >> dateiName;
            	                std::cin.ignore(10, '\n');

            	                std::ifstream eingabe(dateiName);//input modus
            	                studentenListe.clear();// clear bevor Datei lesen

            	                if (!eingabe)
            	                    std::cout<<"falsche eingabe"<<std::endl;

            	                if (eingabe) {


            	                    std::string s=" ";
            	                    getline(eingabe, s);

            	                    do// loop um die ganze datei einzulesen
            	                    {

            	                    unsigned int matNr = 0;
            	                    std::string name = "";
            	                    std::string geburtstag = "";
            	                    std::string adresse = "";


            	                    matNr=std::stoi(s);// str to int
            	                    getline(eingabe, s);

            	                    name=s;

            	                    getline(eingabe, s);
            	                    geburtstag=s;


            	                    getline(eingabe, s);
            	                    adresse=s;


            	                    Student student(matNr, name, geburtstag, adresse);

            	                    studentenListe.push_back(student);
            	                    getline(eingabe, s);

            	                }while(s!="");
            	                    eingabe.close();}

            }break;



            case '9':{

            	 std::string speicherdateiName = "";
            	            		std::cout<<"Gib die name von der Datei die Daten eingespiechert soll";
            	            		   std::cin >> speicherdateiName;
            	            		   std::ofstream outfile(speicherdateiName);
            	            		   for (int i = 0; i < studentenListe.size(); i++) {
            	            		           outfile << studentenListe[i].getMatNr()<< std::endl
            	            		                   << studentenListe[i].getName()<< std::endl
            	            		                   << studentenListe[i].getGeburtstag() << std::endl
            										   << studentenListe[i].getAdresse() << std::endl;

            	            		       }

            	            		   outfile.close();

                        }break;




        }
    }
    while (abfrage != '0');

    return 0;
}
