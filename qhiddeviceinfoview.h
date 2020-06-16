#ifndef QHIDDEVICEINFOVIEW_H
#define QHIDDEVICEINFOVIEW_H
/*
Copyright (C) [year] by Simon Meaden <[simonmeaden@virginmedia.com]>

Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <QTableView>
#include <QHeaderView>

#include "qhidapi_global.h"
#include "hexformatdelegate.h"

class QHIDAPISHARED_EXPORT QHidDeviceInfoView : public QTableView {
    Q_OBJECT
public:
    explicit QHidDeviceInfoView(QWidget *parent = 0);

    virtual QSize sizeHint () const;

signals:

public slots:

};

#endif // QHIDDEVICEINFOVIEW_H
