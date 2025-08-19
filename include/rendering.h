#include <string>
#include <vector>

class Shader {
private:
	unsigned int ID;
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
};

class ObjectBuffer {
private:
	unsigned int VBO, VAO, EBO;
public:
	ObjectBuffer(std::vector<float> vertices, std::vector<unsigned int> indices);
	void bind();
	void unbind();
};