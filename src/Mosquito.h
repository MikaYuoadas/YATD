#ifndef MOSQUITO
#define MOSQUITO

#include <QPainter>

#include "Bug.h"

/**
 * Classe représentant les moustiques. Définie les caractéristiques spécifiques aux moustiques, comme leur graphisme, leur type de déplacement (FLY)...
 */
class Mosquito : public Bug
{
    private:
        QImage * image[2]; /**< Cache d'image. Les images du moustique sont redimensionnées puis mises en cache pour un affichage plus rapide.*/

    public:
        /**
         * Constructeur de Mosquito.
         * Ce constructeur charge les images du moustique et appelle le constructeur parent de Bug() avec les paramètres correspondants aux caractéristiques d'un moustique.
         * @param x Un double correspondant à l'abscisse du point de départ des insectes.
         * @param y Un double correspondant à l'ordonnée du point de départ des insectes.
         * @param s La taille du moustique, influe sur la taille de sa représentation graphique et sur les autres caractéristiques.
         * @param start_angle Angle de départ de l'insecte.
         */
        Mosquito(double x, double y, double s, double start_angle);
        /**
         * Destructeur de Mosquito.
         * Désalloue la mémoire des images du moustique mises en cache.
         */
        ~Mosquito();
        /**
         * Surcharge de la fonction virtuelle pure paint() hérité de QGraphicsObject.
         * Est appelé automatiquement par Qt pour redessiner le moustique.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
