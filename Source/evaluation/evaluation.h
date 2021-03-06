/**
  * @file Evaluation.h
  * @brief Base widget for each evaluation category. These are added to a tab display for total evaluation.
  */

#ifndef EVALUATION_H
#define EVALUATION_H

#include <QGroupBox>
#include <QMap>

//Forward declarations
class QLabel;
class QSlider;
class QTextEdit;
class QVBoxLayout;
class EvaluationData;

class Evaluation : public QGroupBox
{
    Q_OBJECT //Extends Q_OBJECT to implement "signals/slots", a Qt event/handler system.
public:
    Evaluation(QString name); //Constructor

    QString getComments();
    QString getFormattedKey(int val); //Returns a string with the slider value and its corresponding string
    QString getName();
    int     getScore();
    int getRoundedValue();
protected:
    QLabel*                scaleLabel; //Label to display slider value/string
    QLabel*                commentLabel; //Displays "Comments" to show where to enter comments for each section
    QLabel*                characterCount, *characterCountLabel; //Continually updating character count limit for the comments
    QTextEdit*             commentBox; //Holds the comments
    QMap<int, QString>*    scaleTextMap; //Maps the slider value to a string
    QVBoxLayout*           layout;
    QString                name;
    QVBoxLayout*           sliderLayout;
    QSlider*               slider; //Slider to evalutate from 1 to 5
    int                    remainingChars; //Number of characters left from maximum (declared in .cpp)
public slots:
    void updateScaleLabel(); //Updates the slider label with the scale map
    void updateCharCount(); //Updates the characters left with each change in the text box
signals:
    void updatedScaleValue();
};

#endif // EVALUATION_H
