/***************************************************************************
 *   Copyright (C) 2003 by Tim Sutton                                      *
 *   Copyright (C) 2004 by Gary Sherman                                    *
 *   tim@linfiniti.com                                                     *
 *                                                                         *
 *   This is a plugin generated from the QGIS plugin template              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/
#ifndef QGSDELIMITEDTEXTSOURCESELECT_H
#define QGSDELIMITEDTEXTSOURCESELECT_H

#include "ui_qgsdelimitedtextsourceselectbase.h"

#include <QTextStream>
#include "qgscontexthelp.h"
#include "qgisgui.h"

class QgisInterface;

/**
 * \class QgsDelimitedTextSourceSelect
 */
class QgsDelimitedTextSourceSelect : public QDialog, private Ui::QgsDelimitedTextSourceSelectBase
{
    Q_OBJECT

  public:
    QgsDelimitedTextSourceSelect( QWidget * parent, Qt::WFlags fl = QgisGui::ModalDialogFlags, bool embedded = false );
    ~QgsDelimitedTextSourceSelect();

    QStringList splitLine( QString line );

  private:
    bool haveValidFileAndDelimiters();
    void updateFieldLists();
    void getOpenFileName();
    QString selectedChars();

  private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_buttonBox_helpRequested() { QgsContextHelp::run( metaObject()->className() ); }
    void on_btnBrowseForFile_clicked();

  public slots:
    void updateFieldsAndEnable();
    void enableAccept();

  signals:
    void addVectorLayer( QString, QString, QString );
};

#endif // QGSDELIMITEDTEXTSOURCESELECT_H
