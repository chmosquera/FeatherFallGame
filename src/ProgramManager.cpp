#include "ProgramManager.h"
#include <stdlib.h>
#include <memory>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Program.h"


using namespace std;
using namespace glm;

ProgramManager::ProgramManager()
{
}


ProgramManager::~ProgramManager()
{
}

const string ProgramManager::resourceDirectory = "../resources";

// Our shader program
const std::shared_ptr<Program> ProgramManager::progMat = ProgramManager::initProgram();

std::shared_ptr<Program> ProgramManager::initProgram() {
	std::shared_ptr<Program> progMat = make_shared<Program>();
	progMat->setVerbose(true);
	progMat->setShaderNames(resourceDirectory + "/my_vert.glsl", resourceDirectory + "/my_frag.glsl");
	progMat->init();
	progMat->addUniform("P");
	progMat->addUniform("V");
	progMat->addUniform("M");
	progMat->addUniform("MatDif");
	progMat->addUniform("MatAmb");
	progMat->addUniform("MatSpec");
	progMat->addUniform("shine");
	progMat->addUniform("LightPos");
	progMat->addAttribute("vertPos");
	progMat->addAttribute("vertNor");
	progMat->addAttribute("vertTex");
	return progMat;
}

void ProgramManager::setModel(std::shared_ptr<MatrixStack>M) {
	glUniformMatrix4fv(progMat->getUniform("M"), 1, GL_FALSE, value_ptr(M->topMatrix()));
}

void ProgramManager::setMaterial(Material i) {
	switch (i) {
	case BLUE_PLASTIC:
		glUniform3f(progMat->getUniform("MatAmb"), 0.02, 0.04, 0.2);
		glUniform3f(progMat->getUniform("MatDif"), 0.0, 0.16, 0.9);
		glUniform3f(progMat->getUniform("MatSpec"), 0.14, 0.2, 0.8);
		glUniform1f(progMat->getUniform("shine"), 120.0);
		break;
	case FLAT_GREY:
		glUniform3f(progMat->getUniform("MatAmb"), 0.13, 0.13, 0.14);
		glUniform3f(progMat->getUniform("MatDif"), 0.3, 0.3, 0.4);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 4.0);
		break;
	case BRASS:
		glUniform3f(progMat->getUniform("MatAmb"), 0.3294, 0.2235, 0.02745);
		glUniform3f(progMat->getUniform("MatDif"), 0.7804, 0.5686, 0.11373);
		glUniform3f(progMat->getUniform("MatSpec"), 0.9922, 0.941176, 0.80784);
		glUniform1f(progMat->getUniform("shine"), 27.9);
		break;
	case GREEN_PLASTIC:
		glUniform3f(progMat->getUniform("MatAmb"), 0.3294, 0.2235, 0.02745);
		glUniform3f(progMat->getUniform("MatDif"), 0.2, 0.8, 0.2);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 80.0);
		break;
	case LIGHT_BLUE:
		glUniform3f(progMat->getUniform("MatAmb"), 0.8, 0.8, 0.99);
		glUniform3f(progMat->getUniform("MatDif"), 0.0, 0.1, 0.9);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 20.);
		break;
	case PURPLE:
		glUniform3f(progMat->getUniform("MatAmb"), 0.2, 0, 0.2);
		glUniform3f(progMat->getUniform("MatDif"), 0.5, 0.0, 0.5);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 20.);
		break;
	case RED:
		glUniform3f(progMat->getUniform("MatAmb"), .2, 0, 0);
		glUniform3f(progMat->getUniform("MatDif"), 1, 0, 0);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 20.);
		break;
	case DIRT:
		glUniform3f(progMat->getUniform("MatAmb"), .5, .16, .0);
		glUniform3f(progMat->getUniform("MatDif"), .8, .2, 0);
		glUniform3f(progMat->getUniform("MatSpec"), 0.3, 0.3, 0.4);
		glUniform1f(progMat->getUniform("shine"), 20.);
		break;
	}
}

