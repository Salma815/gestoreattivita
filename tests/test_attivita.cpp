#include <gtest/gtest.h>
#include "Attivita.h"

TEST(AttivitaTest, Costruttore) {
    Attivita att(1, "Test attività");
    EXPECT_EQ(att.id, 1);
    EXPECT_EQ(att.descrizione, "Test attività");
    EXPECT_FALSE(att.terminata);
}

TEST(AttivitaTest, SegnaTerminata) {
    Attivita att(2, "Seconda attività");
    att.segnaTerminata();
    EXPECT_TRUE(att.terminata);
}
