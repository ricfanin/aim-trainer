#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time);
        void render();
        void eventHandler(sf::Event::MouseButtonEvent, bool);
        void checkTarget(sf::Event::MouseButtonEvent);

    private:
        sf::RenderWindow window;
        sf::CircleShape target;
        bool targetClicked;
};