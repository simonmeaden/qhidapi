#ifndef QHidDeviceInfoModel_H
#define QHidDeviceInfoModel_H
/*
Copyright (C) [year] by Simon Meaden <[simonmeaden@virginmedia.com]>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <QAbstractTableModel>
#include <QStyledItemDelegate>

#include "qhidapi_global.h"
#include "qhidapi.h"
#include "qhiddeviceinfomodel.h"

class QHIDAPISHARED_EXPORT QHidDeviceInfoModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit QHidDeviceInfoModel(QObject *parent = 0);
    explicit QHidDeviceInfoModel(QList<QHidDeviceInfo> data, QObject *parent = 0);
    ~QHidDeviceInfoModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    static const int s_columnCount = 6;

signals:

public slots:
    void setDataSet(QList<QHidDeviceInfo> data);

protected:
    QList<QHidDeviceInfo> m_data;

};

#endif // QHidDeviceInfoModel_H
