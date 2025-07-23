#include <iostream>
#include <string>
#include "GestoreAttivita.h"

int main() {
    GestoreAttivita gestore;
    int scelta;

    do {
        std::cout << "\n🎯 --- Gestore Attività --- 🎯\n\n";
        std::cout << "1️⃣  Aggiungi attività\n";
        std::cout << "📋  Visualizza tutte le attività\n";
        std::cout << "✅  Segna attività come terminata\n";
        std::cout << "🗑️  Rimuovi attività\n";
        std::cout << "📊  Visualizza statistiche\n";
        std::cout << "🚪  Esci\n";
        std::cout << "Scegli un'opzione: ";

        std::cin >> scelta;
        std::cin.ignore(); // Per pulire il buffer

        if (scelta == 1) {
            std::cout << "Inserisci la descrizione dell'attività: ";
            std::string descrizione;
            std::getline(std::cin, descrizione);
            gestore.aggiungiAttivita(descrizione);
            std::cout << "Attività aggiunta con successo! ✅\n";
        } 
        else if (scelta == 2) {
            gestore.visualizzaTutteLeAttivita();
        }
        else if (scelta == 3) {
            std::cout << "Inserisci l'ID dell'attività da segnare come terminata: ";
            int id;
            std::cin >> id;
            if (gestore.segnaAttivitaTerminata(id)) {
                std::cout << "Attività segnata come terminata! ✅\n";
            } else {
                std::cout << "Attività con ID " << id << " non trovata. ❌\n";
            }
        }
        else if (scelta == 4) {
            std::cout << "Inserisci l'ID dell'attività da rimuovere: ";
            int id;
            std::cin >> id;
            if (gestore.rimuoviAttivita(id)) {
                std::cout << "Attività rimossa con successo! 🗑️\n";
            } else {
                std::cout << "Attività con ID " << id << " non trovata. ❌\n";
            }
        }
        else if (scelta == 5) {
            gestore.visualizzaStatistiche();
        }
        else if (scelta == 0) {
            std::cout << "Uscita in corso... 👋\n";
        }
        else {
            std::cout << "Opzione non valida, riprova.\n";
        }

    } while (scelta != 0);

    return 0;
}
