#include<m_gamepage.hpp>

m_gamepage::m_gamepage(/* args */)
{
}

/*#include<iostream>
#include"m_snake.hpp"
#include"m_fps.hpp"
int main(int argc, char const *argv[])
{
    float horizontal=800,vercital=600,edge=(horizontal+vercital)/100;
    sf::RenderWindow window(sf::VideoMode(horizontal,vercital),"Snake");
    m_fps fps;
    m_snake snake(edge,horizontal,vercital,sf::Color::Cyan);
    float rotation = 0;

    for (int i = 0; i < 9; i++)
    {
        snake.newsnake();
    }
    fps.set(120);
     
    while (window.isOpen())
    {
        bool right=false;
        bool left=false;
        fps.tocount();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type==sf::Event::Closed||event.key.code==sf::Keyboard::Escape)
            {
                window.close();
            }
            if (event.type==sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    left=true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    right=true;
                }
            }
            
            
        }
        window.clear();
        if(right)
            rotation+=10;
        if(left)
            rotation-=10;
        if(snake.eat())
            snake.bait();
        snake.collision();
        snake.movement(rotation);
        for (auto &i :*snake.getvector())
        {
            window.draw(i);
        }
        window.display();
        fps.wait();
        }
    
    return 0;
}*/
