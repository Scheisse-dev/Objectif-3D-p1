#include "GIF.h"

GIF::GIF(const char* _path)
{
	FILE* _f = stbi__fopen(_path, "rb");
	stbi__context _s;
	stbi__start_file(&_s, _f);
	int* _delay = 0; 
	int _z = 0, _comp = 0;

	void* _pixels = stbi__load_gif_main(&_s, &_delay, &size.x, &size.y, &_z, &_comp, STBI_rgb_alpha);
	sf::Image _image;
	int _step = size.x * size.y * 4;
	for (int i = 0; i < _z; i++)
	{
		_image.create(size.x, size.y, (const sf::Uint8*)_pixels + _step * i);
		sf::Texture _texture;
		_texture.loadFromFile(_image);
		frames.push_back(std::tuple<int, sf::Texture>(_delay[i], _texture));
	}

	frameIter = frames.begin();
	stbi_image_free(_pixels);
	if (_delay)
		stbi_image_free(_delay);
	fclose(_f);
	totalDelay = sf::Time::Zero;
	startTime = clock.getElapsedTime();
}

void GIF::Update(sf::Sprite& _sprite)
{
	sf::Time _delay = sf::milliseconds(std::get<0>(*frameIter));
	while (startTime + totalDelay < clock.getElapsedTime())
	{
		totalDelay += _delay;
		_delay = sf::milliseconds(std::get<0>(*frameIter));
	}
	sf::Texture& _texture = std::get<0>(*frameIter);
	_sprite.setTexture(_texture);
}

sf::Vector2i GIF::GetSize() const
{
	return size;
}
