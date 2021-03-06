/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

#include "node.h"
#include "readonlymodel.h"
#include "editablemodel.h"
#include "insertremovemodel.h"
#include "lazymodel.h"



Node *createData() {
    Node *root = new Node("Root");
    for(int i=0; i<10; i++) {
        Node *node1 = new Node(QString("Item %1").arg(i), root);
        for(int ii=0; ii<5; ii++) {
            Node *node2 = new Node(QString("Item %1/%2").arg(i).arg(ii), node1);
            for(int iii=0; iii<3; iii++) {
                new Node(QString("Item %1/%2/%3").arg(i).arg(ii).arg(iii), node2);
            }
        }
    }
    return root;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

//  [Enable for ReadOnlyModel]
 //   ReadOnlyModel *model = new ReadOnlyModel();

//  [Enable for EditableModel]
//    EditableModel *model = new EditableModel();

//  [Enable for InsertRemoveModel]
//    InsertRemoveModel *model = new InsertRemoveModel();

//  [Enable for LazyModel]
    LazyModel *model = new LazyModel();

    Node *root = createData();
    model->setRootNode(root);

    // [Enable for InsertRemoveModel]
    //    model->insertNode(root, 2, new Node("Inserted", root));
    //    model->removeNode(root->children.value(1));

    QWidget *window = new QWidget();
    QGridLayout *layout = new QGridLayout(window);


    QListView *listView = new QListView(window);
    listView->setModel(model);

    QTableView *tableView = new QTableView(window);
    tableView->setModel(model);

    QTreeView *treeView = new QTreeView(window);
    treeView->setModel(model);



    layout->addWidget(new QLabel("QListView"), 0, 0);
    layout->addWidget(listView, 1, 0);
    layout->addWidget(new QLabel("QTableView"), 0, 1);
    layout->addWidget(tableView, 1, 1);
    layout->addWidget(new QLabel("QTreeView"), 0, 2);
    layout->addWidget(treeView, 1, 2);

    window->show();

    return app.exec();
}
