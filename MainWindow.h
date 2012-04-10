#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSpinBox;
class QListWidget;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
public slots:
	void generate ();
private:
	void createPasswordList();
	void createLengthEdit();
	void createCountEdit();
	void createLayout ();
private:
	QListWidget *passwordList;
	QSpinBox *lengthEdit;
	QSpinBox *countEdit;
};

#endif // MAINWINDOW_H
