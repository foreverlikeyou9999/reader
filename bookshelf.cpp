#include "bookshelf.h"

#include <QtCore/QDir>

void Bookshelf::scanDirectory(QString d)
{
    QDir dir(d);
    if (!dir.exists())
    {
        return;
    }

    QStringList entries = dir.entryList(QDir::Files | QDir::Readable);

    for (int loopc=0; loopc<entries.size(); loopc++)
    {
        QString fname = dir.absoluteFilePath(entries[loopc]);
        QFile * file = new QFile(fname);
        file->open(QIODevice::ReadOnly);
            
        Mobi * mobi = new Mobi;
        if (mobi->sniff(file))
        {
            printf("Adding [%s]\n", fname.toAscii().data());
            books.push_back(mobi);
        }
        else
        {
            printf("Can't read [%s]\n", fname.toAscii().data());
            delete mobi;
            delete file;
        }
    }
}

Mobi * Bookshelf::getBook(int index)
{
    return books[index];
}

int Bookshelf::numBooks()
{
    return books.size();
}
