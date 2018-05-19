/*
 * Illustre la production d'un signal analogique à partir de sorties digitales.
 * @author jean-michel-gonet
 */
#include <htc.h>

/**
 * Bits de configuration:
 */
#pragma config FOSC = INTIO67  // Osc. interne, A6 et A7 comme IO.
#pragma config IESO = OFF      // Pas d'osc. au démarrage.
#pragma config FCMEN = OFF     // Pas de monitorage de l'oscillateur.

// Nécessaires pour ICSP / ICD:
#pragma config MCLRE = EXTMCLR // RE3 est actif comme master reset.
#pragma config WDTEN = OFF     // Watchdog inactif.
#pragma config LVP = OFF       // Single Supply Enable bits off.

/**
 * Point d'entrée.
 * Configure le port A comme sortie, puis copie en boucle
 * les échantillons précalculées d'une courbe sinusoïdale.
 */
void main()
{
    char sinus[] =
    {
        16, 21, 25, 28, 30, 31, 30, 
        28, 25, 21, 16, 11,  7,  4,
         2,  1,  2,  4,  7, 11, 16
    };

    char n;

    ANSELA = 0x00;      // Désactive les convertisseurs A/D.
    ANSELB = 0x00;      // Désactive les convertisseurs A/D.
    ANSELC = 0x00;      // Désactive les convertisseurs A/D.

    TRISA = 0x00;       // Tous les bits du port A comme sorties.

    while(1)
    {
        for(n=0; n<20; n++)
        {
            PORTA = sinus[n];
        }
    }
}
