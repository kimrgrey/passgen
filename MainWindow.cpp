#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>
#include "ReadableGenerator.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	this->createPasswordList();
	this->createLengthEdit();
	this->createCountEdit();
	this->createLayout();
	this->setWindowTitle(QString::fromUtf8("Главное окно - Генератор паролей"));
	this->setMinimumSize(400, 200);
}

void MainWindow::createPasswordList()
{
	passwordList = new QListWidget();
	passwordList->setToolTip(QString::fromUtf8("Список сгенерированных паролей"));
}

void MainWindow::createLengthEdit()
{
	lengthEdit = new QSpinBox();
	lengthEdit->setToolTip(QString::fromUtf8("Длина пароля"));
	lengthEdit->setValue(10);
}

void MainWindow::createCountEdit()
{
	countEdit = new QSpinBox();
	countEdit->setToolTip(QString::fromUtf8("Количество паролей"));
	countEdit->setValue(15);
}

void MainWindow::createLayout()
{
	QWidget *centralWidget = new QWidget();
	QPushButton *submitButton = new QPushButton(QString::fromUtf8("Сгенерировать"));
	connect(submitButton, SIGNAL(clicked(void)), this, SLOT(generate(void)));
	QGridLayout *layout = new QGridLayout(centralWidget);
	layout->addWidget(passwordList, 0, 0, 1, 3);
	layout->addWidget(lengthEdit, 1, 0);
	layout->addWidget(countEdit, 1, 1);
	layout->addWidget(submitButton, 1, 2);
	this->setCentralWidget(centralWidget);
}

void MainWindow::generate()
{
	PasswordGenerator *generator = new ReadableGenerator(lengthEdit->value());
	passwordList->clear();
	passwordList->addItems(generator->generate(countEdit->value()));
	delete generator;
}


