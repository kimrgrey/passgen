#include <QStringList>
#include "PasswordGenerator.h"

PasswordGenerator::PasswordGenerator(QObject* parent) : QObject(parent)
{
}

PasswordGenerator::~PasswordGenerator()
{
}

QStringList PasswordGenerator::generate(int count)
{
	QStringList passwords;
	for (int i = 0; i < count; ++i) {
		passwords.append(generate());
	}
	return passwords;
}
