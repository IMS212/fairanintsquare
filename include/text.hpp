#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
namespace sq
{
const std::map<char, int> letters = {
    {'a', 0}, {'b', 3}, {'c', 6}, {'d', 9}, {'e', 12}, {'f', 15}, {'g', 18}, {'h', 21}, {'i', 24}, {'j', 27}, {'k', 30}, {'l', 33}, {'m', 36}, {'n', 39}, {'o', 42}, {'p', 45}, {'q', 48}, {'r', 51}, {'s', 54}, {'t', 57}, {'u', 60}, {'v', 63}, {'w', 66}, {'x', 69}, {'y', 72}, {'z', 75}, {'1', 78}, {'2', 81}, {'3', 84}, {'4', 87}, {'5', 90}, {'6', 93}, {'7', 96}, {'8', 99}, {'9', 102}, {'!', 105}, {'?', 108}, {'+', 111}, {'-', 114}, {'>', 117}, {':', 120}, {' ', 123}};

class writing{
private:
  std::string text = "";
  int posX = 0;
  int posY = 0;
  unsigned int sizeX = 0;
  unsigned int sizeY = 0;
  std::vector<sf::Sprite> writeCharacters(const sf::Texture &font);

public:
  writing();
  writing(const std::string &&input, int x, int y);
  void set_string(const std::string &input);
  std::string get_string() const;
  void set_pos(const int x, const int y);
  void show(sf::RenderWindow &window, const sf::Texture &font);
};
} // namespace sq
#endif
