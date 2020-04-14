#ifndef DIALOGUEMANAGER_H
#define DIALOGUEMANAGER_H

#include <QList>
#include "dialoguefigure.h"
#include "dialoguebucket.h"

class DialogueManager : public QObject
{
    Q_OBJECT
public:
    DialogueManager(QObject *parent = nullptr);

    void setDataDir(QString dir);
    void loadData();
    void saveData();

    void saveFigure(DialogueBucket* bucket);
    void deleteFigure(QString name);

    QList<DialogueFigure*>& getFigures();
    DialogueFigure* getFigure(QString id);
    DialogueFigure* createFigure(ChatType t, QString n, QPixmap a, QString ss);

signals:

public slots:

protected:
    QString data_dir; // 数据路径（末尾带/）
    QList<DialogueFigure*> figures; // 人物模板信息
    QString dialogue_qss, bucket_qss, narrator_qss; // 各种样式表
};

#endif // DIALOGUEMANAGER_H