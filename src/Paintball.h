#ifndef PAINTBALL
#define PAINTBALL

#include "Projectile.h"

/**
 * Classe représentant les projectiles du paintball.
 * Classe représentant les projectiles du paintball, rien de spéciale.
 */
class Paintball : public Projectile
{
    public:
        /**
         * Constructeur de Paintball.
         * Appelle le constructeur de Projectile avec les caractéristiques du paintball.
         * @param start Position de départ.
         * @param target Pointeur vers l'insecte ciblé.
         * @param lvl Le niveau du projectile.
         */
        Paintball(QPointF start, Bug * target, short int lvl);
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour redessiner l'objet.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
