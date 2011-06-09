#ifndef BOWLING
#define BOWLING

#include "Projectile.h"

/**
 * Classe représentant les projectiles du joueur de pétanque.
 * Classe représentant les projectiles du joueu de pétanque, rien de spéciale.
 */
class Bowling : public Projectile
{
    public:
        /**
         * Constructeur de Bowling.
         * Appelle le constructeur de Projectile avec les caractéristiques du joueur de pétanque.
         * @param start Position de départ.
         * @param target Pointeur vers l'insecte ciblé.
         * @param lvl Le niveau du projectile.
         */
        Bowling(QPointF start, Bug * target, short int lvl);
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour redessiner l'objet.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
