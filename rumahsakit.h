#ifndef RUMAHSAKIT_H
#define RUMAHSAKIT_H
#include <iostream>

// define parent
#define firstDoc(L) L.firstDoc
#define lastDoc(L) L.lastDoc
#define infoDoc(p) p->infoDoc
#define nextDoc(p) p->nextDoc
#define prevDoc(p) p->prevDoc

// define patient
#define firstPat(L) L.firstPat
#define lastPat(L) L.lastPat
#define infoPat(q) q->infoPat
#define nextPat(q) q->nextPat
#define prevPat(q) q->prevPat

// define relation
#define nextRel(R) R->nextRel
#define first_relasi(R) R.first_relasi
#define pasien(R) R->pasien
#define dokter(R) R->dokter

using namespace std;

//-------------------------------------------------------------//
// deklarasi list dokter (parent)
struct doctor {
  string nama, speciality, waktu;
  int id_doctor;
};

typedef doctor infotypeDoc;

typedef struct doctorElement *adr_doctor;

struct doctorElement {
  infotypeDoc infoDoc;
  adr_doctor nextDoc, prevDoc;
};

struct ListDoctor {
  adr_doctor firstDoc, lastDoc;
};

//-------------------------------------------------------------//
// deklarasi list pasien (child)

typedef struct elem_pasien *adr_pasien;

struct pasien {
  string nama, alamat, jenis_penyakit, speciality;
  int id_pasien;
};

typedef pasien infotypePat;

struct elem_pasien {
  adr_pasien prevPat, nextPat;
  infotypePat infoPat;
};

struct ListPasien {
  adr_pasien firstPat, lastPat;
};

//-------------------------------------------------------------//
// deklarasi list relasi
typedef struct elm_relasi *adr_relasi;

struct elm_relasi {
  adr_pasien pasien;
  adr_doctor dokter;
  adr_relasi nextRel;
};

struct listRelasi {
  adr_relasi first_relasi;
};

//-------------------------------------------------------------//
// funtion dan procedure dokter (parent)

void createListDoctor(ListDoctor &L);
adr_doctor createElementDoctor(infotypeDoc x);
void insertLastDoc(ListDoctor &L, adr_doctor p);
void deleteFirstDoc(ListDoctor &L, adr_doctor &temp);
void deleteLastDoc(ListDoctor &L, adr_doctor &temp);
void deleteAfterDoc(ListDoctor &L, adr_doctor &temp, adr_doctor prec);
void deleteDokterbyName(ListDoctor &L, adr_doctor &dataOut,string nama,adr_doctor Prec);
adr_doctor findDoctor(ListDoctor &L, string doctorname);
void showDoctor(ListDoctor L);

//-------------------------------------------------------------//
// funtion dan procedure pasien (child)

void createListPasien(ListPasien &L);
adr_pasien createElemenP(infotypePat dataP);
void InsertDataPasien(ListPasien &L, adr_pasien dataBaru);
void DeleteLastPat(ListPasien &L, adr_pasien dataOut);
void DeleteFirstPat(ListPasien &L, adr_pasien dataOut);
void DeleteAfterPat(ListPasien &L, adr_pasien prec, adr_pasien dataOut);
void deletePasienbyID(ListPasien &L, adr_pasien prec, adr_pasien dataOut,
                      int id);
void showDataPasien(ListPasien L);
void countPasien(ListPasien L);
adr_pasien findPasienbyID(ListPasien L, int ID);

//-------------------------------------------------------------//
// funtion dan procedure rumahSakit (relasi)


void createList_relasi(listRelasi &L);
adr_relasi createElementRelasi(adr_pasien pasien, adr_doctor dokter);
void tambahRelasi(listRelasi &LR,ListDoctor LD, ListPasien LP, string doctorName, int id_pasien);
void deletefirst_relasi(listRelasi &L, adr_relasi &p);
void deleteLast_relasi(listRelasi &L, adr_relasi &p);
void deleteAfter_relasi(listRelasi &L, adr_relasi prec, adr_relasi &p);
void deleteRelasi(ListDoctor LD, ListPasien LP, listRelasi &LR, adr_relasi &deleteR, string namaDoctor, int id_pasien);
adr_relasi findElm_relasi(listRelasi &L, string speciality);
void showRelasi(listRelasi LR);
void showPasienfromDokter(listRelasi &L, ListDoctor LD);
void showDokterfromPasien(listRelasi &L, ListPasien LP);
int countPasienParentbased(listRelasi &L, ListDoctor LD);
int countDokterBasedONPasien(listRelasi &L, ListPasien LP);
int countPasienTanpaDokter(listRelasi &L, ListPasien LP);
int countDokterTanpaPasien(listRelasi &L, ListDoctor LD);
void showAllPatientswithDoctors(ListPasien LP, listRelasi Lr);
void showAllDoctorswithPatients(ListDoctor LD, listRelasi Lr);
void editRelasi(listRelasi &L, ListDoctor LD, ListPasien LP);

// function dan precedure menu
int mainMenu();
int menuDoctor();
void clearScreen();
int menuPatient();
int menuRelation();
//void inputOption(int &option);

//procedure data dummy

void insertDummyDoc(ListDoctor &LD, infotypeDoc &databaruD,adr_doctor newDoctor, string nama, string waktu, int id, string speciality);
void dataDummyDoc(ListDoctor &LD, infotypeDoc &dataBaruD, adr_doctor newDoctor);
void insertDummyPat(ListPasien &LP, infotypePat &dataBaruP, adr_pasien newPatient, string nama, int idP, string alamat, string jenisP, string spesialis);
void dataDummyPat(ListPasien &LP, infotypePat &dataBaruP, adr_pasien newPatient);
void DummyRelasi(listRelasi &LR, ListDoctor LD, ListPasien LP);
#endif
