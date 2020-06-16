/*
  Copyright 2013-2020 Simon Meaden

  Permission is hereby granted, free of charge, to any person obtaining a copy
                                                of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
                                                          copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

    @author: Simon Meaden

*/

#ifndef QHIDAPI_P_H
#define QHIDAPI_P_H

#include <QObject>
#include <QMap>
#include <QList>
#include <QVariant>

#include "qhiddeviceinfo.h"
#include "hidapi.h"

class QHidApi;

class QHidApiPrivate
{
public:
  QHidApiPrivate(ushort vendorId, ushort productId, QHidApi* parent);
  ~QHidApiPrivate();

  QList<QHidDeviceInfo> enumerate(ushort vendorId = 0x0, ushort productId = 0x0);

  quint32 open(ushort vendor_id, ushort product_id, QString serial_number = QString());
  quint32 open(QString path);
  void close(quint32 id);
  QByteArray read(quint32 id);
  QByteArray read(quint32 id, int timeout);
  int write(quint32 id, QByteArray data, quint8 reportNumber);
  int write(quint32 id, QByteArray data);
  bool setBlocking(quint32 id);
  bool setNonBlocking(quint32 id);
  QByteArray featureReport(quint32 id, uint reportId);
  int sendFeatureReport(quint32 id, quint8 reportId, QByteArray data);
  QString manufacturerString(quint32 id);
  QString productString(quint32 id);
  QString serialNumberString(quint32 id);
  QString indexedString(quint32 id, int index);
  QString error(quint32 id);
  quint32 nextId();
  int init();
  int exit();
  hid_device* findId(quint32 id);
  quint32 openProduct(ushort vendorId, ushort productId, QString serialNumber);
  quint32 openNewProduct(ushort vendorId, ushort productId, QString serialNumber);

  static const int MAX_STR = 255;

  quint32 mVendorId, mProductId;
  quint32 mNextId;
  QList<QHidDeviceInfo> mDeviceInfoList;
  /*
     map of vendorId -> productId.
  */
  QMultiMap<ushort, QMultiMap<ushort, QVariant>> mVendorMap;
  /*
     map of serialNumber -> id.
  */
  QMap<QString, quint32> mSerDevices;
  /*
     map of QString path -> id.
  */
  QMap<QString, quint32> mPathMap;
  /*
     map of id -> handle.
  */
  QMap<quint32, hid_device*> mIdDeviceMap;
  /*
     reverse of idDeviceMap. Used to check if we already heve a device opened..
  */
  QMap<hid_device*, quint32> mDeviceIdMap;

private:
  QHidApi* q_ptr;

  Q_DECLARE_PUBLIC(QHidApi)

};

#endif // QHIDAPI_P_H
