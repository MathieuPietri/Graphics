#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "ui_toolbar.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColor>
#include <QColorDialog>
#include <QPalette>
#include <QStyleFactory>

class ToolBar : public QMainWindow, private Ui::ToolBar
{
    Q_OBJECT

public:
    explicit ToolBar(QWidget *parent = nullptr);

protected slots:

    /* Barre de Menu section Fichier
     *
     *
    */
    void tableauAleatoire();
    void tableauOuvrir();
    void sauvegarder();
    void enregistrerSous();
    void exporter();
    void imprimer();


    /*
     * section Edition
     *
    */
    void annuler();
    void restaurer();
    void totaleSelection();
    void copier();
    void fusion();


    /*
     * section Affichage
     *
    */
    void zoomPlus();
    void zoomMoins();
    void pleinEcran();
    void barreDEtats();
    void barreDOutils();


    /*
     * section Preferences
     *
    */
    void modeSombre();
    void langues();
    void choixCouleurs();


    /*
     * section Aide
     *
    */
    void aboutGraphEt();
};

#endif // TOOLBAR_H
