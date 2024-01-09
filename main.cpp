#include "rumahsakit.h"
#include <iostream>

using namespace std;

int main() {

  ListDoctor LD;
  ListPasien LP;
  listRelasi Lr;

  infotypePat dataBaruP;
  infotypeDoc dataBaruD;

  createListDoctor(LD);
  createListPasien(LP);
  createList_relasi(Lr);



    adr_doctor newDoctor, foundD,Precdr,dataOutdr;
    adr_pasien newPasien, foundP, Precpt, dataOutPt;
    adr_relasi r;


  int optionMain, optionSub,sumdrnopat;
  int id_pasien,  noDoctor, p, sumdr;

  bool keluar = false;

  string dr;
  string spesialis;


  dataDummyDoc(LD,dataBaruD,newDoctor);
  dataDummyPat(LP,dataBaruP,newPasien);
  DummyRelasi(Lr,LD,LP);
  clearScreen();

  do {
    optionMain = mainMenu();
    clearScreen();
    switch (optionMain) {
    case 1:
      while (!keluar) {
        optionSub = menuDoctor();
        clearScreen();
        switch (optionSub) {
        case 1:// masuk ke menu dokter ---------------------------------------------------------------------------
          int i, in;
          i = 0;
          cout << "-----------------------------------------------------------"
               << endl;
          cout << "enter the number of new doctors:";
          cin >> in;
          cout << "-----------------------------------------------------------"<< endl;
          while (i != in) {
            cout << " Docter's name:";
            cin >> dataBaruD.nama;
            cout << " Working hours :";
            cin >> dataBaruD.waktu;
            cout << " Doctor's id:";
            cin >> dataBaruD.id_doctor;
            cout << " Specialist :";
            cin >> dataBaruD.speciality;
            cout
                << "-----------------------------------------------------------"
                << endl;
            newDoctor = createElementDoctor(dataBaruD);
            cout << endl;
            insertLastDoc(LD, newDoctor);
            cout << endl;
            i++;
          }
          break;
        case 2:
          cout << "Please kindly enter the doctor's name you'd like to delete:"<<endl;
          cin >> dr;
          deleteDokterbyName(LD,dataOutdr,dr,Precdr);
          break;
        case 3:
          cout << "-----------------------------------------------------------"<< endl;
          cout << "Please kindly enter the doctor's name you'd like to find: ";
          cin >> dr;
          cout << "-----------------------------------------------------------"<< endl;
          foundD = findDoctor(LD, dr);
          if (foundD !=NULL){
          cout << "======  Here is the doctor that you are looking for:  ======"
               << endl;
          cout << "Name: " << infoDoc(foundD).nama << endl;
          cout << "Doctor's id: " << infoDoc(foundD).id_doctor << endl;
          cout << "Working hours: " << infoDoc(foundD).waktu << endl;
          cout << "Specialist: " << infoDoc(foundD).speciality << endl;
          cout << "========================================================"<< endl;
         }else{
            cout<<"Doctor doesn't found!, please check your DOCTOR NAME"<<endl;
            cout << "-----------------------------------------------------------"<< endl;
         }
          break;
        case 4:
          cout << "==========  Here is the list the doctors that are available  ==========" << endl;
          showDoctor(LD);
          break;
        case 5:
          showDokterfromPasien(Lr, LP);
          break;
        case 6:
          sumdr = countDokterBasedONPasien(Lr, LP);
          cout << "Number of doctors based on Patient id:"<<sumdr<< endl;
          break;
        case 7:
          sumdrnopat = countDokterTanpaPasien(Lr, LD);
          cout << "Number of Doctors who have no patients:"<< sumdrnopat << endl;
          cout << endl;
          break;
        case 0:
          keluar = true;
          break;
        default:
          clearScreen();
          cout << "---  Incorrect Input, Please Re-Input!  ---" << endl;
          break;
        }
      };
      keluar = false; // kembaliin ke default value
      clearScreen();
      break;
    case 2: // masuk ke menu pasien ---------------------------------------------------------------------------
      while (!keluar) {
        optionSub = menuPatient();
        clearScreen();
        switch (optionSub) {
        case 1:
          int in, i;
          i = 0;
          cout << "--------------------------------------------------------"
               << endl;
          cout << " Enter Multiple Number of New patients: ";
          cin >> in;
          while (i != in) {
            cout << " Patien's name :";
            cin >> dataBaruP.nama;
            cout << " Address :";
            cin >> dataBaruP.alamat;
            cout << " Patient's Id :";
            cin >> dataBaruP.id_pasien;
            cout << " type of disease :";
            cin >> dataBaruP.jenis_penyakit;
            cout << " Specialist :";
            cin >> dataBaruP.speciality;
            cout
                << "-----------------------------------------------------------"
                << endl;
            newPasien = createElemenP(dataBaruP);
            cout << endl;
            InsertDataPasien(LP, newPasien);
            cout << endl;
            i++;
          }
          break;
        case 2:
          cout << "Enter the Patient ID that you'd like to delete: ";
            cin >> id_pasien;
          cout<<endl;

          deletePasienbyID(LP, Precpt, dataOutPt, id_pasien);
          break;
        case 3:
          cout << "--------------------------------------------------------"
               << endl;
          cout << "Enter the Patient Id: ";
          cin >> id_pasien;
          cout << "--------------------------------------------------------"<< endl;
          foundP = findPasienbyID(LP, id_pasien);
          if (foundP != NULL){
          cout << "======  Here is the patient data you are looking for:  ======"
               << endl;
          cout << "Patient's name: " << infoPat(foundP).nama << endl;
          cout << "Patient's Id: " << infoPat(foundP).id_pasien << endl;
          cout << "Address: " << infoPat(foundP).alamat << endl;
          cout << "type of disease: " << infoPat(foundP).jenis_penyakit << endl;
          cout << "Specialist: " << infoPat(foundP).speciality << endl;
          cout << "========================================================"<<endl;

          }else{
              cout << "Patient isn't found! please check your Patient ID"<< endl;
              cout << "--------------------------------------------------------"
             << endl;
          }
          break;
        case 4:
          cout << "=================  Current Patient List  ================="
               << endl;
          showDataPasien(LP);
          cout<<endl;
          break;
        case 5:
            showPasienfromDokter(Lr, LD);
            break;
        case 6:
          p = countPasienParentbased(Lr, LD);
          cout << "Number of patients based on doctor's : "<<p;
          cout << endl;
          break;
        case 7:
          noDoctor = countPasienTanpaDokter(Lr, LP);
          cout << "Number of patients without a doctor: "<<noDoctor;
          cout << endl;
          break;
        case 0:
          keluar = true;
          break;
        default:
          clearScreen();
          cout << "---  Incorrect Input, Please Re-Input!  ---" << endl;
          break;
        }
      };
      keluar = false; // kembaliin ke default value
      clearScreen();
      break;
    case 3:// masuk ke menu relasi ---------------------------------------------------------------------------
      while (!keluar) {
        optionSub = menuRelation();
        clearScreen();
        switch (optionSub) {
        case 1:
            cout<<"Enter the Doctor's name: ";
            cin>>dr;
            cout<<"Enter the Patient Id: ";
            cin>>id_pasien;
          tambahRelasi(Lr,LD,  LP, dr, id_pasien);

          break;
        case 2:
            cout<<"Enter the doctor's name:";
            cin>>dr;
            cout<<"Enter the patient Id:";
            cin>>id_pasien;
          deleteRelasi(LD,LP,Lr,r,dr,id_pasien);
          break;
        case 3:
            cout<<"Enter a specialist: ";
            cin>>spesialis;
            cout << "--------------------------------------------------------"
               << endl;
          r = findElm_relasi(Lr, spesialis);
          if(r!=NULL){
          cout<<"========== DOCTOR =========="<<endl;
          cout<<infoDoc(dokter(r)).nama<<endl;
          cout<<infoDoc(dokter(r)).id_doctor<<endl;
          cout<<"========== PATIENT =========="<<endl;
          cout<<infoPat(pasien(r)).nama<<endl;
          cout<<infoPat(pasien(r)).id_pasien<<endl;
          }else{
            cout<<"Specialist isn't found!, please check your SPECIALIST"<<endl;
            cout << "--------------------------------------------------------"
               << endl;
          }
          break;
        case 4:
          editRelasi(Lr, LD, LP);
          break;
        case 5:
          showRelasi(Lr);
          break;
        case 6:
          showAllPatientswithDoctors(LP,Lr);
          break;
        case 7:
          showAllDoctorswithPatients(LD, Lr);
          break;
        case 0:
          keluar = true;
          break;
        default:
          clearScreen();
          cout << "---  Incorrect Input, Please Re-Input!  ---" << endl;
          break;
        }
      };
      keluar = false; // kembaliin ke default value
      clearScreen();
      break;
    case 0:
      clearScreen();
      cout << "----------  Thank You!  ----------" << endl;
      break;
    default:
      cout << "---  Incorrect Input, Please Re-Input!  ---" << endl;
      break;
    };
  } while (optionMain != 0);
  return 0;
};
