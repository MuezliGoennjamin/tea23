#include <fmt/chrono.h>
#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

#define SOULS 100

/*Aufgabe 2: Beispiel 1*/
/*void cursed() {
    char *soul = (char*)malloc(8);
    strcpy(soul, "boo!");
    fmt::println("{}", soul);
    free(soul);
}

int main() {
    for(int i=0; i < SOULS; i++) {
        cursed();
    }
}*/ 

/*Beispiel 2: #include <fmt/format.h>
#include <cstdlib>
#include <cstring>

int main() {
    char *ghost = (char*)malloc(8);
    strcpy(ghost, "evil");
    fmt::println("vorher {}", ghost);
    free(ghost);
    fmt::println("{}", ghost);

    char *ghost2 = (char*)malloc(8);
    strcpy(ghost2, "evil");
    fmt::println("nachher {}", ghost);
} */

/*Beispiel 3: --> Stack Overflow (while Schleife läuft endlos und speichert pro Aufruf 1kB)

#include <cstdlib>

int main() {
    while (1) {
        malloc(1024);
    }
}

*/

/*Aufgabe 5:  */
#include <fmt/format.h>
#include "graveyard.h"

int undead = 7;

int main() {
    fmt::println("🪦 Globale Variable sagt: {}", "Adresse {}", undead, &undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}

