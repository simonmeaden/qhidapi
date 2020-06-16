/*
  Copyright 2020 Simon Meaden

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
#include "qhiddeviceinfomodel.h"

QHidDeviceInfoModel::QHidDeviceInfoModel(QObject* parent) : QAbstractTableModel(parent)
{
}

QHidDeviceInfoModel::QHidDeviceInfoModel(QList<QHidDeviceInfo> data, QObject* parent) : QAbstractTableModel(parent)
{
  m_data = data;
}

QHidDeviceInfoModel::~QHidDeviceInfoModel()
{

}

void QHidDeviceInfoModel::setDataSet(QList<QHidDeviceInfo> data)
{
  emit beginResetModel();
  m_data = data;
  emit endResetModel();
}

int QHidDeviceInfoModel::rowCount(const QModelIndex& /*parent*/) const
{
  return m_data.size();
}

int QHidDeviceInfoModel::columnCount(const QModelIndex& /*parent*/) const
{
  return s_columnCount;
}

QVariant QHidDeviceInfoModel::data(const QModelIndex& index, int role) const
{
  if (role == Qt::DisplayRole) {
    switch (index.column()) {
    case 0:
      return QVariant(m_data.at(index.row()).vendorId);
      break;

    case 1:
      return QVariant(m_data.at(index.row()).productId);
      break;

    case 2:
      return QVariant(m_data.at(index.row()).manufacturerString);
      break;

    case 3:
      return QVariant(m_data.at(index.row()).productString);
      break;

    case 4:
      return QVariant(m_data.at(index.row()).serialNumber);
      break;

    case 5:
      return QVariant(m_data.at(index.row()).releaseNumber);
      break;

    default:
      break;
    }
  }

  return QVariant();
}

QVariant QHidDeviceInfoModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Horizontal) {
      switch (section) {
      case 0:
        return QString("Vendor Id");

      case 1:
        return QString("Manufacturer");

      case 2:
        return QString("Product Id");

      case 3:
        return QString("Product");

      case 4:
        return QString("Serial Number");

      case 5:
        return QString("Release");

      default:
        return "";
      }
    }
  }

  return QVariant();
}
