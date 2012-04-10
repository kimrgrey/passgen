#include "ReadableGenerator.h"

const int ReadableGenerator::ConsonantMaximum = 2;
const int ReadableGenerator::VowelMaximum = 2;
const QString ReadableGenerator::Alphabet = QString::fromUtf8("abcdefghijklmnopqrstuvwxyz");
const QString ReadableGenerator::Consonants = QString::fromUtf8("bcdfghjklmnpqrstvwxz");
const QString ReadableGenerator::Vowels = QString::fromUtf8("aeiouy");

ReadableGenerator::ReadableGenerator(int length, QObject* parent) : PasswordGenerator(parent)
{
	qsrand(time(NULL));
	this->setPasswordLength(length);
	this->setConsonantMaximum(ReadableGenerator::ConsonantMaximum);
	this->setVowelMaximum(ReadableGenerator::VowelMaximum);
}

void ReadableGenerator::setPasswordLength(int length)
{
	this->length = length;
}

void ReadableGenerator::setConsonantMaximum(int consonant)
{
	this->consonantMaximum = consonant;
}

void ReadableGenerator::setVowelMaximum(int vowel)
{
	this->vowelMaximum = vowel;
}

ReadableGenerator::~ReadableGenerator() { }

QChar ReadableGenerator::generateCharacter() const
{
	return ReadableGenerator::Alphabet.at( qrand() % ReadableGenerator::Alphabet.size());
}

QChar ReadableGenerator::generateCosonant() const
{
	return ReadableGenerator::Consonants.at(qrand() % ReadableGenerator::Consonants.size());
}

QChar ReadableGenerator::generateVowel() const
{
	return ReadableGenerator::Vowels.at(qrand() % ReadableGenerator::Vowels.size());
}

bool ReadableGenerator::isConsonant(const QChar& c)
{
	return ReadableGenerator::Consonants.contains(c, Qt::CaseInsensitive);
}

bool ReadableGenerator::isVowel(const QChar& c)
{
	return ReadableGenerator::Vowels.contains(c, Qt::CaseInsensitive);
}

QString ReadableGenerator::generate()
{
	QString password;
	int consonantCounter = 0;
	int vowelCounter = 0;
	for (int i = 0; i < length; ++i) {
		QChar c = this->generateCharacter();
		if (isConsonant(c)) {
			++consonantCounter;
			if (consonantCounter > consonantMaximum) {
				c = this->generateVowel();
				consonantCounter = 0;
			}
		} else if (isVowel(c)) {
			++vowelCounter;
			if (vowelCounter > vowelMaximum) {
				c = this->generateVowel();
				vowelCounter = 0;
			}
		}
		password.insert(i, c);
	}
	return password;
}
