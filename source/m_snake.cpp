#include"m_snake.hpp"
m_snake::m_snake(float edge,float horizontal,float vercital,sf::Color color){
    m_snake::edge=edge;
    m_snake::horizontal=horizontal;
    m_snake::vercital=vercital;
    m_snake::snakecolor=color;
    sf::RectangleShape *shape= new sf::RectangleShape;
    shape->setFillColor(snakecolor);
    shape->setPosition(300,300);
    shape->setSize(sf::Vector2f(edge,edge));
    snake.push_back(*shape);
    delete shape;
    }
void m_snake::newsnake(){
    sf::RectangleShape *shape= new sf::RectangleShape;
    shape->setFillColor(snakecolor);
    shape->setPosition(snake.back().getPosition().x-1,snake.back().getPosition().y-1);
    shape->setSize(sf::Vector2f(edge,edge));
    snake.push_back(*shape);
    delete shape;
}
void m_snake::movement(float rotation){
    float x,y;
    rotation=rotation*3.14159/180;
    for (int i = snake.size()-2; i > 0; i--)
    {
        snake.at(i).setPosition(snake.at(i-1).getPosition());
    }
    x=cos(rotation)+snake.front().getPosition().x;
    y=sin(rotation)+snake.front().getPosition().y;
    snake.front().setPosition(x,y);
    if (snake.front().getPosition().x<-edge)
        snake.front().setPosition(horizontal,y);
    if (snake.front().getPosition().y<-edge)
        snake.front().setPosition(x,vercital);
    if (snake.front().getPosition().x>horizontal)
        snake.front().setPosition(-edge,y);
    if (snake.front().getPosition().y>vercital)
        snake.front().setPosition(x,-edge);
    
}
std::vector<sf::RectangleShape>* m_snake::getvector(){
    return &snake;
}
void m_snake::bait(){
    for (int i = 0; i < edge; i++)
    {
        newsnake();
    }
    srand(time(NULL));
    sf::RectangleShape *bait= new sf::RectangleShape;
    bait->setFillColor(snakecolor);
    bait->setPosition(rand()%(int)(horizontal-edge),rand()%(int)(vercital-edge));
    bait->setSize(sf::Vector2f(edge,edge));
    snake.push_back(*bait);
    delete bait;
}
void m_snake::collision(){
    for (int i = 120; i < snake.size()-1; i+=10)
    {
        float x,y;
        x=snake.front().getPosition().x-snake.at(i).getPosition().x;
        y=snake.front().getPosition().y-snake.at(i).getPosition().y;
        if ((x>-edge && x<edge)&& (y<edge && y>-edge))
        {
            snake.erase(snake.begin()+i,snake.end()-1);
            break;
        }
    }
}
bool m_snake::eat(){
    float x,y;
    x=snake.front().getPosition().x-snake.at(snake.size()-1).getPosition().x;
    y=snake.front().getPosition().y-snake.at(snake.size()-1).getPosition().y;
    if ((x>-edge && x<edge)&& (y<edge && y>-edge))
    {
        return true;
    }
    return false;
}