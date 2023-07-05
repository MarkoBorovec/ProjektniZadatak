#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "dataType.h"

int main(void) {


    char* datKorisnik = "korisnici.txt";
	char* datVozilo = "automobili.txt";
	char* datRacun = "racun.txt";


	kreiranjeDatoteke_Korisnici(datKorisnik);
	kreiranjeDatoteke_Automobili(datVozilo);

	int uvjet = 1;

	while (uvjet) {
		uvjet = izbornik(datKorisnik, datVozilo,datRacun);
	}


	printf("\n Zavrsetak  programa");

	return 0;
}