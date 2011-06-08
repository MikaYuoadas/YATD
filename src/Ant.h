#ifndef ANT
#define ANT

#include <QPainter>
#include <QTimer>
#include <QObject>

#include "Bug.h"

/**
 * Classe représentant les fourmis.
 * Définie les caractéristiques spécifiques aux fourmis, comme leur graphisme, leur type de déplacement (CRAWL)...
 */
class Ant : public Bug
{
    Q_OBJECT

    private:
        QImage * image[3]; /**< Cache d'images. Les images de la fourmis à chaque position, redimensionnées en fonction de sa taille et mises en cache pour un affichage plus rapide.*/
        QTimer * timer;    /**< Timer de ralentissement. Quand une fourmis est blessée, elle accélère pendant 5 secondes, ce timer permet de faire ce décompte.*/

    public:
        /**
         * Constructeur de Ant.
         * Ce constructeur initialise les images en cache de la fourmi et appelle le constructeur parent (Bug) avec les bons paramètres correspondant aux caractéristique d'une fourmi.
         * @param x Un double correspondant à l'abscisse du point de départ des insectes.
         * @param y Un double correspondant à l'ordonnée du point de départ des insectes.
         * @param s La taille de la fourmi, influe sur la taille de la représentation graphique et sur ses autres caractéristiques.
         * @param start_angle L'angle vers lequel fait face le départ des insectes.
         */
        Ant(double x, double y, double s, double start_angle);
        /**
         * Destructeur de Ant.
         * Désalloue la mémoire des images de la fourmi en cache.
         */
        ~Ant();
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Est appelé automatiquement par Qt pour redessiner la fourmi.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        /**
         * Infliger des dégats à la fourmi et activer sa capacité spéciale.
         * Appelle la méthode Bug::hit() pour infliger les dégats, et lance le timer pour accélérer la fourmi pendant 5 secondes.
         * @param dmg Un double correspondant au montant de dégats à infliger avec réduction.
         */
        void hit(double dmg);

    private slots:
        /**
         * Slot appelé pour ralentir la fourmi
         * Après 5 secondes, le timer émet un signal timeout qui appelle la fonction slowDown() de la fourmi pour reprendre sa vitesse initiale?
         */
        void slowDown();
};
#endif
