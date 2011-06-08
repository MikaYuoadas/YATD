#ifndef ROACH
#define ROACH

#include <QPainter>

#include "Bug.h"

/**
 * Classe représentant un cafard.
 * Définie les caractéristiques spécifiques aux cafards, comme leur graphisme, leur type de déplacement (CRAWL)...
 */
class Roach : public Bug
{
    private:
        QImage * image[3]; /**< Cache d'images. Les images du cafard à chaque position, redimensionnées en fonction de sa taille.*/

    public:
        /**
         * Constructeur de Roach.
         * Appelle le constructeur de Bug avec les paramètres correspondants aux caractéristiques d'un cafard.
         */
        Roach(double x, double y, double s, double start_angle);
        /**
         * Destructeur de Roach.
         * Désalloue la mémoire correctement.
         */
        ~Roach();
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Est appelé automatiquement par Qt pour redessiner le cafard.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
