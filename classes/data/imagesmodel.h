/*
 * LCD Image Converter. Converts images and fonts for embedded applications.
 * Copyright (C) 2013 riuson
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

#ifndef IMAGESMODEL_H
#define IMAGESMODEL_H
//-----------------------------------------------------------------------------
#include <QAbstractItemModel>
//-----------------------------------------------------------------------------
class DataContainer;
//-----------------------------------------------------------------------------
class ImagesModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum ImagesModelRoles
    {
        KeyRole = Qt::UserRole + 1,
        KeyCodeRole,
        ImageRole,
        ImageScaledRole,
        PixmapRole,
        PixmapScaledRole,
        PixmapScaledCroppedRole
    };

    explicit ImagesModel(DataContainer *container, Qt::Orientation orientation = Qt::Vertical, QObject *parent = 0);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

    void callReset();

    int scale() const;
    void setScale(int value);
    void setCrop(int left, int top, int right, int bottom);

private:
    DataContainer *mContainer;
    Qt::Orientation mOrientation;
    int mScale;
    int mLeft;
    int mRight;
    int mTop;
    int mBottom;

    QVariant containerValue(int imageIndex, ImagesModelRoles role) const;
    QSize containerValueSize(int imageIndex, ImagesModelRoles role) const;

private slots:
    void imagesChanged();

signals:
    void scaleChanged();

public slots:

};
//-----------------------------------------------------------------------------
#endif // IMAGESMODEL_H
