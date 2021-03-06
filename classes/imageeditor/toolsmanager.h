/*
 * LCD Image Converter. Converts images and fonts for embedded applications.
 * Copyright (C) 2015 riuson
 * mailto: riuson@gmail.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/
 */

#ifndef TOOLSMANAGER_H
#define TOOLSMANAGER_H
//-----------------------------------------------------------------------------
#include <QObject>
#include "iimageeditorparams.h"
//-----------------------------------------------------------------------------
class QAction;
template <class T1> class QList;
//-----------------------------------------------------------------------------
namespace ImageEditor
{
//-----------------------------------------------------------------------------
class IImageEditorTool;
class ToolZoom;
class ToolColor;
//-----------------------------------------------------------------------------
class ToolsManager : public QObject, public IImageEditorParams
{
    Q_OBJECT
    Q_INTERFACES(ImageEditor::IImageEditorParams)

public:
    explicit ToolsManager(QObject *parent = 0);
    ~ToolsManager();

    const QList <IImageEditorTool *> *tools() const;
    const QList<QAction *> *toolsActions() const;

    int scale() const;
    const QColor foreColor() const;
    const QColor backColor() const;
    QWidget *parentWidget() const;

public slots:
    void setScale(int value);

signals:
    void toolChanged(int toolIndex);
    void scaleChanged(int value);

private:
    QList <IImageEditorTool *> *mTools;
    QList <QAction *> *mToolsActions;
    IImageEditorTool *mSelectedTool;
    ToolZoom *mZoomer;
    ToolColor *mColors;
    QWidget *mParentWidget;

    void initializeTools();
    void initializeActions();
    void selectTool(IImageEditorTool *tool);

private slots:
    void on_toolAction_triggered();
};
//-----------------------------------------------------------------------------
} // end of namespace
//-----------------------------------------------------------------------------
#endif // TOOLSMANAGER_H
