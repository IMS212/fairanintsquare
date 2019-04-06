#include "text.hpp"
#include <memory>

std::vector<sf::Sprite> sq::writing::write_characters(const sf::Texture &font)
{
    int originalX = posX;
    std::vector<sf::Sprite> container;
    for (auto &it : text)
    {
        if (it == '\n')
        {
            posX = originalX;
            posY += 6;
        }
        else
        {
            sf::Sprite temp;
            temp.setTexture(font);
            temp.setTextureRect(sf::IntRect(letters.at(it), 0, 3, 5));
            temp.setPosition(sf::Vector2f(posX, posY));
            posX += 4;
            container.push_back(temp);
        }
    }
    return container;
}

void sq::writing::set_string(const std::string &input)
{
    text = input;
    for (auto &it : text)
    {
        it = std::tolower(it);
    }
    unsigned int counter = 0;
    for (auto &it : text)
    {
        //Breaks reset the lenght counter
        if (it == '\n')
        {
            counter = 0;
            //Each character is 5 pixels high plus 1 pixel accounting for the space between letters
            sizeY += 6;
        }
        else
        {
            counter++;
            if (counter > sizeX)
            {
                sizeX++;
            }
        }
    }
    //Each character is 3 pixels long plus 1 pixel accounting for the space between letters
    sizeX *= 4;
}

std::string sq::writing::get_string() const
{
    return text;
}

//Maybe add stuff to move or squish when on the screen's edge
void sq::writing::set_pos(const int x, const int y)
{
    posX = x;
    posY = y;
}

void sq::writing::show(sf::RenderWindow &window, const sf::Texture &font)
{
    //Make a pretty rectangle around the text
    auto base = std::make_unique<sf::RectangleShape>();
    //SizeX's offset is 5 instead of 6 because remember that the last
    //letter still has that space after it
    //Same kind of deal for sizeY
    base->setSize(sf::Vector2f(sizeX + 5, sizeY + 11));
    base->setPosition(sf::Vector2f(posX - 3, posY - 3));
    base->setFillColor(sf::Color(0, 128, 255));
    base->setOutlineThickness(-1);
    base->setOutlineColor(sf::Color(255, 255, 255));

    //Write the text itself
    auto characters = std::make_unique<std::vector<sf::Sprite>>();
    *characters = write_characters(font);
    window.draw(*base);
    for (auto &it : *characters)
    {
        window.draw(it);
    }
}

sq::writing::writing()
{
}

sq::writing::writing(const std::string &&input, int x, int y)
{
    set_string(input);
    posX = x;
    posY = y;
}
 