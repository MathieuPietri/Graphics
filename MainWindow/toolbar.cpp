#include "toolbar.h"
#include "Graph/csv.h"
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
    connect(actionEnregistrerSous, SIGNAL(triggered()), this, SLOT(enregistrerSous()));
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
    connect(actionChoisirCouleurs, SIGNAL(triggered()), this, SLOT(choixCouleurs()));


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




    /*
     *  action aide
     *
     *
    */
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(aboutGraphEt()));


/*  Barre d'Outils (Icônes)
 *
 *
 *
 */
    connect(actionEnregistrerTool, SIGNAL(triggered()), this, SLOT(sauvegarder()));
    connect(actionEnregistrerSousTool, SIGNAL(triggered()), this, SLOT(enregistrerSous()));
    connect(actionAnnulerTool, SIGNAL(triggered()), this, SLOT(annuler()));
    connect(actionRestaurerTool, SIGNAL(triggered()), this, SLOT(restaurer()));
    connect(actionZoomPlusTool, SIGNAL(triggered()), this, SLOT(zoomPlus()));
    connect(actionZoomMoinsTool, SIGNAL(triggered()), this, SLOT(zoomMoins()));
    connect(actionFusionTool, SIGNAL(triggered()), this, SLOT(fusion()));
    connect(actionOuvrirTool, SIGNAL(triggered()), this, SLOT(tableauOuvrir()));
    connect(actionChoisirCouleurTool, SIGNAL(triggered()), this, SLOT(choixCouleurs()));
    connect(actionNouveauTableauAleatoireTool, SIGNAL(triggered()), this, SLOT(tableauAleatoire()));


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
    //Ouverture d'un fichier
   QString fichier = QFileDialog::getOpenFileName(this,"Ouvrir un fichier", QString(), "Tableurs (*.csv *.txt)");
   QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" +fichier);

   std::string filePath = fichier.toStdString();


   //TEMPORAIRE

   //MainWidget::addTab();
   mainWidget->fillFirstTable(openFromCSV(filePath));
}

void ToolBar::sauvegarder()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::enregistrerSous()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QString SaveFile = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Fichiers GraphET (*.grep)");
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

void ToolBar::choixCouleurs()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QColor color = QColorDialog::getColor(Qt::white, this);

    QPalette palette;
    palette.setColor(QPalette::ButtonText, color);
    //this -> setPalette(palette);

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

    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    qApp->setPalette(p);
}

void ToolBar::langues()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}




/*
 * section Aide
 *
*/
void ToolBar::aboutGraphEt()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, "About GraphET", "Cette application a été créer par :\n Alix, Anthony, Mathieu, Maxime, Oriane et Quentin \n en février 2020. \n");
}

/*
ToolBar::~ToolBar()
{
    delete this;
}
*/
