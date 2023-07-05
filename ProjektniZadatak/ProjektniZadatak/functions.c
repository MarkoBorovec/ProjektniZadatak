#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"
 int brojKorisnika = 0;
 int brojAutomobila = 0;


void kreiranjeDatoteke_Korisnici(const char* const datKorisnik) {
	FILE* pF = fopen(datKorisnik, "w");
	if (pF == NULL) {
		perror("Kreiranje datoteke korisnici.txt");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojKorisnika, sizeof(int), 1, pF);
	fclose(pF);
}

void kreiranjeDatoteke_Automobili(const char* const datVozilo) {
	FILE* pF = fopen(datVozilo, "w");
	if (pF == NULL) {
		perror("Kreiranje datoteke automobili.txt");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojAutomobila, sizeof(int), 1, pF);
	fclose(pF);
}


void dodajKorisnika(const char* const datKorisnik) {
	FILE* pF = fopen(datKorisnik, "r+");
	if (pF == NULL) {
		perror("Dodavanje korisnika u datoteku korisnici.txt");
		exit(EXIT_FAILURE);
	}
	fread(&brojKorisnika, sizeof(int), 1, pF);
	printf("brojKorisnika: %d\n", brojKorisnika);
	KORISNIK temp = { 0 };
	temp.id = brojKorisnika + 1;
	getchar();
	printf("Unesite ime Korisnika!\n");
	scanf("%19[^\n]", temp.ime);
	printf("Unesite prezime Korisnika!\n");
	getchar();
	scanf("%19[^\n]", temp.prezime);
	printf("Unesite adresu korisnika!\n");
	getchar();
	scanf("%29[^\n]", temp.adresa);
	printf("Unesite broj telefona \n");
	getchar();
	scanf("%d", &temp.brojMobitela);
	temp.aktivnost = 0;
	temp.idVozilo = 0;
	fseek(pF, sizeof(KORISNIK) * brojKorisnika, SEEK_CUR);
	fwrite(&temp, sizeof(KORISNIK), 1, pF);
	rewind(pF);
	brojKorisnika++;
	fwrite(&brojKorisnika, sizeof(int), 1, pF);
	fclose(pF);
}


void dodajVozilo(const char* const datVozilo) {
	FILE* pF = fopen(datVozilo, "r+");
	if (pF == NULL) {
		perror("Dodavanje vozila u datoteku automobili.txt");
		exit(EXIT_FAILURE);
	}
	fread(&brojAutomobila, sizeof(int), 1, pF);
	printf("brojAutomobila: %d\n", brojAutomobila);
	VOZILO temp = { 0 };
	temp.id = brojAutomobila+1;
	getchar();
	printf("Unesite marku vozila!\n");
	scanf("%19[^\n]", temp.marka);
	printf("Unesite model vozila \n");
	getchar();
	scanf("%19[^\n]", temp.model);
	printf("Unesite vrstu vozila(coupe, karavan, limuzina, SUV)\n");
	getchar();
	scanf("%19[^\n]", temp.vrsta);
	printf("Unesite godinu prozivodnje auta\n");
	scanf("%d", &temp.godina_proizvodnje);
	printf("Unesite broj kilometara koje vozilo ima\n");
	scanf("%d", &temp.kilometri);
	printf("unesi vrstu goriva \n");
	getchar();
	scanf("%9[^\n]]", temp.vrsta_goriva);
	printf("unesi boju vozila \n");
	getchar();
	scanf("%19[^\n]]", temp.boja);
	printf("Unesite cijenu posudbe automobila po danu (EUR) \n");
	scanf("%d", &temp.cijenaNajma);
	temp.idKorisnik = 0;
	temp.dostupnost = 0;
	fseek(pF, sizeof(VOZILO) * brojAutomobila, SEEK_CUR);
	fwrite(&temp, sizeof(VOZILO), 1, pF);
	rewind(pF);
	brojAutomobila++;
	fwrite(&brojAutomobila, sizeof(int), 1, pF);
	fclose(pF);
}

KORISNIK* ucitavanjeKorisnika(const char* const datKorisnik) {
	FILE* fp = fopen(datKorisnik, "r");

	if (fp == NULL) {
		perror("Ucitavanje korisnika");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojKorisnika, sizeof(int), 1, fp);

	KORISNIK* poljeKorisnika = (KORISNIK*)calloc(brojKorisnika, sizeof(KORISNIK));

	if (poljeKorisnika == NULL) {
		perror("Zauzimanje memorije za polje korisnika");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeKorisnika, sizeof(KORISNIK), brojKorisnika, fp);

	fclose(fp);

	return poljeKorisnika;
}
 VOZILO* ucitavanjeVozila(const char* const datVozilo) {

	FILE* fp = fopen(datVozilo, "r");

	if (fp == NULL) {
		perror("Ucitavanje Vozila");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojAutomobila, sizeof(int), 1, fp);

	VOZILO* poljeVozila = (VOZILO*)calloc(brojAutomobila, sizeof(VOZILO));

	if (poljeVozila == NULL) {
		perror("Zauzimanje memorije za polje Vozila");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeVozila, sizeof(VOZILO), brojAutomobila, fp);

	fclose(fp);

	return poljeVozila;
}

void ispisivanjeKorisnika(const KORISNIK* const poljeKorisnika) {

	if (brojKorisnika == 0) {
		printf("Polje clanova prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojKorisnika; i++) {
		printf("ID: %d  Ime: %s  Prezime: %s  Adresa: %s  Broj mobitela: %d  Posuduje li bilo koje vozilo: %s  ID posudenog vozila: %d\n\n",
			(poljeKorisnika + i)->id,
			(poljeKorisnika + i)->ime,
			(poljeKorisnika + i)->prezime,
			(poljeKorisnika + i)->adresa,
			(poljeKorisnika + i)->brojMobitela,
			(poljeKorisnika + i)->aktivnost == 1 ? "Da" : "Ne",
			(poljeKorisnika + i)->idVozilo);
	}
}

void ispisivanjeVozila(const VOZILO* const poljeVozila) {

	if (brojAutomobila == 0) {
		printf("Polje vozila prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojAutomobila; i++) {
		printf("ID: %d  Marka: %s  Model: %s Vrsta: %s Godina proizvodnje: %d.  Broj kilometara: %d Vrsta goriva: %s Boja: %s  Cijena najma: %d EUR  Posudeno vozilo: %s \n\n",
			(poljeVozila + i)->id,
			(poljeVozila + i)->marka,
			(poljeVozila + i)->model,
			(poljeVozila + i)->vrsta,
			(poljeVozila + i)->godina_proizvodnje,
			(poljeVozila + i)->kilometri,
			(poljeVozila + i)->vrsta_goriva,
			(poljeVozila + i)->boja,
			(poljeVozila + i)->cijenaNajma,
			(poljeVozila + i)->dostupnost == 1 ? "Da" : "Ne");
	}

}

void zamjena(VOZILO* const veci, VOZILO* const manji) {
	VOZILO temp = { 0 };
	temp = *manji;
	*manji = *veci;
	*veci = temp;
}

const VOZILO* sortitajPoCijeni(const VOZILO* poljeVozila) {
	int min = -1;
	for (int i = 0; i < brojAutomobila - 1; i++) {
		min = i;
		for (int j = i + 1; j < brojAutomobila; j++) {
			if ((poljeVozila + j)->cijenaNajma < (poljeVozila + min)->cijenaNajma) {
				min = j;
			}
		}
		zamjena((VOZILO*)(poljeVozila + i), (VOZILO*)(poljeVozila + min));
	}
	return poljeVozila;
}
void ispisisortiraneautomobile(const VOZILO* poljeVozila) {

	if (brojAutomobila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	int i;


	poljeVozila = sortitajPoCijeni(poljeVozila);


	for (i = 0; i < brojAutomobila; i++) {
		printf("ID: %d  Marka: %s  Model: %s Vrsta: %s Godina proizvodnje: %d.  Broj kilometara: %d Vrsta goriva: %s Boja: %s  Cijena najma: %d EUR  Posudeno vozilo: %s \n\n",
			(poljeVozila + i)->id,
			(poljeVozila + i)->marka,
			(poljeVozila + i)->model,
			(poljeVozila + i)->vrsta,
			(poljeVozila + i)->godina_proizvodnje,
			(poljeVozila + i)->kilometri,
			(poljeVozila + i)->vrsta_goriva,
			(poljeVozila + i)->boja,
			(poljeVozila + i)->cijenaNajma,
			(poljeVozila + i)->dostupnost == 1 ? "Da" : "Ne");
	}
}


void pronadiKorisnikaPrezime(KORISNIK* const poljeKorisnika) {

	if (brojKorisnika == 0) {
		printf("Polje korisnika prazno\n");
		return;
	}

	char trazenoPrezime[25];

	printf("Unesite prezime koje trazite: ");
	getchar();
	scanf("%24[^\n]", trazenoPrezime);

	int i, counter = 0;

	for (i = 0; i < brojKorisnika; i++) {

		if (strcmp(trazenoPrezime, (poljeKorisnika + i)->prezime) == 0) {

			printf("ID: %d  Ime: %s  Prezime: %s  Adresa: %s  Broj mobitela: %d  Posuduje li bilo koje vozilo: %s  ID posudenog vozila: %d\n\n",
				(poljeKorisnika + i)->id,
				(poljeKorisnika + i)->ime,
				(poljeKorisnika + i)->prezime,
				(poljeKorisnika + i)->adresa,
				(poljeKorisnika + i)->brojMobitela,
				(poljeKorisnika + i)->aktivnost == 1 ? "Da" : "Ne",
				(poljeKorisnika + i)->idVozilo);
			counter++;
		}
	}

	if (counter == 0) {
		printf("Nema korisnika s unesenim prezimenom\n");
		return;
	}
}

void pronadiAutomobilPoMarki(VOZILO* poljeVozila) {

	if (brojAutomobila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	char trazenaMarka[25];

	printf("Unesite marku koje trazite: ");
	getchar();
	scanf("%24[^\n]", trazenaMarka);

	int i, counter = 0;

	printf("\n");

	for (i = 0; i < brojAutomobila; i++) {

		if (strcmp(trazenaMarka, (poljeVozila + i)->marka) == 0) {

			printf("ID: %d  Marka: %s  Model: %s Vrsta: %s Godina proizvodnje: %d.  Broj kilometara: %d Vrsta goriva: %s Boja: %s  Cijena najma: %d EUR  Posudeno vozilo: %s \n\n",
				(poljeVozila + i)->id,
				(poljeVozila + i)->marka,
				(poljeVozila + i)->model,
				(poljeVozila + i)->vrsta,
				(poljeVozila + i)->godina_proizvodnje,
				(poljeVozila + i)->kilometri,
				(poljeVozila + i)->vrsta_goriva,
				(poljeVozila + i)->boja,
				(poljeVozila + i)->cijenaNajma,
				(poljeVozila + i)->dostupnost == 1 ? "Da" : "Ne");

			counter++;
		}
	}
	if (counter == 0) {
		printf("Nema automobila te marke\n");
		return;
	}
}



void ispisiKorisnikeKojiIznajmljuju(KORISNIK* const poljeKorisnika) {

	if (brojKorisnika == 0) {
		printf("Polje korisnika prazno");
		return;
	}

	int i, counter = 0;

	printf("Korisnici koji trenutno iznajmljuju automobil: \n");

	for (i = 0; i < brojKorisnika; i++) {

		if ((poljeKorisnika + i)->aktivnost == 1) {
			printf("ID: %d  Ime: %s  Prezime: %s  Adresa: %s  Broj mobitela: %d  ID posudenog vozila: %d\n\n",
				(poljeKorisnika + i)->id,
				(poljeKorisnika + i)->ime,
				(poljeKorisnika + i)->prezime,
				(poljeKorisnika + i)->adresa,
				(poljeKorisnika + i)->brojMobitela,
				(poljeKorisnika + i)->idVozilo);

			counter;
		}
	}

	if (counter == 0) {
		printf("Trenutno nema korisnika koji iznajmljuju automobil\n");
	}
}

void ispisiDostupnaVozila(VOZILO* const poljeVozila) {

	if (brojAutomobila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	int i, counter = 0;

	printf("Trenutno slobodni automobili: \n");

	for (i = 0; i < brojAutomobila; i++) {

		if ((poljeVozila + i)->dostupnost== 0) {
			printf("ID: %d  Marka: %s  Model: %s Vrsta: %s Godina proizvodnje: %d.  Broj kilometara: %d Vrsta goriva: %s Boja: %s  Cijena najma: %d EUR  \n\n",
				(poljeVozila + i)->id,
				(poljeVozila + i)->marka,
				(poljeVozila + i)->model,
				(poljeVozila + i)->vrsta,
				(poljeVozila + i)->godina_proizvodnje,
				(poljeVozila + i)->kilometri,
				(poljeVozila + i)->vrsta_goriva,
				(poljeVozila + i)->boja,
				(poljeVozila + i)->cijenaNajma);

			counter++;
		}
	}

	if (counter == 0) {
		printf("Nazalost trenutno nema slobodnih automobila\n");
	}
}

void azuriranjeKorisnika(KORISNIK* poljeKorisnika, const char* const datKorisnik) {
	if (brojKorisnika == 0) {
		printf("Polje korisnika prazno\n");
		return;
	}

	FILE* fp = fopen(datKorisnik, "r+");

	if (fp == NULL) {
		perror("Azuriranje korisnika");
		exit(EXIT_FAILURE);
	}

	int trazeniId;

	printf("Unesite ID korisnika kojeg zelite azurirati: ");

	do {
		scanf("%d", &trazeniId);

		if (trazeniId < 1 || trazeniId > brojKorisnika) {
			printf("Korisnik s unesenim ID-em ne postoji. Unesite ID koji postoji: ");
		}
	} while (trazeniId < 1 || trazeniId > brojKorisnika);

	KORISNIK temp = { 0 };

	temp.id = trazeniId;
	getchar();


	printf("Unesite ime korisnika (trenutno: %s): ", (poljeKorisnika + trazeniId - 1)->ime);
	scanf("%19[^\n]", temp.ime);
	getchar();

	printf("Unesite prezime korisnika (trenutno %s): ", (poljeKorisnika + trazeniId - 1)->prezime);
	scanf("%19[^\n]", temp.prezime);
	getchar();

	printf("Unesite adresu korisnika (trenutno %s): ", (poljeKorisnika + trazeniId - 1)->adresa);
	scanf("%29[^\n]", temp.adresa);
	getchar();

	printf("Unesite starost korisnika (trenutno %d): ", (poljeKorisnika + trazeniId - 1)->brojMobitela);
	scanf("%d", &temp.brojMobitela);

	temp.aktivnost = (poljeKorisnika + trazeniId - 1)->aktivnost;
	temp.idVozilo = (poljeKorisnika + trazeniId - 1)->idVozilo;

	fseek(fp, sizeof(int), SEEK_SET);
	fseek(fp, sizeof(KORISNIK) * (trazeniId - 1), SEEK_CUR);
	fwrite(&temp, sizeof(KORISNIK), 1, fp);

	printf("Korisnik uspjesno azuriran\n");

	fclose(fp);
}

void azuriranjeVozila(VOZILO* poljeVozila, const char* const datVozilo) {
	if (brojAutomobila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	FILE* fp = fopen(datVozilo, "r+");

	if (fp == NULL) {
		perror("Azuriranje automobila");
		exit(EXIT_FAILURE);
	}

	int trazeniId;

	printf("Unesite ID automobila kojeg zelite azurirati: ");

	do {
		scanf("%d", &trazeniId);

		if (trazeniId < 1 || trazeniId > brojAutomobila) {
			printf("Automobil s unesenim ID-em ne postoji. Unesite ID koji postoji: ");
		}
	} while (trazeniId < 1 || trazeniId > brojAutomobila);

	VOZILO temp = { 0 };

	temp.id = trazeniId;

	getchar();
	printf("Unesite marku automobila (trenutno: %s): ", (poljeVozila + trazeniId - 1)->marka);
	scanf("%19[^\n]", temp.marka);
	getchar();

	printf("Unesite model automobila (trenutno: %s): ", (poljeVozila + trazeniId - 1)->model);
	scanf("%19[^\n]", temp.model);
	getchar();

	printf("Unesite vrstu automobila (trenutno: %s): ", (poljeVozila + trazeniId - 1)->vrsta);
	scanf("%19[^\n]", temp.vrsta);
	getchar();

	printf("Unesite godinu proizvodnje automobila (trenutno: %d.): ", (poljeVozila + trazeniId - 1)->godina_proizvodnje);
	scanf("%d", &temp.godina_proizvodnje);
	getchar();

	printf("Unesite kilometre koje vozilo ima (trenutno: %d.): ", (poljeVozila + trazeniId - 1)->kilometri);
	scanf("%d", &temp.kilometri);
	getchar();

	printf("Unesite vrstu goriva koje vozilo koristi(trenutno %s): ", (poljeVozila + trazeniId - 1)->vrsta_goriva);
	scanf("%9[^\n]", temp.vrsta_goriva);
	getchar();

	printf("Unesite boju automobila (trenutno %s): ", (poljeVozila + trazeniId - 1)->boja);
	scanf("%19[^\n]", temp.boja);
	getchar();

	printf("Unesite cijenu automobila po danu (EUR) (trenutno: %d EUR): ", (poljeVozila + trazeniId - 1)->cijenaNajma);
	scanf("%d", &temp.cijenaNajma);

	temp.idKorisnik = (poljeVozila + trazeniId - 1)->idKorisnik;
	temp.dostupnost = (poljeVozila + trazeniId - 1)->dostupnost;

	fseek(fp, sizeof(int), SEEK_SET);
	fseek(fp, sizeof(VOZILO) * (trazeniId - 1), SEEK_CUR);
	fwrite(&temp, sizeof(VOZILO), 1, fp);

	printf("Automobil uspjesno azuriran\n");

	fclose(fp);
}

void brisanjeKorisnika(KORISNIK* const poljeKorisnika, const char* const datKorisnik) {

	if (brojKorisnika == 0) {
		printf("Polje korisnika prazno\n");
		return;
	}

	FILE* fp = fopen(datKorisnik, "r+");

	if (fp == NULL) {
		perror("Brisanje korisnika");
		exit(EXIT_FAILURE);
	}

	fseek(fp, sizeof(int), SEEK_CUR);

	int i, trazeniId;

	printf("Unesite ID korisnika kojeg zelite obrisati: ");

	do {
		scanf("%d", &trazeniId);
		if (trazeniId < 1 || trazeniId > brojKorisnika) {
			printf("Korisnik s unesenim ID-em ne postoji. Unesite ID koji postoji: ");
		}
		if ((poljeKorisnika + trazeniId - 1)->aktivnost == 1) {
			printf("Korisnik s unesenim ID-em trenutno posuduje automobil i nemoguce ga je obrisati prije nego li ga vrati.\n");
			return;
		}
	} while (trazeniId < 1 || trazeniId > brojKorisnika || (poljeKorisnika + trazeniId - 1)->aktivnost == 1);

	KORISNIK* pomocnoPolje = (KORISNIK*)calloc(brojKorisnika - 1, sizeof(KORISNIK));

	int counter = 0;

	for (i = 0; i < brojKorisnika; i++) {

		if (trazeniId != (poljeKorisnika + i)->id) {
			*(pomocnoPolje + counter) = *(poljeKorisnika + i);

			if ((pomocnoPolje + counter)->id > trazeniId) {
				(pomocnoPolje + counter)->id -= 1;
			}

			fwrite((pomocnoPolje + counter), sizeof(KORISNIK), 1, fp);
			counter++;
		}
	}

	free(pomocnoPolje);
	pomocnoPolje = NULL;

	rewind(fp);

	fwrite(&counter, sizeof(int), 1, fp);
	fclose(fp);

	printf("Korisnik je uspjesno obrisan\n");
}

void brisanjeVozila(VOZILO* const poljeVozila, const char* const datVozilo) {
	if (brojAutomobila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	FILE* fp = fopen(datVozilo, "r+");

	if (fp == NULL) {
		perror("Brisanje automobila");
		exit(EXIT_FAILURE);
	}

	fseek(fp, sizeof(int), SEEK_CUR);

	int i, trazeniId;

	printf("Unesite ID automobila kojeg zelite obrisati: ");

	do {
		scanf("%d", &trazeniId);
		if (trazeniId < 1 || trazeniId > brojAutomobila) {
			printf("Automobil s unesenim ID-em ne postoji. Unesite ID koji postoji: ");
		}
		if ((poljeVozila + trazeniId - 1)->dostupnost == 1) {
			printf("Automobil s unesenim ID-em je trenutno posuden i nemoguce ga je obrisati u ovom trenutku.");
		}
	} while (trazeniId < 1 || trazeniId > brojAutomobila || (poljeVozila + trazeniId - 1)->dostupnost == 1);

	VOZILO* pomocnoPolje = (VOZILO*)calloc(brojAutomobila - 1, sizeof(VOZILO));

	int counter = 0;

	for (i = 0; i < brojAutomobila; i++) {
		if (trazeniId != (poljeVozila + i)->id) {
			*(pomocnoPolje + counter) = *(poljeVozila + i);

			if ((pomocnoPolje + counter)->id > trazeniId) {
				(pomocnoPolje + counter)->id -= 1;
			}

			fwrite((pomocnoPolje + counter), sizeof(VOZILO), 1, fp);
			counter++;
		}
	}

	free(pomocnoPolje);
	pomocnoPolje = NULL;

	rewind(fp);

	fwrite(&counter, sizeof(int), 1, fp);
	fclose(fp);

	printf("Automobil je uspjesno obrisan\n");
}



void brisanjeDatoteke_Korisnik(const char* datKorisnik)
{
	FILE* fp = fopen(datKorisnik, "r");
	int status;
	if (fp == NULL) {
		printf("Datoteka %s ne postoji na disku\n", datKorisnik);
		return;
	}
	else {
		fclose(fp);
	}
	status = remove(datKorisnik);
	if (status == 0) {
		printf("Uspjesno obrisana datoteka!\n");
	}
	else {
		printf("Nemogucnost brisanja datoteke!\n");
	}
}


void brisanjeDatoteke_Vozilo(const char* datVozilo)
{
	FILE* fp = fopen(datVozilo, "r");
	int status;
	if (fp == NULL) {
		printf("Datoteka %s ne postoji na disku\n", datVozilo);
		return;
	}
	else {
		fclose(fp);
	}
	status = remove(datVozilo);
	if (status == 0) {
		printf("Uspjesno obrisana datoteka!\n");
	}
	else {
		printf("Nemogucnost brisanja datoteke!\n");
	}
}

void iznajmljivanjeVozila(KORISNIK* poljeKorisnika, VOZILO* poljeVozila, const char* const datKorisnik, const char* const datVozilo, const char* const racun) {

	if (brojKorisnika == 0) {
		printf("Polje korisnika prazno\n");
		return;
	}

	if (poljeVozila == 0) {
		printf("Polje automobila prazno\n");
		return;
	}

	FILE* fpk = fopen(datKorisnik, "r+");

	if (fpk == NULL) {
		perror("Ucitavanje korisnika");
		exit(EXIT_FAILURE);
	}

	FILE* fpa = fopen(datVozilo, "r+");

	if (fpa == NULL) {
		perror("Ucitavanje automobila");
		exit(EXIT_FAILURE);
	}
	const char* const datRacun = racun;
	FILE* fpr = fopen(datRacun, "w+");

	if (fpr == NULL) {
		printf("Pogreska pri stvaranju racuna");
		return;
	}


	int trazeniClan;

	ispisivanjeKorisnika(poljeKorisnika);

	printf("\nUnesite ID clana koji zeli posuditi automobil: ");

	do {
		scanf("%d", &trazeniClan);

		if (trazeniClan < 1 || trazeniClan > brojKorisnika) {
			printf("Korisnik s unesenim ID-om ne postoji, unesite ispravan ID: ");
		}
	} while (trazeniClan < 1 || trazeniClan > brojKorisnika);

	printf("Odaberite jedan od slobodnih automobila\n");

	ispisiDostupnaVozila(poljeVozila);

	int trazeniAutomobil = 0;

	printf("Unesite ID automobila kojeg zelite iznajmiti: ");

	do {
		scanf("%d", &trazeniAutomobil);

		if ((poljeVozila + trazeniAutomobil)->dostupnost== 1) {
			printf("Odabrali ste automobil koji je trenutno zauzet , odaberite neki drugi automobil: ");
			ispisiDostupnaVozila(poljeVozila);
		}

		if (trazeniAutomobil < 1 || trazeniAutomobil > brojAutomobila) {
			printf("Automobil s unesenim ID-om ne postoji, unesite ispravan ID: ");
			ispisiDostupnaVozila(poljeVozila);
		}
	} while ((poljeVozila + trazeniAutomobil)->dostupnost == 1 || trazeniAutomobil < 1 || trazeniAutomobil > brojAutomobila);

	(poljeKorisnika + trazeniClan - 1)->aktivnost = 1;
	(poljeKorisnika + trazeniClan - 1)->idVozilo = trazeniAutomobil;

	(poljeVozila + trazeniAutomobil - 1)->dostupnost = 1;
	(poljeVozila + trazeniAutomobil - 1)->idKorisnik = trazeniClan;

	rewind(fpk);
	fseek(fpk, sizeof(int) * 1, SEEK_CUR);
	fseek(fpk, sizeof(KORISNIK) * (trazeniClan - 1), SEEK_CUR);
	fwrite((poljeKorisnika + trazeniClan - 1), sizeof(KORISNIK), 1, fpk);

	rewind(fpa);
	fseek(fpa, sizeof(int) * 1, SEEK_CUR);
	fseek(fpa, sizeof(VOZILO) * (trazeniAutomobil - 1), SEEK_CUR);
	fwrite((poljeVozila + trazeniAutomobil - 1), sizeof(VOZILO), 1, fpa);

	fclose(fpa);
	fclose(fpk);

	int brojDana;

	printf("Koliko dana zelite posudivati automobil (max 30 dana): ");

	do {
		scanf("%d", &brojDana);

		if (brojDana < 1 || brojDana > 30) {
			printf("Ne mozete posudivati automobil toliko dana. Unesite manji broj dana (max 30): \n");
		}
	} while (brojDana < 1 || brojDana > 30);

	int brojRacuna = 0 + (int)rand() / RAND_MAX * (99999 - 0);

	fprintf(fpr, "\t\t RENT-A-CAR \n\n");
	fprintf(fpr, "===================================================\n\n");
	fprintf(fpr, "Racun broj: %d\n", brojRacuna);
	fprintf(fpr, "===================================================\n\n");
	fprintf(fpr, "Ime : %s\n", (poljeKorisnika + trazeniClan - 1)->ime);
	fprintf(fpr, "Prezime : %s\n", (poljeKorisnika + trazeniClan - 1)->prezime);
	fprintf(fpr, "Adresa : %s\n", (poljeKorisnika + trazeniClan - 1)->adresa);
	fprintf(fpr, "Broj mobitela: %d\n", (poljeKorisnika + trazeniClan - 1)->brojMobitela);
	fprintf(fpr, "ID automobila : %d\n", (poljeVozila + trazeniAutomobil - 1)->id);
	fprintf(fpr, "Marka : %s\n", (poljeVozila + trazeniAutomobil - 1)->marka);
	fprintf(fpr, "Model : %s \n", (poljeVozila + trazeniAutomobil - 1)->model);
	fprintf(fpr, "Vrsta : %s \n", (poljeVozila + trazeniAutomobil - 1)->vrsta);
	fprintf(fpr, "Vrsta goriva : %s \n", (poljeVozila + trazeniAutomobil - 1)->vrsta_goriva);
	fprintf(fpr, "Kilometri : %d \n", (poljeVozila + trazeniAutomobil - 1)->kilometri);
	fprintf(fpr, "Boja : %s\n", (poljeVozila + trazeniAutomobil - 1)->boja);
	fprintf(fpr, "Cijena po danu : %d EUR\n", (poljeVozila + trazeniAutomobil - 1)->cijenaNajma);
	fprintf(fpr, "Trajanje posudbe : %d dana\n\n", brojDana);
	fprintf(fpr, "===================================================\n\n");
	fprintf(fpr, "Ukupna cijena za platit : %d EUR", brojDana * (poljeVozila+ trazeniAutomobil - 1)->cijenaNajma);


	fclose(fpr);
}