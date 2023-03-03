#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>
#include <math.h>

#include <glm/geometric.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include <vector>
#include "Vertex.h"
#include "HalfEdge.h"
#include "Face.h"

using namespace std;

class Mesh {

public:

  Mesh();
  //Mesh(vector<Vertex*> Vertexarray, vector<HalfEdge*> HalfEdgearray, vector<Face*> Facearray );
  vector<Vertex*> Vertexarray;
  vector<HalfEdge*> HalfEdgearray;
  vector<Face*> Facearray;
  

};