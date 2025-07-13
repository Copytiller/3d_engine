
#include "raylib.h"
#include "rcamera.h"

//camera's (vector3){.,.,.} positions

#define tc camera.target
#define tx  camera.target.x
#define ty  camera.target.y
#define tz  camera.target.z

#define px camera.position.x
#define py camera.position.y
#define pz camera.position.z

#define at (Vector3)
#define REPEAT(v) for (int i=0; i<v; i+=1)
#define KEY(v) (IsKeyDown((48)+(v)))   
#define MAX_COLUMNS 20

#define hud_txt txt_n+=TXT




//#define debug 1


int debug = 0;



//shows all axies of a point 
float SHOW(Vector3 param){
    
       int t_=1;
   DrawLine3D(param,param , BLACK);
   DrawLine3D(at{param.x+t_, param.y, param.z}, param, WHITE);
   DrawLine3D(at{param.x, param.y+t_, param.z}, param, BLUE);
   DrawLine3D(at{param.x, param.y, param.z+t_}, param, WHITE);
        t_=-1;
   DrawLine3D(at{param.x+t_, param.y, param.z}, param, WHITE);
   DrawLine3D(at{param.x, param.y+t_, param.z}, param, WHITE);
   DrawLine3D(at{param.x, param.y, param.z+t_}, param, WHITE);
   
   
    
   }

float TXT(const char* preface, float param, float param1, float param2){
    DrawText(TextFormat(preface, param, param1, param2), 350, 25+(25)*param, 25, WHITE);
    return 1; }
    
    int    get_address()
    {
        //int ptr;
        //ptr = 6;     
    //   *MemAlloc(ptr);

     return 9; 
    }

//function to quickly highlight a point using cubes; relative to player

float wires_(float param, Vector3 pos){     float OUT_F=param;
     DrawCubeWires(pos, 5.0f, pos.y, 5.0f, BLACK);
     DrawCubeWires(pos, 5.0f+OUT_F, pos.y, 5.0f+OUT_F, MAROON);
     DrawCubeWires(pos, 5.0f-OUT_F, pos.y, 5.0f-OUT_F, GREEN);
     
return 1;
}

//float cubeC(){
//get_address()
//return 1;
//}
//=

//----------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void){
    int box[5];
box[0] =5555;
box[1] = 666;

int arbitrary = 2;


//

//int* myptr;
//myptr = (int*)malloc(sizeof(9995));
//*myptr = 5555;


//

    int detachView=3;
float look_distance=1;
//for (int i=0; i<5; i+=1){}
//REPEAT(50){}
   int  t_=0;
   float zoomDebt=0;
   //create//
   float bigZoom=0;
 int latest_key=4;                  
 float objects_num =0;   
 //select line ending position
 float tempX = 1.09;
 float tempY = 1.09;
 float tempZ = 1.09;                 
 Vector3 end_pos = (Vector3){0.1f, 0.1f, 0.1f};         
 Vector3 temp_pos = (Vector3){0.1f, 0.1f, 0.1f};         
 
 Vector3 from_point = (Vector3){0.1f, 0.1f, 0.1f};         
 Vector3 to_point = (Vector3){0.1f, 0.1f, 0.1f};         
 
 Vector3 cubePosition = { 0.0f, 30.0f, 0.0f };
 Vector3 cubeSize = { 5.0f, 5.0f, 2.0f };

    int t;
    RayCollision collision = { 0 };     // Ray collision hit info
    
    //Sound fxWav = LoadSound("resources/sound.wav ");         // Load WAV audio file
    //Sound fxOgg = LoadSound("resources/target.ogg");    
    // inf window height inf window width
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");
   
    //sensitivity
    //--------------------------------------------------------------------------------------
    float sensX = 0.05f;
    float sensY = 0.05f;
    float zoomSpeed = -5.0f;
    //POV camera projection
    //--------------------------------------------------------------------------------------
    float target_modifier;
    float t_m = 1.0f;
    Camera camera = { 0 };
    camera.position = at{ 0.0f, 2.0f, 4.0f };    // Camera position
    Vector3 vec1 = camera.position;
    camera.target = at{ 0.01f, 2.01f, 0.01f};      // Camera looking at point
    camera.up = at{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
    
    
    //misc vars
    //--------------------------------------------------------------------------------------
  Model z55= LoadModelFromMesh(GenMeshSphere(40, 32.0f, 8));
  
  Image img = LoadImage("resources/skybox.png");
  Image img2 = LoadImage("resources/skybox.png");

  //ImageDrawRectangle(&img2, 0, 435, 5354, 45, BLACK);
    Vector3 tempPos = at{0,0,0}; Vector3 tempTarget = at{0,0,0};  
ImageFlipHorizontal(&img2);
REPEAT(50)
{ImageDrawRectangle(&img2, (i+5)*20, i*5, (i-1)*20, i/i, GetColor(GetRandomValue(5,100000000000000)));}
  //ImageDrawTextEx(&img2, font, "OKOKOK", (Vector2){ 0, 0 }, (float)font.baseSize, -2, WHITE);
const char* txt1 = "fff";
Image myimg;

//myimg=GenImageChecked(300, 300, 60, 60,PINK, BLUE);        // Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
//myimg= GenImageColor(50, 500, Color color);                                           // Generate image: plain color
//myimg=     GenImageGradientLinear(50, 500, int direction, Color start, Color end);        // Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient
    //myimg= GenImageGradientRadial(50, 500, 25.5f, RED, WHITE);      // Generate image: radial gradient
   
//   myimg= GenImageGradientRadial(50, 500, 5.5f, PINK, BLUE);      // Generate image: radial gradient
  
 // myimg= GenImageGradientSquare(50, 500, 0.5f, RED, WHITE);      // Generate image: square gradient
  /// myimg= GenImageChecked(300, 300, 60, 60,WHITE, RED);
   //myimg= GenImageWhiteNoise(50, 500, 0.5);                                     // Generate image: white noise
   //myimg=  GenImagePerlinNoise(50, 500, 20, 20, 10);           // Generate image: perlin noise
   //myimg= GenImageCellular(50, 500, 5);                                       // Generate image: cellular algorithm, bigger tileSize means bigger cells
  //myimg=  GenImageText(50, 500,"vsa");                                       // Generate image: grayscale image from text data

    //double GetTime(void);  
  Texture2D textureok = LoadTextureFromImage(img);
  textureok = LoadTextureFromImage(img2);
//ImageFlipHorizontal(&myimg);
  Texture2D texture_myimg = LoadTextureFromImage(myimg);
    DrawTexture(texture_myimg, 666, 555, WHITE);   
 // textureok = LoadTextureFromImage(img2); 

  z55.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = textureok;
  int aa = 1;
  int bb = 2;
  int cc = 3;
  int cameraMode = CAMERA_FIRST_PERSON;
  float prevX = px; float prevZ = pz;
  float ddd=0;
  int zoom=-2;


    //audio
    InitAudioDevice();      // Initialize audio device

    //inf fps 
    DisableCursor();                    // Limit cursor to relative movement inside the window
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    float spd1 = 0.1f;
    float spd = 0.1f;
    float spd2 = spd1*10;
    float acc1  = 0.004f;
    float acc    = 0.004f;
        int i; int ii; int iii;
        float debug;
        float accX=0; float accZ=0;
               Ray ray = GetMouseRay(GetMousePosition(), camera);

// infmaxcolumns
    //--------------------------------------------------------------------------------------
    
    float heights[MAX_COLUMNS] = { 0 };
    Vector3 positions[MAX_COLUMNS] = { 0 };
    Color colors[MAX_COLUMNS] = { 0 };

    //coloumn structures generation
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(1, 12);
        positions[i] = at{ (float)GetRandomValue(-15, 15), heights[i]/2.0f, (float)GetRandomValue(-15, 15) };
        colors[i] = (Color){ GetRandomValue(20, 15), GetRandomValue(10, 15), 30, 40};
    }
        float zoomGeneral=0;
   
    //inf step
    
    while (!WindowShouldClose())        // Detect window close button or ESC key
    { 
    float ANG_X = (px-tx);
float ANG_Y = (py-ty);
float ANG_Z = (pz-tz);

    if (IsKeyDown(KEY_LEFT_SHIFT)){if (spd<spd2){spd +=acc;}}
    else{if (!(spd == spd1)){spd-=acc;} if (spd<spd1){spd=spd1;}}

    if (!(prevX = px)){accX+=5;} if (!(prevZ=pz)){accZ=5;}
        accX = (accX*0.9); accZ = (accZ*0.1);
//default
if (detachView==3){tempPos = camera.position; tempTarget = tc; detachView=0;}
if (detachView==1){tempPos = camera.position; tempTarget = tc; detachView=0;}
if (detachView==2){camera.position = tempPos; tc=tempTarget; detachView=0;}
if (IsKeyPressed(KEY_FOUR)){detachView=1;}
if (IsKeyPressed(KEY_FIVE)){detachView=2;}

        
         //prevX = px;
         //prevZ = pz;

        // Update
        //----------------------------------------------------------------------------------

    zoomGeneral += GetMouseWheelMove()*2.0f;
    if (zoomGeneral<0){zoomGeneral=0;}
    
            //----------------------------------------------------------------------------------
        //if (IsKeyPressed(KEY_SPACE)) PlaySound(fxWav);      // Play WAV sound
        //if (IsKeyPressed(KEY_ENTER)) PlaySound(fxOgg);   

//ANG_X = (px-tx);
      if (IsCursorHidden()){}
      float ZOOMF=(GetMouseWheelMove()+zoom)*zoomSpeed;
    if (!(GetMouseWheelMove()>0)){t_m = 0; camera.target = at{tx, ty, tz};}
      //t_m+=();
      //camera.target = at{ tx/2, ty/2, tz/2};
    //if (ZOOMF>0)
    //{
   // if ((ZOOMF)<0){camera.target = at{ tx*t_m, ty*t_m, tz*t_m};}
    //}      // Camera looking at point
    

if (bigZoom+GetMouseWheelMove()>(-4))
{bigZoom += GetMouseWheelMove();}
//if (bigZoom<-4){bigZoom=-4;}

    
    //float temp1 = px;
    //float temp2 = py;
   // float temp3 = pz;
    
UpdateCameraPro(&camera,
            at  {
                (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*spd -      // Move forward-backward
                (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*spd,    
                (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*spd -   // Move right-left
                (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*spd,
                0.0f                                                // Move up-down
                },
            at  {
                GetMouseDelta().x*sensX,                            // Rotation: yaw
                GetMouseDelta().y*sensY,                            // Rotation: pitch
                0.0f                                                // Rotation: roll
                },
0.0f 
                //GetMouseWheelMove()*0
);            // Move to target (zoom)
    
//if (zoomDebt!=bigZoom){
    

    //float diff1= px-temp1;
    // float diff2= py-temp2;
    // float diff3= pz-temp3;
//deletable 
///////////
    if (zoomDebt>50000.0f){
//UpdateCameraPro(&camera,
       //     at  {
                //(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))*0 -      // Move forward-backward
                //(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))*0,    
               // (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))*0 -   // Move right-left
               // (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))*0,
              //  0.0f                                                // Move up-down
             //   },
           // at  {
               // GetMouseDelta().x*0,                            // Rotation: yaw
              //  GetMouseDelta().y*0,                            // Rotation: pitch
             //   0.0f                                                // Rotation: roll
           //     },
         //       -GetMouseWheelMove()/100
       //     );            // Move to target (zoom)
         
     //tx = tx+diff1*100;
     //ty=ty+diff2*100;
     //tz=tz+diff3*100; 
 
     //zoomDebt = bigZoom;      
//}
}
zoom=0;
        // Toggle camera controls
        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            if (IsCursorHidden()) EnableCursor();
            else DisableCursor();
        }
if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (!collision.hit)
            {ray = GetMouseRay((Vector2){960,540}, camera);

                collision = GetRayCollisionBox(ray,
                            (BoundingBox){at{ cubePosition.x - cubeSize.x/2, cubePosition.y - cubeSize.y/2, cubePosition.z - cubeSize.z/2 },
                                          at{ cubePosition.x + cubeSize.x/2, cubePosition.y + cubeSize.y/2, cubePosition.z + cubeSize.z/2 }});
                collision = GetRayCollisionBox(ray,
                            (BoundingBox){from_point,
                                          to_point});
            
            }
        else collision.hit = false;}

if (IsKeyPressed(KEY_THREE)){
    //;;//;//;//array[objects_num+1]=getFreshAddress();
    //(*array[objects_num+1])[0] *<-----aka sub_array* = format(determines what of the other part of the array is used)
    //""[1] = color
    //""[2] = saturation
    //""[3] = alpha
    //""[4] = X
    //""[5] = Y
    //""[6] = Z
    //""[n] = ...
//objects_num+=1;
 if (IsCursorHidden()) EnableCursor();
            else DisableCursor();
            //create object-bullet
            //designate axis of fire
            //fure
            //travel at designated speed
            //fubd collisions
}
//    for(int i=0; i<objects_num, i++)
    //{draw(object_table[i])}
            
        //selected_thing:
        //(*shape.address)
        
        
        
        //=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//
        // DRAW_______________________________________________
        //=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//=//
            BeginDrawing(); 
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
 
int totalSquares = 35;
int height_length = 8;
int yOffset = 2;
int y_add = 0;
//
float table_x[totalSquares];
float table_y[totalSquares];
int table_state[totalSquares];
//float* table_x_ptr = &table_x;
//
for (i=0; i<totalSquares; i++)
{
    int rowLength = totalSquares/height_length;
    int xOffset = 2;
    int x_add = ((((i%(rowLength))+1)-((rowLength)/2))*(xOffset))-1;

    int check_mod = ((i%rowLength)+1);
    if  (check_mod == 1)      
    {
        y_add+= (yOffset);
    }
    table_x[i] = px+x_add;
    table_y[i] = y_add;

    Vector3 cube_pos = at{table_x[i],table_y[i],pz+-10};

    if (table_x[i] == table_x[1])
    {
        DrawCube(cube_pos,2, 2, 2.0f, BLUE);
    }
    else
    {
        DrawCube(cube_pos,2, 2, 2.0f, YELLOW);
    }
                     

    DrawCubeWires(cube_pos,2, 2, 2.001f, BLACK);
    //optimise: using a Vector2 type array?

    //create object that holds 2 arrays
    //table 
}
//corner1 = X+xOffset Y+yOffset
//corner2 = X+xOffset Y-yOffset
//corner3 = X+xOffset Y+yOffset
//corber4 = X+xOffset Y-yOffset

            




               //floor plane
                DrawPlane(at{ 0.0f, 0.0f, 0.0f }, (Vector2){ 128, 128.0f }, GetColor((unsigned int)0x00332280)); // Draw ground
                //DrawPlane(at{ 0.0f, 50.0f, 0.0f }, (Vector2){ 128, 128.0f }, GetColor((unsigned int)0x00332280)); // Draw ground
                
                //floor grid
                DrawGrid(200, 5.0f);  
                //DrawGrid(200, 2.0f);  
                
                //???
                t+=1;
    //Ladder2heaven
    int ladder_height = 1000;
    for(float i = 0.01f; i<ladder_height; i+=1)
    {DrawPoint3D(at{0.1f, i/25, 0.1f}, BLACK);}
    //
    //colorful lines start
   if (to_point.y<4.0){to_point.y=4.0;}
   
   if (from_point.y<4.0){from_point.y=4.0;}
    float length = 3;
    float p1x; float p1z;
    float p2x; float p2z;
    float p3x; float p3z;
    float p4x; float p4z;
    int gap = 1;
 //end
    
//draw a square in the sky
int xmod=0; int ymod=0; int zmod=0;
Vector3 vec1 = at{0.0f, 50.0f, 0.0f};


//capture recent key press to 'keycool'
 for (int i=0; i<500; i+=1)
{
    if(IsKeyPressed(i)){latest_key=i;}
}    
 
 //when pressing:
 //two
 //jump the 2nd point of the given line to your target position
 
 int spdF = 1;
 
 if (GetMouseWheelMove()){look_distance+=(GetMouseWheelMove());}
 if KEY(2)
    {

 //end_pos=tc;
    from_point.x += ((px+ANG_X*-look_distance)-from_point.x)/2*spdF;
    from_point.y += ((py+ANG_Y*-look_distance)-from_point.y)/2*spdF;
    from_point.z += ((pz+ANG_Z*-look_distance)-from_point.z)/2*spdF;
    wires_(0.05f*-look_distance, from_point);
    }
 if KEY(1)      
    {
    //tempX+=(tx-tempX)/4; tempY=ty; tempZ=tz
    to_point.x += ((px+ANG_X*-look_distance)-to_point.x)/2*spdF;
    to_point.y += ((py+ANG_Y*-look_distance)-to_point.y)/2*spdF;
    to_point.z += ((pz+ANG_Z*-look_distance)-to_point.z)/2*spdF;
    
//to_point = tc;
   
    //to_point.x+=(from_point.x-to_point.x)/2;
    //to_point.y+=(from_point.y-to_point.y)/2;
    //to_point.z+=(from_point.z-to_point.z)/2;
    
    wires_(0.05f*-look_distance, to_point);
    }    
    
    float numT = 25.0f;
    //freeze line
SHOW(to_point); //t_=((t_)%(100))-50;
SHOW(from_point);

Vector3 to_floor = to_point;
to_floor.y=to_point.y/2;
SHOW(to_floor);
to_floor.y=0;
SHOW(to_floor);

Vector3 from_floor = from_point;
from_floor.y=from_point.y/2;
SHOW(from_floor);
from_floor.y=0;
SHOW(from_floor);


//if (arbitrary==5)
//{
//    box[0] = this_var_does_not_exist;
//}

   
   //extra
 //DrawLine3D(to_point,from_point,PURPLE);
 Vector3 crosspoint = (Vector3){(from_point.x+to_point.x)/2,(from_point.y+to_point.y)/2,(from_point.z+to_point.z)/2};
 crosspoint.y+=5;
 crosspoint.x-=1.5;
 
 
 DrawCube(at{0.0f,280.0f,0.05f}, 111,2 ,111, BLUE);
 DrawCubeWires(at{0.0f,280.0f,0.05f}, 111,2 ,111, BLACK);
 DrawCube(at{0.0f,275.0f,0.05f}, 110,2 ,85, WHITE); 
 DrawCube(at{0.0f,270.0f,0.05f}, 110,2 ,55, WHITE);
  
//HUH??????? TRY THIS
//DrawModel(z55, at{0.0f,255.0f,0.0f}, -300.0f, WHITE);
 //i think its the square of the fl sky overlapping or smthn
 
 
DrawModel(z55, camera.position, -10.0f, WHITE);
 
 
 crosspoint.z-=1.5;

Vector3 tp2 = at{5,5,5};
Vector3 fp2 = at{0,0,0};
 DrawLine3D(fp2,tp2 , GREEN);
 DrawLine3D(tp2 ,fp2,PURPLE);

 DrawLine3D(crosspoint,to_point , GREEN);
 DrawLine3D(crosspoint,from_point,PURPLE);
 DrawLine3D(to_point,from_point,WHITE);   
    //selection of objects
 if (collision.hit)
         {
         //selected draw____
         //DrawCube(cubePosition, cubeSize.x, cubeSize.y, cubeSize.z,
         //inner highlight
              DrawCylinderWiresEx(to_point, from_point, 2.0f,2.0f, 4, MAROON); // Draw a cylinder wires with base at startPos and 
         }
                else
                {
                //non-selected draw____
                }

//my insert
int draw_how_many_pillars = 3;

//devcode
for (int i = 0; i < MAX_COLUMNS-(MAX_COLUMNS-draw_how_many_pillars); i++)
{
DrawCube(positions[i], 2.0f, heights[i], 2.0f, colors[i]);
DrawCubeWires(positions[i], 2.0f, heights[i], 2.0f, WHITE);
}






//Draw some shapes/structures

int times = 25;
for(int i=0; i<times; i+=1){
//obelisks
DrawCubeWires(at{-40+(i*50),25,-20}, 5.0f, 50, 10.0f, BEIGE      );


int rate=2;


if ((i)%(rate+2)==1)
{DrawCube(at{5,-22,10},2, 20, 2.0f, BLUE);
//COOL!!! DO NOT DELETE
//if ((i)%(rate+2)==1)
//{DrawCube(at{-(rate*(times/2))+(i*rate),5*((i)%(45)),10},2, 55, 2.0f, BLUE);
        }   
    }

//3D draw end    
EndMode3D();

//HUD

int recSize = 12;

//crosshair
const int rw = 1920/2;
const int rh = 1080/2;
//
DrawRectangleLines(rw-recSize, rh-recSize, recSize*2, recSize*2, WHITE);
//
recSize = 9; 
DrawRectangleLines(rw-recSize, rh-recSize, recSize*2, recSize*2, WHITE);
//
recSize = 10; 
DrawRectangleLines(rw-recSize, rh-recSize, recSize*2, recSize*2, BLACK);
//

//


//#ifdef debug

//#if 1

//#if debug == 1
#ifdef debug
DrawTexture(texture_myimg, 0,0, WHITE);
#endif

//    
//

//text
//v123 contains an address
//*v123 contains the value that address owns


if KEY(7){
//*v123 = 6;
//int fff123 = (&(v123));

//&myptr

float txt_n=0; 
hud_txt("- Position: (%1.0f, %1.0f, %1.0f)",    txt_n, camera.position.y, camera.position.z);
hud_txt("- Target: (%1.0f, %1.0f, %1.0f)",      txt_n, camera.target.y, camera.target.z);
//hud_txt("(%f, *%1.0f*, *%f*)",txt_n, *myptr, (latest_key));
//this isnt step???
//*myptr += 5;
DrawFPS(100,100); }//else{MemFree(v123);}

if KEY(8){

//free(myptr);
//###
//this will reallocate to NEW malloc obviously so free is necessary
//myptr = (int*)malloc(sizeof(box));

//*myptr = 5555;
//*myptr = 5;
//py = py +2;
}
        
        
if KEY(9){
//MemFree(myptr);
py = py -2;}


//hud_txt("- yeah: (%1.0f, %1.0f, %1.0f)",        txt_n, collision.hit, camera.target.z);
//hud_txt("aight",                                txt_n, 0.0f, 0.0f);
                 /////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
//////////////////////////////////////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////            
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
/////////////////////////////////
//EVENT: EXIT
        EndDrawing();
        //----------------------------------------------------------------------------------
    }//END OF PROGRAM
    //=========================================================

    // De-Initialization
    //sound(snd); 
    //UnloadSound(fxWav);     // Unload sound data
    //UnloadSound(fxOgg);     // Unload sound data

    CloseAudioDevice();     // Close audio device
    
     //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}