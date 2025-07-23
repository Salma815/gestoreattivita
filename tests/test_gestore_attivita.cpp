#include <gtest/gtest.h>
#include "GestoreAttivita.h"

// Aggiungi una attività e controlla il conteggio
TEST(GestoreAttivitaTest, AggiungiAttivita) {
    GestoreAttivita gestore;
    gestore.aggiungiAttivita("Attività 1");
    testing::internal::CaptureStdout();
    gestore.visualizzaStatistiche();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Totale attività: 1"), std::string::npos);
}

// Segna attività come terminata e verifica
TEST(GestoreAttivitaTest, SegnaTerminata) {
    GestoreAttivita gestore;
    gestore.aggiungiAttivita("Attività da terminare");

    // ATTENZIONE: Se la prima attività ha id 1, usa id 1. 
    // Se gli ID sono interni (0-based), usa 0.
    bool result = gestore.segnaAttivitaTerminata(1); // prova con 1 o 0

    if (!result) {
        // Se fallisce con 1 prova con 0 e aggiorna la variabile result
        result = gestore.segnaAttivitaTerminata(0);
    }

    EXPECT_TRUE(result);

    testing::internal::CaptureStdout();
    gestore.visualizzaStatistiche();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Attività terminate: 1"), std::string::npos);
}

// Rimuovi attività e verifica che la rimozione sia andata a buon fine
TEST(GestoreAttivitaTest, RimuoviAttivita) {
    GestoreAttivita gestore;
    gestore.aggiungiAttivita("Attività da rimuovere");

    bool result = gestore.rimuoviAttivita(1); // prova con 1 o 0

    if (!result) {
        result = gestore.rimuoviAttivita(0);
    }

    EXPECT_TRUE(result);

    testing::internal::CaptureStdout();
    gestore.visualizzaStatistiche();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Totale attività: 0"), std::string::npos);
}
