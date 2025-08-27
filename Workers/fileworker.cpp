#include "fileworker.h"


FileWorker::FileWorker() {}

QList<QStringList> FileWorker::ReadFileContent(const QString &filePath) {
    QList<QStringList> linesList;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Nie można otworzyć pliku");
        return linesList;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split("\t");
        linesList.append(values);
    }

    file.close();
    return linesList;
}

bool FileWorker::RemoveLineFromFile(const QString &filePath, int id) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Nie można otworzyć pliku");
        return false;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines << in.readLine();
    }
    file.close();

    bool found = false;
    for (int i = 0; i < lines.size(); ++i) {
        QStringList parts = lines[i].split("\t");
        if (!parts.isEmpty() && parts[0].toInt() == id) {
            lines.removeAt(i);
            found = true;
            break;
        }
    }

    if (!found) return false;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning("Nie można zapisać do pliku");
        return false;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
    return true;
}

bool FileWorker::ModifyLineInFile(const QString &filePath, int id, const QStringList &newValues) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Nie można otworzyć pliku");
        return false;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines << in.readLine();
    }
    file.close();

    bool found = false;
    for (int i = 0; i < lines.size(); ++i) {
        QStringList parts = lines[i].split("\t");
        if (!parts.isEmpty() && parts[0].toInt() == id) {
            lines[i] = newValues.join("\t");
            found = true;
            break;
        }
    }

    if (!found) return false;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qWarning("Nie można zapisać do pliku");
        return false;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    file.close();
    return true;
}

bool FileWorker::AddObjectToFile(const QString &filePath, const QStringList &valuesWithoutId) {
    QFile file(filePath);

    int newId = 1;

    if (file.exists()) {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qWarning("Nie można otworzyć pliku");
            return false;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("\t");
            if (!parts.isEmpty()) {
                int id = parts[0].toInt();
                if (id >= newId) {
                    newId = id + 1;
                }
            }
        }
        file.close();
    }

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning("Nie można zapisać do pliku");
        return false;
    }

    QTextStream out(&file);

    QStringList fullValues = valuesWithoutId;
    fullValues.prepend(QString::number(newId));
    out << fullValues.join("\t") << "\n";

    file.close();
    return true;
}
