#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>
#include <QGraphicsScene>
#include "define.h"
#include "snake.h"
#include "food.h"
#include <QTimer>
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
class Snake;
class Food;

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QGraphicsScene *scene, QObject *parent);

    ~GameController();


    Snake  *snake;
    QGraphicsScene *scene;
    QTimer  timer;
    Food  *food;
    void  addNewFood();
    bool  eventFilter(QObject *object, QEvent *event);

    void resume();   //恢复移动
    void pause();    //暂停
    void handleKeyPressed(QKeyEvent *event);
    void snakeAteFood(Snake *snake, Food *food);
    void snakeAteItself(Snake *snake);
public slots:
    void gameOver();

};

#endif // GAMECONTROLLER_H
