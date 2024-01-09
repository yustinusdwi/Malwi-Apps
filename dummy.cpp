#include "rumahsakit.h"
#include <iostream>

using namespace std;

void insertDummyDoc(ListDoctor &LD, infotypeDoc &dataBaruD,adr_doctor newDoctor, string nama, string waktu, int id, string speciality){
    dataBaruD.nama = nama;
    dataBaruD.waktu = waktu;
    dataBaruD.id_doctor = id;
    dataBaruD.speciality = speciality;
    newDoctor = createElementDoctor(dataBaruD);
    insertLastDoc(LD, newDoctor);
}

//dummy dokter
void dataDummyDoc(ListDoctor &LD, infotypeDoc &dataBaruD, adr_doctor newDoctor){
// data1
    insertDummyDoc(LD, dataBaruD, newDoctor, "ikmal", "10.00", 1301220078, "Penyakit_Dalam");

//data2
    insertDummyDoc(LD, dataBaruD, newDoctor, "widy", "15.00", 1301220001, "Orthopedi");

//data3
    insertDummyDoc(LD, dataBaruD, newDoctor, "lamki", "12.00", 1301220087, "Kulit");
//data4
    insertDummyDoc(LD, dataBaruD, newDoctor, "ydiw", "18.00", 1301220002, "Mata");
}

//insert dummy pasien
void insertDummyPat(ListPasien &LP, infotypePat &dataBaruP, adr_pasien newPatient, string nama, int idP, string alamat, string jenisP, string spesialis){
    dataBaruP.nama = nama;
    dataBaruP.id_pasien = idP;
    dataBaruP.alamat = alamat;
    dataBaruP.jenis_penyakit = jenisP;
    dataBaruP.speciality = spesialis;
    newPatient = createElemenP(dataBaruP);
    InsertDataPasien(LP, newPatient);
}
//dummy pasien
void dataDummyPat(ListPasien &LP, infotypePat &dataBaruP, adr_pasien newPatient){
// data1
    insertDummyPat(LP, dataBaruP, newPatient, "Oddie", 12345, "Jl_ruby","Katarak", "Mata");

//data2
    insertDummyPat(LP, dataBaruP, newPatient, "Orrie", 12377, "Jl_diamond","Jerawat", "Kulit");

//data3
    insertDummyPat(LP, dataBaruP, newPatient, "Ollie", 12368, "Jl_sapphire","Patah_tulang", "Orthopedi");

//data4
    insertDummyPat(LP, dataBaruP, newPatient, "Ossie", 12378, "Jl_Emerald","Jantung", "Penyakit_dalam");

//data5
    insertDummyPat(LP, dataBaruP, newPatient, "Ovvie", 12399, "Jl_kenangan","Fungal", "Kulit");
}


//dummy relasi
void DummyRelasi(listRelasi &LR, ListDoctor LD, ListPasien LP){
    tambahRelasi(LR, LD, LP,"ikmal", 12378);
    tambahRelasi(LR, LD, LP,"widy", 12368);
    tambahRelasi(LR, LD, LP,"lamki", 12377);
    tambahRelasi(LR, LD, LP,"ydiw", 12345);
}
