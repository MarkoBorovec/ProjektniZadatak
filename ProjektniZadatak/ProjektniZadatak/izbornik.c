#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"

int izbornik(const char* const datKorisnik, const char* const datVozilo, char* const datRacun) {
	printf("====================");
	printf("Izaberite jednu od ponudenih opcija:");
	printf("====================\n");

	printf("\t\t\tOpcija 1: dodavanje novih korisnika!\n");
	printf("\t\t\tOpcija 2: dodavanje novih vozila !\n");
	printf("\t\t\tOpcija 3: ispisivanje korisnika!\n");
	printf("\t\t\tOpcija 4: ispisivanje automobila!\n");
	printf("\t\t\tOpcija 5: sortiranje vozila od najjeftinijeg prema najskupljem \n");
	printf("\t\t\tOpcija 6: pretrazivanje korisnika pomocu prezimena \n");
	printf("\t\t\tOpcija 7: pretrazivanje vozila pomocu marke \n");
	printf("\t\t\tOpcija 8: ispisivanje aktivnih korisnika !\n");
	printf("\t\t\tOpcija 9: ispisivanje dostupnih vozila!\n");
	printf("\t\t\tOpcija 10: azuriranje korisnika!\n");
	printf("\t\t\tOpcija 11: azuriranje vozila!\n");
	printf("\t\t\tOpcija 12: brisanje korisnika!\n");
	printf("\t\t\tOpcija 13: brisanje vozila !\n");
	printf("\t\t\tOpcija 14: brisanje datoteka korisnici i vozila!\n");
	printf("\t\t\tOpcija 15: Iznajmljivanje vozila\n");
	printf("\t\t\tOpcija 16: izlaz iz programa!\n");

	int uvijet = 0;
	static KORISNIK* poljeKorisnika = NULL;
	static KORISNIK* pronadeniKorisnik = NULL;
	static VOZILO* poljeVozila = NULL;
	static VOZILO* pronadenoVozilo = NULL;
	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		dodajKorisnika(datKorisnik);
		break;
	case 2:
		dodajVozilo(datVozilo);
		break;

	case 3:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		ispisivanjeKorisnika(poljeKorisnika);
		break;


	case 4:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}
		poljeVozila = (VOZILO*)ucitavanjeVozila(datVozilo);
		ispisivanjeVozila(poljeVozila);
		break;


	case 5:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}

		poljeVozila = (VOZILO*)ucitavanjeVozila(datVozilo);

		ispisisortiraneautomobile(poljeVozila);
		break;
	case 6:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		pronadiKorisnikaPrezime(poljeKorisnika);
		break;
	case 7:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}

		poljeVozila = (VOZILO*)ucitavanjeVozila(datVozilo);

		pronadiAutomobilPoMarki(poljeVozila);
		break;
	
	case 8:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		ispisiKorisnikeKojiIznajmljuju(poljeKorisnika);
		break;
	case 9:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}

		poljeVozila= (VOZILO*)ucitavanjeVozila(datVozilo);

		ispisiDostupnaVozila(poljeVozila);
		break;

	case 10:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		azuriranjeKorisnika(poljeKorisnika, datKorisnik);
		break;
	case 11:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila= NULL;
		}

		poljeVozila = (VOZILO*)ucitavanjeVozila(datVozilo);

		azuriranjeVozila(poljeVozila, datVozilo);
		break;
	case 12:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		brisanjeKorisnika(poljeKorisnika, datKorisnik);
		break;
	case 13:
		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}

		poljeVozila = (VOZILO*)ucitavanjeVozila(datVozilo);
		brisanjeVozila(poljeVozila, datVozilo);
		break;

	case 14:
		brisanjeDatoteke_Korisnik(datKorisnik);
	    brisanjeDatoteke_Vozilo(datVozilo);
		break;

	case 15:
		if (poljeKorisnika != NULL) {
			free(poljeKorisnika);
			poljeKorisnika = NULL;
		}

		poljeKorisnika = (KORISNIK*)ucitavanjeKorisnika(datKorisnik);

		if (poljeVozila != NULL) {
			free(poljeVozila);
			poljeVozila = NULL;
		}

		poljeVozila= (VOZILO*)ucitavanjeVozila(datVozilo);

		iznajmljivanjeVozila(poljeKorisnika, poljeVozila, datKorisnik, datVozilo, datRacun);
		break;

	default:
		uvijet = 0;
	}
	return uvijet;
	
}

	