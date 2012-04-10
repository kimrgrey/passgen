#ifndef PASSWORDGENERATOR_H
#define	PASSWORDGENERATOR_H

#include <QObject>
#include <QStringList>

class PasswordGenerator : public QObject {
	Q_OBJECT
public:
	PasswordGenerator(QObject *parent = 0);
	virtual ~PasswordGenerator();
	virtual QString generate () = 0;
	virtual QStringList generate(int count);
} ;


#endif	/* PASSWORDGENERATOR_H */

