#include "Gif.h"
#define STB_IMAGE_IMPLEMENTATION
#define STB_ONLY_GIF

#include "stb_image.h"

GIF::GIF(const char* _path)
{
    FILE* _f = stbi__fopen(_path, "rb");
    stbi__context _s;
    stbi__start_file(&_s, _f);
    int* _delays = 0;
    int _z = 0, _comp = 0;

    void* _pixels = stbi__load_gif_main(&_s, &_delays, &size.x, &size.y, &_z, &_comp, STBI_rgb_alpha);
    sf::Image _image;
    int _step = size.x * size.y * 4;
    for (int i = 0; i < _z; i++)
    {
        _image.create(size.x, size.y, (const sf::Uint8*)_pixels + _step * i);
        sf::Texture _texture;
        _texture.loadFromImage(_image);
        frames.push_back(std::tuple<int, sf::Texture>(_delays[i], _texture));
    }

    frameIter = frames.begin();
    stbi_image_free(_pixels);
    if (_delays)
        stbi_image_free(_delays);
    fclose(_f);
    totalDelay = sf::Time::Zero;
    startTime = clock.getElapsedTime();
}

void GIF::Update(sf::Sprite& _sprite)
{
    sf::Time _delay = sf::milliseconds(std::get<0>(*frameIter));
    while (startTime + totalDelay < clock.getElapsedTime())
    {
        frameIter++;
        if (frameIter == frames.end()) frameIter = frames.begin();
        totalDelay += _delay;
        _delay = sf::milliseconds(std::get<0>(*frameIter));
    }
    sf::Texture& _texture = std::get<1>(*frameIter);
    _sprite.setTexture(_texture);
}

sf::Vector2i GIF::GetSize() const
{
    return size;
}