#ifndef RENDER
#define RENDER

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QHash>
#include <QTimer>
#include <QPoint>
#include <QStringList>

#include "define.h"
#include "Hatchery.h"
#include "Tower.h"

class Bug;
class Hatchery;
class Tower;
class Projectile;

/**
 * Classe gérant le rendu graphique du jeu.
 * Classe héritant de QGraphicsScene et gérant les interactions entre les éléments du jeu, le placement des tours...
 */
class Render : public QGraphicsScene
{
    Q_OBJECT

    private:
        QTimer waveTimer;            /**< Timer appelant la méthode nextBug() a intervalle régulier lors d'une vague.*/
        QPoint * start;              /**< La position du départ des insectes.*/
        double start_angle;          /**< L'angle de départ des insectes.*/
        int waveNumber;              /**< Le numéro de la vague en cours.*/
        QStringList * wave;          /**< La liste des insectes restant a spawn dans la vague en cours.*/
        int map[ROW][COLUMN];        /**< Un tableau à deux dimensions des cases de la map avec leur contenu (chemin, boue, herbe).*/
        Tower * towers[ROW][COLUMN]; /**< Un tableau à deux dimensions de pointeurs vers les tours présentent sur la map.*/
        QPoint goalSquare;           /**< La position de l'arrivée des insectes.*/
        QHash<int, QPixmap> tiles;   /**< La liste des images des différentes tuiles présentent sur la map.*/
        Hatchery * b1;               /**< Un pointeur vers la fabrique a utiliser pour spawn les insectes.*/
        QString tower2build;         /**< La tour que l'on vient d'acheter et que l'on doit placer.*/
        QList<Bug *> bugs;           /**< Une liste de pointeur vers tous les insectes présent dans la Scene.*/
        /**
         * Interface de addItem() spécialisé.
         * Permet d'ajouter un insecte en initialisant correctement son parent et an l'ajoutant à la liste spécifique aux insectes.
         */
        void addBug(Bug * bug);

    public:
        /**
         * Constructeur du rendu.
         * Crée un nouvelle objet pour gérer le rendu.
         */
        Render();
        /**
         * Destructeur de Render.
         * Désalloue correctement la mémoire puis quitte le jeu.
         */
        ~Render();
        /**
         * Méthode surchargée de QGraphicsScene.
         * Appelé automatiquement par Qt, permet de redessiner le fond de la scène.
         */
        void drawBackground(QPainter *painter, const QRectF & rect);
        /**
         * Donne les coordonnées de la case où se trouve l'objet graphique donnée.
         * Donne les coordonnées de la case où se trouve l'objet graphique donnée.
         * @param item Un pointeur vers l'objet dont on veut connaitre la position.
         * @return Les coordonnée de la case sous forme d'un QPoint.
         */
        QPoint square(QGraphicsItem & item);
        /**
         * Acesseur.
         * Retourne la position de l'arrivée.
         * @return les coordonnées de l'arrivée sous forme d'un QPoint.
         */
        QPoint goal();
        /**
         * Permet à un insecte de se diriger.
         * Donne à un insecte l'angle vers lequel se tourner pour suivre le chemin.
         * @param current La position actuelle de l'insecte.
         * @return L'angle vers lequel se diriger.
         */
        double getAngle(QPoint & current);
        /**
         * Catch les événements souris.
         * Surcharge de la méthode héritée de QGraphicsScene pour gérer les entrées souris.
         * @param mouseEvent L'événement souris générée par Qt.
         */
        void mousePressEvent(QGraphicsSceneMouseEvent * mouseEvent);
        /**
         * Permet aux tours de choisir leur prochaine cible.
         * Donne l'insecte le plus avancé sur le chemin à portée de la tour et d'un type de déplacement permettant d'être touché par la tour.
         * @param pos La position de la tour.
         * @param range La portée en case de la tour.
         * @param targetType Le(s) type(s) de cibles que la tour peut attaquer.
         * @return L'insecte à abattre.
         */
        Bug * getTarget(QPointF pos, double range, short int targetType);

    public slots:
        /**
         * Lance la prochaine Vague.
         * Lance la prochaine Vague en lisant le fichier de conguration dans map/.
         */
        void nextWave();
        /**
         * Crée le prochaine insecte de la vague.
         * Appelle la fabrique pour spawn l'insecte suivant de la vague donnée par la liste wave.
         */
        void nextBug();
        /**
         * Message indiquant l'achat d'une tour à la scène.
         * Message indiquant l'achat d'une tour à la scène.
         * @param type Le type de tour à placer.
         */
        void towerBought(QString type);
        /**
         * Arrivée d'un insecte.
         * Quand un insecte arrive la scène le détruit et fais perdre une vie (emit loseLife()) au joueur.
         * @param bug Un pointeur vers l'insecte qui vient d'arriver à la fin.
         */
        void bugFinish(Bug * bug);
        /**
         * Mort d'un insecte.
         * Quand un insecte est tué, la scène le détruit, appelant ses caractéristiques spéciales et ajoute un crédit au joueur.
         * @param bug Un pointeur vers l'insecte qui vient d'arriver à la fin.
         */
        void bugKilled(Bug * bug);
        /**
         * Ajout d'un projectile.
         * Lorsqu'un projectile est tirée, Render l'ajoute à la scène.
         * @param missile Un pointeur vers le projectile qui vient d'être tiré.
         */
        void addProjectile(Projectile * missile);
        /**
         * Vente d'une tour.
         * Lorsqu'une défense est vendu, la scène la détruit.
         * @param tower Un pointeur vers la tour à détruire.
         */
        void destroyTower(Tower * tower);
        /**
         * explosion d'un projectile.
         * Lorsqu'un projectile explose, la scène le détruit.
         * @param missile Un pointeur vers le projectile à faire exploser.
         */
        void explodingProjectile(Projectile * missile);
        /**
         * Pause.
         * Lance la pause.
         */
        void stop();
        /**
         * Fin pause.
         * Relance le jeu
         */
        void restart();

    signals:
        /**
         * Nouvelle vaque.
         * Indique à l'UI de changer le nom de la vague en cours.
         * @param name le nom de la nouvelle vague.
         */
        void newWaveName(QString name);
        /**
         * Perte d'une vie.
         * Indique à l'UI que le joueur viens de perdre une vie.
         */
        void loseLife();
        /**
         * Gain d'un crédit.
         * Indique à l'UI de créditer le joueur pour un kill d'insecte.
         */
        void getCred();
        /**
         * Sélection d'une tour.
         * Indique à l'UI que le joueur vient de sélectionner une défense.
         * @param tower Un pointeur vers la défense sélectionnée.
         */
        void selectTower(Tower * tower);
        /**
         * Pause.
         * Stoppe le jeu.
         */
        void pause();
        /**
         * Fin pause.
         * Relance le jeu en cours.
         */
        void unpause();
};
#endif
