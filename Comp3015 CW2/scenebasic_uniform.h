#ifndef SCENEBASIC_UNIFORM_H
#define SCENEBASIC_UNIFORM_H

#include "helper/scene.h"

#include <glad/glad.h>
#include "helper/glslprogram.h"


#include "helper/objmesh.h"
#include "helper/skybox.h"
#include <vector>
#include "camera.h"

class SceneBasic_Uniform : public Scene
{
private:
    GLuint vaoHandle;
    GLSLProgram prog;
    GLSLProgram progNomralMap;
    GLSLProgram projSky;
    GLSLProgram progAlpha;
    GLSLProgram progLight;
    GLSLProgram projBlur;
    GLSLProgram projFinal;
    GLSLProgram simpleDepthShader;
    GLSLProgram debugDepthQuad;
    GLSLProgram projShadow;

    const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
    unsigned int depthMapFBO;
    unsigned int depthMap;

    float angle;
    

    Camera camera;

    unsigned int planeVAO;

    unsigned int woodTexture;
    void compile();


    glm::vec3 lightPos;

    // model
    std::vector<std::unique_ptr<TriangleMesh>> modelList;
    std::vector<GLuint> texIdxList;

    // normal Map
    unsigned int diffuseMap;
    unsigned int normalMap;


    // skybox
    unsigned int cubemapTexture;
    std::unique_ptr<TriangleMesh> skyboxMesh;


    // grass
    unsigned int transparentVAO;
    unsigned int transparentTexture;

    // gaussian blur
    unsigned int hdrFBO;
    unsigned int pingpongFBO[2];
    unsigned int pingpongColorbuffers[2];
    unsigned int colorBuffers[2];
public:
    SceneBasic_Uniform();

    void renderScene(bool isRenderShadow);
    void initGrass();
    void initSkybox();
    void initScene();
    void update( float t );
    void render();
    void resize(int, int);
};

#endif // SCENEBASIC_UNIFORM_H
