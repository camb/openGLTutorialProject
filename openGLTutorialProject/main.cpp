#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 1200
#define HEIGHT 800


int main(int argc, char* argv[]) {
	Display display(WIDTH, HEIGHT, "Hello World");

	Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0),	 glm::vec2(.4805, .65)),
						  Vertex(glm::vec3(0, 0.5, 0),		 glm::vec2(0.6605, .15)),
						  Vertex(glm::vec3(0.5, -0.5, 0),	 glm::vec2(.8405, .65)) };

	unsigned int indices[] = { 0, 1, 2 };

	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh2(".\\res\\monkey3.obj");
	Shader shader(".\\res\\basicShader");
	Texture texture(".\\res\\painting.jpg");
	Camera camera(glm::vec3(0.0, 0.0, 6.0), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);
	Transform transform;

	float counter = 0.0f;

	while (!display.isClosed()) {
		display.clear(0.0f, 0.0f, 0.0f, 1.0f);
		float sinCounter = sinf(counter);
		float cosCounter = cos(counter);

		transform.getPos().x = sinCounter;
		transform.getPos().z = (cosCounter * 2) + 2;
		transform.getRot().x = counter * 3;
		transform.getRot().y = counter * 7;
		transform.getRot().z = counter * 11;
		transform.getScale() = glm::vec3(.5f);

		shader.bind();
		texture.bind(0);
		shader.update(transform, camera);
		mesh2.Draw();

		display.update();
		counter += 0.002f;
	}
	return 0;
}