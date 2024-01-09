#include "rumahsakit.h"
#include <iostream>

using namespace std;

// dokter.cpp ----------------------------------------------------

void createListDoctor(ListDoctor &L) {
  firstDoc(L) = NULL;
  lastDoc(L) = NULL;
}

adr_doctor createElementDoctor(infotypeDoc x) {
  adr_doctor newDoctor = new doctorElement;

  infoDoc(newDoctor).nama = x.nama;
  infoDoc(newDoctor).id_doctor = x.id_doctor;
  infoDoc(newDoctor).speciality = x.speciality;
  infoDoc(newDoctor).waktu = x.waktu;

  nextDoc(newDoctor) = NULL;
  prevDoc(newDoctor) = NULL;
  return newDoctor;
}

void insertLastDoc(ListDoctor &L, adr_doctor p) {
  if (firstDoc(L) == NULL) {
    firstDoc(L) = p;
    lastDoc(L) = p;
  } else {
    prevDoc(p) = lastDoc(L);
    nextDoc(lastDoc(L)) = p;
    lastDoc(L) = p;
  }
}

void deleteFirstDoc(ListDoctor &L, adr_doctor &temp) {
  if (firstDoc(L) == NULL) {
        cout << "Empty List!" << endl;
  } else if (next(firstDoc(L)) == NULL) {
        temp = firstDoc(L);
        firstDoc(L) = NULL;
        lastDoc(L) = NULL;
  } else {
    temp = firstDoc(L);
    firstDoc(L) = nextDoc(firstDoc(L));
    nextDoc(temp) = NULL;
    prevDoc(firstDoc(L)) = NULL;
  }
}


void deleteLastDoc(ListDoctor &L, adr_doctor &temp) {
  if (firstDoc(L) == NULL) {
    cout << "Empty List!" << endl;
  } else if (nextDoc(firstDoc(L)) == NULL) {
    temp = firstDoc(L);
    firstDoc(L) = NULL;
    lastDoc(L) = NULL;
  } else {
    temp = lastDoc(L);
    lastDoc(L) = prevDoc(lastDoc(L));
    prevDoc(temp) = NULL;
    nextDoc(lastDoc(L)) = NULL;
  }
}

void deleteAfterDoc(ListDoctor &L, adr_doctor &temp, adr_doctor prec) {
  if (firstDoc(L) == NULL) {
    cout << "Empty List!" << endl;
  } else {
    temp = nextDoc(prec);
    nextDoc(prec) = nextDoc(temp);
    prevDoc(nextDoc(temp)) = prec;
    prevDoc(temp) = NULL;
    nextDoc(temp) = NULL;
  }
}


void deleteDokterbyName(ListDoctor &L, adr_doctor &dataOut, string nama, adr_doctor Prec) {
    adr_doctor tDocDelete = findDoctor(L, nama);


    if(tDocDelete != NULL){
        Prec = prevDoc(tDocDelete);
        if (tDocDelete == firstDoc(L)) {
            deleteFirstDoc(L, dataOut);
            cout << "the doctor has been deleted!" << endl;
        } else if (tDocDelete == lastDoc(L)) {
            deleteLastDoc(L, dataOut);
            cout << "the doctor has been deleted!" << endl;
        } else {
            deleteAfterDoc(L, dataOut, Prec);
            cout << "the doctor has been deleted!" << endl;
        }


    }else{
        cout<<"data not found!"<<endl;
    }
}


adr_doctor findDoctor(ListDoctor &L, string doctorname) {
  adr_doctor p = firstDoc(L);
  while (p != NULL) {
    if (infoDoc(p).nama == doctorname) {
      return p;
    }
    p = nextDoc(p);
  }
  return NULL;
}

void showDoctor(ListDoctor L) {
  if (firstDoc(L) == NULL) {
    cout << "Doctor is not found!" << endl;
  } else {
    adr_doctor p = firstDoc(L);
    while (p != NULL) {
      cout<<"======================================="<<endl;
      cout << "name             \t:" << infoDoc(p).nama << endl;
      cout << "id\              \t:" << infoDoc(p).id_doctor << endl;
      cout << "specialist       \t:" << infoDoc(p).speciality << endl;
      cout << "working times    \t:" << infoDoc(p).waktu << endl;
      cout<<"======================================="<<endl;
      p = nextDoc(p);
    }
    cout << "" << endl;
  }
}

// Pasien.cpp ----------------------------------------------------

void createListPasien(ListPasien &L) {
  firstPat(L) = NULL;
  lastPat(L) = NULL;
}
adr_pasien createElemenP(infotypePat dataP) {
  adr_pasien p;
  p = new elem_pasien;
  infoPat(p) = dataP;
  return p;
}
void InsertDataPasien(ListPasien &L, adr_pasien dataBaru) {
  if (firstPat(L) == NULL) {
    firstPat(L) = dataBaru;
    lastPat(L) = dataBaru;
    nextPat(lastPat(L)) = dataBaru;
    prevPat(dataBaru) = firstPat(L);
  } else {
    prevPat(dataBaru) = lastPat(L);
    nextPat(dataBaru) = firstPat(L);
    prevPat(firstPat(L)) = dataBaru;
    nextPat(lastPat(L)) = dataBaru;
    lastPat(L) = dataBaru;
  }
}
void DeleteLast(ListPasien &L, adr_pasien dataOut) {
  if (firstPat(L) == NULL) {
    cout << "empty list!";
  } else if (nextPat(firstPat(L)) == NULL) {
    dataOut = firstPat(L);
    firstPat(L) = NULL;
  } else {
    dataOut = lastPat(L);
    lastPat(L) = prevPat(dataOut);
    nextPat(lastPat(L)) = firstPat(L);
    prevPat(firstPat(L)) = lastPat(L);
    prevPat(dataOut) = NULL;
    nextPat(dataOut) = NULL;
  }
}
void DeleteFirst(ListPasien &L, adr_pasien dataOut) {
  if (firstPat(L) == NULL) {
    cout << "empty list";
  } else if (nextPat(firstPat(L)) == NULL) {
    dataOut = firstPat(L);
    firstPat(L) = NULL;
  } else {
    dataOut = firstPat(L);
    lastPat(L) = nextPat(dataOut);
    prevPat(firstPat(L)) = lastPat(L);
    nextPat(lastPat(L)) = firstPat(L);
    prevPat(dataOut) = NULL;
    nextPat(dataOut) = NULL;
  }
}
void DeleteAfter(ListPasien &L, adr_pasien prec, adr_pasien dataOut) {
  if (firstPat(L) == NULL) {
    cout << "empty list";
  } else if (nextPat(firstPat(L)) == NULL) {
    dataOut = firstPat(L);
    firstPat(L) = NULL;
  } else {
    dataOut = nextPat(prec);
    nextPat(prec) = nextPat(dataOut);
    prevPat(nextPat(dataOut)) = prec;
    nextPat(dataOut) = NULL;
    prevPat(dataOut) = NULL;
  }
}

void deletePasienbyID(ListPasien &L, adr_pasien prec, adr_pasien dataOut,
                      int id) {

  adr_pasien x = findPasienbyID(L, id);
    if (x != NULL){
        prec= prevPat(findPasienbyID(L,id));
        if (x == firstPat(L)) {
            DeleteFirst(L, dataOut);
            cout<<"Delete Patient Successfully (v)";
        } else if (x == lastPat(L)) {
            DeleteLast(L, dataOut);
            cout<<"Delete Patient Successfully (v)";
        } else if(x != firstPat(L) && x != lastPat(L)){
            DeleteAfter(L, prec, dataOut);
            cout<<"Delete Patient Successfully (v)"<<endl;
        }

    }else{
        cout<<"data not found!"<<endl;

    }

    //return;
}
void showDataPasien(ListPasien L) {
  adr_pasien x;
  x = firstPat(L);
  do {
    cout<<"======================================="<<endl;
    cout << "Patient's name  \t:" << infoPat(x).nama << endl;
    cout << "Id              \t:" << infoPat(x).id_pasien << endl;
    cout << "Address         \t:" << infoPat(x).alamat << endl;
    cout << "Type of Disease \t:" << infoPat(x).jenis_penyakit << endl;
    cout << "Specialist      \t:" << infoPat(x).speciality << endl;
    cout<<"======================================="<<endl;
    x = nextPat(x);
  } while (x != firstPat(L));
}
void countPasien(ListPasien L) {
  adr_pasien x;
  int jumlah = 0;
  x = firstPat(L);
  do {
    jumlah++;
    x = nextPat(x);
  } while (x != firstPat(L));
  cout << "Current Number of Patients:" << jumlah << endl;
}
adr_pasien findPasienbyID(ListPasien L, int id) {
  adr_pasien x, y;
    y = NULL;
  x = firstPat(L);
  do {
    if (infoPat(x).id_pasien == id) {
      y = x;
    }
    x = nextPat(x);
  } while (x != firstPat(L));
  return y;
}

// relasi.cpp ----------------------------------------------------
void createList_relasi(listRelasi &L) { first_relasi(L) = NULL; }

adr_relasi createElementRelasi(adr_pasien pasien, adr_doctor dokter) {
  adr_relasi p = new elm_relasi;
  pasien(p) = pasien;
  dokter(p) = dokter;
  nextRel(p) = NULL;
  return p;
}

adr_relasi findElm_relasi(listRelasi &L, string speciality) {
  adr_relasi p = first_relasi(L);
  while (p != NULL) {
    if (speciality == infoDoc(dokter(p)).speciality && speciality == infoPat(pasien(p)).speciality) {
      return p;
    }
    p = nextRel(p);
  }
  return NULL;
}


void tambahRelasi(listRelasi &LR,ListDoctor LD, ListPasien LP, string doctorName, int id_pasien){
    adr_doctor d = findDoctor(LD,doctorName);
    adr_pasien p = findPasienbyID(LP,id_pasien);

    if (d!=NULL && p!=NULL){
        adr_relasi r= createElementRelasi(p,d);
        if (r!=NULL){
            if(first_relasi(LR) == NULL){
                first_relasi(LR)=r;
            }else{
                adr_relasi x = first_relasi(LR);
                while (nextRel(x) !=NULL){
                    x=nextRel(x);
                }
                nextRel(x)=r;
            }
            cout << "Relationship successfully added!" << endl;
            return;

        }
        cout << "Failed To add a relation!" << endl;
        return;
    }
    cout << "Doctor or patient not found." << endl;
    return;
}


void deletefirst_relasi(listRelasi &L, adr_relasi &p) {
  if (first_relasi(L) == NULL) {
    p = NULL;
    cout << "Empty List" << endl;
  } else if (nextRel(first_relasi(L)) == NULL) {
    p = first_relasi(L);
    first_relasi(L) = NULL;
  } else {
    p = first_relasi(L);
    first_relasi(L) = nextRel(first_relasi(L));
    nextRel(p) = NULL;
  }
}

void deleteLast_relasi(listRelasi &L, adr_relasi &p) {
  if (first_relasi(L) == NULL) {
    p = NULL;
    cout << "Empty List" << endl;
  } else if (nextRel(first_relasi(L)) == NULL) {
    p = first_relasi(L);
    first_relasi(L) = NULL;
  } else {
    adr_relasi x = first_relasi(L);
    while (nextRel(nextRel(x)) != NULL) {
      x = nextRel(x);
    }
    p = nextRel(x);
    nextRel(x) = NULL;
  }
}

void deleteAfter_relasi(listRelasi &L, adr_relasi prec, adr_relasi &p) {
  if (first_relasi(L) == NULL) {
    p = NULL;
    cout << "empty list!" << endl;
  } else {
    nextRel(p) = nextRel(prec);
    nextRel(prec) = nextRel(p);
  }
}

void deleteRelasi(ListDoctor LD, ListPasien LP, listRelasi &LR, adr_relasi &deleteR,
             string namaDoctor, int id_pasien) {
  adr_doctor d = findDoctor(LD, namaDoctor);
  adr_pasien p = findPasienbyID(LP, id_pasien);
  adr_relasi  prec;
  deleteR = first_relasi(LR);
  if (d !=NULL && p !=NULL){
        while (deleteR != NULL) {
        if (dokter(deleteR) == d && pasien(deleteR) == p) {
          if (deleteR == first_relasi(LR)) {
            deletefirst_relasi(LR,deleteR);
          } else if (nextRel(deleteR) == NULL) {
            deleteLast_relasi(LR, deleteR);
          } else {
            deleteAfter_relasi(LR, prec, deleteR);
          };

          cout << "Relation Successfully Deleted." << endl;
          return;
        };

        deleteR = nextRel(deleteR);
      };
  }else{
    cout << "Data not found!" << endl;
  }

};


void showRelasi(listRelasi LR){
    int i = 1;
    adr_relasi r = first_relasi(LR);

  if (r == NULL) {
    cout << "empty list" << endl;
    return;
  };

  while(r!=NULL){
    cout << endl;
    cout <<  "Relation "<<i<<" :"<< endl;
    cout << "=======  Doctor  =======" << endl;
    cout << "Doctor's name  \t: " << infoDoc(dokter(r)).nama << endl;
    cout << "Doctor's Id    \t: " << infoDoc(dokter(r)).id_doctor  << endl;
    cout << "=======  Pasien  ========" << endl;
    cout << "Patient's name \t: " << infoPat(pasien(r)).nama << endl;
    cout << "Patient's Id   \t: " << infoPat(pasien(r)).id_pasien << endl;
    cout << "--------------------------------------------" << endl;
    r = nextRel(r);
    i++;
  }
  cout << endl;
}

void showPasienfromDokter(listRelasi &L, ListDoctor LD) {
  string dokter;
  cout<<"Enter the Doctor's Name: ";
  cin>> dokter;
  cout << "-----------------------------------------------------------"<< endl;
  adr_relasi p = first_relasi(L);
  adr_doctor caridokter = findDoctor(LD, dokter);
  if (caridokter!=NULL){
    cout<<"=====  Patient list by doctor named  "<<dokter<<" ====="<<endl;
      while (p != NULL) {
        if (dokter(p) == caridokter) {
          cout<<"======================================="<<endl;
          cout << "Name            \t: " << infoPat(pasien(p)).nama << endl;
          cout << "Address         \t: " << infoPat(pasien(p)).alamat << endl;
          cout << "Type of Disease \t: " << infoPat(pasien(p)).jenis_penyakit << endl;
          cout << "Specialist      \t: " << infoPat(pasien(p)).speciality << endl;
          cout << "Id              \t: " << infoPat(pasien(p)).id_pasien << endl;
          cout<<"======================================="<<endl;
        }
        p = nextRel(p);
    }
  }else{
    cout<<"Doctor isn't found!, please check your DOCTOR NAME"<<endl;
    cout << "-----------------------------------------------------------"<< endl;
  }
}

void showDokterfromPasien(listRelasi &L, ListPasien LP) {
  int id_pasien;
  cout<<"Enter the patient Id: ";
  cin >> id_pasien;
  cout << "-----------------------------------------------------------"<< endl;
  adr_relasi p = first_relasi(L);
  adr_pasien caripasien = findPasienbyID(LP, id_pasien);
  if(caripasien!=NULL){
      while (p != NULL) {
        if (pasien(p) == caripasien) {
          cout<<"======================================="<<endl;
          cout << "Name           \t: " << infoDoc(dokter(p)).nama << endl;
          cout << "Working Hours  \t: "<<infoDoc(dokter(p)).waktu << endl;
          cout << "Id             \t: " <<infoDoc(dokter(p)).id_doctor << endl;
          cout << "Specialist     \t: " <<infoDoc(dokter(p)).speciality << endl;
          cout<<"======================================="<<endl;
        }
        p = nextRel(p);
      }
  }else{
    cout<<"Patient isn't found!, please check your PATIENT ID"<<endl;
    cout << "-----------------------------------------------------------"<< endl;
  }
}

int countPasienParentbased(listRelasi &L, ListDoctor LD) {
  string dokter;
  int sumPasien = 0;
  cout<<"Enter the Doctor's name: ";
  cin >> dokter;
  adr_relasi p = first_relasi(L);
  adr_doctor d = findDoctor(LD, dokter);

  while (p != NULL) {
    if (dokter(p) == d) {
      sumPasien++;
    }
    p = nextRel(p);
  }
  return sumPasien;
}

int countDokterBasedONPasien(listRelasi &L, ListPasien LP) {
  int sumDokter = 0;
  int pasien;
  adr_relasi p = first_relasi(L);
  cout << "  Enter the Patient Id:  ";
  cin >> pasien;
  cout << endl;
  adr_pasien pat = findPasienbyID(LP, pasien);
  while (p != NULL) {
    if (pasien(p) == pat) {
      sumDokter++;
    }
    p = nextRel(p);
  }
  return sumDokter;
}

int countPasienTanpaDokter(listRelasi &L, ListPasien LP) {
  int sumTanpaDokter = 0;
  bool found = false;
  adr_pasien x = firstPat(LP);

  do {
    adr_relasi p = first_relasi(L);
    while (p != NULL) {
      if (pasien(p) == x) {
        found = true;
        break;
      }
      p = nextRel(p);
    }
    if (!found) {
      sumTanpaDokter++;
    }
    found = false;
    x = nextPat(x);
  } while (x != firstPat(LP));
  return sumTanpaDokter;
}

int countDokterTanpaPasien(listRelasi &L, ListDoctor LD) {
  int sumTanpaPasien = 0;
  bool found = false;
  adr_relasi p = first_relasi(L);
  adr_doctor d = firstDoc(LD);


  while (d != NULL) {
    while (p != NULL) {
      if (dokter(p) == d) {
        found = true;
        break;
      }
      p = nextRel(p);
    }
    if (!found) {
      sumTanpaPasien++;
    }
    found = false;
    d = nextDoc(d);
  }
  return sumTanpaPasien;
}

void showAllDoctorswithPatients(ListDoctor LD, listRelasi Lr) {
  bool found = false;
  adr_doctor d = firstDoc(LD);
  cout << "======[ Doctor's list with patients ]=======" << endl;
  if (d == NULL) {
    cout << "Data dokter kosong." << endl;
    return;
  };
  while (d != NULL) {
    cout << endl;
    cout << "==============[ Doctor's data ]===============" << endl;
    cout << "Name                   \t: " << infoDoc(d).nama << endl;
    cout << "Working hours          \t: "<< infoDoc(d).waktu<<endl;
    cout << "Id                     \t: " << infoDoc(d).id_doctor << endl;
    cout << "Specialist             \t: " << infoDoc(d).speciality << endl;

    adr_relasi r = first_relasi(Lr);
    if ( r == NULL) {
      cout << "There's no relation" << endl;
      cout << endl;
      cout << "============================================" << endl;
      return;
    };
    do {
      if (dokter(r) == d) {
        cout << "============[ Related Patient's Data  ]===========" << endl;
        cout << "Name            \t: " << infoPat(pasien(r)).nama << endl;
        cout << "Address         \t: " << infoPat(pasien(r)).alamat << endl;
        cout << "Id              \t: " << infoPat(pasien(r)).id_pasien<< endl;
        cout << "Type of Disease \t: " << infoPat(pasien(r)).jenis_penyakit << endl;
        cout << "Specialist      \t: " <<infoPat(pasien(r)).speciality << endl;
        cout << "-------------------------------------" << endl;
        found = true;
      };
      r = nextRel(r);
    } while (r != NULL);
    if (!found) {
      cout << "-------------------------------------" << endl;
      cout << "There are doctors who do not have a patient!" << endl;
    }
    found = false;
    d = nextDoc(d);
  };
  cout << endl;
  cout << "==============================================" << endl;
};

void showAllPatientswithDoctors(ListPasien LP, listRelasi Lr) {
  bool found = false;
  adr_pasien p = firstPat(LP);
  cout << "======[ Doctor's list with patients ]=======" << endl;
  if (p == NULL) {
    cout << "Empty patient data!" << endl;
    return;
  };
  do{
    cout << endl;
    cout << "==============[ Patient's Data ]===============" << endl;
    cout << "Name            \t: " <<infoPat(p).nama << endl;
    cout << "Address         \t: "<<infoPat(p).alamat<<endl;
    cout << "Id              \t: "<<infoPat(p).id_pasien << endl;
    cout << "Type of Disease \t: "<< infoPat(p).jenis_penyakit << endl;
    cout << "Specialist      \t: "<< infoPat(p).speciality << endl;
    adr_relasi r = first_relasi(Lr);
    if ( r == NULL) {
      cout << "There's no relation" << endl;
      cout << endl;
      cout << "============================================" << endl;
      return;
    };
    while  (r != NULL){
      if (pasien(r) ==  p) {
        cout << "============[ Related Doctor's Data ]===========" << endl;
        cout << "Name                   \t: " << infoDoc(dokter(r)).nama << endl;
        cout << "Working hours          \t: " << infoDoc(dokter(r)).waktu << endl;
        cout << "Id                     \t: " << infoDoc(dokter(r)).id_doctor << endl;
        cout << "Specialist             \t: " << infoDoc(dokter(r)).speciality << endl;
        found = true;
      };
      r = nextRel(r);
    };
    if (!found) {
      cout << "-------------------------------------" << endl;
      cout << "There are patients who do not have a doctor!" << endl;
    }
    found = false;
    p = nextPat(p);
  }while (p != firstPat(LP));
  cout << endl;
  cout << "==============================================" << endl;
};

void editRelasi(listRelasi &L, ListDoctor LD, ListPasien LP) {
  adr_relasi R = first_relasi(L);

  string NAMAdokter;

  int IDpasien;
  cout<<"Enter the Patient Id: ";
  cin >> IDpasien;
  adr_pasien p = findPasienbyID(LP, IDpasien);
  cout<<"Enter the Doctor's Name: ";
  cin >> NAMAdokter;
  adr_doctor d = findDoctor(LD, NAMAdokter);
  if (p == NULL || d == NULL) {
    cout << "data not found!" << endl;
    return;
  }else{
      while (R != NULL) {
        if (pasien(R) == p && dokter(R) == d) {
          cout<<"======================================="<<endl;
          cout << "Patient's name  \t: " << infoPat(pasien(R)).nama << endl;
          cout << "Patient's id    \t: " << infoPat(pasien(R)).id_pasien << endl;
          cout << "Doctor's name   \t: " << infoDoc(dokter(R)).nama << endl;
          cout  << "Doctor's Id     \t: " << infoDoc(dokter(R)).id_doctor << endl;
          cout<<"======================================="<<endl;
          cout<<"Enter a new Patient Id: ";
          cin >> IDpasien;
          p = findPasienbyID(LP, IDpasien);
          cout<<"Enter a new Doctor's name: ";
          cin >> NAMAdokter;
          d = findDoctor(LD, NAMAdokter);
          if (p != NULL && d != NULL) {
            pasien(R) = p;
            dokter(R) = d;
            cout<<"======================================="<<endl;
            cout << "Patient's name    \t: " << infoPat(pasien(R)).nama << endl;
            cout << "Patient's Id      \t: " << infoPat(pasien(R)).id_pasien << endl;
            cout << "Doctor's name     \t: " << infoDoc(dokter(R)).nama << endl;
            cout << "Doctor's Id       \t: " << infoDoc(dokter(R)).id_doctor << endl;
            cout<<"======================================="<<endl;
          } else {
            cout << "----------------------------------------------------------------"<< endl;
            cout << "Data not found, please check your PATIENT'S ID or DOCTOR'S NAME" << endl;
            cout << "----------------------------------------------------------------"<< endl;
          }
          return;
        }
        R = nextRel(R);
    }
  }
}
