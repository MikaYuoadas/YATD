#ifndef STONE
#define STONE

#include "Projectile.h"

/**
 * Classe représentant les projectiles du lance-pierres.
 * Classe représentant les projectiles du lance-pierres, rien de spéciale.
 */
class Stone : public Projectile
{
    public:
        /**
         * Constructeur de Stone.
         * Appelle le constructeur de Projectile avec les caractéristiques du lance-pierre.
         * @param start Position de départ.
         * @param target Pointeur vers l'insecte ciblé.
         * @param lvl Le niveau du projectile.
         */
        Stone(QPointF start, Bug * target, short int lvl);
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour redessiner l'objet.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
