#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include "JlCompress.h"

void CompressDir(QString ZipFile, QString Directory)
{
    if(JlCompress::compressDir(ZipFile,Directory))
    {
        qDebug() << "Created: " <<  ZipFile;
    }
    else
    {
        qDebug() << "Could not create: " <<  ZipFile;
    }
}

void DecompressDir(QString ZipFile, QString Directory)
{
    QStringList list = JlCompress::extractDir(ZipFile,Directory);

    foreach(QString item, list)
    {
        qDebug() << "Extracted: " << item;
    }
}

void CompressFiles(QString ZipFile, QStringList Files)
{
    if(JlCompress::compressFiles(ZipFile,Files))
    {
        qDebug() << "Created: " <<  ZipFile;
    }
    else
    {
        qDebug() << "Could not create: " <<  ZipFile;
    }
}

void DecompressFiles(QString ZipFile, QStringList Files, QString Directory)
{
    QStringList list = JlCompress::extractFiles(ZipFile, Files, Directory);

    foreach(QString item, list)
    {
        qDebug() << "Extracted: " << item;
    }
}

void ListContents(QString ZipFile)
{
    QFile File(ZipFile);

    if(!File.exists())
    {
        qDebug() << "Zip file not found!";
        return;
    }

    QStringList list = JlCompress::getFileList(ZipFile);

    foreach(QString item, list)
    {
        qDebug() << item;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ZipFile = "/home/rootshell/ZipVids/test.zip";
    QString OriginalDir = "/home/rootshell/ZipVids/Original";
    QString NewDir = "/home/rootshell/ZipVids/NewDir";
    QString SingleFile = OriginalDir + "/drunk.jpg";

    //Compress a directory
    CompressDir(ZipFile,OriginalDir);

    //List the contents of a zip file
    ListContents(ZipFile);

    //Compress a single file
    //CompressFiles(ZipFile,QStringList() << SingleFile);

    //Decompress an archive to a directory
    //DecompressDir(ZipFile,NewDir);

    //Decompress a single file
    DecompressFiles(ZipFile,QStringList() << "drunk.jpg",NewDir);


    return a.exec();
}
