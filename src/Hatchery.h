#ifndef HATCHERY
#define HATCHERY

#include <QString>

#include "Bug.h"

class Bug;

/**
 * Classe implémentation du design pattern Factory.
 * Design pattern Factory utilisé pour créer un nouvel insecte au niveau du spawn.
 */
class Hatchery
{
    private:
        double x; /**< Abscisse du spawn des insectes.*/
        double y; /**< Ordonnée du spawn des insectes.*/
        double angle; /**< Angle vers lequel fait face le spawn des insectes.*/

    public:
        /**
         * Constructeur d'Hatchery.
         * Permet d'instancier un objet Hatchery pour initialiser la position et l'angle du spawn des insectes.
         * @param start_x Un double correspondant à l'abscisse du point de départ des insectes.
         * @param start_y Un double correspondant à l'ordonnée du point de départ des insectes.
         * @param start_angle Un double correspondant à l'angle de départ des insectes (en degré).
         */
        Hatchery(double start_x, double start_y, double start_angle);
        /**
         * Crée un nouvel insecte de la race et de la taille données.
         * @param race Un QString donnant la race de l'insecte a créer.
         * @param size Un double donnant la taille de l'insecte.
         * @return Un pointeur vers l'insecte créé.
         */
        Bug * spawnBug(QString race, double size);
};
#endif
