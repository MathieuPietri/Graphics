/********************************************************************************
** Form generated from reading UI file 'toolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBAR_H
#define UI_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBar
{
public:
    QAction *actionNouveauTableauAleatoire;
    QAction *actionOuvrirTableau;
    QAction *actionSauvegarder;
    QAction *actionExporter;
    QAction *actionImprimer;
    QAction *actionAnnuler;
    QAction *actionRestaurer;
    QAction *actionZoomPlus;
    QAction *actionZoomMoins;
    QAction *actionPleinEcran;
    QAction *actionBarreDEtat;
    QAction *actionBarreDOutils;
    QAction *actionModeSombre;
    QAction *actionLangues;
    QAction *actionAbout;
    QAction *actionToutSelectionner;
    QAction *actionCopier;
    QAction *actionAnnulerTool;
    QAction *actionRestaurerTool;
    QAction *actionZoomPlusTool;
    QAction *actionZoomMoinsTool;
    QAction *actionFusionTool;
    QAction *actionOuvrirTool;
    QAction *actionChoisirCouleurTool;
    QAction *actionFusionner;
    QAction *actionEnregistrerSous;
    QAction *actionImageTailleReelle;
    QAction *actionManuelAide;
    QAction *actionApercuAvantImpression;
    QAction *actionChoisirCouleurs;
    QAction *actionEnregistrerTool;
    QAction *actionEnregistrerSousTool;
    QAction *actionNouveauTableauAleatoireTool;
    QAction *actionExporterTool;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QMenu *menuPreferences;
    QMenu *menuAide;
    QToolBar *toolBar;
    QStatusBar *barreDeStatut;

    void setupUi(QMainWindow *ToolBar)
    {
        if (ToolBar->objectName().isEmpty())
            ToolBar->setObjectName(QString::fromUtf8("ToolBar"));
        ToolBar->resize(900, 600);
        ToolBar->setMinimumSize(QSize(900, 600));
        actionNouveauTableauAleatoire = new QAction(ToolBar);
        actionNouveauTableauAleatoire->setObjectName(QString::fromUtf8("actionNouveauTableauAleatoire"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Icones/icons8-ajouter-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNouveauTableauAleatoire->setIcon(icon);
        actionOuvrirTableau = new QAction(ToolBar);
        actionOuvrirTableau->setObjectName(QString::fromUtf8("actionOuvrirTableau"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Icones/icons8-ajouter-un-onglet-48(1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrirTableau->setIcon(icon1);
        actionSauvegarder = new QAction(ToolBar);
        actionSauvegarder->setObjectName(QString::fromUtf8("actionSauvegarder"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Icones/icons8-sauvegarder-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSauvegarder->setIcon(icon2);
        actionExporter = new QAction(ToolBar);
        actionExporter->setObjectName(QString::fromUtf8("actionExporter"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../Icones/icons8-image-enti\303\250re-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExporter->setIcon(icon3);
        actionImprimer = new QAction(ToolBar);
        actionImprimer->setObjectName(QString::fromUtf8("actionImprimer"));
        actionAnnuler = new QAction(ToolBar);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../Icones/icons8-annuler-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnnuler->setIcon(icon4);
        actionRestaurer = new QAction(ToolBar);
        actionRestaurer->setObjectName(QString::fromUtf8("actionRestaurer"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../Icones/icons8-refaire-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestaurer->setIcon(icon5);
        actionZoomPlus = new QAction(ToolBar);
        actionZoomPlus->setObjectName(QString::fromUtf8("actionZoomPlus"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../Icones/icons8-zoomer-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomPlus->setIcon(icon6);
        actionZoomMoins = new QAction(ToolBar);
        actionZoomMoins->setObjectName(QString::fromUtf8("actionZoomMoins"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../Icones/icons8-d\303\251zoomer-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomMoins->setIcon(icon7);
        actionPleinEcran = new QAction(ToolBar);
        actionPleinEcran->setObjectName(QString::fromUtf8("actionPleinEcran"));
        actionBarreDEtat = new QAction(ToolBar);
        actionBarreDEtat->setObjectName(QString::fromUtf8("actionBarreDEtat"));
        actionBarreDEtat->setCheckable(true);
        actionBarreDEtat->setChecked(true);
        actionBarreDOutils = new QAction(ToolBar);
        actionBarreDOutils->setObjectName(QString::fromUtf8("actionBarreDOutils"));
        actionBarreDOutils->setCheckable(true);
        actionBarreDOutils->setChecked(true);
        actionModeSombre = new QAction(ToolBar);
        actionModeSombre->setObjectName(QString::fromUtf8("actionModeSombre"));
        actionModeSombre->setCheckable(true);
        actionLangues = new QAction(ToolBar);
        actionLangues->setObjectName(QString::fromUtf8("actionLangues"));
        actionAbout = new QAction(ToolBar);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionToutSelectionner = new QAction(ToolBar);
        actionToutSelectionner->setObjectName(QString::fromUtf8("actionToutSelectionner"));
        actionCopier = new QAction(ToolBar);
        actionCopier->setObjectName(QString::fromUtf8("actionCopier"));
        actionAnnulerTool = new QAction(ToolBar);
        actionAnnulerTool->setObjectName(QString::fromUtf8("actionAnnulerTool"));
        actionAnnulerTool->setIcon(icon4);
        QFont font;
        actionAnnulerTool->setFont(font);
        actionRestaurerTool = new QAction(ToolBar);
        actionRestaurerTool->setObjectName(QString::fromUtf8("actionRestaurerTool"));
        actionRestaurerTool->setEnabled(true);
        actionRestaurerTool->setIcon(icon5);
        actionRestaurerTool->setVisible(true);
        actionZoomPlusTool = new QAction(ToolBar);
        actionZoomPlusTool->setObjectName(QString::fromUtf8("actionZoomPlusTool"));
        actionZoomPlusTool->setIcon(icon6);
        actionZoomMoinsTool = new QAction(ToolBar);
        actionZoomMoinsTool->setObjectName(QString::fromUtf8("actionZoomMoinsTool"));
        actionZoomMoinsTool->setIcon(icon7);
        actionFusionTool = new QAction(ToolBar);
        actionFusionTool->setObjectName(QString::fromUtf8("actionFusionTool"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../Icones/icons8-pincer-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFusionTool->setIcon(icon8);
        actionOuvrirTool = new QAction(ToolBar);
        actionOuvrirTool->setObjectName(QString::fromUtf8("actionOuvrirTool"));
        actionOuvrirTool->setIcon(icon1);
        actionChoisirCouleurTool = new QAction(ToolBar);
        actionChoisirCouleurTool->setObjectName(QString::fromUtf8("actionChoisirCouleurTool"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../Icones/icons8-cercle-rvb-40.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChoisirCouleurTool->setIcon(icon9);
        actionFusionner = new QAction(ToolBar);
        actionFusionner->setObjectName(QString::fromUtf8("actionFusionner"));
        actionFusionner->setIcon(icon8);
        actionEnregistrerSous = new QAction(ToolBar);
        actionEnregistrerSous->setObjectName(QString::fromUtf8("actionEnregistrerSous"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../Icones/icons8-enregistrer-sous-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrerSous->setIcon(icon10);
        actionImageTailleReelle = new QAction(ToolBar);
        actionImageTailleReelle->setObjectName(QString::fromUtf8("actionImageTailleReelle"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../Icones/icons8-zoom-taille-r\303\251elle-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImageTailleReelle->setIcon(icon11);
        actionManuelAide = new QAction(ToolBar);
        actionManuelAide->setObjectName(QString::fromUtf8("actionManuelAide"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("../Icones/icons8-aide-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManuelAide->setIcon(icon12);
        actionApercuAvantImpression = new QAction(ToolBar);
        actionApercuAvantImpression->setObjectName(QString::fromUtf8("actionApercuAvantImpression"));
        actionChoisirCouleurs = new QAction(ToolBar);
        actionChoisirCouleurs->setObjectName(QString::fromUtf8("actionChoisirCouleurs"));
        actionChoisirCouleurs->setIcon(icon9);
        actionEnregistrerTool = new QAction(ToolBar);
        actionEnregistrerTool->setObjectName(QString::fromUtf8("actionEnregistrerTool"));
        actionEnregistrerTool->setIcon(icon2);
        actionEnregistrerSousTool = new QAction(ToolBar);
        actionEnregistrerSousTool->setObjectName(QString::fromUtf8("actionEnregistrerSousTool"));
        actionEnregistrerSousTool->setIcon(icon10);
        actionNouveauTableauAleatoireTool = new QAction(ToolBar);
        actionNouveauTableauAleatoireTool->setObjectName(QString::fromUtf8("actionNouveauTableauAleatoireTool"));
        actionNouveauTableauAleatoireTool->setIcon(icon);
        actionExporterTool = new QAction(ToolBar);
        actionExporterTool->setObjectName(QString::fromUtf8("actionExporterTool"));
        actionExporterTool->setIcon(icon3);
        centralWidget = new QWidget(ToolBar);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 539));

        verticalLayout->addWidget(widget);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        ToolBar->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ToolBar);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 22));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        menuBar->setNativeMenuBar(false);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuPreferences = new QMenu(menuBar);
        menuPreferences->setObjectName(QString::fromUtf8("menuPreferences"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        ToolBar->setMenuBar(menuBar);
        toolBar = new QToolBar(ToolBar);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        toolBar->setMinimumSize(QSize(32, 32));
        toolBar->setMovable(false);
        ToolBar->addToolBar(Qt::TopToolBarArea, toolBar);
        barreDeStatut = new QStatusBar(ToolBar);
        barreDeStatut->setObjectName(QString::fromUtf8("barreDeStatut"));
        ToolBar->setStatusBar(barreDeStatut);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuPreferences->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouveauTableauAleatoire);
        menuFichier->addAction(actionOuvrirTableau);
        menuFichier->addSeparator();
        menuFichier->addAction(actionSauvegarder);
        menuFichier->addAction(actionEnregistrerSous);
        menuFichier->addAction(actionExporter);
        menuFichier->addAction(actionApercuAvantImpression);
        menuFichier->addAction(actionImprimer);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionRestaurer);
        menuEdition->addSeparator();
        menuEdition->addAction(actionToutSelectionner);
        menuEdition->addSeparator();
        menuEdition->addAction(actionCopier);
        menuEdition->addSeparator();
        menuEdition->addAction(actionFusionner);
        menuEdition->addAction(actionChoisirCouleurs);
        menuAffichage->addAction(actionZoomPlus);
        menuAffichage->addAction(actionZoomMoins);
        menuAffichage->addAction(actionImageTailleReelle);
        menuAffichage->addAction(actionPleinEcran);
        menuAffichage->addSeparator();
        menuAffichage->addAction(actionBarreDEtat);
        menuAffichage->addAction(actionBarreDOutils);
        menuPreferences->addAction(actionModeSombre);
        menuPreferences->addSeparator();
        menuPreferences->addAction(actionLangues);
        menuPreferences->addSeparator();
        menuAide->addAction(actionManuelAide);
        menuAide->addAction(actionAbout);
        toolBar->addAction(actionNouveauTableauAleatoireTool);
        toolBar->addAction(actionOuvrirTool);
        toolBar->addAction(actionEnregistrerTool);
        toolBar->addAction(actionEnregistrerSousTool);
        toolBar->addAction(actionExporterTool);
        toolBar->addAction(actionAnnulerTool);
        toolBar->addAction(actionRestaurerTool);
        toolBar->addAction(actionZoomPlusTool);
        toolBar->addAction(actionZoomMoinsTool);
        toolBar->addAction(actionFusionTool);
        toolBar->addAction(actionChoisirCouleurTool);

        retranslateUi(ToolBar);

        QMetaObject::connectSlotsByName(ToolBar);
    } // setupUi

    void retranslateUi(QMainWindow *ToolBar)
    {
        ToolBar->setWindowTitle(QCoreApplication::translate("ToolBar", "ToolBar", nullptr));
        actionNouveauTableauAleatoire->setText(QCoreApplication::translate("ToolBar", "Nouveau tableau aleatoire...", nullptr));
#if QT_CONFIG(shortcut)
        actionNouveauTableauAleatoire->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOuvrirTableau->setText(QCoreApplication::translate("ToolBar", "Ouvrir tableau...", nullptr));
#if QT_CONFIG(shortcut)
        actionOuvrirTableau->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSauvegarder->setText(QCoreApplication::translate("ToolBar", "Enregistrer", nullptr));
#if QT_CONFIG(shortcut)
        actionSauvegarder->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExporter->setText(QCoreApplication::translate("ToolBar", "Exporter...", nullptr));
        actionImprimer->setText(QCoreApplication::translate("ToolBar", "Imprimer...", nullptr));
#if QT_CONFIG(shortcut)
        actionImprimer->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAnnuler->setText(QCoreApplication::translate("ToolBar", "Annuler", nullptr));
#if QT_CONFIG(shortcut)
        actionAnnuler->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRestaurer->setText(QCoreApplication::translate("ToolBar", "Restaurer", nullptr));
#if QT_CONFIG(shortcut)
        actionRestaurer->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomPlus->setText(QCoreApplication::translate("ToolBar", "Zoom avant", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomPlus->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl++", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomMoins->setText(QCoreApplication::translate("ToolBar", "Zoom arriere", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomMoins->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPleinEcran->setText(QCoreApplication::translate("ToolBar", "Plein ecran", nullptr));
#if QT_CONFIG(shortcut)
        actionPleinEcran->setShortcut(QCoreApplication::translate("ToolBar", "F11", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBarreDEtat->setText(QCoreApplication::translate("ToolBar", "Barre d'etats", nullptr));
        actionBarreDOutils->setText(QCoreApplication::translate("ToolBar", "Barre d'outils", nullptr));
        actionModeSombre->setText(QCoreApplication::translate("ToolBar", "Mode sombre", nullptr));
#if QT_CONFIG(shortcut)
        actionModeSombre->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLangues->setText(QCoreApplication::translate("ToolBar", "Langues...", nullptr));
        actionAbout->setText(QCoreApplication::translate("ToolBar", "A propos...", nullptr));
        actionToutSelectionner->setText(QCoreApplication::translate("ToolBar", "Tout selectionner", nullptr));
#if QT_CONFIG(shortcut)
        actionToutSelectionner->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopier->setText(QCoreApplication::translate("ToolBar", "Copier", nullptr));
#if QT_CONFIG(shortcut)
        actionCopier->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAnnulerTool->setText(QCoreApplication::translate("ToolBar", "Annuler Tool", nullptr));
#if QT_CONFIG(tooltip)
        actionAnnulerTool->setToolTip(QCoreApplication::translate("ToolBar", "Annuler", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAnnulerTool->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRestaurerTool->setText(QCoreApplication::translate("ToolBar", "Restaurer Tool", nullptr));
#if QT_CONFIG(shortcut)
        actionRestaurerTool->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomPlusTool->setText(QCoreApplication::translate("ToolBar", "Zoom Tool Plus", nullptr));
        actionZoomMoinsTool->setText(QCoreApplication::translate("ToolBar", "Zoom Tool Moins", nullptr));
        actionFusionTool->setText(QCoreApplication::translate("ToolBar", "Fusion Tool", nullptr));
        actionOuvrirTool->setText(QCoreApplication::translate("ToolBar", "Ouvrir Tool", nullptr));
        actionChoisirCouleurTool->setText(QCoreApplication::translate("ToolBar", "Choisir Couleur Tool", nullptr));
        actionFusionner->setText(QCoreApplication::translate("ToolBar", "Fusionner", nullptr));
#if QT_CONFIG(shortcut)
        actionFusionner->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregistrerSous->setText(QCoreApplication::translate("ToolBar", "Enregistrer sous...", nullptr));
#if QT_CONFIG(shortcut)
        actionEnregistrerSous->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImageTailleReelle->setText(QCoreApplication::translate("ToolBar", "Image taille r\303\251elle ", nullptr));
#if QT_CONFIG(shortcut)
        actionImageTailleReelle->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+0", nullptr));
#endif // QT_CONFIG(shortcut)
        actionManuelAide->setText(QCoreApplication::translate("ToolBar", "Manuel d'aide...", nullptr));
#if QT_CONFIG(shortcut)
        actionManuelAide->setShortcut(QCoreApplication::translate("ToolBar", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionApercuAvantImpression->setText(QCoreApplication::translate("ToolBar", "Aper\303\247u avant impression", nullptr));
#if QT_CONFIG(shortcut)
        actionApercuAvantImpression->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Shift+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionChoisirCouleurs->setText(QCoreApplication::translate("ToolBar", "Changer la couleur d'un noeud", nullptr));
        actionEnregistrerTool->setText(QCoreApplication::translate("ToolBar", "Enregistrer", nullptr));
#if QT_CONFIG(tooltip)
        actionEnregistrerTool->setToolTip(QCoreApplication::translate("ToolBar", "Enregistrer", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionEnregistrerTool->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnregistrerSousTool->setText(QCoreApplication::translate("ToolBar", "EnregistrerSous", nullptr));
#if QT_CONFIG(shortcut)
        actionEnregistrerSousTool->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNouveauTableauAleatoireTool->setText(QCoreApplication::translate("ToolBar", "NouveauTableauAleatoire", nullptr));
#if QT_CONFIG(shortcut)
        actionNouveauTableauAleatoireTool->setShortcut(QCoreApplication::translate("ToolBar", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExporterTool->setText(QCoreApplication::translate("ToolBar", "Exporter", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("ToolBar", "Fichier", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("ToolBar", "Edition", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("ToolBar", "Affichage", nullptr));
        menuPreferences->setTitle(QCoreApplication::translate("ToolBar", "Preferences", nullptr));
        menuAide->setTitle(QCoreApplication::translate("ToolBar", "Aide", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("ToolBar", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBar: public Ui_ToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBAR_H
