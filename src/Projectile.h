#ifndef PROJECTILE
#define PROJECTILE

#include <QGraphicsObject>
#include <QPainter>
#include <QPointF>
#include <QString>

#include "Bug.h"

class Bug;

/**
 * Classe représentant les projectiles des tours.
 * Définie les méthodes des projectiles ainsi que leur caractéristiques de base.
 */
class Projectile : public QGraphicsObject
{
    Q_OBJECT

    protected:
        /**
         * Surcharge de la méthode virtuelle pure héritée de QGraphicsObject. Est appellé automatiquement par Qt deux fois par appelle au slot advance de la QGraphicsScene.
         * @param step appelé une fois avant de redessiner avec step = 0 et une fois avec step = 1.
         */
        void advance(int step);

    private:
        QPointF dest;     /**< La destination du projectile.*/
        Bug * target;     /**< L'insecte ciblée par le projectile.*/
        double speed;     /**< La vitesse en case par seconde du projectile.*/
        double dmg;       /**< Les dégats infligé à l'impact par le projectile.*/
        double maxrange;  /**< La portée maximale du projectile (s'il n'atteint personne avant d'arriver à se portée max, il disparait).*/
        double travelled; /**< La distance parcourue par le projectile.*/

    public:
        /**
         * Constructeur de Projectile
         * Initialise les caractéristiques du projectile.
         * @param start Point de départ du projectile.
         * @param trgt Insecte cible du projectile.
         * @param init_speed Vitesse de vol du projectile.
         * @param damage Dégats infligés à l'impact par le projectile.
         */
        Projectile(QPointF start, Bug * trgt, double init_speed, double damage);
        /**
         * Surcharge de la methode virtuelle pure boundingRect() héritée de QGraphicsObject.
         * Fonction appelé automatiquement par QT pour savoir s'il doit redessiner ou non l'objet graphique.
         * @return Un object QRectF correspondant au rectangle englobant le dessin du projectile.
         */
        QRectF boundingRect() const;
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Est appelé automatiquement par Qt pour redessiner le projectile.
         */
        void paint(QPainter *painter, QColor color);

    signals:
        /**
         * Signal d'explosion du projectile.
         * Signale émit lorsque le projectile explose pour qu'il soit retiré de la scène.
         * @param missile Un pointeur vers le projectile pour que la scène puisse le détruire correctement.
         */
        void explode(Projectile * missile);
};
#endif
