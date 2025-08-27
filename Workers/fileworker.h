#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QFile>
#include <QTextStream>

class FileWorker
{
public:
    FileWorker();
    QList<QStringList> ReadFileContent(const QString &filePath);
    bool RemoveLineFromFile(const QString &filePath, int id);
    bool ModifyLineInFile(const QString &filePath, int id, const QStringList &newValues);
    int AddObjectToFile(const QString &filePath, const QStringList &valuesWithoutId);
};

#endif // FILEWORKER_H
