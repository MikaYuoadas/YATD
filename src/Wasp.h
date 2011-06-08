#ifndef WASP
#define WASP

#include <QPainter>

#include "Bug.h"

/**
 * Classe représentant les guêpes.
 * Définie les caractéristiques propres aux guêpes.
 */
class Wasp : public Bug
{
    private:
        QImage * image[2]; /**< Cache d'images. Les images de la guêpes redimensionnées.*/

    public:
        /**
         * Constructeur de Wasp.
         * Appelle le constructeur de Bug avec les paramètres spécifiques aux guêpes.
         * @param x L'abscisse du départ des insectes.
         * @param y L'ordonnée du départ des insectes.
         * @param s La taille de la guêpe.
         * @param start_angle l'angle de départ des insectes.
         */
        Wasp(double x, double y, double s, double start_angle);
        /**
         * Destructeur de Wasp.
         * Désalloue la mémoire des images.
         */
        ~Wasp();
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Est appelé automatiquement par Qt pour dessiner la guêpe.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
