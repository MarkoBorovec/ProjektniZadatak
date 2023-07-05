#ifndef DATATYPE_H
#define DATATYPE_H
typedef struct korisnik {
	int id;
	char ime[20];
	char prezime[20];
	char adresa[30];
	int brojMobitela;
	int aktivnost;
	int idVozilo;

}KORISNIK;

typedef struct vozilo {
	int id;
	char marka[20];
	char model[20];
	char vrsta[20];
	int godina_proizvodnje;
	int kilometri;
	char vrsta_goriva[10];
	char boja[20];
	int cijenaNajma;
	int dostupnost;
	int idKorisnik;
}VOZILO;

typedef struct racun {
	int id;
	int idKorisnik;
	int idVozilo;
	char marka;
	char model;
	char vrsta[20];
	int kilometri;
	char vrsta_goriva[10];
	char imeKorisnik[20];
	char prezimeKorisnik[20];
	int brojMobitela;
	int cijena;
	int posudba;
}RACUN;
#endif //DATATYPE_H
