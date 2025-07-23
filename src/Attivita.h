#pragma once
#include <string>
#include <iostream>

class Attivita {
public:
    int id;
    std::string descrizione;
    bool terminata;

    Attivita(int id, const std::string& descrizione);
    void segnaTerminata();
    void visualizza() const;
};
