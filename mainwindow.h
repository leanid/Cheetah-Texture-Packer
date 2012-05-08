#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "imagepacker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void RecurseDirectory(const QString &dir);
    QStringList imageExtensions;
    QString topImageDir;
    ImagePacker packer;
    QList<packedImage> packedImageList;
    bool exporting;
    int recursiveLoaderCounter;
    bool recursiveLoaderDone;
signals:
    void renderedImage(const QList<QImage> &image);
public slots:
    void addTiles();
    void deleteSelectedTiles();
    void packerUpdate();
    void updateAuto();
    void setTextureSize128();
    void setTextureSize256();
    void setTextureSize512();
    void setTextureSize1024();
    void getFolder();
    void exportImage();
    void swapSizes();
    void clearTiles();
};

#endif // MAINWINDOW_H