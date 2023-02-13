#include<m_mainpage.hpp>
#include<m_fps.hpp>
m_mainpage::m_mainpage(int x,int y,sf::Color color,sf::Font *font)
{
}
void m_mainpage::selection(select choose,m_text* text){
    int x=0;
    if(text->getshape()->size()==6)
        x++;
    switch (choose)
    {
    case e_play:
        text->getshape()->back()->setPosition(text->getshape()->at(x)->getPosition());
        break;
    case e_fps:
        text->getshape()->back()->setPosition(text->getshape()->at(x+1)->getPosition());
        break;
    case e_gamespeed:
        text->getshape()->back()->setPosition(text->getshape()->at(x+2)->getPosition());
        break;
    case e_volume:
        text->getshape()->back()->setPosition(text->getshape()->at(x+3)->getPosition());
        break;
    }
}
void m_mainpage::page(sf::RenderWindow* window){
    sf::Font font;
    font.loadFromFile("resource/sansation.ttf");
    m_text text(true,&font);
    select choose=e_play;
    int fps=60; 
    m_fps ofps;
    ofps.set(60);
    while (window->isOpen())
    {
        ofps.tocount();
        sf::Event event;
        bool w_up=false;
        bool s_up=false;
        while(window->pollEvent(event)){
            if (event.type==sf::Event::Closed || event.key.code==sf::Keyboard::Escape)
            {
                window->close();
            }
            if (event.type==sf::Event::KeyReleased)
            {
                if (event.key.code==sf::Keyboard::W||event.key.code==sf::Keyboard::Up)
                {
                    w_up=true;
                }
                if (event.key.code==sf::Keyboard::S||event.key.code==sf::Keyboard::Down)
                {
                    s_up=true;
                }
                
            }
            
        }
        if(w_up)
            switch (choose)
                {
                case 0:
                    choose=e_fps;
                    break;
                case 1:
                    choose=e_gamespeed;
                    break;
                case 2:
                    choose=e_volume;
                    break;
                case 3:
                    choose=e_play;
                    break;
                }
        if(s_up)
            switch (choose)
                {
                case 0:
                    choose=e_volume;
                    break;
                case 1:
                    choose=e_play;
                    break;
                case 2:
                    choose=e_fps;
                    break;
                case 3:
                    choose=e_gamespeed;
                    break;
                }
        selection(choose,&text);
        
        window->clear();
        for (auto &&i : *text.getshape())
        {
            window->draw(*i);
        }
        for (auto &&i : *text.getText())
        {
            window->draw(*i);
        }
        window->display();
        ofps.wait();

    }
    
}