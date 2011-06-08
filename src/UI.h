#ifndef Ui
#define Ui

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QLCDNumber>
#include <QString>

#include "Tower.h"

/**
 * Classe de l'interface graphique.
 * Gère l'ensemble des éléments de l'interface graphique affichée à droite.
 */
class UI : public QWidget
{
    Q_OBJECT

    private:
        QGroupBox * tower;       /**< Regroupe les éléments du magasin de défenses.*/
        QGroupBox * stats;       /**< Regroupe les éléments ayant attrait à la défense sélectionnée.*/
        QPushButton * sell;      /**< Le bouton pour vendre la tour sélectionnée.*/
        QPushButton * upg;       /**< Le bouton pour améliorer la tour sélectionnée.*/
        QPushButton * water;     /**< Le bouton pour acheter un pistolet à eau.*/
        QPushButton * sling;     /**< Le bouton pour acheter un lance-pierre.*/
        QPushButton * bowling;   /**< Le bouton pour engager un joueur de pétanque.*/
        QPushButton * paintball; /**< Le bouton pour acheter un Paintball.*/
        QLabel * name;           /**< Le texte 'Type : '.*/
        QLabel * lvl;            /**< Le texte 'Niveau : '.*/
        QLabel * range;          /**< Le texte 'portée : '.*/
        QLabel * firerate;       /**< Le texte 'cadence : '.*/
        QLabel * t_name;         /**< Le type de la tour sélectionnée.*/
        QLabel * t_lvl;          /**< Le niveau de la tour sélectionnée.*/
        QLabel * t_range;        /**< La portée de la tour sélectionnée.*/
        QLabel * t_firerate;     /**< La cadence de tir de la tour sélectionnée.*/
        QLabel * wave;           /**< le nom de la vague en cours.*/
        QLabel * cred_txt;       /**< Le texte 'crédits : '.*/
        QLabel * life_txt;       /**< Le texte 'vie : '.*/
        QLCDNumber * cred;       /**< L'affciheur de crédits restants.*/
        QLCDNumber * life;       /**< L'afficheur de vie restantes.*/
        Tower * selected;        /**< Un pointeur vers la tour sélectionnée actuellement.*/

    public:
        QPushButton *start;      /**< Le bouton pour lancer la vague suivante.*/
        /**
         * Constructeur de UI. initialise l'interface utilisateur.
         * @param parent Le widge parent de l'UI.
         */
        UI(QWidget * parent);

    public slots:
        /**
         * Changement de vague.
         * Change le nom de la vague courante.
         * @param name Le nom de la nouvelle vague.
         */
        void setWaveName(QString name);
        /**
         * Gain d'un crédit. Incrémente de 1 les crédit du joueur.
         */
        void addCred();
        /**
         * Perte de vie. Décrémente de 1 le total de vies du joueur.
         */
        void loseLife();
        /**
         * Vague suivante. Reçoit le signal du bouton "lancer la vague suivante".
         */
        void startWave();
        /**
         * Achat d'une défense "pistolet à eau".
         * Vérifie si le joueur possède suffisament de crédit puis décompte le prix.
         */
        void buyWaterTower();
        /**
         * Achat d'une défense "lance-pierres".
         * Vérifie si le joueur possède suffisament de crédit puis décompte le prix.
         */
        void buySlingshotTower();
        /**
         * Achat d'une défense "paintball".
         * Vérifie si le joueur possède suffisament de crédit puis décompte le prix.
         */
        void buyPaintballTower();
        /**
         * Achat d'une défense "pétanque".
         * Vérifie si le joueur possède suffisament de crédit puis décompte le prix.
         */
        void buyBowlingTower();
        /**
         * Sélection d'une tour.
         * Affiche les caractérisque de la défense sélectionnée.
         * @param tower Un pointeur vers la nouvelle défense sélectionnée.
         */
        void selectTower(Tower * tower);
        /**
         * Vente de la tour sélectionnée.
         * Reçoit le signal du bouton "Vendre" et recrédite le joueur du moitié du prix de la défense.
         */
        void sellSelectedTower();
        /**
         * Amélioration de la défense sélectionnée.
         * Reçoit le signal du bouton "améliorer" et améliore la tour si les crédits sont suffisants.
         */
        void upgradeSelectedTower();

    signals:
        /**
         * Achat d'une tour. Indique au Render de placer la défense achetée.
         * @param type Le type de la défense achetée.
         */
        void buyTower(QString type);
        /**
         * Vague suivante. Indique au Render de lancer la vague suivante.
         */
        void nextWave();
        /**
         * Vente d'une défense. Indique au Render de détruire une défense vendue.
         * @param tower Un pointeur vers la défense à détruire.
         */
        void towerSold(Tower * tower);
        /**
         * Signal de défaite. Indique au programme de stopper le jeu.
         */
        void defeat();
};
#endif
