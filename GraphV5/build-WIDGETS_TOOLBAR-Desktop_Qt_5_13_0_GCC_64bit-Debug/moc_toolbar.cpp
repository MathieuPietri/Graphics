/****************************************************************************
** Meta object code from reading C++ file 'toolbar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SignalsDONE/toolbar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToolBar_t {
    QByteArrayData data[22];
    char stringdata0[235];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolBar_t qt_meta_stringdata_ToolBar = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ToolBar"
QT_MOC_LITERAL(1, 8, 16), // "tableauAleatoire"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "tableauOuvrir"
QT_MOC_LITERAL(4, 40, 11), // "sauvegarder"
QT_MOC_LITERAL(5, 52, 15), // "enregistrerSous"
QT_MOC_LITERAL(6, 68, 8), // "exporter"
QT_MOC_LITERAL(7, 77, 8), // "imprimer"
QT_MOC_LITERAL(8, 86, 7), // "annuler"
QT_MOC_LITERAL(9, 94, 9), // "restaurer"
QT_MOC_LITERAL(10, 104, 15), // "totaleSelection"
QT_MOC_LITERAL(11, 120, 6), // "copier"
QT_MOC_LITERAL(12, 127, 6), // "fusion"
QT_MOC_LITERAL(13, 134, 8), // "zoomPlus"
QT_MOC_LITERAL(14, 143, 9), // "zoomMoins"
QT_MOC_LITERAL(15, 153, 10), // "pleinEcran"
QT_MOC_LITERAL(16, 164, 11), // "barreDEtats"
QT_MOC_LITERAL(17, 176, 12), // "barreDOutils"
QT_MOC_LITERAL(18, 189, 10), // "modeSombre"
QT_MOC_LITERAL(19, 200, 7), // "langues"
QT_MOC_LITERAL(20, 208, 13), // "choixCouleurs"
QT_MOC_LITERAL(21, 222, 12) // "aboutGraphEt"

    },
    "ToolBar\0tableauAleatoire\0\0tableauOuvrir\0"
    "sauvegarder\0enregistrerSous\0exporter\0"
    "imprimer\0annuler\0restaurer\0totaleSelection\0"
    "copier\0fusion\0zoomPlus\0zoomMoins\0"
    "pleinEcran\0barreDEtats\0barreDOutils\0"
    "modeSombre\0langues\0choixCouleurs\0"
    "aboutGraphEt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x09 /* Protected */,
       3,    0,  115,    2, 0x09 /* Protected */,
       4,    0,  116,    2, 0x09 /* Protected */,
       5,    0,  117,    2, 0x09 /* Protected */,
       6,    0,  118,    2, 0x09 /* Protected */,
       7,    0,  119,    2, 0x09 /* Protected */,
       8,    0,  120,    2, 0x09 /* Protected */,
       9,    0,  121,    2, 0x09 /* Protected */,
      10,    0,  122,    2, 0x09 /* Protected */,
      11,    0,  123,    2, 0x09 /* Protected */,
      12,    0,  124,    2, 0x09 /* Protected */,
      13,    0,  125,    2, 0x09 /* Protected */,
      14,    0,  126,    2, 0x09 /* Protected */,
      15,    0,  127,    2, 0x09 /* Protected */,
      16,    0,  128,    2, 0x09 /* Protected */,
      17,    0,  129,    2, 0x09 /* Protected */,
      18,    0,  130,    2, 0x09 /* Protected */,
      19,    0,  131,    2, 0x09 /* Protected */,
      20,    0,  132,    2, 0x09 /* Protected */,
      21,    0,  133,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToolBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tableauAleatoire(); break;
        case 1: _t->tableauOuvrir(); break;
        case 2: _t->sauvegarder(); break;
        case 3: _t->enregistrerSous(); break;
        case 4: _t->exporter(); break;
        case 5: _t->imprimer(); break;
        case 6: _t->annuler(); break;
        case 7: _t->restaurer(); break;
        case 8: _t->totaleSelection(); break;
        case 9: _t->copier(); break;
        case 10: _t->fusion(); break;
        case 11: _t->zoomPlus(); break;
        case 12: _t->zoomMoins(); break;
        case 13: _t->pleinEcran(); break;
        case 14: _t->barreDEtats(); break;
        case 15: _t->barreDOutils(); break;
        case 16: _t->modeSombre(); break;
        case 17: _t->langues(); break;
        case 18: _t->choixCouleurs(); break;
        case 19: _t->aboutGraphEt(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ToolBar::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ToolBar.data,
    qt_meta_data_ToolBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBar.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
