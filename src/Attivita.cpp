#include "Attivita.h"

Attivita::Attivita(int id, const std::string& descrizione)
    : id(id), descrizione(descrizione), terminata(false) {}

void Attivita::segnaTerminata() { terminata = true; }

void Attivita::visualizza() const {
    std::cout << "ID: " << id << " | " << descrizione
              << (terminata ? " | ✅ Terminata" : " | ⏳ In sospeso")
              << std::endl;
}
