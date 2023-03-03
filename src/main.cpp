#include "viewer.hpp"
#include "Mesh.h"
//#include "Vertex.h"
#include <vector>
#include <map>

#include <bits/stdc++.h>
namespace V = COL781::Viewer;
using namespace glm;



int unitsquare(float m ,float n){

    float height=1/m;
    float width=1/n;


   // Mesh* mesh= new Mesh();

    Vertex* vertex;

    std::vector<Vertex*> Vertexarray={};
    std::vector<HalfEdge*> HalfEdgearray={};
    std::vector<Face*> Facearray={};

    
    vec3 tempPosition={0.0,0.0,0.0};
    vec3 tempNormal={0.0,0.0,1.0};

    ivec3 tempIndices={0,0,0};
    Face* face1;
    Face* face2;

    for(int i=0; i<m+1; i++){

        for(int j=0; j<n+1; j++){
            //adding vertices in vertexarray
            tempPosition[0]=i*height - 0.5;          
            tempPosition[1]=j*width - 0.5;
            vertex=new Vertex( );

            vertex->position=tempPosition;
            vertex->normal=tempNormal;
            
            Vertexarray.push_back(vertex);


        }
    }

    int a,b,c,d;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){
            
            a=i*(n+1)+j;
            b=a+1;
            c=a+n+1;
            d=c+1;


            face1=new Face();
            face1->indices={a,b,d};

            Facearray.push_back(face1);

            face2 = new Face();
            face2->indices={a,c,d};

            Facearray.push_back(face2);


        }
    }

    //no of vertices and no of faces
    a=(m+1)*(n+1); 
    
    b=2*m*n;


    vec3 vertices[a]={};

    vec3 normals[a]={};
    
    ivec3 triangles[b]={};


//     vec3 vertices[] = {
//         vec3(-0.5, -0.5, 0.0),
//         vec3( 0.5, -0.5, 0.0),
// 		vec3(-0.5,  0.5, 0.0),
//         vec3( 0.5,  0.5, 0.0),
// 		vec3( 0.0,  0.0, 1.0),
//          vec3(-0.5, -0.5, 0.0),
//         vec3( 0.5, -0.5, 0.0),
// 		vec3(-0.5,  0.5, 0.0),
//         vec3( 0.5,  0.5, 0.0),
// 		vec3( 0.0,  0.0, 1.0)
		
//    };
    // vec3 normals[] = {
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
	// 	vec3(0.0, 0.0,1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
    //     vec3(0.0, 0.0, 1.0),
	// 	vec3(0.0, 0.0,1.0)
    // };
	// ivec3 triangles[] = {
	// 	ivec3(0, 1, 2),
	// 	ivec3(1, 2, 3),
	// 	ivec3(0,1,4),
	// 	ivec3(1,2,4),
	// 	ivec3(2,3,4),
	// 	ivec3(3,0,4),
    //     ivec3(0, 1, 2),
	// 	ivec3(1, 2, 3),
	// 	ivec3(0,1,4),
	// 	ivec3(1,2,4),
	// 	ivec3(2,3,4),
	// 	ivec3(3,0,4)
	// };





    //extracting out vertexs- postion ,normal , and indices -> to set them in viewer class and render them

    //extracting vertices -> postion and normals
    for(int i=0; i<Vertexarray.size(); i++){
        vertices[i]=Vertexarray[i]->position;
          
        normals[i]=Vertexarray[i]->normal;

        //for(int j=0; j<3 ; j++){
        //std::cout<< Vertexarray[i]->position[j]<<std::endl;
          //vertices[i]=Vertexarray[i]->position;
          //std::cout<< Vertexarray[i]->position[j];
           //normals[i]=Vertexarray[i]->normal;
        //}
        //std::cout<<" "<<std::endl;
    }

    //extracting out Face/triangle indices information from faces
    
    
    for(int i=0; i<Facearray.size(); i++){

        triangles[i]=Facearray[i]->indices;


    }


       //do rendering

	V::Viewer v;
	if (!v.initialize("Mesh viewer", 840, 680)) {
		return EXIT_FAILURE;
	}
	v.setVertices(a, vertices);
	v.setNormals(a, normals);
	v.setTriangles(b, triangles);
	v.view();

    return 0;

}



int unitsphere(int m, int n){

    
    Vertex* vertex;
    Face* face;

    std::vector<Vertex*> Vertexarray={};
    std::vector<HalfEdge*> HalfEdgearray={};
    std::vector<Face*> Facearray={};


    float di=360/m;
    float angle=radians(di);

    float degree=0;

    
    vec3 tempPosition={0.0,0.0,1.0};
    vec3 tempNormal={0.0,0.0,1.0};

    std::vector<float> mysin={};
    std::vector<float> mycos={};
    
    for(int i=0; i<m; i++){

        degree=i*di;
        angle=radians(degree);

        mysin.push_back(sin(angle));
        mycos.push_back(cos(angle));

        if(abs(mysin[i])< exp(-5)){
            mysin[i]=0;
        }
        
        if(abs(mycos[i])< exp(-5)){
            mycos[i]=0;
        }


       cout<<mysin[i]<<" "<<mycos[i]<<endl;
    }


   // cout<<" "<<endl;


    float tempn=n;
    float z=1;
    float height=2/tempn;
    float r=0;

    //float tempz=0;

    int a,b,c,d;

    for(int i=0; i<n+1; i++){

        if(i==0 || i==n){

            r=abs(z);
            r=sqrt(1-r*r);
            

            tempPosition[0]=0;
            tempPosition[1]=0;
            tempPosition[2]=z;
            vertex=new Vertex();

            vertex->position=tempPosition;
            vertex->normal=tempNormal;
            Vertexarray.push_back(vertex);
        
            if(i==n){
                for(int j=0; j<m; j++){
                    a=Vertexarray.size()-1;
                    b=a-(j+1);
                    c=a-(j+2);
                    if(j==m-1){
                        c=a-1;
                    }

                    face= new Face();
                    face->indices= {a,b,c};
                    Facearray.push_back(face);

                }
            }

        }else{
            for(int j=0; j<m; j++){
            
        
            r=abs(z);
            r=sqrt(1-r*r);
            

            tempPosition[0]=r*mysin[j];
            tempPosition[1]=r*mycos[j];
            tempPosition[2]=z;
            vertex=new Vertex();

            vertex->position=tempPosition;
            vertex->normal=tempNormal;
            Vertexarray.push_back(vertex);
        }

            if(i!=1){
            
                for(int j=0; j<m; j++){
                a=Vertexarray.size()-1-j;
                b=a-1;
                c=b-m;
                d=a-m;
                if(j==m-1){
                    b=Vertexarray.size()-1;
                    c=b-m;
                }

                face=new Face();
                face->indices= {a,b,d};

                Facearray.push_back(face);

                face=new Face();
                face->indices={b,c,d};
                Facearray.push_back(face);

                 }
             }else{

                for(int j=0; j<m; j++){
                    a=Vertexarray.size()-1 -m;
                    b=a+(j+1);
                    c=b+1;

                    if(j==m-1){
                        c=a+1;
                    }

                    face= new Face();
                    face->indices= {a,b,c};
                    Facearray.push_back(face);
                }
             }

        }


        z=z-height;
    
    }



    //no of vertices and no of faces
    a=Vertexarray.size(); 
    
    b=Facearray.size();


    vec3 vertices[a]={};

    vec3 normals[a]={};
    
    ivec3 triangles[b]={};





  //extracting out vertexs- postion ,normal , and indices -> to set them in viewer class and render them

    //extracting vertices -> postion and normals
    for(int i=0; i<Vertexarray.size(); i++){
        vertices[i]=Vertexarray[i]->position;
          
        normals[i]=Vertexarray[i]->normal;

    //     for(int j=0; j<3 ; j++){
        
        
    //      std::cout<< Vertexarray[i]->position[j]<<" ";
           
    //    }
    //    std::cout<<" "<<std::endl;
    }

    //extracting out Face/triangle indices information from faces
    
    std::cout<<" "<<std::endl;
    
    for(int i=0; i<Facearray.size(); i++){

        triangles[i]=Facearray[i]->indices;
        
    //     for(int j=0; j<3 ; j++){
        
        
    //      std::cout<< Facearray[i]->indices[j]<<" ";
           
    //    }
    //    std::cout<<" "<<std::endl;


    }




    //do rendering

	V::Viewer v;
	if (!v.initialize("Mesh viewer", 840, 680)) {
		return EXIT_FAILURE;
	}
	v.setVertices(a, vertices);
	v.setNormals(a, normals);
	v.setTriangles(b, triangles);
	v.view();

    return 0;

}



int main(){





    //return unitsquare(5,2);

    return unitsphere(20,20);
    //return 0;
}


/*

int main() {
    vec3 vertices[] = {
        vec3(-0.5, -0.5, 0.0),
        vec3( 0.5, -0.5, 0.0),
		vec3(-0.5,  0.5, 0.0),
        vec3( 0.5,  0.5, 0.0),
		vec3( 0.0,  0.0, 1.0),
		
   };
    vec3 normals[] = {
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
        vec3(0.0, 0.0, 1.0),
		vec3(0.0, 0.0,1.0)
    };
	ivec3 triangles[] = {
		ivec3(0, 1, 2),
		ivec3(1, 2, 3),
		ivec3(0,1,4),
		ivec3(1,2,4),
		ivec3(2,3,4),
		ivec3(3,0,4)
	};


    // vector<vector<int>> mytriangles={

    //     {0,1,2},
    //     {1,2,3}
    // };


    Vertex* tempV ;
    HalfEdge* tempHE;
    Face* tempF;
    
    std::vector<Vertex*> Vertexarray={};
    std::vector<HalfEdge*> HalfEdgearray={};
    std::vector<Face*> Facearray={};
    
    map<pair<int,int> ,int> mp;

    //std::cout<<Vertexarray.size()<<std::endl;

    for(int i=0;i<4; i++){
        tempV=new Vertex();
        Vertexarray.push_back(tempV);
    }
    for(int i=0; i<7; i++){
        tempHE=new HalfEdge();
        HalfEdgearray.push_back(tempHE);
    }
    for(int i=0; i<2; i++){
        tempF=new Face();
        Facearray.push_back(tempF);
    }
    
     for(int i=0; i<4; i++){
    
        Vertexarray[i]->position=vertices[i];
        Vertexarray[i]->normal=normals[i];
     }

    //  for(int i=0; i<4; i++){
    //     for(int j=0; j<3; j++){
    //      std::cout<< Vertexarray[i]->position[j]<<" ";   
    //     }
    //     std::cout<<" "<<std::endl;
    //  }

    int k,k1;
    int a,b,c;

    vector<int> temp;
     pair<int ,int> p,p1;
     bool love=false;
    
    
    
    //filling our data structure
    for(int i=0; i<2; i++){
        
      
      temp={};
      for(int w=0; w<3; w++){

        temp.push_back(triangles[i][w]);
      }


      temp.push_back(temp[0]);
      love=true;

      for(int j=0; j<3; j++){
        p={temp[j],temp[j+1]};
        if(mp[p]!=0){
            love=false;
            break;
        }
      }

      if(love==false){
        temp={};
        for(int w=0; w<3; w++){

            temp.push_back(triangles[i][w]);
        }
        reverse(temp.begin(), temp.end());
        temp.push_back(temp[0]);
      }

    
      for(int j=0; j<3; j++){
        Facearray[i]->indices[j]=temp[j];
        k=3*i+j+1;
        p={temp[j],temp[j+1]};
        
        p1={temp[j+1],temp[j]};        
        if(mp[p1]!=0){
            k1=mp[p1];
            HalfEdgearray[k]->pair=HalfEdgearray[k1];
            HalfEdgearray[k1]->pair=HalfEdgearray[k];
        }
        mp[p]=k;

        HalfEdgearray[k]->face=Facearray[i];
        Facearray[i]->myhalfedge=HalfEdgearray[k];

        if(j==2){
            HalfEdgearray[k]->next=HalfEdgearray[k-2];
        }else{
            HalfEdgearray[k]->next=HalfEdgearray[k+1];
        }
       
        HalfEdgearray[k]->head =Vertexarray[temp[j+1]];
        Vertexarray[temp[j+1]]->myhalfedge=HalfEdgearray[k];

      }

    }


    //do mesh-editing----

    //extracting out vertexs- postion ,normal , and indices -> to set them in viewer class and render them

    //extracting vertices -> postion and normals
    for(int i=0; i<Vertexarray.size(); i++){
        vertices[i]=Vertexarray[i]->position;
          
        normals[i]=Vertexarray[i]->normal;

        //for(int j=0; j<3 ; j++){
        //std::cout<< Vertexarray[i]->position[j]<<std::endl;
          //vertices[i]=Vertexarray[i]->position;
          //std::cout<< Vertexarray[i]->position[j];
           //normals[i]=Vertexarray[i]->normal;
        //}
        //std::cout<<" "<<std::endl;
    }

    //extracting out Face/triangle indices information from faces
    
    
    for(int i=0; i<Facearray.size(); i++){

        triangles[i]=Facearray[i]->indices;


    }

    

    //do rendering

	V::Viewer v;
	if (!v.initialize("Mesh viewer", 640, 480)) {
		return EXIT_FAILURE;
	}
	v.setVertices(4, vertices);
	v.setNormals(4, normals);
	v.setTriangles(2, triangles);
	v.view();
}
*/