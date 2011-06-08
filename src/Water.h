#ifndef WATER
#define WATER

#include "Projectile.h"

/**
 * Classe représentant les projectiles du pistolet à eau.
 * Classe représentant les projectiles du pistolet à eau, rien de spéciale.
 */
class Water : public Projectile
{
    public:
        /**
         * Constructeur de Ware.
         * Appelle le constructeur de Projectile avec les caractéristiques du pistolet à eau.
         * @param start Position de départ.
         * @param target Pointeur vers l'insecte ciblé.
         * @param lvl Le niveau du projectile.
         */
        Water(QPointF start, Bug * target, short int lvl);
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour redessiner l'objet.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
