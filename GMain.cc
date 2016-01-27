#include <QtGui>

#include "GMain.h"

GMain::GMain()
{
  listWidget = new QListWidget();
  addButton = new QPushButton("Add");
  removeButton = new QPushButton("Remove");
  quitButton = new QPushButton("Quit");

  QWidget *mainWidget = new QWidget();
  setCentralWidget(mainWidget);

  connect(addButton, SIGNAL(clicked()), this, SLOT(addClass()));
  connect(removeButton, SIGNAL(clicked()), this, SLOT(removeClass()));
  connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

  QVBoxLayout *mainLayout = new QVBoxLayout();
  mainLayout->addWidget(listWidget);

  QHBoxLayout *buttonLayout = new QHBoxLayout();
  buttonLayout->addWidget(addButton);
  buttonLayout->addWidget(removeButton);
  mainLayout->addLayout(buttonLayout);

  mainLayout->addWidget(quitButton);
  mainWidget->setLayout(mainLayout);

}

void GMain::reciveClasses(const QString &str1, const QString &str2)
{
  if (listWidget->count() < 5)
  {
    QString final = str1 + " : [" + str2 + "]";
    listWidget->addItem(final);
    if (dialog->isVisible())
    {
      dialog->setVisible(false);
    }
  }
}

void GMain::addClass()
{
  if (!dialog)
  {
    dialog = new GDialog(this);
    connect(dialog, SIGNAL(sendClass(const QString&, const QString&)),
            this, SLOT(reciveClasses(const QString&, const QString&)));
  }
  if (listWidget->count() < 5)
  {
    dialog->show();
    dialog->activateWindow();
  } else {
    std::cout << "Maximum 5 courses allowed, remove one to add another." << std::endl;
  }
}

void GMain::removeClass()
{
  if (listWidget->currentRow() >= 0)
  {
    listWidget->takeItem(listWidget->currentRow());
  }

}
