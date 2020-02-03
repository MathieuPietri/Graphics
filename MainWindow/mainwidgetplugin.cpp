#include "mainwidget.h"
#include "mainwidgetplugin.h"

#include <QtPlugin>

MainWidgetPlugin::MainWidgetPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void MainWidgetPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool MainWidgetPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *MainWidgetPlugin::createWidget(QWidget *parent)
{
    return new MainWidget(parent);
}

QString MainWidgetPlugin::name() const
{
    return QLatin1String("MainWidget");
}

QString MainWidgetPlugin::group() const
{
    return QLatin1String("");
}

QIcon MainWidgetPlugin::icon() const
{
    return QIcon();
}

QString MainWidgetPlugin::toolTip() const
{
    return QLatin1String("");
}

QString MainWidgetPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool MainWidgetPlugin::isContainer() const
{
    return false;
}

QString MainWidgetPlugin::domXml() const
{
    return QLatin1String("<widget class=\"MainWidget\" name=\"mainWidget\">\n</widget>\n");
}

QString MainWidgetPlugin::includeFile() const
{
    return QLatin1String("mainwidget.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(mainwidgetplugin, MainWidgetPlugin)
#endif // QT_VERSION < 0x050000
