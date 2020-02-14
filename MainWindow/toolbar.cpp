#include "toolbar.h"
#include "Graph/csv.h"
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QErrorMessage>
#include "helpdialog.h"
#include "graphaction.h"


ToolBar::ToolBar(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    barreDeStatut->addPermanentWidget(nbNodesLabel);
    barreDeStatut->addPermanentWidget(nbEdgesLabel);
    barreDeStatut->addPermanentWidget(nodeWeightLabel);
    barreDeStatut->addPermanentWidget(nbNodesSelected);
    barreDeStatut->addPermanentWidget(progressBar);

    /*
    progressBar->setVisible(false);
    nbNodesLabel->setVisible(false);
    nbEdgesLabel->setVisible(false);
    nodeWeightLabel->setVisible(false);
    nbNodesSelected->setVisible(false);


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
    connect(actionImageTailleReelle, SIGNAL(triggered()), this, SLOT(zoomTailleReelle()));
    connect(actionPleinEcran, SIGNAL(changed()), this, SLOT(pleinEcran()));
    connect(actionBarreDeStatus, SIGNAL(triggered()), this, SLOT(BarreDeStatus()));
    connect(actionBarreDOutils, SIGNAL(changed()), this, SLOT(barreDOutils()));


    /*
     * section preferences
     *
     *
    */
    connect(actionModeSombre, SIGNAL(changed()), this, SLOT(modeSombre()));
    connect(actionLangues, SIGNAL(triggered()), this, SLOT(langues()));




    /*
     *  action aide
     *
     *
    */
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(aboutGraphEt()));
    connect(actionManuelAide, SIGNAL(triggered()), this, SLOT(aide()));

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
    // TODO donner nullptr comme nom


    try{
        vector<vector<string>> file = createButNotFromCSV();
        mainWidget->addDataSet(file, nullptr);
    } catch (exception &e) {
        string str = e.what();
        cout << str;
    }

}

void ToolBar::tableauOuvrir()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    //Ouverture d'un fichier

   QString fichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"),
                                                    "../documents_CSV", tr("Tableurs (*.csv *.txt, *gret)"), nullptr, QFileDialog::DontUseNativeDialog);

   string filePath = fichier.toStdString();

   if(fichier != NULL){
       try {
           vector<vector<string>> file = openFromCSV(filePath);
           mainWidget->addDataSet(file, QString::fromStdString(filePath));
           QMessageBox::information(this, tr("Fichier"), tr("Vous avez sélectionné :\n") + fichier);
       } catch (exception &e) {
            string str = e.what();
            cout << str;
       }
   }
   else {
       cout << "Annulation de l'ouverture d'un tableau ";
   }

}

void ToolBar::sauvegarder()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    if(mainWidget->getCurrentTabContent() != nullptr){
        if(mainWidget->getCurrentTabContent()->getFileName() != nullptr){
            QString nomFichier = mainWidget->getCurrentTabContent()->getFileName();
            modifierContenu(nomFichier);
        }
        else {
            enregistrerSous();
        }
    }
    else {
        QErrorMessage * erreur = new QErrorMessage();
        if(messageAlive){
            erreur->showMessage("Impossible de sauvegarder du vide, voyons ! (Au fait, ne décochez pas la case s'il vous plait, vous risqueriez de me tuer.");
            messageAlive = false;
        }
        else
            erreur->showMessage("VOUS PENSIEZ ME DETRUIRE ???? JE SUIS IMMORTEL !!! MWAHAHAHAHAHAH");
    }
}

void ToolBar::enregistrerSous()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    //QString SaveFile = QFileDialog::getSaveFileName(this, tr("Enregistrer un fichier"), QString(), tr("Fichiers GraphET (*.gret)"));

    QString nomFichier = QFileDialog::getSaveFileName(this, tr("Sauvegarder Graphe"),
                                                        "../documents_GRAPHE", tr("NINJA (*.gret)"), nullptr, QFileDialog::DontUseNativeDialog);

    if(nomFichier.isEmpty())
        cout << "ET C'EST LE RIP POUR LE JOUEUR FRANCAIS";
    else {
        cout << nomFichier.toStdString();
        if(!nomFichier.toStdString().find('.'))
            nomFichier.append(".gret");
        modifierContenu(nomFichier);
        mainWidget->getCurrentTabContent()->setFileName(nomFichier);
        QString nomFichierSansLePASSNAVIGO = QString::fromStdString(MainWidget::getNameFromPath(nomFichier));
        mainWidget->renameCurrentTab(nomFichierSansLePASSNAVIGO);
        }
}

void ToolBar::modifierContenu(QString nomFichier)
{
    QFile data(nomFichier);
    if(data.open(QFile::WriteOnly | QFile ::Truncate)) {

        //TODOUDOU
        /*
        TabContentWidget *interieurOfTab = new TabContentWidget();
        TabContentWidget & interieurOfTab_ = *interieurOfTab;

        QTextStream out(&data);
        out << translateToGret(interieurOfTab_);
        */
    }
}

void ToolBar::exporter()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, tr("Fonctionnalité disponible bientôt"), tr("Cette fonctionnalité sera disponible très prochainement !"));
}

void ToolBar::imprimer()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, tr("Fonctionnalité disponible bientôt"), tr("Cette fonctionnalité sera disponible très prochainement !"));
}


/*
 * section Edition
 *
*/
void ToolBar::annuler()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    mainWidget->getCurrentTabContent()->undoLast();
}

void ToolBar::restaurer()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    mainWidget->getCurrentTabContent()->redoLast();
}

void ToolBar::totaleSelection()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    Graph *graph = mainWidget->getCurrentTabContent()->getGraph();

    if(graph->getSelectionState() == 0) {
        graph->changeSelectionState();
        for(Node *n : graph->getNodes()) n->select();
    }
    else {
        graph->changeSelectionState();
        for(Node *n : graph->getNodes()) n->unselect();
    }
}

void ToolBar::copier()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, tr("Fonctionnalité disponible bientôt"), tr("Cette fonctionnalité sera disponible très prochainement !"));
}

void ToolBar::fusion()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    mainWidget->getCurrentTabContent()->getGraph()->mergeNodes();
}

void ToolBar::choixCouleurs()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();

    QColor color = QColorDialog::getColor(Qt::white, this, nullptr, QColorDialog::DontUseNativeDialog);

    QPalette palette;
    palette.setColor(QPalette::ButtonText, color);
    //this -> setPalette(palette);
    vector<Node*> selectedNodes = mainWidget->getCurrentTabContent()->getGraph()->getSelectedNodes();
    mainWidget->getCurrentTabContent()->addGraphAction(new ColorChangedAction(selectedNodes, color));

    mainWidget->getCurrentTabContent()->getGraph()->colorationSelectedNodes(color);

}

/*
 * section Affichage
 *
*/
void ToolBar::zoomPlus()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    mainWidget->getCurrentTabContent()->getGraphArea().scale(1.3, 1.3);
}

void ToolBar::zoomMoins()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    mainWidget->getCurrentTabContent()->getGraphArea().scale(0.8, 0.8);
}

void ToolBar::zoomTailleReelle()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
}

void ToolBar::pleinEcran()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    if(actionPleinEcran->isChecked()){
        this->showFullScreen();
    }else {
        this->showNormal();
        //this->showMaximized();
    }

}

void ToolBar::BarreDeStatus()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    if(actionBarreDeStatus->isChecked()){
        this->barreDeStatut->show();
        qDebug() << "Bar des Statues pas caché";
    }else {
        this->barreDeStatut->hide();
        qDebug() << "Bar des Statues caché";

    }
}

void ToolBar::barreDOutils()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    if(actionBarreDOutils->isChecked()){
        this->toolBar->show();
        qDebug() << "toolBar pas caché";
    }else {
        this->toolBar->hide();
        qDebug() << "toolBar caché";

    }
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

    if(actionModeSombre->isChecked()){
        qDebug() << "IsEnabled";
        p = qApp->palette();
        p.setColor(QPalette::Window, QColor(53,53,53));
        p.setColor(QPalette::Button, QColor(53,53,53));
        p.setColor(QPalette::Highlight, QColor(142,45,197));
        p.setColor(QPalette::ButtonText, QColor(255,255,255));
        qApp->setPalette(p);
    }else{
        qDebug() << "isDisabled";
        p = qApp->palette();
        p.setColor(QPalette::Window, QColor(239,239,239));
        p.setColor(QPalette::Button, QColor(239,239,239));
        p.setColor(QPalette::Highlight, QColor(48,140,198));
        p.setColor(QPalette::ButtonText, QColor(0,0,0));
        qApp->setPalette(p);
    }
}

void ToolBar::langues()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, tr("Fonctionnalité disponible bientôt"), tr("Cette fonctionnalité sera disponible très prochainement !"));
}




/*
 * section Aide
 *
*/
void ToolBar::aboutGraphEt()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    QMessageBox::information(this, tr("About GraphET"), tr("Cette application a été créé par :\n Alix Eymar,Maxime Graziano, Anthony Gignac,\n Mathieu Pietri, Oriane Donadio et Quentin Decloitre \n en février 2020. \n"));
}

void ToolBar::aide()
{
    qDebug() << __FUNCTION__ << "The event sender is" << sender();
    HelpDialog * help = new HelpDialog ();
    help->show();
}

/*
ToolBar::~ToolBar()
{
    delete this;
}
*/
