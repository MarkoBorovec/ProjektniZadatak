#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "dataType.h"
int izbornik(const char* const datKorisnik, const char* const datVozilo, const char* const datRacun);
void kreiranjeDatoteke_Korisnici(const char* const);
void kreiranjeDatoteke_Automobili(const char* const);
void dodajKorisnika(const char* const);
void dodajVozilo(const char* const);
KORISNIK* ucitavanjeKorisnika(const char* const datKorisnik);
VOZILO* ucitavanjeVozila(const char* const datVozilo);
void ispisivanjeKorisnika(const KORISNIK* const);
void ispisivanjeVozila(const VOZILO* const);
void ispisiDostupnaVozila(VOZILO* const);
void pronadiAutomobilPoMarki(VOZILO* poljeVozila);
void ispisisortiraneautomobile(const VOZILO* poljeVozila);
void ispisiKorisnikeKojiIznajmljuju(KORISNIK* const poljeKorisnika);
void azuriranjeKorisnika(KORISNIK*, const char* const);
void azuriranjeVozila(VOZILO*, const char* const);
void brisanjeVozila(VOZILO* const, const char* const);
void brisanjeKorisnika(KORISNIK* const, const char* const);
void brisanjeDatoteke_Korisnik(const char*);
void brisanjeDatoteke_Vozilo(const char*);
void pronadiAutomobilPoMarki(VOZILO*);
void iznajmljivanjeVozila(KORISNIK*, VOZILO*,const char* const, const char* const, const char* const);
int izlazIzPrograma(KORISNIK*, VOZILO*);
static int brojKorisnika;
static int brojAutomobila;
#endif //FUNCTIONS_H