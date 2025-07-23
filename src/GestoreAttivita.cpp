#include "GestoreAttivita.h"
#include <iostream>

GestoreAttivita::GestoreAttivita() : prossimoId(1) {}

void GestoreAttivita::aggiungiAttivita(const std::string& descrizione) {
    if (!descrizione.empty()) {
        attivita.emplace_back(prossimoId++, descrizione);
    }
}

void GestoreAttivita::visualizzaTutteLeAttivita() const {
    if (attivita.empty()) {
        std::cout << "Nessuna attività." << std::endl;
        return;
    }
    for (const auto& a : attivita) a.visualizza();
}

bool GestoreAttivita::segnaAttivitaTerminata(int id) {
    for (auto& a : attivita) {
        if (a.id == id) {
            a.segnaTerminata();
            return true;
        }
    }
    return false;
}

bool GestoreAttivita::rimuoviAttivita(int id) {
    for (auto it = attivita.begin(); it != attivita.end(); ++it) {
        if (it->id == id) {
            attivita.erase(it);
            return true;
        }
    }
    return false;
}

void GestoreAttivita::visualizzaStatistiche() const {
    int totale = attivita.size();
    int terminate = 0;
    for (const auto& a : attivita) {
        if (a.terminata) terminate++;
    }
    std::cout << "Totale attività: " << totale << std::endl;
    std::cout << "Attività terminate: " << terminate << std::endl;
}
