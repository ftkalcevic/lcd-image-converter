/*
 * LCD Image Converter. Converts images and fonts for embedded applciations.
 * Copyright (C) 2010 riuson
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

#ifndef PARSER_H
#define PARSER_H
//-----------------------------------------------------------------------------
#include <QObject>
#include <QMap>

class IDocument;
class IDataContainer;
class Preset;
//-----------------------------------------------------------------------------
class Parser : public QObject
{
    Q_OBJECT
public:
    enum TemplateType
    {
        TypeImage,
        TypeFont
    };

    Parser(QObject *parent, TemplateType templateType);
    virtual ~Parser();

    QString name();

    QString convert(IDocument *document, QMap<QString, QString> &tags) const;

private:
    QString mSelectedPresetName;
    Preset *mPreset;
    QString mTemplateFileName;

    void parse(const QString &templateString, QString &resultString, QMap<QString, QString> &tags, IDocument *doc) const;
    void parseBlocks(const QString &templateString, QString &resultString, QMap<QString, QString> &tags, IDocument *doc) const;
    void parseImagesTable(const QString &templateString, QString &resultString, QMap<QString, QString> &tags, IDocument *doc) const;
    void parseSimple(const QString &templateString, QString &resultString, QMap<QString, QString> &tags, IDocument *doc) const;
    QString hexCode(const QChar &ch, const QString &encoding, bool bom) const;
    void addMatrixInfo(QMap<QString, QString> &tags) const;
};
//-----------------------------------------------------------------------------
#endif // PARSER_H