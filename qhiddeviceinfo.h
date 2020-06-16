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
#ifndef QHIDDEVICEINFO_H
#define QHIDDEVICEINFO_H

#include <QString>

struct QHidDeviceInfo {
    /** Platform-specific device path */
    QString path;
    /** Device Vendor ID */
    ushort vendorId;
    /** Device Product ID */
    ushort productId;
    /** Serial Number */
    QString serialNumber;
    /** Device Release Number in binary-coded decimal,
            also known as Device Version Number */
    ushort releaseNumber;
    /** Manufacturer String */
    QString manufacturerString;
    /** Product string */
    QString productString;
#if defined(Q_OS_WIN32) || defined(Q_OS_MAC)
    /** Usage Page for this Device/Interface
            (Windows/Mac only). */
    ushort usagePage;
    /** Usage for this Device/Interface
            (Windows/Mac only).*/
    ushort usage;
#endif
    /** The USB interface which this logical device
            represents. Valid on both Linux implementations
            in all cases, and valid on the Windows implementation
            only if the device contains more than one interface. */
    int interfaceNumber;
};

#endif // QHIDDEVICEINFO_H
