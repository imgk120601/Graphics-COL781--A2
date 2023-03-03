// #pragma once
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



class Face;
class Vertex;




class HalfEdge {


public:

    HalfEdge();

 //HalfEdge(Vertex* head, HalfEdge* next , HalfEdge* pair);
    Vertex* head;
    HalfEdge* next;
    HalfEdge* pair;
    Face* face;
   
};
