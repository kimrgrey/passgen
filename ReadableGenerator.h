#ifndef READABLEGENERATOR_H
#define	READABLEGENERATOR_H

#include "PasswordGenerator.h"

class ReadableGenerator : public PasswordGenerator {
	Q_OBJECT
public:
	ReadableGenerator(int length = 10, QObject *parent = 0);
	~ReadableGenerator();
	void setPasswordLength(int length);
	void setConsonantMaximum(int consonant);
	void setVowelMaximum(int vowel);
	QString generate();
public:
	const static int ConsonantMaximum;
	const static int VowelMaximum;
	const static QString Alphabet;
	const static QString Vowels;
	const static QString Consonants;
private:
	QChar generateCharacter() const;
	QChar generateCosonant() const;
	QChar generateVowel() const;
	bool isConsonant(const QChar &c);
	bool isVowel(const QChar &c);
private:
	int consonantMaximum;
	int vowelMaximum;
	int length;
} ;

#endif	/* READABLEGENERATOR_H */

