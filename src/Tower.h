#ifndef TOWER
#define TOWER

#include <QGraphicsObject>
#include <QPainter>
#include <QPointF>
#include <QTimer>
#include <QString>

#include "Projectile.h"
#include "Render.h"

class Render;
class Projectile;

/**
 * Classe représentant toutes les défenses.
 * Implémente les méthodes communes à toutes les défenses (la différenciation se fait surtout au niveau des projectiles et des stats des défenses).
 */
class Tower : public QGraphicsObject
{
    Q_OBJECT

    private:
        short int level;       /**< Le niveau actuel de la défense.*/
        float price;           /**< Le prix de revent de la défense.*/
        float upg1;            /**< Le coût pour améliorer la défense du niveau 1 au 2.*/
        float upg2;            /**< Le coût pour améliorer la défense du niveau 2 au 3.*/
        QColor color;          /**< La couleur de la défense.*/
        short int targetType;  /**< Le type de cible que peut atteindre la défense.*/
        double range;          /**< La portée de la défense.*/
        double firerate;       /**< La cadence de tir de la défense.*/
        QTimer * timer;        /**< Timer utilisé pour la cadence de tir de la défense.*/
        QPointF pos;           /**< La position sur la map de la défense.*/
        QString type;          /**< Le type spécifique de la défense.*/

    public:
        Render * parent;       /**< L'objet Render parent de la défense.*/
        /**
         * Constructeur de Tower.
         * Initialise les caractéristiques de la tour selon son type.
         * @param buildPos La position où placer la défense.
         * @param typeTower Le type de défense à créer.
         */
        Tower(QPointF buildPos, QString typeTower);
        /**
         * Surcharge de la méthode virtuelle pure boudingRect() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour savoir s'il doit ou non redessiner l'objet.
         * @return Le rectangle englobant tous les dessins de la défense.
         */
        QRectF boundingRect() const;
        /**
         * Surcharge de la méthode virtuelle pure paint() héritée de QGraphicsObject.
         * Appelé automatiquement par Qt pour dessiner la défense.
         */
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        /**
         * Assesseur. Assesseur vers type.
         * @return Le contenu de l'attribut type.
         */
        QString getType();
        /**
         * Assesseur. Assesseur vers range.
         * @return Le contenu de l'attribut range.
         */
        double getRange();
        /**
         * Assesseur. Assesseur vers level.
         * @return Le contenu de l'attribut level.
         */
        short int getLvl();
        /**
         * Assesseur. Assesseur vers firerate.
         * @return Le contenu de l'attribut firerate.
         */
        double getFirerate();
        /**
         * Assesseur. Assesseur vers price.
         * @return Le contenu de l'attribut price.
         */
        float getPrice();
        /**
         * Assesseur. Assesseur vers upg.
         * @return Le prix pour améliorer la défense vers le niveau suivant.
         */
        float getUpgCost();
        /**
         * Amélioration de la défense.
         * Améliore la défense (et donc ses caractéristiques) vers le niveau suivant.
         */
        void upgrade();

    public slots:
        /**
         * Signal de tir reçu.
         * Méthode appelé par le timer de cadence pour tirer.
         */
        void fire();

    signals:
        /**
         * Création de projectile.
         * Envoie le projectile créer à la scène.
         * @param missile Un pointeur vers le projectile tirée.
         */
        void projectile(Projectile * missile);
};
#endif
