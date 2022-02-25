#include "main.h"

# define M_PI           3.14159265358979323846


int main()
{

    srand(time(NULL));
    
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    window.setVerticalSyncEnabled(1);
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(1);
    bool game = true;
    
    Spaceship player(300, 200, 0, 0,50);
    Spaceship b1(player.x, player.y, 0, 0, 5);
    b1.texture.loadFromFile("img/bullet.png");
    b1.sprite.setTexture(b1.texture);
    Spaceship a(200, 800, -30, 0, 120);
    std::vector<Spaceship> bullets;
    std::vector<Spaceship> asteroids;
    float x = (rand() % windowWidth);
    float y = (rand() % windowHeight);
    asteroids.push_back({ x,y, (rand() % 100 )- 50 , (rand() % 100) - 50 , 120});
    //asteroids.push_back(Spaceship(a));
    int numberOfAsteroids = 1;
    sf::Texture aTexture;
    aTexture.loadFromFile("img/asteroid.png");

    if (!player.texture.loadFromFile("img/avenger.png"))
        std::cout << "avenger texture could not be loaded!\n";
    player.texture.setSmooth(1);

    player.sprite.setTexture(player.texture);
    player.sprite.setOrigin(24, 24);
    player.sprite.setPosition(player.x, player.y);

    
    sf::Clock cooldown;
    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();
        b1.x = player.x;
        b1.y = player.y;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //keymapping
        if (game)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                player.angleOfRotation += 250.f * dt.asSeconds();
                if (player.angleOfRotation <= 0)
                    player.angleOfRotation = 360 + player.angleOfRotation;
                if (player.angleOfRotation >= 360)
                {
                    player.angleOfRotation = player.angleOfRotation - 360;
                }
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            player.angleOfRotation -= 250.f * dt.asSeconds();
            if (player.angleOfRotation <= 0)
                player.angleOfRotation = 360 + player.angleOfRotation;
            if (player.angleOfRotation >= 360)
            {
                player.angleOfRotation = player.angleOfRotation - 360;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            player.dx = sin(player.angleOfRotation * M_PI / 180) * 8000.f * dt.asSeconds();;
            player.dy = -cos(player.angleOfRotation * M_PI / 180) * 8000.f * dt.asSeconds();;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            b1.angleOfRotation = player.angleOfRotation;
            if (cooldown.getElapsedTime().asSeconds() > 0.2f)
            {
                bullets.push_back(Spaceship(b1));
                cooldown.restart();
            }

            for (size_t i = 0; i < bullets.size(); i++)
            {

                bullets[i].dx = sin(bullets[i].angleOfRotation * M_PI / 180) * 30000.f * dt.asSeconds();;
                bullets[i].dy = -cos(bullets[i].angleOfRotation * M_PI / 180) * 30000.f * dt.asSeconds();;

            }
        }



        player.sprite.setRotation(player.angleOfRotation);



        //moving
        player.move(dt);
        for (size_t i = 0; i < bullets.size(); i++)
        {

            bullets[i].move(dt);
            if (bullets[i].x > windowWidth || bullets[i].x < 0 || bullets[i].y > windowHeight || bullets[i].y < 0)
                bullets.erase(bullets.begin() + i);
        }

        //asteroids
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            asteroids[i].sprite.setPosition(asteroids[i].x, asteroids[i].y);
            asteroids[i].move(dt);
            asteroids[i].sprite.setOrigin(asteroids[i].size / 2, asteroids[i].size / 2);

            asteroids[i].sprite.setTexture(aTexture);
            float tempScale = asteroids[i].size / 120;
            asteroids[i].sprite.setScale(tempScale, tempScale);



            for (size_t ii = 0; ii < bullets.size(); ii++)
            {
                //collision detection

                if (sqrt((bullets[ii].x - asteroids[i].x) * (bullets[ii].x - asteroids[i].x) + (bullets[ii].y - asteroids[i].y) * (bullets[ii].y - asteroids[i].y)) < asteroids[i].size / 2
                    || sqrt((bullets[ii].x - asteroids[i].x + windowWidth) * (bullets[ii].x - asteroids[i].x + windowWidth) + (bullets[ii].y - asteroids[i].y) * (bullets[ii].y - asteroids[i].y)) < asteroids[i].size / 2
                    || sqrt((bullets[ii].x - asteroids[i].x - windowWidth) * (bullets[ii].x - asteroids[i].x - windowWidth) + (bullets[ii].y - asteroids[i].y) * (bullets[ii].y - asteroids[i].y)) < asteroids[i].size / 2
                    || sqrt((bullets[ii].x - asteroids[i].x) * (bullets[ii].x - asteroids[i].x) + (bullets[ii].y - asteroids[i].y + windowHeight) * (bullets[ii].y - asteroids[i].y + windowHeight)) < asteroids[i].size / 2
                    || sqrt((bullets[ii].x - asteroids[i].x) * (bullets[ii].x - asteroids[i].x) + (bullets[ii].y - asteroids[i].y - windowHeight) * (bullets[ii].y - asteroids[i].y - windowHeight)) < asteroids[i].size / 2)
                {
                    bullets.erase(bullets.begin() + ii);
                    std::cout << "i: " << i << " size: " << asteroids[i].size << "\n";
                    if (asteroids[i].size == 120)
                    {
                        asteroids[i].size = 60;
                        x = asteroids[i].x + ((rand() % 100) - 50);
                        y = asteroids[i].y + ((rand() % 100) - 50);
                        asteroids.push_back({ x,y, (rand() % 100) - 50 , (rand() % 100) - 50 , 60 });

                        x = asteroids[i].x + ((rand() % 100) - 50);
                        y = asteroids[i].y + ((rand() % 100) - 50);

                        asteroids[i].x = x;
                        asteroids[i].y = y;
                        asteroids[i].dx = (rand() % 100) - 50;
                        asteroids[i].dy = (rand() % 100) - 50;
                    }
                    else if (asteroids[i].size == 60)
                    {
                        asteroids[i].size = 30;
                        x = asteroids[i].x + ((rand() % 100) - 50);
                        y = asteroids[i].y + ((rand() % 100) - 50);
                        asteroids.push_back({ x,y, (rand() % 100) - 50 , (rand() % 100) - 50 , 30 });

                        x = asteroids[i].x + ((rand() % 100) - 50);
                        y = asteroids[i].y + ((rand() % 100) - 50);

                        asteroids[i].x = x;
                        asteroids[i].y = y;
                        asteroids[i].dx = (rand() % 100) - 50;
                        asteroids[i].dy = (rand() % 100) - 50;
                    }
                    else if (asteroids[i].size == 30)
                    {
                        asteroids[i].size = 15;
                    }



                }
            }
            if (asteroids[i].size < 30)
            {
                asteroids.erase(asteroids.begin() + i);
            }
        }

        if (asteroids.size() == 0)
        {
            for (int i = 0; i < numberOfAsteroids; i++)
            {
                float x = (rand() % windowWidth);
                float y = (rand() % windowHeight);
                asteroids.push_back({ x,y, (rand() % 100) - 50 , (rand() % 100) - 50 , 120 });
            }
            numberOfAsteroids++;
        }

        //std::cout << asteroids.size() << "\n";
        player.sprite.setPosition(player.x, player.y);

        //player collision detection
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (sqrt((player.x - asteroids[i].x) * (player.x - asteroids[i].x) + (player.y - asteroids[i].y) * (player.y - asteroids[i].y)) < asteroids[i].size / 2
                || sqrt((player.x - asteroids[i].x + windowWidth) * (player.x - asteroids[i].x + windowWidth) + (player.y - asteroids[i].y) * (player.y - asteroids[i].y)) < asteroids[i].size / 2
                || sqrt((player.x - asteroids[i].x - windowWidth) * (player.x - asteroids[i].x - windowWidth) + (player.y - asteroids[i].y) * (player.y - asteroids[i].y)) < asteroids[i].size / 2
                || sqrt((player.x - asteroids[i].x) * (player.x - asteroids[i].x) + (player.y - asteroids[i].y + windowHeight) * (player.y - asteroids[i].y + windowHeight)) < asteroids[i].size / 2
                || sqrt((player.x - asteroids[i].x) * (player.x - asteroids[i].x) + (player.y - asteroids[i].y - windowHeight) * (player.y - asteroids[i].y - windowHeight)) < asteroids[i].size / 2)
            {
                game = false;
            }

        }
    }
        window.clear();
        
        window.draw(player.sprite);
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            wrapObjects(window, asteroids[i], asteroids[i].sprite);
            window.draw(asteroids[i].sprite);
        }
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bullets[i].sprite.setPosition(bullets[i].x, bullets[i].y);
            window.draw(bullets[i].sprite);
        }
        wrapObjects(window, player, player.sprite);
        
        window.display();
    }

    return 0;
}