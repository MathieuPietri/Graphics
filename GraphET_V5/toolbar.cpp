#include "toolbar.h"
#include <QDebug>

ToolBar::ToolBar(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    barreDeStatut->addPermanentWidget(progressBar);

/* Barre de Menus
 * section fichier
 *
 *
*/
    connect(actionNouveauTableauAleatoire, SIGNAL(triggered()), this, SLOT(tableauAleatoire()));
    connect(actionOuvrirTableau, SIGNAL(triggered()), this, SLOT(tableauOuvrir()));
    connect(actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauvegarder()));
    connect(actionExporter, SIGNAL(triggered()), this, SLOT(exporter()));
    connect(actionImprimer, SIGNAL(triggered()), this, SLOT(imprimer()));


    /*
     * section edition
     *
     *
    */
    connect(actionAnnuler, SIGNAL(triggered()), this, SLOT(annuler()));
    connect(actionRestaurer, SIGNAL(triggered()), this, SLOT(restaurer()));
    connect(actionToutSelectionner, SIGNAL(triggered()), this, SLOT(totaleSelection()));
    connect(actionCopier, SIGNAL(triggered()), this, SLOT(copier()));
    connect(actionFusionner, SIGNAL(triggered()), this, SLOT(fusion()));


    /*
     * section affichage
     *
     *
    */
    connect(actionZoomPlus, SIGNAL(triggered()), this, SLOT(zoomPlus()));
    connect(actionZoomMoins, SIGNAL(triggered()), this, SLOT(zoomMoins()));
    connect(actionPleinEcran, SIGNAL(triggered()), this, SLOT(pleinEcran()));
    connect(actionBarreDEtat, SIGNAL(triggered()), this, SLOT(barreDEtats()));
    connect(actionBarreDOutils, SIGNAL(triggered()), this, SLOT(barreDOutils()));


    /*
     * section preferences
     *
     *
    */
    connect(actionModeSombre, SIGNAL(triggered()), this, SLOT(modeSombre()));
    connect(actionLangues, SIGNAL(triggered()), this, SLOT(langues()));
    connect(actionChoisirCouleurs, SIGNAL(triggered()), this, SLOT(choixCouleurs()));



    /*
     *  action aide
     *
     *
    */
    connect(actionAide, SIGNAL(triggered()), this, SLOT(aide()));


/*  Barre d'Outils (Icônes)
 *
 *
 *
 */
    connect(actionAnnulerTool, SIGNAL(triggered()), this, SLOT(annuler()));
    connect(actionRestaurerTool, SIGNAL(triggered()), this, SLOT(restaurer()));
    connect(actionZoomPlusTool, SIGNAL(triggered()), this, SLOT(zoomPlus()));
    connect(actionZoomMoinsTool, SIGNAL(triggered()), this, SLOT(zoomMoins()));
    connect(actionFusionTool, SIGNAL(triggered()), this, SLOT(fusion()));
    connect(actionOuvrirTool, SIGNAL(triggered()), this, SLOT(tableauOuvrir()));
    connect(actionChoisirCouleurTool, SIGNAL(triggered()), this, SLOT(choixCouleurs()));
}

/*
 * section Fichier
 *
*/
void ToolBar::tableauAleatoire()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::tableauOuvrir()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::sauvegarder()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::exporter()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::imprimer()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}


/*
 * section Edition
 *
*/
void ToolBar::annuler()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::restaurer()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::totaleSelection()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::copier()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::fusion()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}


/*
 * section Affichage
 *
*/
void ToolBar::zoomPlus()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::zoomMoins()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::pleinEcran()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::barreDEtats()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::barreDOutils()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}


/*
 * section Preferences
 *
*/
void ToolBar::modeSombre()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::langues()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::choixCouleurs()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}


/*
 * section Aide
 *
*/
void ToolBar::aide()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

/*
ToolBar::~ToolBar()
{
    delete this;
}
*/
