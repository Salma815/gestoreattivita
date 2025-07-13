// gestore_attivita_semplice.cpp - Gestore di attività semplice in un file
/*
 * Progetto: Sistema di Gestione Attività
 * Corso: Programmazione Orientata agli Oggetti
 * Università: [La tua università italiana]
 * 
 * Descrizione: Applicazione console per gestire attività personali
 * utilizzando i principi della programmazione orientata agli oggetti.
 * 
 * Caratteristiche implementate:
 * - Due classi principali: Attivita e GestoreAttivita  
 * - Gestione dinamica memoria con std::vector
 * - Menu interattivo per l'utente
 * - Operazioni CRUD complete (Create, Read, Update, Delete)
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Classe che rappresenta una singola attività
 * 
 * Questa classe modella un'attività con le sue proprietà fondamentali:
 * ID univoco, descrizione testuale e stato di completamento.
 */
class Attivita {
public:
    int id;                 // Identificativo univoco dell'attività
    string descrizione;     // Testo descrittivo dell'attività
    bool terminata;         // Stato: true se completata, false se in sospeso
    
    /**
     * @brief Costruttore per creare una nuova attività
     * @param id Identificativo univoco 
     * @param desc Descrizione dell'attività
     */
    Attivita(int id, string desc) : id(id), descrizione(desc), terminata(false) {}
    
    /**
     * @brief Segna l'attività come completata
     * 
     * Cambia lo stato dell'attività da "in sospeso" a "terminata"
     */
    void segnaTerminata() {
        terminata = true;
    }
    
    /**
     * @brief Visualizza l'attività in formato leggibile
     * 
     * Stampa a console le informazioni dell'attività con formattazione
     */
    void visualizza() {
        cout << "ID: " << id << " | " << descrizione;
        if (terminata) {
            cout << " | ✅ Terminata";
        } else {
            cout << " | ⏳ In sospeso";
        }
        cout << endl;
    }
};

/**
 * @brief Classe principale per la gestione delle attività
 * 
 * Questa classe implementa la logica di business dell'applicazione,
 * gestendo una collezione di attività e fornendo operazioni per
 * manipolarle (aggiungere, rimuovere, modificare, visualizzare).
 */
class GestoreAttivita {
private:
    vector<Attivita> attivita;  // Contenitore dinamico per le attività
    int prossimoId;             // Contatore per generare ID univoci
    
public:
    /**
     * @brief Costruttore del gestore attività
     * 
     * Inizializza il gestore con una collezione vuota e il primo ID disponibile
     */
    GestoreAttivita() : prossimoId(1) {}
    
    /**
     * @brief Aggiunge una nuova attività alla collezione
     * 
     * Richiede all'utente di inserire la descrizione e crea una nuova
     * attività con ID auto-incrementale. Valida l'input per evitare
     * descrizioni vuote.
     */
    void aggiungiAttivita() {
        cout << "\n📝 Inserisci la descrizione dell'attività: ";
        string descrizione;
        cin.ignore();  // Pulisce il buffer da precedenti input
        getline(cin, descrizione);  // Legge l'intera riga inclusi gli spazi
        
        if (!descrizione.empty()) {
            // Crea nuova attività e la aggiunge alla collezione
            attivita.push_back(Attivita(prossimoId++, descrizione));
            cout << "✅ Attività aggiunta con successo!" << endl;
        } else {
            cout << "❌ La descrizione non può essere vuota!" << endl;
        }
    }
    
    /**
     * @brief Visualizza tutte le attività presenti
     * 
     * Mostra l'elenco completo delle attività con formattazione.
     * Se non ci sono attività, mostra un messaggio informativo.
     */
    void visualizzaTutteLeAttivita() {
        cout << "\n📋 Tutte le attività:" << endl;
        cout << "=======================" << endl;
        
        if (attivita.empty()) {
            cout << "Nessuna attività al momento." << endl;
            return;
        }
        
        // Itera attraverso tutte le attività e le visualizza
        for (auto& att : attivita) {
            att.visualizza();
        }
    }
    
    /**
     * @brief Segna un'attività come terminata
     * 
     * Mostra l'elenco delle attività, richiede l'ID da completare
     * e aggiorna lo stato dell'attività corrispondente.
     */
    void segnaAttivitaTerminata() {
        if (attivita.empty()) {
            cout << "❌ Nessuna attività da completare!" << endl;
            return;
        }
        
        visualizzaTutteLeAttivita();
        cout << "\n🎯 Inserisci l'ID dell'attività da completare: ";
        int idAttivita;
        cin >> idAttivita;
        
        // Cerca l'attività con l'ID specificato
        for (auto& att : attivita) {
            if (att.id == idAttivita) {
                att.segnaTerminata();
                cout << "✅ Attività segnata come terminata!" << endl;
                return;
            }
        }
        
        cout << "❌ Attività non trovata!" << endl;
    }
    
    /**
     * @brief Visualizza le statistiche delle attività
     * 
     * Calcola e mostra statistiche utili come numero totale di attività,
     * quante sono terminate, quante in sospeso e la percentuale di completamento.
     */
    void visualizzaStatistiche() {
        int totale = attivita.size();
        int terminate = 0;
        
        // Conta le attività terminate
        for (const auto& att : attivita) {
            if (att.terminata) {
                terminate++;
            }
        }
        
        cout << "\n📊 Statistiche:" << endl;
        cout << "==================" << endl;
        cout << "📝 Totale attività: " << totale << endl;
        cout << "✅ Attività terminate: " << terminate << endl;
        cout << "⏳ Attività in sospeso: " << (totale - terminate) << endl;
        
        // Calcola e mostra la percentuale di completamento
        if (totale > 0) {
            double percentuale = (double)terminate / totale * 100;
            cout << "🎯 Tasso di completamento: " << percentuale << "%" << endl;
        }
    }
    
    /**
     * @brief Rimuove un'attività dalla collezione
     * 
     * Mostra l'elenco, richiede l'ID da rimuovere e elimina
     * l'attività corrispondente dalla collezione.
     */
    void rimuoviAttivita() {
        if (attivita.empty()) {
            cout << "❌ Nessuna attività da rimuovere!" << endl;
            return;
        }
        
        visualizzaTutteLeAttivita();
        cout << "\n🗑️ Inserisci l'ID dell'attività da rimuovere: ";
        int idAttivita;
        cin >> idAttivita;
        
        // Cerca e rimuove l'attività con l'ID specificato
        for (auto it = attivita.begin(); it != attivita.end(); ++it) {
            if (it->id == idAttivita) {
                attivita.erase(it);  // Rimuove l'elemento dal vector
                cout << "🗑️ Attività rimossa!" << endl;
                return;
            }
        }
        
        cout << "❌ Attività non trovata!" << endl;
    }
    
    /**
     * @brief Visualizza il menu principale dell'applicazione
     * 
     * Mostra le opzioni disponibili all'utente in formato grafico
     * con emoji per rendere l'interfaccia più user-friendly.
     */
    void visualizzaMenu() {
        cout << "\n🌟================================🌟" << endl;
        cout << "        Gestore Attività          " << endl;
        cout << "🌟================================🌟" << endl;
        cout << "1️⃣  Aggiungi nuova attività" << endl;
        cout << "2️⃣  Visualizza tutte le attività" << endl;
        cout << "3️⃣  Segna attività come terminata" << endl;
        cout << "4️⃣  Rimuovi attività" << endl;
        cout << "5️⃣  Visualizza statistiche" << endl;
        cout << "0️⃣  Esci" << endl;
        cout << "==================================" << endl;
        cout << "La tua scelta: ";
    }
    
    /**
     * @brief Metodo principale che gestisce l'esecuzione dell'applicazione
     * 
     * Implementa il loop principale del programma, gestendo l'input
     * dell'utente e chiamando i metodi appropriati basandosi sulla scelta.
     * Continua l'esecuzione fino a quando l'utente sceglie di uscire.
     */
    void esegui() {
        cout << "🎉 Benvenuto nel Gestore Attività!" << endl;
        cout << "===================================" << endl;
        
        int scelta;
        do {
            visualizzaMenu();
            cin >> scelta;
            
            // Switch per gestire le diverse opzioni del menu
            switch(scelta) {
                case 1:
                    aggiungiAttivita();
                    break;
                case 2:
                    visualizzaTutteLeAttivita();
                    break;
                case 3:
                    segnaAttivitaTerminata();
                    break;
                case 4:
                    rimuoviAttivita();
                    break;
                case 5:
                    visualizzaStatistiche();
                    break;
                case 0:
                    cout << "\n👋 Grazie per aver usato il Gestore Attività!" << endl;
                    cout << "🌟 A presto!" << endl;
                    break;
                default:
                    cout << "❌ Scelta non valida! Riprova." << endl;
            }
            
            // Pausa per permettere all'utente di leggere l'output
            if (scelta != 0) {
                cout << "\n⏸️ Premi Invio per continuare...";
                cin.ignore();
                cin.get();
            }
            
        } while (scelta != 0);  // Continua fino alla scelta di uscita
    }
};

/**
 * @brief Funzione principale del programma
 * 
 * Punto di ingresso dell'applicazione. Crea un'istanza del GestoreAttivita
 * e avvia l'esecuzione del programma.
 * 
 * @return 0 se l'esecuzione termina correttamente
 */
int main() {
    // Crea un'istanza del gestore e avvia l'applicazione
    GestoreAttivita app;
    app.esegui();
    return 0;
}

/*
 * ==========================================
 * NOTE TECNICHE PER LA PRESENTAZIONE ORALE:
 * ==========================================
 * 
 * 1. ARCHITETTURA DEL PROGETTO:
 *    - Due classi principali con responsabilità ben definite
 *    - Attivita: modella una singola attività (data model)
 *    - GestoreAttivita: gestisce la collezione e la business logic
 * 
 * 2. PRINCIPI OOP APPLICATI:
 *    - Incapsulamento: dati privati con interfacce pubbliche controllate
 *    - Astrazione: interfacce semplici che nascondono la complessità interna
 *    - Modularità: codice organizzato in classi con responsabilità specifiche
 * 
 * 3. STRUTTURE DATI UTILIZZATE:
 *    - std::vector<Attivita>: container dinamico per gestione efficiente memoria
 *    - Crescita automatica quando si aggiungono elementi
 *    - Accesso casuale agli elementi in tempo O(1)
 * 
 * 4. ALGORITMI IMPLEMENTATI:
 *    - Ricerca lineare: per trovare attività per ID
 *    - Iterazione: per visualizzazione e conteggio
 *    - Inserimento e rimozione dinamica da container
 * 
 * 5. GESTIONE INPUT/OUTPUT:
 *    - Validazione input utente per evitare errori
 *    - Uso di getline() per leggere stringhe con spazi
 *    - Buffer cleaning con cin.ignore()
 * 
 * 6. INTERFACE UTENTE:
 *    - Menu driven interface per facilità d'uso
 *    - Feedback immediato per ogni operazione
 *    - Uso di emoji Unicode per migliorare UX
 * 
 * 7. GESTIONE DELLA MEMORIA:
 *    - Uso di container STL per gestione automatica memoria
 *    - Nessun memory leak grazie a RAII
 *    - Oggetti gestiti automaticamente dal vector
 */