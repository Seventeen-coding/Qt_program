#include "gamecontroller.h"
#include <QMessageBox>
GameController::GameController(QGraphicsScene *scene, QObject *parent):
    QObject(parent),
    scene(scene)
{
    timer.start(1000/33);
    //    Food *a1 = new Food(30,-60);
    //    scene->addItem(a1);
    snake = new Snake(this);
    scene->addItem(snake);
    addNewFood();
    scene->installEventFilter(this);
    resume();
}

void GameController::addNewFood()
{
    int x, y;
    do {
        x = (int) (qrand() % SCENE_SIZE/2) / 30;
        y = (int) (qrand() % SCENE_SIZE/2) / 30;
        x *= 30;
        y *= 30;

    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + TILE_SIZE/2, y +
                                                                 TILE_SIZE/2))));

    qDebug() << x << y << snake->mapFromScene(QPointF(x + TILE_SIZE/2, y + TILE_SIZE/2));
    Food *food = new Food(x , y);
    scene->addItem(food);
}

void GameController::snakeAteFood(Snake *snake, Food *food)
{
    scene->removeItem(food);
    delete food;
    addNewFood();
}

GameController::~GameController()
{

}

void GameController::resume()
{
    connect(&timer,SIGNAL(timeout()),scene,SLOT(advance()));
}

void GameController::pause()
{
    disconnect(&timer,SIGNAL(timeout()),scene,SLOT(advance()));
}


bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    }
    else
    {
        return QObject::eventFilter(object,event);
    }
}


void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
        snake->setMoveDirection(MoveLeft);
        break;
    case Qt::Key_Right:
        snake->setMoveDirection(MoveRight);
        break;
    case Qt::Key_Up:
        snake->setMoveDirection(MoveUp);
        break;
    case Qt::Key_Down:
        snake->setMoveDirection(MoveDown);
        break;
    }
}

void GameController::snakeAteItself(Snake *snake)
{
    QTimer::singleShot(0, this, SLOT(gameOver()));

}
void GameController::gameOver()
{
    scene->clear();
    QMessageBox::information(0,tr("游戏结束"),tr("游戏结束"),tr("确定"));
}