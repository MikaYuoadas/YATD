#ifndef BUG
#define BUG

#include <QGraphicsObject>
#include <QPainterPath>
#include <QPoint>

#include "define.h"
#include "Render.h"

class Render;

/**
 * Classe abstraite dont héritent les ennemis. Cette classe définie les actions de base commune à tous les insectes (l'affichage, la vie et les déplacements entre autres).
 */
class Bug : public QGraphicsObject
{
    Q_OBJECT

    protected:
        double size;            /**< Taille. La taille de l'insecte, influe à la fois sur la taille de la représentation graphique et sur les caractéristiques de l'insecte.'*/
        int frame;              /**< Compteur de frame. Compteur d'image utilisé pour afficher successivement chaque image des animations.*/
        double speed;           /**< Vitesse de base. La vitesse en case/seconde à laquelle se déplace l'insecte.*/
        /**
         * Implémentation de la fonction virtuelle pure advance() héritée de QGGaphicsObject.
         * Implémentation de la fonction virtuelle pure advance() héritée de QGGaphicsObject.
         * @param step La fonction est appelé deux fois automatiquement par QT à chaque update(), une fois avec 0 comme paramètre puis une fois avec 1.
         */
        void advance(int step);

    private:
        double hp;              /**< Point de vie. La vitalité de l'insecte, quand elle atteint 0, l'insecte meurt et le joueur gagne 1 crédit.*/
        double resist;          /**< Résistance. La résistance aux dégats de l'insecte.*/
        double angle;           /**< Angle des déplacements. Angle dans lequel l'insecte se déplace.*/
        short int moveType;     /**< Type de déplacement. Peut prendre les valeurs prédéfinies FLY ou CRAWL.*/
        QPoint lastSquare;      /**< Case d'origine. Dernière case visité par l'insecte. Elle est utilisé dans la détection de changement de case.*/

    public:
        Render * parent;        /**< L'objet Render parent de l'insecte. Quand on ajoute un insecte à l'objet Render par la méthode addBug(), cet attribut est automatiquement initialisé.*/
        /**
         * Constructeur de Bug.
         * La classe Bug étant abstraite, le constructeur sera toujours appelé par ses classes filles (Wasp, Ant, Mosquito, Roach) avec les bons paramètres.
         * @param x Un double correspondant à l'abscisse du point de départ des insectes.
         * @param y Un double correspondant à l'ordonnée du point de départ des insectes.
         * @param s La taille de l'insecte à créer.
         * @param health Un double donnant la vitalité initiale de l'insecte.
         * @param res Un double donnant la résistance aux dégats de l'insecte.
         * @param start_angle L'angle vers lequel fait face le départ des insectes.
         * @param init_speed La vitesse initiale de l'insecte.
         * @param type Prends une des valeurs prédéfinies FLY ou CRAWL correspondant au type de déplacement de l'insecte.
         */
        Bug(double x, double y, double s, double health, double res, double start_angle, double init_speed, short int type);
        /**
         * Surcharge de la fonction boudingRect() hérité de QGraphicsObject.
         * Fonction appelé automatiquement par QT pour savoir s'il doit ou non réafficher l'insecte.
         * @return Un objet QRectF correspondant au rectangle englobant l'ensemble du dessin de l'insecte.
         */
        QRectF boundingRect() const;
        /**
         * Surcharge de la fonction shape() hérité de QGraphicsObject.
         * Fonction utilisé par QT pour traiter les collisions entre objets graphiques.
         * @return Un object QPainterPath correspondant au contour de collision de l'insecte.
         */
        QPainterPath shape() const;
        /**
         * Infliger des dégats à l'insecte.
         * Fonction pouvant être appelée pour infliger des dégats à l'insecte (par exemple par les projectiles des tours).
         * @param dmg Un double correspondant au point de dégat à infliger (avant réduction par la résistance de l'insecte).
         */
        void hit(double dmg);

    signals:
        /**
         * Signal de mort de l'insecte. Signal émit lorsque l'insecte est tué.
         * @param bug Un pointeur vers l'insecte qui vient de mourir.
         */
        void dead(Bug * bug);
        /**
         * Signal d'arrivé. Signal émit par l'insecte lorsqu'il atteint son but.
         * @param bug Un pointeur vers l'insecte.
         */
        void goalReached(Bug * bug);
};
#endif
