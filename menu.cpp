#include "rumahsakit.h"
#include <iostream>
#include <limits>
#include <string>
#include <typeinfo>

using namespace std;

int mainMenu() {
  cout << "================================ Welcome to Wimal Hospital "
    "=============================="
  << endl;
  cout << "-----    by : Ade Ikmal Maulana (1301220078) and Yustinus Dwi Adyra "
    "(1301223129)    -----"
  << endl;
  cout << "===================================================================="
    "====================="
  << endl;
  cout << "=============  Main Menu  =============" << endl;
  cout << "[1]. Menu Doctor" << endl;
  cout << "[2]. Menu Patient" << endl;
  cout << "[3]. Menu Relation" << endl;
  cout << "[0]. Exit" << endl;
  cout << "=======================================" << endl;
  int option;
  cout << "please kindly choose your menu: ";
  cin >> option;
  //if (!option){
    //inputOption(option);
  //}
  return option;
}

int menuDoctor() {
  cout << "=============  Doctor Menu  =============" << endl;
  cout << "[1]. Add doctors to the list" << endl;
  cout << "[2]. Delete a doctor from the list" << endl;
  cout << "[3]. Find a doctor" << endl;
  cout << "[4]. Show all the doctors" << endl;
  cout << "[5]. Show doctors from a patient" << endl;
  cout << "[6]. Count doctors of a patient" << endl;
  cout << "[7]. Count doctors without any patient" << endl;
  cout << "[0]. Back to Main menu" << endl;
  cout << "=========================================" << endl;
  int option;
  cout << "please kindly choose your menu: ";
  cin >> option;
  //if (!option){
    //inputOption(option);
  //}
  return option;
}

int menuPatient() {
  cout << "=============  Patient Menu  =============" << endl;
  cout << "[1]. Add patients to the list" << endl;
  cout << "[2]. Delete a patient from the list" << endl;
  cout << "[3]. Find a patient" << endl;
  cout << "[4]. Show all the patients" << endl;
  cout << "[5]. Show patients from a doctor" << endl;
  cout << "[6]. Count patients from a doctor" << endl;
  cout << "[7]. Count patients without any doctor" << endl;
  cout << "[0]. Back to Main menu" << endl;
  cout << "==========================================" << endl;
  int option;
  cout << "please kindly choose your menu: ";
  cin >> option;
  //if (!option){
    //inputOption(option);
  //}
  return option;
}

int menuRelation() {
  cout << "=============  Relation Menu  =============" << endl;
  cout << "[1]. Add relations to the list" << endl;
  cout << "[2]. Delete a relation from the list" << endl;
  cout << "[3]. Find a relation" << endl;
  cout << "[4]. Edit a relation" << endl;
  cout << "[5]. Show relations" << endl;
  cout << "[6]. Show All Patients with Doctors" << endl;
  cout << "[7]. Show All Doctors with Patients" << endl;
  cout << "[0]. Back to Main menu" << endl;
  cout << "==========================================" << endl;
  int option;
  cout << "please kindly choose your menu: ";
  cin>>option;
  //if (!option){
    //inputOption(option);
  //}
  return option;
}

// fungsi untuk menghapus layar
void clearScreen() {
#ifdef _WIN32 // Windows
  system("cls");
#else
  (void)system("clear"); // Mac/Linux
#endif
}

//void inputOption(int &option) {
    //if(option!=0){
        //while (!option || option != 0) {
            //cout << "-------- Incorrect Input, Please Re-Input! --------" << endl;
            //cout << "*****input must be a number available in the menu options*****" << endl;
            //cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //cout << "please kindly choose your menu: ";
            //cin >> option;
        //}
    //}
//}
