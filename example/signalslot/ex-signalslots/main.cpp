/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>
#include "myemitter.h"
#include "myreceiver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyEmitter *emitter = new MyEmitter("Hello World");
    MyReceiver *receiver = new MyReceiver;
    //QObject::connect(emitter, SIGNAL(aSignal()), receiver, SLOT(aSlot()));

    QObject::connect(emitter,
                     SIGNAL(anOtherSignal(int,QWidget*)),
                     receiver,
                     SLOT(anOtherSlot(int,QWidget*)));
    emitter->show();

    return app.exec();
}
