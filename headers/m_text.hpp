#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<iostream>
class m_text
{
private:
    std::vector<sf::Text*> text;
    std::vector<sf::RectangleShape*> textshape;
    std::string str[5]{"Continue","New Game","Fps : 60","Game Speed : 1","Volume : 5"};
public:
    m_text(bool page,sf::Font* font){
        if(page){
        this->str[1]="Play";
        }
        for (int i = page,y=100; i< 5; i++,y+=50)
        {
            this->text.push_back(new sf::Text(this->str[i],*font,24));
            this->text.back()->setPosition(sf::Vector2f(200,y));
            this->text.back()->setFillColor(sf::Color::Black);
            this->textshape.push_back(new sf::RectangleShape(sf::Vector2f(250,40)));
            this->textshape.back()->setFillColor(sf::Color::Cyan);
            this->textshape.back()->setPosition(sf::Vector2f(190,y));
        }
        this->textshape.push_back(new sf::RectangleShape(sf::Vector2f(250,40)));
        this->textshape.back()->setFillColor(sf::Color::Red);
        this->textshape.back()->setPosition(this->textshape.front()->getPosition());
    }
    std::vector<sf::RectangleShape*>* getshape(){
        return  &this->textshape;
    }
    std::vector<sf::Text*>* getText(){
        return  &this->text;
    }
    ~m_text(){
        this->text.erase(this->text.begin(),this->text.end());
        this->textshape.erase(this->textshape.begin(),this->textshape.end());
    }
};
