#pragma once
#include <string>
#include <GL/glew.h>


class Texture
{
public:
	Texture(const std::string& fileName);

	void bind(unsigned int unit);

	virtual ~Texture();

protected:

private:
	Texture(const Texture& other);
	void operator=(const Texture& other);

	GLuint m_texture;
};

