#pragma once
#include <vector>
#include "Attivita.h"

class GestoreAttivita {
private:
    std::vector<Attivita> attivita;
    int prossimoId;

public:
    GestoreAttivita();
    void aggiungiAttivita(const std::string& descrizione);
    void visualizzaTutteLeAttivita() const;
    bool segnaAttivitaTerminata(int id);
    bool rimuoviAttivita(int id);
    void visualizzaStatistiche() const;
};
