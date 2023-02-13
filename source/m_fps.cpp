#include"m_fps.hpp"
void m_fps::tocount(){
    time=clock.getElapsedTime();
}
void m_fps::wait(){
    if (time.asMilliseconds()<fps)
    {
        sf::sleep(sf::milliseconds(fps-time.asMilliseconds()));
    }
    clock.restart();
}
void m_fps::set(int fps){
    this->fps=1000/fps;
}

