/*
 *		This Code Was Created By Jeff Molofee 2000
 *		A HUGE Thanks To Fredric Echols For Cleaning Up
 *		And Optimizing This Code, Making It More Flexible!
 *		If You've Found This Code Useful, Please Let Me Know.
 *		Visit My Site At nehe.gamedev.net
*/

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include "Camera.h"
#include "texture.h"
#include "Model_3DS.h"
#include <ctime>
#include "GLTexture.h"
#include<stdio.h>
#include<mmsystem.h>

HDC			hDC=NULL;		// Private GDI Device Context
HGLRC		hRC=NULL;		// Permanent Rendering Context
HWND		hWnd=NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active=TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen=TRUE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

struct Point
{
	float x , y , z ;  
	Point (float x , float y , float z)
	{
		this->x = x ; 
		
		this->y = y ; 
		
		this->z = z ; 

	}
} ;

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height==0)										// Prevent A Divide By Zero By
	{
		height=1;										// Making Height Equal One
	}

	glViewport(0,0,width,height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,20000000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


int tablem, refregiter, oven, moket, moket1, moket2,stales,black,ame1,ame2 ,ame3,ame6,refregeter,sss,wisher, wall2,iii,oven1,mi;

int ch_red, ch_wood ,  wall, carpet , white , door , fulldoor , trainwall , traintopwall , wheel , traintop ,  bookLocker1,bookLocker2 , Wood1 , Wood2 , faceChair ; 

int chair_livery , chair_livery2 , wallclock , tv ; 
	
Camera First_Person_Shooter ; 


int back, front, left, right,top,Down , control;
int bulding_tex1,bulding_tex2,bulding_tex3,buldingUpSide_tex,buldingUpSide_tex2;
int front3,Back,back3,top3,top2,Down3;
int image,road,sky2;
int Rails;

//Sky Box
Model_3DS *tree;
Model_3DS * tower;
Model_3DS * station;

//Restorant
Model_3DS * table;
Model_3DS * table_glass;
Model_3DS * indoorPlanet;
Model_3DS * eatingTable;
Model_3DS * frameBurger;
Model_3DS * lamp;

//Bedroom
Model_3DS * bed;
Model_3DS * night_stand;
Model_3DS * bedtable;
Model_3DS * TV;




void loadmodel() 
{
	//3D Models
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//sky box chair (Bench)
	//Station
	station=new Model_3DS();
	station->Load("Models/station1.3DS");
	GLTexture station_tex,station_tex1;
	station_tex.LoadBMP("image/platform.bmp");
	station_tex1.LoadBMP("image/stationWall.bmp");
	for(int i=0;i<10;i++)
	station->Materials[i].tex=station_tex;
	for(int i=10;i<13;i++)
	station->Materials[i].tex=station_tex1;
	
	//Tower
	tower=new Model_3DS();
	tower->Load("Models/wooden watch tower2.3DS");
	GLTexture tower_tex1,tower_tex2;
	tower_tex1.LoadBMP("image/tower1.bmp");
	tower_tex2.LoadBMP("image/tower2.bmp");
	tower->Materials[0].tex=tower_tex1;
	tower->Materials[1].tex=tower_tex2;
	//tree
	tree=new Model_3DS();
	tree->Load("Models/Tree1.3ds");
	GLTexture tree1tex,leaf1,leaf2;
	tree1tex.LoadBMP("image/bark_loo.bmp");
	leaf1.LoadBMP("image/Leaf.bmp");
	leaf2.LoadBMP("image/blatt1_a.bmp");
	tree->Materials[0].tex=tree1tex;
	tree->Materials[1].tex=tree1tex;
	for (int i = 2;i < 5;i++)
	tree->Materials[i].tex=leaf1;
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	//Tree
	tree=new Model_3DS();
	tree->Load("Models//M_TREE5.3ds");
	GLTexture treetex,leaf;
	treetex.LoadBMP("Models//BARK.bmp");
	leaf.LoadBMP("Models//Leaf.bmp");
	tree->Materials[0].tex=treetex;
	tree->Materials[1].tex=leaf;
	//table
	table = new Model_3DS();
	table->Load("Models//Table.3DS");
	GLTexture tabletex;
	tabletex.LoadBMP("Models//wood1.bmp");
	table->Materials[0].tex=tabletex;
	
	//table_glass
	table_glass = new Model_3DS();
	table_glass->Load("Models//Wood_Table.3DS");
	GLTexture table_glasstex1,table_glasstex2,table_glasstex3,table_glasstex4;
	table_glasstex1.LoadBMP("Models//tabletex//Wood_Table_C.bmp");
	table_glasstex2.LoadBMP("Models//tabletex//Wood_Table_C_2.bmp");
	table_glasstex3.LoadBMP("Models//tabletex//Wood_Table_N.bmp");
	table_glasstex4.LoadBMP("Models//tabletex//Reflexion.bmp");
	table_glass->Materials[0].tex=table_glasstex1;
	table_glass->Materials[1].tex=table_glasstex2;
	table_glass->Materials[2].tex=table_glasstex3;
	table_glass->Materials[3].tex=table_glasstex4;
	
	//indoorPlanet
	indoorPlanet = new Model_3DS();
	indoorPlanet->Load("Models//indoor plant_02.3DS");
	GLTexture indoorPlanetwood,indoorPlanetleaf;
	indoorPlanetwood.LoadBMP("Models//BARK.bmp");
	indoorPlanetleaf.LoadBMP("Models//Leaf.bmp");
	for(int i=0;i<2;i++)
	indoorPlanet->Materials[i].tex=indoorPlanetwood;
	for(int i=2;i<5;i++)
	indoorPlanet->Materials[i].tex=indoorPlanetleaf;
	
	//eating Table
	eatingTable = new Model_3DS();
	eatingTable->Load("Models//Outdoor Furniture_02_3ds.3DS");
	GLTexture eattabletex;
	eattabletex.LoadBMP("Models//wood1.bmp");
	eatingTable->Materials[0].tex=eattabletex;
	
	
	//frameBurger
	frameBurger = new Model_3DS();
	frameBurger->Load("Models//3d-frame.3DS");
	GLTexture frameBurgertex,frameBurgertex1;
	frameBurgertex.LoadBMP("Models//BARK.bmp");
	frameBurgertex1.LoadBMP("Models//burger.bmp");
	frameBurger->Materials[0].tex=frameBurgertex;
	frameBurger->Materials[1].tex=frameBurgertex1;
	frameBurger->Materials[2].tex=frameBurgertex1;
	
	
	
	//lamp
	lamp = new Model_3DS();
	lamp->Load("Models//secto_design_octo_lamp_190sm.3DS");
	GLTexture lamptex1,lamptex2,lamptex3;
	lamptex1.LoadBMP("Models//wood1.bmp");
	lamptex2.LoadBMP("Models//scratched-steel-texture-3.bmp");
	lamptex3.LoadBMP("Models//banana.bmp");
	lamp->Materials[0].tex=lamptex1;
	lamp->Materials[1].tex=lamptex2;
	lamp->Materials[2].tex=lamptex3;
	
	
	//Bed

	bed = new Model_3DS();
	bed->Load("Models//uploads_files_1017667_black_bed.3DS");
	GLTexture bedtex1,bedtex2,bedtex3,bedtex4;
	bedtex1.LoadBMP("Models//Red.bmp");
	bedtex2.LoadBMP("Models//jens.bmp");
	bedtex3.LoadBMP("Models//dcmap1.bmp");
	bedtex4.LoadBMP("Models//black.bmp");
	bed->Materials[0].tex=bedtex1;
	bed->Materials[1].tex=bedtex2;
	bed->Materials[2].tex=bedtex3;
	bed->Materials[3].tex=bedtex4;
	
	
	//night_stand
	night_stand = new Model_3DS();
	night_stand->Load("Models//Nightstand.3DS");
	GLTexture night_standtex;
	night_standtex.LoadBMP("Models//Wood1_Albedo.bmp");
	night_stand->Materials[0].tex=night_standtex;
	
	//bedtable
	bedtable = new Model_3DS();
	bedtable->Load("Models//AT_Sideboard_01.3DS");
	GLTexture bedtabletex,bedtabletex1;
	bedtabletex.LoadBMP("Models//wood1.bmp");
	bedtabletex1.LoadBMP("Models//blackwood1.bmp");
	bedtable->Materials[0].tex=bedtabletex;
	bedtable->Materials[1].tex=bedtabletex1;
	
	//TV
	TV = new Model_3DS();
	TV->Load("Models//uploads_files_1935814_Smart+TV.3DS");
	GLTexture TVtex1,TVtex2,TVtex3;
	TVtex1.LoadBMP("Models//Levi.bmp");
	TVtex2.LoadBMP("Models//blackwood.bmp");
	TVtex3.LoadBMP("Models//egg.bmp");
	TV->Materials[0].tex=TVtex1;
	TV->Materials[1].tex=TVtex2;
	TV->Materials[2].tex=TVtex3;
}

int hwalls,hdoor, hground, hroof, hgrass, hwindow, hpip, hwelcome;
	
int frontlucker , rightlucker ;
void loadimage() 
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glEnable(GL_TEXTURE_2D);
	back = LoadTexture("image/back.bmp",255);
	glEnable(GL_TEXTURE_2D);
	front = LoadTexture("image/front.bmp",255);
	glEnable(GL_TEXTURE_2D);
	left = LoadTexture("image/left.bmp",255);
	glEnable(GL_TEXTURE_2D);
	right = LoadTexture("image/right.bmp",255);
	glEnable(GL_TEXTURE_2D);
	top = LoadTexture("image/top.bmp",255);
	glEnable(GL_TEXTURE_2D);
	Down=LoadTexture("image/Down.bmp",255);
	/////////////////////////////////////////////////
	back3 = LoadTexture("image/Back3.bmp",255);
	front3 = LoadTexture("image/Front3.bmp",255);
	top3 = LoadTexture("image/Bottom3.bmp",255);
	Down3=LoadTexture("image/Down3.bmp",255);
	frontlucker = LoadTexture("image/frontlucker.bmp") ;
	rightlucker = LoadTexture("image/blacklucker.bmp") ; 

	//////////////////////////////////////////////////	
	image=LoadTexture("image/image.bmp",255);
	road=LoadTexture("image/road.bmp",255);
	sky2=LoadTexture("image/sky2.bmp",255);
	Rails=LoadTexture("image/Rails.bmp",255);
	//////////////////////////////////////////////////	
	bulding_tex1 = LoadTexture("image/building 1.bmp",255);
	bulding_tex2 = LoadTexture("image/building 2.bmp",255);
	bulding_tex3 = LoadTexture("image/building 3.bmp",255);
	buldingUpSide_tex = LoadTexture("image/roof.bmp",255);
	buldingUpSide_tex2 = LoadTexture("image/roof2.bmp",255);
	//texture
	glEnable(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	iii = LoadTexture("image/iii.bmp", 255);
	oven1 = LoadTexture("image/oven.bmp", 255);
	carpet = LoadTexture("image/carpet.bmp", 255);
	wall = LoadTexture("image/wall.bmp", 255);
	white = LoadTexture("image/white.bmp", 255);
	fulldoor = LoadTexture("image/FullDoor.bmp", 255);
	door = LoadTexture("image/Door.bmp", 255);
	trainwall = LoadTexture("image/TrainWall2.bmp", 255);
	traintopwall = LoadTexture("image/TrainTopWall.bmp", 255);
	wheel = LoadTexture("image/Wheel.bmp", 255);
	tablem = LoadTexture("table.bmp", 255);

	moket = LoadTexture("image/moket.bmp", 255);
	refregiter = LoadTexture("image/kitchen.bmp", 255);
	moket1 = LoadTexture("image/moket1.bmp", 255);
	moket2 = LoadTexture("image/moket2.bmp", 255);
	stales = LoadTexture("image/stales.bmp", 255);
	black = LoadTexture("image/black.bmp", 255);
	ame1 = LoadTexture("image/ame.bmp", 255);
	ame2 = LoadTexture("image/ame5.bmp", 255);
	ame3 = LoadTexture("image/ame2.bmp", 255);
	ame6 = LoadTexture("image/ame6.bmp", 255);
	refregeter = LoadTexture("image/side.bmp", 255);
	sss = LoadTexture("image/sss.bmp", 255);
	wisher = LoadTexture("image/aa.bmp", 255);
	wall2 = LoadTexture("image/wall.bmp", 255);
	mi= LoadTexture("image/mi.bmp", 255);
	
	
	carpet = LoadTexture( "image/carpet.bmp" , 255 );  
	wall = LoadTexture("image/wall.bmp" , 255) ; 
	traintop = LoadTexture("image/traintop.bmp") ;  
	white  = LoadTexture("image/white.bmp" , 255 ) ; 
	fulldoor = LoadTexture("image/FullDoor.bmp",255) ; 	
	door = LoadTexture("image/Door.bmp" , 255 ) ; 
	trainwall = LoadTexture("image/TrainWall2.bmp",255); 
	traintopwall = LoadTexture("image/TrainTopWall.bmp", 255) ; 
	wheel = LoadTexture("image/Wheel.bmp", 255) ;
	bookLocker1=LoadTexture("image/book locker.bmp",255);
	bookLocker2=LoadTexture("image/book Locker2.bmp",255);
	Wood1=LoadTexture("image/Wood.bmp",255);
	Wood2=LoadTexture("image/Wood2.bmp",255);
	faceChair=LoadTexture("image/face.bmp",255);
	control = LoadTexture("image/Control.bmp") ; 
	
	//chair Texute
	ch_red = LoadTexture("Models/red.bmp");
	ch_wood = LoadTexture("Models/brown.bmp");
	

	//Passenger 
	chair_livery=LoadTexture("image/chair livery.bmp", 255) ;
	chair_livery2=LoadTexture("image/chair livery2.bmp", 255) ;
	tv=LoadTexture("image/tv2.bmp", 255) ;
	wallclock=LoadTexture("image/wallclock4.bmp", 255) ;
	
	//House
	hdoor = LoadTexture("image/Crate.bmp",255);
	hwalls = LoadTexture("image/rasif.bmp",255);
	hground = LoadTexture("image/ground.bmp",255);
	hroof = LoadTexture("image/roof2.bmp",255);
	hgrass = LoadTexture("image/Green.bmp",255);
	hwindow = LoadTexture("image/R.bmp",180);
	hpip = LoadTexture("image/platform.bmp",255);
	hwelcome = LoadTexture("image/R (1).bmp",255);

}

Point FTR_First_Carriage = Point ( -1850 ,-70 ,-25) ;
 

bool Third_Person_Shooter = true ;
bool Third_Person_Shooter2 = false ;
bool First_Person = false ; 
bool Doors_Open = false ;

bool Light= false ;
void CameraKeyboardControl(float Train_Points_Collision[])
{
	if(keys['L'])
	{
		Light=true;
	}
	if(keys['K'])
	{
		Light=false;
		glDisable(GL_LIGHTING);
	}
	if(keys['C'])
	{
		
		if(Third_Person_Shooter2)
		{
			First_Person = true ; 
			Third_Person_Shooter2 = false ; 
		}
		else if (Third_Person_Shooter)
		{
				Third_Person_Shooter = false ;
				First_Person = true ;
		}else 
		{
				Third_Person_Shooter = true ;
				First_Person = false;
		}

	}

	if(keys['P'])
	{
		Third_Person_Shooter2 = true ;
		Third_Person_Shooter = false ; 
		First_Person = false ; 
	}

	if(Third_Person_Shooter) 
	{
			gluLookAt(FTR_First_Carriage.x - 65 ,  FTR_First_Carriage.y + 7 , FTR_First_Carriage.z - 6 , 
				FTR_First_Carriage.x  , FTR_First_Carriage.y , FTR_First_Carriage.z - 5 , 
			0 , 1 , 0);
	}
	if(Third_Person_Shooter2)
	{
				gluLookAt(FTR_First_Carriage.x - 65 ,  FTR_First_Carriage.y + 7 , FTR_First_Carriage.z - 40 , 
				FTR_First_Carriage.x + 25 , FTR_First_Carriage.y , FTR_First_Carriage.z - 5 , 
				0 , 1 , 0);
	
	}
	if (First_Person ) 
	{
			
		bool CanUp = true ;
		bool CanDown = true  ;
		bool CanRight = true ;
		bool CanLeft = true ;
			
		

		 
		for (int i = 0; i < 20; i++)
		{
			
			if(! Doors_Open)
			{
				if( First_Person_Shooter.Position.x >= (Train_Points_Collision[i] - 1.5 )&& First_Person_Shooter.Position.x <= (Train_Points_Collision[i] - 0.5)  ) 
						First_Person_Shooter.Position.x -= 1 ; 
			}else
				if( First_Person_Shooter.Position.x >= (Train_Points_Collision[i] - 1.5 )&& First_Person_Shooter.Position.x <= (Train_Points_Collision[i] - 0.5) && !( First_Person_Shooter.Position.z <= ( -29 ) &&  First_Person_Shooter.Position.z >= ( -33 ) ) )
						First_Person_Shooter.Position.x -= 1 ;
		
					
			if(! Doors_Open)
			{
				if( First_Person_Shooter.Position.x <= (Train_Points_Collision[i] + 1) && First_Person_Shooter.Position.x >= (Train_Points_Collision[i] - 0.5) ) 
						First_Person_Shooter.Position.x += 1 ;	  
			}else
				if( First_Person_Shooter.Position.x <= (Train_Points_Collision[i] + 1) && First_Person_Shooter.Position.x >= (Train_Points_Collision[i] - 0.5) && !( First_Person_Shooter.Position.z <= ( -29 ) &&  First_Person_Shooter.Position.z >= ( -33 ) )) 
						First_Person_Shooter.Position.x += 1 ;
		
			if(i%2 != 0) 
			{
				if(First_Person_Shooter.Position.x >= (Train_Points_Collision[i]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[i+1]))
				{
					if(First_Person_Shooter.Position.z > -30  )
						First_Person_Shooter.Position.z -= 0.6 ; 
					
					if(First_Person_Shooter.Position.z < -33  )
						First_Person_Shooter.Position.z += 0.6 ;
				}
			}
		}	
			
		
		//Carriage1 Library Collision 
		if(First_Person_Shooter.Position.x <= (Train_Points_Collision[1]))
		{

				if(First_Person_Shooter.Position.z > -28.5  )
					First_Person_Shooter.Position.z -= 0.6 ; 
				
				

				if(First_Person_Shooter.Position.z < -38 &&  First_Person_Shooter.Position.x <  ( Train_Points_Collision[1] - 15 ) &&  First_Person_Shooter.Position.x >  ( Train_Points_Collision[1] - 20 ) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
				else if(First_Person_Shooter.Position.z < -34 && ( First_Person_Shooter.Position.x >  ( Train_Points_Collision[1] - 15 ) ||  First_Person_Shooter.Position.x <  ( Train_Points_Collision[1] - 20 )))
						First_Person_Shooter.Position.z +=0.6 ; 
		}

		if(First_Person_Shooter.Position.x <= (Train_Points_Collision[17]) && First_Person_Shooter.Position.x >= (Train_Points_Collision[16]))
		{

				if(First_Person_Shooter.Position.z > -28.5  )
					First_Person_Shooter.Position.z -= 0.6 ; 
				
				

				if(First_Person_Shooter.Position.z < -38 &&  First_Person_Shooter.Position.x <  ( Train_Points_Collision[17] - 15 ) &&  First_Person_Shooter.Position.x >  ( Train_Points_Collision[17] - 20 ) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
				else if(First_Person_Shooter.Position.z < -34 && ( First_Person_Shooter.Position.x >  ( Train_Points_Collision[17] - 15 ) ||  First_Person_Shooter.Position.x <  ( Train_Points_Collision[17] - 20 )))
						First_Person_Shooter.Position.z +=0.6 ; 
		}
		

		//BedRoom1 Collision
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[4]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[5]) )
		{

				if(First_Person_Shooter.Position.z > -25  &&  First_Person_Shooter.Position.x > (Train_Points_Collision[5]-11) )
					First_Person_Shooter.Position.z -= 0.6 ; 
				else if(First_Person_Shooter.Position.z > -28.5 &&  First_Person_Shooter.Position.x < (Train_Points_Collision[5]-11) )
						First_Person_Shooter.Position.z -= 0.6 ; 

				
				if(First_Person_Shooter.Position.z < -35 &&  (First_Person_Shooter.Position.x <  ( Train_Points_Collision[4] + 10 ) ||  ( First_Person_Shooter.Position.x >  ( Train_Points_Collision[4] + 15 ) && First_Person_Shooter.Position.x <  ( Train_Points_Collision[4] + 20 ) ) ) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
				else if(First_Person_Shooter.Position.z < -32 &&  (/*2*/ (/*1*/First_Person_Shooter.Position.x >(Train_Points_Collision[4] + 10) &&  First_Person_Shooter.Position.x <  (Train_Points_Collision[4] + 15) /*1*/) || (/*1*/ First_Person_Shooter.Position.x >  ( Train_Points_Collision[4] + 21.5 ) && First_Person_Shooter.Position.x <  ( Train_Points_Collision[5]  )/*1*/) /*2*/) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
		}

		//BedRoom 2 Collision
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[14]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[15]) )
		{

				if(First_Person_Shooter.Position.z > -25  &&  First_Person_Shooter.Position.x > (Train_Points_Collision[15]-11) )
					First_Person_Shooter.Position.z -= 0.6 ; 
				else if(First_Person_Shooter.Position.z > -28.5 &&  First_Person_Shooter.Position.x < (Train_Points_Collision[15]-11) )
						First_Person_Shooter.Position.z -= 0.6 ; 

				
				if(First_Person_Shooter.Position.z < -35 &&  (First_Person_Shooter.Position.x <  ( Train_Points_Collision[14] + 10 ) ||  ( First_Person_Shooter.Position.x >  ( Train_Points_Collision[14] + 15 ) && First_Person_Shooter.Position.x <  ( Train_Points_Collision[14] + 20 ) ) ) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
				else if(First_Person_Shooter.Position.z < -32 &&  (/*2*/ (/*1*/First_Person_Shooter.Position.x >(Train_Points_Collision[14] + 10) &&  First_Person_Shooter.Position.x <  (Train_Points_Collision[14] + 15) /*1*/) || (/*1*/ First_Person_Shooter.Position.x >  ( Train_Points_Collision[14] + 21.5 ) && First_Person_Shooter.Position.x <  ( Train_Points_Collision[15]  )/*1*/) /*2*/) )
					First_Person_Shooter.Position.z +=0.6 ; 
				
		}


		//Resturant 
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[8]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[9] -5) )
		{
				if(First_Person_Shooter.Position.z > -25  &&  First_Person_Shooter.Position.x >  ( Train_Points_Collision[8] + 3 ) &&  First_Person_Shooter.Position.x <  ( Train_Points_Collision[8] + 10 ) )
					First_Person_Shooter.Position.z -= 0.6 ; 
				
				if(First_Person_Shooter.Position.z > -30  && ( First_Person_Shooter.Position.x <  ( Train_Points_Collision[8]+3 ) ||  First_Person_Shooter.Position.x >  ( Train_Points_Collision[8] +7 )))
					First_Person_Shooter.Position.z -= 0.6 ;
				
				if(First_Person_Shooter.Position.z < -33 ) 
					First_Person_Shooter.Position.z +=0.6 ;
		}
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[9] -5) && First_Person_Shooter.Position.x <= (Train_Points_Collision[9]) )
		{
			if(First_Person_Shooter.Position.z > -25  )
				First_Person_Shooter.Position.z -= 0.6 ; 
			
			if(First_Person_Shooter.Position.z < -38)
				First_Person_Shooter.Position.z +=0.6 ;

		}
	
		//Resturant 2
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[12]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[13] -5) )
		{
				if(First_Person_Shooter.Position.z > -25  &&  First_Person_Shooter.Position.x >  ( Train_Points_Collision[12] + 3 ) &&  First_Person_Shooter.Position.x <  ( Train_Points_Collision[12] + 10 ) )
					First_Person_Shooter.Position.z -= 0.6 ; 
				
				if(First_Person_Shooter.Position.z > -30  && ( First_Person_Shooter.Position.x <  ( Train_Points_Collision[12]+3 ) ||  First_Person_Shooter.Position.x >  ( Train_Points_Collision[12] +7 )))
					First_Person_Shooter.Position.z -= 0.6 ;
				
				if(First_Person_Shooter.Position.z < -33 ) 
					First_Person_Shooter.Position.z +=0.6 ;
		}
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[13] -5) && First_Person_Shooter.Position.x <= (Train_Points_Collision[13]) )
		{
			if(First_Person_Shooter.Position.z > -25  )
				First_Person_Shooter.Position.z -= 0.6 ; 
			
			if(First_Person_Shooter.Position.z < -38)
				First_Person_Shooter.Position.z +=0.6 ;

		}
		
		//Kitchen
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[6]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[6] +7) )
		{
			if(First_Person_Shooter.Position.z < -37.5)
				First_Person_Shooter.Position.z +=0.6 ;

			if (First_Person_Shooter.Position.z > -25 && First_Person_Shooter.Position.x <= (Train_Points_Collision[6] +4))
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}
			else if (	First_Person_Shooter.Position.z > -29 &&  First_Person_Shooter.Position.x >= (Train_Points_Collision[6] +4) ) 
				First_Person_Shooter.Position.z -= 0.6 ;

		}
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[6] + 7) && First_Person_Shooter.Position.x <= (Train_Points_Collision[6] +11) )
		{
			if(First_Person_Shooter.Position.z < -33.5)
				First_Person_Shooter.Position.z +=0.6 ;
				
			if (First_Person_Shooter.Position.z > -29 )
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}

		}
		
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[6] + 11) && First_Person_Shooter.Position.x <= (Train_Points_Collision[6] +19) )
		{
			if(First_Person_Shooter.Position.z < -29.5)
				First_Person_Shooter.Position.z +=0.6 ;
				
		}
		
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[6] + 19.1) && First_Person_Shooter.Position.x <= (Train_Points_Collision[7]) )
		{
			if(First_Person_Shooter.Position.z < -33.5)
				First_Person_Shooter.Position.z +=0.6 ;
				
			if (First_Person_Shooter.Position.z > -29 )
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}

		}

		//Pessanger Carriage
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[2]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[3]) )
		{
			if(First_Person_Shooter.Position.z < -33)
				First_Person_Shooter.Position.z +=0.6 ;
				
			if (First_Person_Shooter.Position.z > -30.5 )
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}
		}
		
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[10]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[11]) )
		{
			if(First_Person_Shooter.Position.z < -33)
				First_Person_Shooter.Position.z +=0.6 ;
				
			if (First_Person_Shooter.Position.z > -30.5 )
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}
		}
		if(First_Person_Shooter.Position.x >= (Train_Points_Collision[18]) && First_Person_Shooter.Position.x <= (Train_Points_Collision[19]) )
		{
			
			if(First_Person_Shooter.Position.z < -37.5)
				First_Person_Shooter.Position.z +=0.6 ;
				
			if (First_Person_Shooter.Position.z > -25 )
			{
				First_Person_Shooter.Position.z -= 0.6 ;
			}	
				
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (keys['D'] ) First_Person_Shooter.RotateY(-5);
	
		if (keys['A']) First_Person_Shooter.RotateY(5) ;
	
		if (keys[VK_DOWN] && CanDown)
		{
			First_Person_Shooter.MoveForward(-0.4);
		}
		if (keys[VK_UP]&&CanUp) 
		{
			First_Person_Shooter.MoveForward(0.4) ;
		}
		if (keys[VK_RIGHT]&&CanRight  )
		{
			First_Person_Shooter.MoveRight(0.4) ;;
		}
		if(keys[VK_LEFT]&& CanLeft)
		{
			First_Person_Shooter.MoveRight(-0.4) ;
		}
		
		First_Person_Shooter.Render() ; 
	
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Skybox1()
  {
    glScaled(260,60,80);
	glBindTexture(GL_TEXTURE_2D,front);   
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glEnd();
	//Bottom*/

	//*---------------------Back-----------------------------*
	glBindTexture(GL_TEXTURE_2D,left);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(-1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(0,1);
	glVertex3f(1.5f,1.5f,-3.5f);
	glEnd(); 

	//*---------------------top--------------------------------*
	glBindTexture(GL_TEXTURE_2D,top);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glEnd();
	
	
	//*-------------------------Down--------------------------------*
	glBindTexture(GL_TEXTURE_2D,Down);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,3.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	
	glEnd();

	//*---------------------------Right------------------------------------*
	glBindTexture(GL_TEXTURE_2D,right);
    glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(1.5f,1.5f,3.5f);			
	glTexCoord2d(1,0);				
	glVertex3f(1.5f,-1.5f,3.5f);			
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,-3.5f);			
	glTexCoord2d(0,1);
	glVertex3f(1.5f,1.5f,-3.5f);			
	glEnd();
	//right
	//*------------------rail Road----------------------------*
	glBindTexture(GL_TEXTURE_2D,Rails);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.45f, 0.6f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.45f,0.8f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.45f,0.8f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.45f,0.6f);
	
	glEnd();

	

	//*__________________________________________________________*
	//glBindTexture(GL_TEXTURE_2D,Back);
 //   glBegin(GL_QUADS);
	//glTexCoord2d(0,0);
	//glVertex3f(-1.5f,1.5f,3.5f);
	//glTexCoord2d(1,0);
	//glVertex3f(-1.5f,-1.5f,3.5f);
	//glTexCoord2d(1,1);
	//glVertex3f(-1.5f,-1.5f,-3.5f);
	//glTexCoord2d(0,1);
	//glVertex3f(-1.5f,1.5f,-3.5f);
	//glEnd();
	////left
}

Camera MyCamera ; 
void key()
{
 if (keys['Q'])    		MyCamera.MoveUpward(5);
	if (keys['E'])			MyCamera.MoveUpward(-5);
	if (keys['A'])			MyCamera.RotateY(5);
	if (keys['D'])		    MyCamera.RotateY(-5);
	if (keys['S'])		    MyCamera.RotateX(-5);
	if (keys['W'])		    MyCamera.RotateX(5);
	if (keys[VK_DOWN])        MyCamera.MoveForward(-5);
	if (keys[VK_UP])      MyCamera.MoveForward(5);
	if (keys[VK_LEFT])	    MyCamera.MoveRight(-5);
	if (keys[VK_RIGHT])		MyCamera.MoveRight(5);
	 MyCamera.Render() ; 
}

void Skybox2()
{
	//*-------------------------Front--------------------------*
    glScaled(260,60,80);
	glBindTexture(GL_TEXTURE_2D,front3);           
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glEnd();

	//Bottom*/

	//*-------------------------Back-------------------------------*
	glBindTexture(GL_TEXTURE_2D,front3);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glEnd(); 
	
	//*-----------------------------Top--------------------------------*
	glBindTexture(GL_TEXTURE_2D,top3);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glEnd();
	
	
	//*------------------------------Down-------------------------------------*
	glBindTexture(GL_TEXTURE_2D,Down3);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,3.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	
	glEnd();

	//*------------------rail Road----------------------------*
	glBindTexture(GL_TEXTURE_2D,Rails);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.45f, 0.6f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.45f,0.8f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.45f,0.8f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.45f,0.6f);
	
	glEnd();

	//*______________________________________________________*
	//glBindTexture(GL_TEXTURE_2D,Right);
 //   glBegin(GL_QUADS);
	//glTexCoord2d(1,1);
	//glVertex3f(1.5f,1.5f,3.5f);
	//glTexCoord2d(1,0);
	//glVertex3f(1.5f,-1.5f,3.5f);
	//glTexCoord2d(0,0);
	//glVertex3f(1.5f,-1.5f,-3.5f);
	//glTexCoord2d(0,1);
	//glVertex3f(1.5f,1.5f,-3.5f);
	//glEnd();
	////right
	//
	////*__________________________________________________________*
	//glBindTexture(GL_TEXTURE_2D,Back);
    //glBegin(GL_QUADS);
	//glTexCoord2d(0,0);
	//glVertex3f(-1.5f,1.5f,3.5f);
	//glTexCoord2d(1,0);
	//glVertex3f(-1.5f,-1.5f,3.5f);
	//glTexCoord2d(1,1);
	//glVertex3f(-1.5f,-1.5f,-3.5f);
	//glTexCoord2d(0,1);
	//glVertex3f(-1.5f,1.5f,-3.5f);
	//glEnd();
	////left
}
void Skybox3()
	 {
		 //*------------------------Front----------------------------------*
     glScaled(260,60,80);
	glBindTexture(GL_TEXTURE_2D,image);           
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glEnd();
	//Bottom*/

	//*-------------------------------Back----------------------------*
	glBindTexture(GL_TEXTURE_2D,image);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glEnd(); 
	//Back

	//*-------------------------Top--------------------------------*
	glBindTexture(GL_TEXTURE_2D,sky2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-3.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,3.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);
	glEnd();
	//top
	
	//*-----------------------Down--------------------------------*
	glBindTexture(GL_TEXTURE_2D,road);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,3.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-3.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,3.5f);
	
	glEnd();

	//Down
	//*------------------rail Road----------------------------*
	glBindTexture(GL_TEXTURE_2D,Rails);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.45f, 0.6f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.45f,0.8f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.45f,0.8f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.45f,0.6f);
	
	glEnd();
//*______________________________________________________*
	//glBindTexture(GL_TEXTURE_2D,Right);
 //   glBegin(GL_QUADS);
	//glTexCoord2d(1,1);
	//glVertex3f(1.5f,1.5f,3.5f);
	//glTexCoord2d(1,0);
	//glVertex3f(1.5f,-1.5f,3.5f);
	//glTexCoord2d(0,0);
	//glVertex3f(1.5f,-1.5f,-3.5f);
	//glTexCoord2d(0,1);
	//glVertex3f(1.5f,1.5f,-3.5f);
	//glEnd();
	////right
	//
	//*--------------------------Left------------------------------*
	glBindTexture(GL_TEXTURE_2D,image);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1.5f,1.5f,3.5f);					
	glTexCoord2d(1,0);
	glVertex3f(-1.5f,-1.5f,3.5f);					
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-3.5f);					
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-3.5f);					
	glEnd();
	//left
} 
void makeBuilding1()
  {
	glRotated(90,1,0,0);
	//Bottom*/
	glBindTexture(GL_TEXTURE_2D,bulding_tex1);   
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();

	//*---------------------top-----------------------------*
	glBindTexture(GL_TEXTURE_2D,buldingUpSide_tex);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd(); 

	//*---------------------front--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex1);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();
	
	
	//*-------------------------back--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex1);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,6.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	
	glEnd();
	//right
	//*---------------------------Right------------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex1);
    glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(1.5f,1.5f,-6.5f);
	glEnd();
	

	//left
	//*__________________________________________________________*
	glBindTexture(GL_TEXTURE_2D,bulding_tex1);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd();
}
void makeBuilding2()
  {
	glRotated(90,1,0,0);
	//Bottom*/
	glBindTexture(GL_TEXTURE_2D,bulding_tex2);   
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();

	//*---------------------top-----------------------------*
	glBindTexture(GL_TEXTURE_2D,buldingUpSide_tex2);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd(); 

	//*---------------------front--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();
	
	
	//*-------------------------back--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex2);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,6.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	
	glEnd();
	//right
	//*---------------------------Right------------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex2);
    glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(1.5f,1.5f,-6.5f);
	glEnd();


	//left
	//*__________________________________________________________*
	glBindTexture(GL_TEXTURE_2D,bulding_tex2);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd();
}
void makeBuilding3()
  {
	glRotated(90,1,0,0);
	//Bottom*/
	glBindTexture(GL_TEXTURE_2D,bulding_tex3);   
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();

	//*---------------------top-----------------------------*
	glBindTexture(GL_TEXTURE_2D,buldingUpSide_tex);
    glBegin(GL_QUADS);
	
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd(); 

	//*---------------------front--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex3);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,6.5f);
	glEnd();
	
	
	//*-------------------------back--------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex3);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,6.5f);
    glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
    glTexCoord2d(0,1);
	glVertex3f(-1.5f,-1.5f,6.5f);
	
	glEnd();
	//right
	//*---------------------------Right------------------------------------*
	glBindTexture(GL_TEXTURE_2D,bulding_tex3);
    glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(1.5f,-1.5f,6.5f);
	glTexCoord2d(0,0);
	glVertex3f(1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(1.5f,1.5f,-6.5f);
	glEnd();
	

	//left
	//*__________________________________________________________*
	glBindTexture(GL_TEXTURE_2D,bulding_tex3);
    glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1.5f,1.5f,6.5f);
	glTexCoord2d(1,0);
	glVertex3f(-1.5f,-1.5f,6.5f);
	glTexCoord2d(1,1);
	glVertex3f(-1.5f,-1.5f,-6.5f);
	glTexCoord2d(0,1);
	glVertex3f(-1.5f,1.5f,-6.5f);
	glEnd();
}
void makeTree(float tree_x,float tree_y,float tree_z,float tree_rotate,float tree_scale){
	tree->pos.x=tree_x;
	tree->pos.y=tree_y;
	tree->pos.z=tree_z;
	tree->rot.y=tree_rotate;
	tree->scale=tree_scale;
	tree->Draw();
}
void makeTower(float tower_x,float tower_y,float tower_z,float tower_rotate,float tower_scale){
	tower->pos.x=tower_x;
	tower->pos.y=tower_y;
	tower->pos.z=tower_z;
	tower->rot.y=tower_rotate;
	tower->scale=tower_scale;
	tower->Draw();
}
void makeStation(float s_x,float s_y,float s_z,float s_rotate,float s_scale){
	station->pos.x=s_x;
	station->pos.y=s_y;
	station->pos.z=s_z;
	station->rot.y=s_rotate;
	station->scale=s_scale;
	station->Draw();
}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void draw_windows(Point FTR , float width , float height , float depth)
{

	//Front windows
	
	glColor4f(0 , 0 , 1 , 0.5);
	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x-width/10, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z);
	
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	
	glVertex3f(FTR.x-width/10, FTR.y-(height/1.4), FTR.z);

	
	glEnd(); 

	//front windows inside 

	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	glVertex3f(FTR.x-width/10, FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z);
	glVertex3f(FTR.x-width/10, FTR.y-height/3, FTR.z);
	
	glEnd(); 

	//Back windows
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z-depth);
	
	glEnd(); 
	
	
	//back windows inside 
	glBegin(GL_QUADS);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);
	
	glEnd(); 
	
}



float Translate_door ; 
float Doors_Depth = 0 ;   
clock_t stime , etime ;
bool Doors_Opening = true ; 
bool Doors_Closing = true ; 
void Carriage(Point FTR, float width , float height , float depth)
{
	if(Light==true)
	{	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	GLfloat LightPos[] = { FTR.x+(width/2), FTR.y, FTR.z+(depth/2), 1.0 };
	GLfloat LightAmb[] = {3.0f,3.0f,3.0f, 3.0f};
	GLfloat LightDiff[] = { 1.0f,1.0f,1.0f,1.0f }; 
	GLfloat LightSpec[] = { 0.2f,0.2f,0.2f,1.0f };

	glLightfv(GL_LIGHT1, GL_POSITION, LightPos);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiff);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpec);
	
	
	}
	//front
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);// عكس
	glTexCoord2d(1.5 , 1) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y, FTR.z); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z); 
	 
	glTexCoord2d( 1.5 , 0) ;
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z);

	
	glEnd() ;
	

	//fornt inside 
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z);
	
	glTexCoord2d(0 , 0  ) ; 
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z); 
	
	glTexCoord2d( 0 , 1  ) ; 
	glVertex3f(FTR.x-width, FTR.y, FTR.z); 
	
	glTexCoord2d(1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	
	glEnd() ;
	
	//front bottom
	glBindTexture(GL_TEXTURE_2D , trainwall) ; 
	glBegin(GL_QUADS); 
	
	glTexCoord2d(1.5 , 1 ); 
	
	glVertex3f(FTR.x  - width/10 , FTR.y-(height/1.4), FTR.z);
	glTexCoord2d(0 , 1 ); 
	
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);

	glTexCoord2d(0 , 0 ); 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);


	glTexCoord2d(1.5 , 0 ); 
	glVertex3f(FTR.x-width/10, FTR.y-height, FTR.z);
	
	glEnd(); 

	//front bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS); 
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x-width/10, FTR.y-height, FTR.z);
	
	glTexCoord2d( 0, 0  ) ; 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);
	
	glTexCoord2d(0, 1  ) ; 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x-width/10, FTR.y-(height/1.4), FTR.z);
	
	
	glEnd(); 

	//left
	
	Point FTL = Point(FTR.x-width, FTR.y, FTR.z) ;   
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(1 , 1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z);
	
	glTexCoord2d(0 , 1 ) ;
	glVertex3f( FTL.x , FTL.y , FTL.z-depth );
	
	glTexCoord2d(0 , 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height/2.5, FTL.z-depth );
	
	glTexCoord2d(1 , 0 ) ;
	glVertex3f( FTL.x, FTL.y-height/2.5, FTR.z );
	
	glEnd();
	
	
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1, 1 ) ;  
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth/3 );
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height, FTL.z-depth/3 );
	
	glTexCoord2d(1, 0 ) ;
	glVertex3f( FTL.x, FTL.y-height, FTR.z );
	
	glEnd();
	
	
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 	
	glBegin(GL_QUADS);
	
	glTexCoord2d(1, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z - depth*2/3);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z - depth);
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height, FTL.z - depth );
	
	glTexCoord2d(1, 0 ) ;
	glVertex3f( FTL.x, FTL.y-height, FTR.z - depth*2/3);
	
	glEnd();
	

	
	
	//left inside Top
	glColor3f(1,1,1) ; 

	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y-height/2.5, FTL.z );
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height/2.5, FTL.z-depth );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z-depth );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z);
	
	glEnd();
	
	//left inside bottom
	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y- height, FTR.z );
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height , FTL.z-depth/3 );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth/3 );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z);
	
	glEnd();
	
	//left inside bottom 
	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y- height, FTR.z -depth*2/3);
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height , FTL.z-depth );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth*2/3);
	
	glEnd();
	
	
	//back
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1.5 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glTexCoord2d(1.5 , 0) ;
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);

	glTexCoord2d(0 ,0 ) ;
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z-depth); 

	glTexCoord2d(0 ,1 ) ;
	glVertex3f(FTR.x-width, FTR.y, FTR.z-depth); 
	
	glEnd() ;
	
	//back bottom
	glBindTexture(GL_TEXTURE_2D ,trainwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1.5 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glTexCoord2d(1.5, 0  ) ;
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 

	
	//back inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f(FTR.x-width, FTR.y, FTR.z-depth); 
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z-depth); 
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
		
	
	glEnd() ;
	
	//back bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	  
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);

	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 
	
	//right 
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1 ,1) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glTexCoord2d(0 , 1) ;
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glTexCoord2d(0 , 0) ;
	glVertex3f(FTR.x, FTR.y-height/2.5 , FTR.z);
	
	glTexCoord2d(1 , 0) ;
	glVertex3f(FTR.x , FTR.y-height/2.5 , FTR.z-depth);	

	glEnd();

	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS) ; 

	glTexCoord2d( 1, 1) ; 	
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth/3);

	glTexCoord2d( 0, 1) ; 
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z);
	
	glTexCoord2d( 0, 0) ; 
	glVertex3f(FTR.x, FTR.y-height , FTR.z);
	
	glTexCoord2d( 1, 0) ; 
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth/3);	


	glEnd(); 

	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS) ; 

	glTexCoord2d( 1, 1) ;
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth);
	
	glTexCoord2d( 0, 1) ;
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth*2/3);
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x, FTR.y-height , FTR.z-depth*2/3);
	
	glTexCoord2d( 1, 0) ;
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth);	


	glEnd(); 

	
	//right inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x , FTR.y-height/2.5 , FTR.z-depth);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x, FTR.y-height/2.5 , FTR.z);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	
	glEnd();

	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);

	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth/3);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x, FTR.y-height , FTR.z);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth/3);
	
	glEnd();


	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x, FTR.y-height , FTR.z-depth*2/3);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth*2/3);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y-height/2.5, FTR.z-depth);
	
	glEnd();

    //top
	glBindTexture(GL_TEXTURE_2D , traintop) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glTexCoord2d( 1 , 0.6) ;
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glTexCoord2d( 0 , 0.6 ) ;
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	
	glTexCoord2d( 0 , 0 ) ;
	glVertex3f(FTR.x-width , FTR.y , FTR.z);

		
	glEnd();
	
	//top inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d(0 ,0);
	glVertex3f(FTR.x-width , FTR.y , FTR.z);
	
	glTexCoord2d(0 , 1);
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	
	glTexCoord2d(1 , 1);
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glTexCoord2d(1,0);
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
		
	glEnd();
	
	//bottom

	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glEnd() ; 

	//bottom inside
	glBindTexture(GL_TEXTURE_2D , carpet ) ; 

	glBegin(GL_QUADS);
	glTexCoord2d(3 ,3 ) ; 
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glTexCoord2d(0 , 3 ) ; 
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);

	glTexCoord2d(0 ,0 ) ; 
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);

		
	glTexCoord2d(3 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	

	glEnd();
	
	
	//Doors
	glDisable(GL_CULL_FACE); 
	

	//Front Door
	glPushMatrix(); 
	
	glBindTexture(GL_TEXTURE_2D , door) ; 
	glColor3f(0.75,0.75,0.83) ; 
	

	glBegin(GL_QUADS);
	
	glTexCoord2d(0 , 1 ) ; 
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-0.01);
	
	glTexCoord2d( 1 , 1 ) ; 
	glVertex3f(FTR.x-width/10, FTR.y-height/3, FTR.z -0.01); 
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x - width/10 , FTR.y-height, FTR.z -0.01); 
	 
	glTexCoord2d( 0 , 0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z -0.01);
	
	glEnd() ;

	glPopMatrix();  
	//left Door 
	glPushMatrix();
	if(keys['O'])
	{
		Doors_Open = true ; 
		Doors_Opening = true ; 
		Doors_Closing = false ;
		
		stime = clock();  
	}
	if(Doors_Open)
	{
		etime=clock();
		
		if (etime  - stime  > 4000)
		{
			Doors_Opening = false ;
			Doors_Closing = true ;
		}

		if( Translate_door < 2 && Doors_Opening)
		{
			Translate_door += 0.01; 
		}

		if (Doors_Closing)
		{			
			if(Translate_door < 0)
			{
				Doors_Open = false ;
			}

			Translate_door -=0.01 ; 
		}
		
	}

	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	glBegin(GL_QUADS);
	

	glTexCoord2d(0,1);
	glVertex3f( FTL.x+0.01 , FTL.y-height/2.5 , FTL.z-depth/3 + Translate_door);
	
	glTexCoord2d(0.5, 1);
	glVertex3f( FTL.x+0.01 , FTL.y-height/2.5 , FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0.5 ,0);
	glVertex3f( FTL.x +0.01 , FTL.y-height, FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0 , 0);
	glVertex3f( FTL.x +0.01, FTL.y-height, FTR.z -depth/3 + Translate_door);
	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0.5,1);
	glVertex3f( FTL.x +0.01, FTL.y-height/2.5 , FTL.z-depth/2 - Translate_door);
	
	glTexCoord2d(1,1);
	glVertex3f( FTL.x +0.01, FTL.y-height/2.5 , FTL.z-depth*2/3 - Translate_door);

	glTexCoord2d(1,0);	
	glVertex3f( FTL.x  +0.01, FTL.y-height, FTL.z-depth*2/3 - Translate_door);
	
	glTexCoord2d(0.5 ,0 );
	
	glVertex3f( FTL.x +0.01, FTL.y-height, FTR.z -depth/2- Translate_door);
	
	glEnd();
	
	glPopMatrix(); 
	

	//right Door 
	glPushMatrix(); 
	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0,1);
	glVertex3f( FTR.x-0.01 , FTL.y-height/2.5 , FTL.z-depth/3 + Translate_door);
	
	glTexCoord2d(0.5, 1);
	glVertex3f( FTR.x-0.01 , FTL.y-height/2.5 , FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0.5 ,0);
	glVertex3f( FTR.x -0.01 , FTL.y-height, FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0 , 0);
	glVertex3f( FTR.x -0.01, FTL.y-height, FTR.z -depth/3 + Translate_door);
	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0.5,1);
	glVertex3f( FTR.x-0.01 , FTL.y-height/2.5 , FTL.z-depth/2 - Translate_door);
	
	glTexCoord2d(1,1);
	glVertex3f( FTR.x-0.01 , FTL.y-height/2.5 , FTL.z-depth*2/3 - Translate_door);

	glTexCoord2d(1,0);	
	glVertex3f( FTR.x  , FTL.y-height, FTL.z-depth*2/3 - Translate_door);
	
	glTexCoord2d(0.5-0.01 ,0 );
	
	glVertex3f( FTR.x-0.01, FTL.y-height, FTR.z -depth/2- Translate_door);
	
	glEnd();
	
	glPopMatrix(); 
	

	//Lines 
	glLineWidth(5) ;
	
	glBegin(GL_LINES) ; 
	glVertex3f(FTR.x-width/5, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z);

	glVertex3f(FTR.x-width/3, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z);


	
	glVertex3f(FTR.x-width/2, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z);


	glVertex3f(FTR.x-width/1.5, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z);

	
	glVertex3f(FTR.x-width/1.2, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z);

	//Lines back 

	glVertex3f(FTR.x-width/5, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/3, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z-depth);


	
	glVertex3f(FTR.x-width/2, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.5, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.2, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glEnd() ;


	//Wheel
	glBindTexture(GL_TEXTURE_2D , wheel) ; 
	glBegin(GL_QUADS);// 
	
	glTexCoord2d(3 , 1) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y-height, FTR.z); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height*1.2, FTR.z); 
	
	glTexCoord2d( 3 , 0) ;
	glVertex3f(FTR.x, FTR.y-height*1.2, FTR.z);

	glEnd() ;
	
	//Back Wheel
	glBindTexture(GL_TEXTURE_2D , wheel) ; 
	glBegin(GL_QUADS);// 
	
	glTexCoord2d(3 , 1) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y-height, FTR.z-depth); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height*1.2, FTR.z-depth); 
	
	glTexCoord2d( 3 , 0) ;
	glVertex3f(FTR.x, FTR.y-height*1.2, FTR.z-depth);

	glEnd() ;

	
	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}


float c, t, rad=3;
float theta;
float height = 10;
void chairmo(Point FTR) {


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();





}
void whole_quad(Point FTR ,float width, float height,float wide) {

	
	glBegin(GL_QUADS);

	
	glVertex3f(FTR.x, FTR.y, FTR.z);
	glVertex3f(FTR.x+width, FTR.y, FTR.z);
	glVertex3f(FTR.x+width, FTR.y+height, FTR.z);
	glVertex3f(FTR.x, FTR.y+height, FTR.z);
	

	glEnd();

	//side left
	glBegin(GL_QUADS);


	glVertex3f(FTR.x+width, FTR.y, FTR.z);
	glVertex3f(FTR.x + width, FTR.y+height, FTR.z);
	glVertex3f(FTR.x + width, FTR.y + height, FTR.z+wide);
	glVertex3f(FTR.x+width, FTR.y + height, FTR.z+wide);

	glEnd();

	  //side right

	glBegin(GL_QUADS);


	glVertex3f(FTR.x , FTR.y, FTR.z);
	glVertex3f(FTR.x , FTR.y + height, FTR.z);
	glVertex3f(FTR.x , FTR.y + height, FTR.z + wide);
	glVertex3f(FTR.x , FTR.y + height, FTR.z + wide);

	glEnd();


	//up
	glBegin(GL_QUADS);


	glVertex3f(FTR.x, FTR.y, FTR.z);
	glVertex3f(FTR.x, FTR.y , FTR.z+wide);
	glVertex3f(FTR.x+width, FTR.y , FTR.z + wide);
	glVertex3f(FTR.x+width, FTR.y , FTR.z );

	glEnd();

}
void draw_moket(Point center, float x, float y, float z) {



	glBindTexture(GL_TEXTURE_2D, moket);

	glBegin(GL_QUADS);
	glTexCoord3d(0, 1, 0);
	glVertex3d(center.x, center.y + y, center.z);
	glTexCoord3d(1, 1, 0);
	glVertex3d(x + center.x, center.y + y, center.z);
	glTexCoord3d(1, 0, 1);
	glVertex3d(x + center.x, center.y, center.z + z);
	glTexCoord3d(0, 0, 1);
	glVertex3d(center.x, center.y, center.z + z);
	glEnd();




}
void draw_table1(Point center, float x, float y, float z, float leg) {
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);
	glVertex3d(center.x, center.y, center.z);
	glTexCoord3d(1, 0, 0);
	glVertex3d(center.x + x, center.y, center.z);
	glTexCoord3d(1, 0, 1);
	glVertex3d(center.x + x, center.y , center.z + z);
	glTexCoord3d(0, 0, 1);
	glVertex3d(center.x, center.y , center.z + z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);
	glVertex3d(center.x, center.y , center.z + z);
	glTexCoord3d(1, 0, 0);
	glVertex3d(center.x + x, center.y , center.z + z);
	glTexCoord3d(1, 1, 0);
	glVertex3d(center.x + x, center.y  - 0.5f, center.z + z);
	glTexCoord3d(0, 1, 0);
	glVertex3d(center.x, center.y  - 0.5f, center.z + z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);
	glVertex3d(center.x + x, center.y - y, center.z + z);
	glTexCoord3d(0, 0, 1);
	glVertex3d(center.x + x, center.y, center.z);
	glTexCoord3d(0, 1, 1);
	glVertex3d(center.x + x, center.y - 0.5f, center.z);
	glTexCoord3d(0, 1, 0);
	glVertex3d(center.x + x, center.y - 0.5f, center.z + z);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);
	glVertex3d(center.x, center.y , center.z + z);
	glTexCoord3d(0, 0, 1);
	glVertex3d(center.x, center.y, center.z);
	glTexCoord3d(0, 1, 1);
	glVertex3d(center.x, center.y - 0.5f, center.z);
	glTexCoord3d(0, 1, 0);
	glVertex3d(center.x, center.y - 0.5f, center.z + z);

	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord3d(0, 0, 0);
	glVertex3d(center.x, center.y , center.z );
	glTexCoord3d(1, 0, 0);
	glVertex3d(center.x+x, center.y, center.z);
	glTexCoord3d(1, 1, 0);
	glVertex3d(center.x+x, center.y - 0.5f, center.z);
	glTexCoord3d(0, 1, 0);
	glVertex3d(center.x, center.y - 0.5f, center.z );

	glEnd();
}
void Kitchen_Carriage(Point FTR, float width , float height , float depth)
{
	Carriage(FTR , width , height , depth ) ; 

	glDisable(GL_CULL_FACE) ; 

	

	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x-4, FTR.y - height + 2.5, FTR.z);
	glTexCoord2d(1,0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5, FTR.z);
	glTexCoord2d(1,1);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(0,1);

	glVertex3d(FTR.x-4, FTR.y - height + 2.5, FTR.z - 2);


	glEnd();
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5, FTR.z-2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5-0.5f, FTR.z);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5, FTR.z);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z-2);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5, FTR.z-2);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z );
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5, FTR.z );
	glEnd();







	//leg1
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 -0.5f, FTR.z - 2);

	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5-0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5-0.5f - 2.5f, FTR.z-2+0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5-0.5f, FTR.z-2 +0.3f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 -0.2f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2 + 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4-0.2f, FTR.y - height + 2.5 - 0.5f, FTR.z - 2 + 0.3f);
	glEnd();



	//leg2

	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 8 + 0.3f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2 );
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 8 + 0.3f, FTR.y - height + 2.5 - 0.5f, FTR.z - 2 );
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 8 , FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2+0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 8 , FTR.y - height + 2.5 - 0.5f, FTR.z - 2+0.3f);
	glEnd();
	  

	//leg3
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z );
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z );
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z  - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z  - 0.3f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f, FTR.z-0.3f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 8, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z-0.3f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 8+0.3f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z-0.3f );
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 8+0.3f, FTR.y - height + 2.5 - 0.5f, FTR.z-0.3f);
	glEnd();

	//leg4

	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z );
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z );
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 , FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f, FTR.z-0.3f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z-0.3f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4-0.2f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4-0.2f, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();



	//table 2




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 2.5, FTR.z);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5, FTR.z);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5, FTR.z - 2);


	glEnd();
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5, FTR.z);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5, FTR.z - 2);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5, FTR.z);
	glEnd();







	//leg1
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2 + 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 2 + 0.3f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2 + 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 2.5 - 0.5f, FTR.z - 2 + 0.3f);
	glEnd();



	//leg2

	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25 + 0.3f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 25 + 0.3f, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 2);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 2 + 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 2 + 0.3f);
	glEnd();


	//leg3
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 25, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 25 + 0.3f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 25 + 0.3f, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();

	//leg4

	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 2.5 - 0.5f - 2.5f, FTR.z - 0.3f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 2.5 - 0.5f, FTR.z - 0.3f);
	glEnd();







	//chairs


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 4 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 4, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 4, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();





	//chair2



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0); 

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();





//chair3


	glPushMatrix();

	glTranslated(FTR.x - 7, FTR.y - height + 4, FTR.z - 6);


	glRotated(90,0,1,0);


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 7 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 7, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 7, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();

	glPopMatrix();





	//chair table2







	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	//chair 2table 2
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, moket2);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 23 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 23, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 23, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();






	glPopMatrix();


	//dish washer
	glBindTexture(GL_TEXTURE_2D, black);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 0);
	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();
	glBindTexture(GL_TEXTURE_2D, black);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(FTR.x, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);
	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);
	glVertex3f(FTR.x, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);


	glEnd();







	glBindTexture(GL_TEXTURE_2D, black);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();

	glBindTexture(GL_TEXTURE_2D, black);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);


	glEnd();






	glBindTexture(GL_TEXTURE_2D, black);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);


	glEnd();

	// Ø­ÙˆØ¶
	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3-0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3-0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13 + 3);


	glEnd();

	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13 + 3);


	glEnd();
	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13);


	glEnd();

	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(1, 1);


	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 1, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13);


	glEnd();


	//ÙˆÙˆÙˆÙˆÙˆÙˆÙˆ
	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 5, FTR.y - height, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5, FTR.y - height, FTR.z - 13 + 3);


	glEnd();

	glBindTexture(GL_TEXTURE_2D, black);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 5, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 5, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 5 + 0.2f, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 5 + 0.2f, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();




	glBindTexture(GL_TEXTURE_2D, stales);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10, FTR.y - height, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10, FTR.y - height, FTR.z - 13 + 3);


	glEnd();

	glBindTexture(GL_TEXTURE_2D, black);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 10, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 10, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 10 - 0.2f, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 10 - 0.2f, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();









	glBindTexture(GL_TEXTURE_2D, black);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13 + 3);


	glEnd();





//texture

	glBindTexture(GL_TEXTURE_2D, ame1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(FTR.x - 5, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);
	glVertex3f(FTR.x - 5, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);
	glVertex3f(FTR.x, FTR.y - height, FTR.z - 13 + 3);


	glEnd();




	glBindTexture(GL_TEXTURE_2D, ame1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(FTR.x - 10, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);
	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x-5, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);
	glVertex3f(FTR.x-5, FTR.y - height, FTR.z - 13 + 3);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, ame1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);
	glVertex3f(FTR.x - 15, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x - 10, FTR.y - height + 3 - 0.2f, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);
	glVertex3f(FTR.x - 10	, FTR.y - height, FTR.z - 13 + 3);


	glEnd();




	glEnd();


	glBindTexture(GL_TEXTURE_2D, ame1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height+5, FTR.z - 13+3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x-15 , FTR.y - height +8, FTR.z - 13+3);
	glTexCoord2d(2, 1);

	glVertex3f(FTR.x , FTR.y - height +8, FTR.z - 13 +3);
	glTexCoord2d(2, 0);

	glVertex3f(FTR.x , FTR.y - height+5, FTR.z - 13+3 );


	glEnd();




	glBindTexture(GL_TEXTURE_2D, ame6);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 );
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x-15, FTR.y - height + 8, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x-15, FTR.y - height + 8, FTR.z - 13 );


	glEnd();





	glBindTexture(GL_TEXTURE_2D, ame6);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x , FTR.y - height+5 , FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x , FTR.y - height +5, FTR.z - 13);


	glEnd();

	//draw refregeter

	glBindTexture(GL_TEXTURE_2D, moket);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 20, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 23, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 23, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 20, FTR.y - height + 5, FTR.z - 13);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, refregiter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 20, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 20, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 23, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 23, FTR.y - height + 5, FTR.z - 13 + 3);


	glEnd();
	glPushMatrix();
	glColor3ub(0, 180, 200);
	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 20, FTR.y - height+5, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 20, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 20, FTR.y - height , FTR.z - 13+3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 20, FTR.y - height + 5, FTR.z - 13+3);


	glEnd();







	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 23, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 23, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 23, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 23, FTR.y - height + 5, FTR.z - 13 + 3);


	glEnd();



	glPopMatrix();
	/////////////oven
	glBindTexture(GL_TEXTURE_2D, moket);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 19, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, oven1);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 19, FTR.y - height , FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();
	glPushMatrix();
	glColor3ub(0, 180, 200);
	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();







	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 19, FTR.y - height, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 19, FTR.y - height, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13 + 3);


	glEnd();



	glPopMatrix();
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, iii);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13+3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13+3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height +3 , FTR.z - 13);
	glTexCoord2d(0,1);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13 );


	glEnd();
	glPopMatrix();


	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 19, FTR.y - height + 3, FTR.z - 13 +0.1f);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 3, FTR.z - 13 + 0.1f);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 3+3, FTR.z - 13+0.1f);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 19, FTR.y - height + 3+3, FTR.z - 13+0.1f);


	glEnd();







////microwave
	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 12, FTR.y - height+3, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13);


	glEnd();


	glBindTexture(GL_TEXTURE_2D, mi);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 12, FTR.y - height+3, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 + 3);


	glEnd();
	glPushMatrix();
	glColor3ub(0, 180, 200);
	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 12, FTR.y - height+3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 12, FTR.y - height+3, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13 + 3);


	glEnd();







	glBindTexture(GL_TEXTURE_2D, refregeter);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height+3, FTR.z - 13 + 3);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 + 3);


	glEnd();



	glPopMatrix();
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, iii);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13 + 3);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 12, FTR.y - height + 5, FTR.z - 13);
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13);


	glEnd();
	glPopMatrix();





////



	glPushMatrix();
	glColor3ub(150, 100, 50);
	glBindTexture(GL_TEXTURE_2D, wall2);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3f(FTR.x , FTR.y - height + 5, FTR.z - 13+0.2f);
	glTexCoord2d(1, 0);

	glVertex3f(FTR.x , FTR.y - height+3, FTR.z - 13+0.2f);
	glTexCoord2d(1, 1);

	glVertex3f(FTR.x - 15, FTR.y - height+3 , FTR.z - 13+0.2f );
	glTexCoord2d(0, 1);

	glVertex3f(FTR.x - 15, FTR.y - height + 5, FTR.z - 13+0.2f);


	glEnd();

	//draw table middle



	glPushMatrix();
	glColor3d(1, 0, 0);
	glBegin(GL_QUADS);
	for (float i = 0; i <= 360; i += 0.1) {

		theta = i*(3.14) / 180;

		float l = 0.3f*cos(theta);
		float c = 0.3f*sin(theta);

		glVertex3f(FTR.x - 15, FTR.y - height + 2, FTR.z - 7);

		glVertex3f(FTR.x - 15, FTR.y - height, FTR.z - 7);

		glVertex3f(FTR.x - 15 + l, FTR.y - height + 2, FTR.z - 7 + c);

		glVertex3f(FTR.x - 15 + l, FTR.y - height, FTR.z - 7 + c);



	}


	glEnd();


	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	/*glColor3f(0, 0, 0);*/
	glTranslated(FTR.x - 15, FTR.y - height + 4, FTR.z - 24);
	glRotated(90, 0, 1, 0);
	Point point2 = Point(4, 6, 0);
	chairmo(point2);
	glPopMatrix();
	glPopMatrix();








	glPushMatrix();

	glTranslated(FTR.x - 15, FTR.y - height + 4, FTR.z + 10);
	glRotated(270, 0, 1, 0);
	Point point3 = Point(4, 6, 0);
	chairmo(point3);
	glPopMatrix();

	glPushMatrix();

	glTranslated(FTR.x - 32, FTR.y - height + 4, FTR.z - 7.5);
	glRotated(180, 0, 1, 0);
	Point point4 = Point(4, 6, 0);
	chairmo(point4);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();





	glPushMatrix();

	glTranslated(FTR.x + 2, FTR.y - height + 4, FTR.z - 6);

	Point point5 = Point(4, 6, 0);
	chairmo(point5);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();





	glPushMatrix();
	
	glColor3ub(255, 180, 150);

	glBegin(GL_LINES);


	for (float i = 0; i <= 360; i += 0.1) {
		theta = i*(3.14) / 180;
		float l = rad*cos(theta);
		float c = rad*sin(theta);

		glVertex3f(FTR.x - 15, FTR.y - height + 2, FTR.z - 7);

		glVertex3f(FTR.x - 15 + l, FTR.y - height + 2, FTR.z - 7 + c);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 155, 50);
	glBegin(GL_QUADS);
	for (float i = 0; i <= 360; i += 0.1) {

		theta = i*(3.14) / 180;

		float l = rad*cos(theta);
		float c = rad*sin(theta);

		glVertex3f(FTR.x - 15, FTR.y - height + 2, FTR.z - 7);

		glVertex3f(FTR.x - 15, FTR.y - height + 2 - 0.3f, FTR.z - 7);

		glVertex3f(FTR.x - 15 + l, FTR.y - height + 2, FTR.z - 7 + c);

		glVertex3f(FTR.x - 15 + l, FTR.y - height + 2 - 0.3f, FTR.z - 7 + c);



	}


	glEnd();
	glPopMatrix();





	draw_windows(FTR , width , height , depth ) ; 
	
	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}



void makeTableglass(Point FTR,float tg_x,float tg_y,float tg_z,float tg_rotate,float tg_scale){
	table_glass->pos.x=FTR.x+tg_x;
	table_glass->pos.y=FTR.y+tg_y;
	table_glass->pos.z=FTR.z+tg_z;
	table_glass->rot.y=tg_rotate;
	table_glass->scale=tg_scale;
	table_glass->Draw();
}
void makeIndoorPlanet(Point FTR,float inpla_x,float inpla_y,float inpla_z,float inpla_rotate,float inpla_scale){
	indoorPlanet->pos.x=FTR.x+inpla_x;
	indoorPlanet->pos.y=FTR.y+inpla_y;
	indoorPlanet->pos.z=FTR.z+inpla_z;
	indoorPlanet->rot.y=inpla_rotate;
	indoorPlanet->scale=inpla_scale;
	indoorPlanet->Draw();
}
void makeEatingTable(Point FTR,float eattab_x,float eattab_y,float eattab_z,float eattab_rotate,float eattab_scale){
	eatingTable->pos.x=FTR.x+eattab_x;
	eatingTable->pos.y=FTR.y+eattab_y;
	eatingTable->pos.z=FTR.z+eattab_z;
	eatingTable->rot.y=eattab_rotate;
	 eatingTable->scale=eattab_scale;
	 eatingTable->Draw();
}


void makeframeBurger(Point FTR,float frameBurger_x,float frameBurger_y,float frameBurger_z,float frameBurger_rotate,float frameBurger_scale){
	frameBurger->pos.x=FTR.x+frameBurger_x;
	 frameBurger->pos.y=FTR.y+frameBurger_y;
	 frameBurger->pos.z=FTR.z+frameBurger_z;
	 frameBurger->rot.y=frameBurger_rotate;
	 frameBurger->scale=frameBurger_scale;
	 frameBurger->Draw();
}
void makeLamp(Point FTR,float lamp_x,float lamp_y,float lamp_z,float lamp_rotate,float lamp_scale){
	lamp->pos.x=FTR.x+lamp_x;
	 lamp->pos.y=FTR.y+lamp_y;
	 lamp->pos.z=FTR.z+lamp_z;
	 lamp->rot.y=lamp_rotate;
	 lamp->scale=lamp_scale;
	 lamp->Draw();
}
void makemchair(Point FTR) {
	
	glDisable(GL_CULL_FACE); 
	float height = 10;
	glBindTexture(GL_TEXTURE_2D, ch_red);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_red);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	//surfuce up
	glBindTexture(GL_TEXTURE_2D, ch_red);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glEnd();



	//back

	glBindTexture(GL_TEXTURE_2D, ch_red);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glEnd();

	//sides
	glBindTexture(GL_TEXTURE_2D, ch_red);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, ch_red);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f + 1, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();

	//border botom
	glBindTexture(GL_TEXTURE_2D, ch_red);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_red);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_red);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, ch_red);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f, FTR.z - 4 + 1);
	glEnd();



	//draw leg of chairs
	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();






	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 2, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 2 + 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 0.2f);
	glEnd();





	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, ch_wood);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 0);

	glVertex3d(FTR.x - 20 - 0.2f, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(1, 1);

	glVertex3d(FTR.x - 20, FTR.y - height, FTR.z - 4 + 1 - 0.2f);
	glTexCoord2d(0, 1);

	glVertex3d(FTR.x - 20, FTR.y - height + 1.5f - 0.2f, FTR.z - 4 + 1 - 0.2f);
	glEnd();


	glEnable(GL_CULL_FACE);


}

void Food_Carriage(Point point, float width , float height , float depth)
{
	
	Carriage(point , width , height , depth) ; 
	

	makeTableglass(point,-28,-10,-1.7,0,5);			
	makeTableglass(point,-28,-10,-11.3,0,5);		
	makeIndoorPlanet(point,-28,-7.6,-1.7,0,0.5);	
	makeIndoorPlanet(point,-28,-7.6,-11.3,0,0.5);	
	makeEatingTable(point,-8,-10,-10.5,90,0.065);
	makeEatingTable(point,-16,-10,-10.5,90,0.065);
	makeEatingTable(point,-8,-10,-2.5,90,0.065);
	makeEatingTable(point,-16,-10,-2.5,90,0.065);
	makeframeBurger(point,-1,-5,-2.5,-90,0.06);
	makeframeBurger(point,-1,-5,-10.5,-90,0.06);
	makeLamp(point,-15,0,-5.5,0,0.02);
	makeLamp(point,-5,0,-5.5,0,0.02);
	makeLamp(point,-25,0,-5.5,0,0.02);
		
	draw_windows(point , width , height , depth) ; 

	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}

void makeBed(Point FTR,float bed_x,float bed_y,float bed_z,float bed_rotate,float bed_scale){
	 bed->pos.x=FTR.x+bed_x;
	 bed->pos.y=FTR.y+bed_y;
	 bed->pos.z=FTR.z+bed_z;
	 bed->rot.y=bed_rotate;
	 bed->scale=bed_scale;
	 bed->Draw();
}
void makestand(Point FTR,float stand_x,float stand_y,float stand_z,float stand_rotate,float stand_scale){
	 night_stand->pos.x=FTR.x+stand_x;
	 night_stand->pos.y=FTR.y+stand_y;
	 night_stand->pos.z=FTR.z+stand_z;
	 night_stand->rot.y=stand_rotate;
	 night_stand->scale=stand_scale;
	 night_stand->Draw();
}
void makeBedTable(Point FTR,float bt_x,float bt_y,float bt_z,float bt_rotate,float bt_scale){
	bedtable->pos.x=FTR.x+bt_x;
	 bedtable->pos.y=FTR.y+bt_y;
	 bedtable->pos.z=FTR.z+bt_z;
	 bedtable->rot.y=bt_rotate;
	 bedtable->scale=bt_scale;
	 bedtable->Draw();
}
void makeTV(Point FTR,float tv_x,float tv_y,float tv_z,float tv_rotate,float tv_scale){
	TV->pos.x=FTR.x+tv_x;
	TV->pos.y=FTR.y+tv_y;
	TV->pos.z=FTR.z+tv_z;
	TV->rot.y=tv_rotate;
	TV->scale=tv_scale;
	TV->Draw();
}

void Drawlucker( Point Center , float width , float height ) 
{
	glBindTexture(GL_TEXTURE_2D , frontlucker) ; 
	glBegin(GL_QUADS);  
	glTexCoord2d(0 , 0) ; 
	glVertex3f(Center.x -width /2 , Center.y - height/2 , Center.z ) ; 
	glTexCoord2d(1 , 0) ; 
	glVertex3f(Center.x +width /2 , Center.y - height/2 , Center.z ) ; 
	glTexCoord2d(1 ,1 ) ; 
	glVertex3f(Center.x +width /2 , Center.y + height/2 , Center.z ) ; 
	glTexCoord2d(0 , 1) ; 
	glVertex3f(Center.x -width /2 , Center.y + height/2 , Center.z ) ; 

	glEnd() ;

	glBindTexture(GL_TEXTURE_2D , rightlucker) ; 
	glBegin(GL_QUADS);  
	
	glTexCoord2d(0 , 0) ; 
	glVertex3f(Center.x -width /2 , Center.y - height/2 , Center.z + 3 ) ; 
	
	glTexCoord2d(1 , 0) ; 
	glVertex3f(Center.x -width /2 , Center.y - height/2 , Center.z) ; 
	
	glTexCoord2d(1 ,1 ) ; 
	glVertex3f(Center.x -width /2 , Center.y + height/2 , Center.z ) ; 
	
	glTexCoord2d(0 , 1) ; 
	glVertex3f(Center.x -width /2 , Center.y + height/2 , Center.z + 3) ; 
	
	glEnd() ;

	
	glBegin(GL_QUADS);  
	
	glTexCoord2d(0 , 0) ; 
	glVertex3f(Center.x +width /2 , Center.y - height/2 , Center.z +3) ; 
	
	glTexCoord2d(1 , 0) ; 
	glVertex3f(Center.x +width /2 , Center.y - height/2 , Center.z ) ; 
	
	glTexCoord2d(1 ,1 ) ; 
	glVertex3f(Center.x +width /2 , Center.y + height/2 , Center.z ) ; 
	
	glTexCoord2d(0 , 1) ; 
	glVertex3f(Center.x +width /2 , Center.y + height/2 , Center.z + 3) ; 
	
	glEnd() ;

}

void bedroom_Carriage(Point FTR, float width , float height , float depth)
{
	
	Carriage(FTR , width , height , depth) ; 


	makeBed(FTR,-19,-10,-7.2,-0.5,0.03);
	makeBed(FTR,-7.5,-10,-7.2,-0.5,0.03);
	makestand(FTR,-21.5,-10,-12,0,5);
	makestand(FTR,-10,-10,-12,0,5);
	makeBedTable(FTR,-15,-10,-1,90,0.035);
	makeTableglass(FTR,-28,-10,-11.3,0,5);
	makeIndoorPlanet(FTR,-28,-7.6,-11.3,0,0.5);
	makeLamp(FTR,-15,0,-5.5,0,0.02);
	makeLamp(FTR,-5,0,-5.5,0,0.02);
	makeLamp(FTR,-25,0,-5.5,0,0.02);
	makeTV(FTR,-17,-7.4,-1.3,180,0.004);
	makeIndoorPlanet(FTR,-18,-7.5,-1.3,180,0.3);
	Point point1 = Point(FTR.x -23 , FTR.y - 7 , FTR.z - 3 ) ; 
	glDisable(GL_CULL_FACE);
	Drawlucker(point1 , 6 , 7 ) ; 

	draw_windows(FTR , width , height , depth) ; 

	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}



void Passenger_Carriage(Point FTR, float width , float height , float depth)
{
	Carriage(FTR , width , height , depth ) ; 

	glDisable(GL_CULL_FACE) ;
	

	glPushMatrix();
	glTranslated(FTR.x - 25, FTR.y - height + 4, FTR.z -28);
	glRotated(90, 0, 1, 0);
	
	Point point1 = Point(4,6,0);
	 chairmo(point1);


	 glPopMatrix();
	 glPushMatrix();
	 glTranslated(FTR.x - 25 +3, FTR.y - height + 4, FTR.z - 28);
	 glRotated(90, 0, 1, 0);
	 Point point2 = Point(4,6,0);
	 chairmo(point2);


	 glPopMatrix();



	 for (int i = FTR.x - 19; i <= FTR.x ; i += 3) {
	
		 glPushMatrix();
		 glTranslated(i, FTR.y - height + 4, FTR.z - 28);
		 glRotated(90, 0, 1, 0);
		 Point point3 = Point(4,6,0);
		 chairmo(point3);


		 glPopMatrix();


	 }




	 for (int i = FTR.x - 25; i <= FTR.x; i += 3) {

		 glPushMatrix();
		 glTranslated(i, FTR.y - height + 4, FTR.z - 25.5);
		 glRotated(90, 0, 1, 0);
		 Point point4 = Point(4,6,0);
		 chairmo(point4);


		 glPopMatrix();


	 }


	 for (int i = FTR.x - 25; i <= FTR.x; i += 3) {

		 glPushMatrix();
		 glTranslated(i, FTR.y - height + 4, FTR.z - 19);
		 glRotated(90, 0, 1, 0);
		 Point point5 = Point(4,6,0);
		 chairmo(point5);


		 glPopMatrix();


	 }




	 for (int i = FTR.x - 25; i <= FTR.x; i += 3) {

		 glPushMatrix();
		 glTranslated(i, FTR.y - height + 4, FTR.z - 21.5);
		 glRotated(90, 0, 1, 0);
		 Point point6 = Point(4,6,0);
		 chairmo(point6);


	 glPopMatrix();


 }




	draw_windows(FTR , width , height , depth ) ; 
	
	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}


void istwani(){
   // bottom circle  
	 glBegin(GL_TRIANGLE_FAN); 
	  glVertex3d(0,-1,0); 
	  for(float angle = -0.2;angle<=2*3.14;angle += 0.01){ 
	   float x = cos(angle); 
	   float z = sin(angle); 
 
	   glVertex3d(x,-1,z); 
	  } 
	 glEnd();
 
	   // upper circle  
	 glBegin(GL_TRIANGLE_FAN); 
	  glVertex3d(0,6,0); 
	  for(float angle = -0.2;angle<=2*3.14;angle += 0.01){ 
	   float x = cos(angle); 
	   float z = sin(angle); 
 
	   glVertex3d(x,6,z); 
	  } 
	 glEnd(); 
  
	// side 
	glBegin(GL_QUAD_STRIP); 
	for(float angle = -0.2;angle<=2*3.14;angle += 0.001)
	{ 
		   float x = cos(angle); 
		   float z = sin(angle); 
 
		   glVertex3d(x,-1,z); 
		   glVertex3d(x,6,z); 
	} 
	glEnd(); 
}

void DrawSolidCircle(Point center, float radius)
{
	glDisable(GL_CULL_FACE) ; 
	glBegin(GL_TRIANGLES);
	float z , y , z1 , y1 ; 
	glColor3f(1 ,1,0) ; 
	for(float angle = 0.0f ; angle <=(2.0f*3.14f);angle += 0.01)
	{
	   
	   z = radius*(cos(angle) )+ center.z;
	   y = radius*(sin(angle))+ center.y ;
	   
	   z1 = radius*(cos(angle+0.1) )+ center.z;
	   y1 = radius*(sin(angle + 0.1)) + center.y ;
	   
	 
	   
	   glVertex3f(center.x,center.y,center.z);
	   glVertex3f(center.x , y , z);
	   glVertex3f(center.x , y1 , z1) ; 
	
	}
	glColor3f(1 ,1,1) ;
	glEnd();
	glEnable(GL_CULL_FACE) ; 
};

void DriverCarriage(Point FTR, float width , float height , float depth)
{
	
	//front
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);// عكس
	glTexCoord2d(1.5 , 1) ; 
	glVertex3f(FTR.x  - width/2, FTR.y, FTR.z);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y, FTR.z); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z); 
	 
	glTexCoord2d( 1.5 , 0) ;
	glVertex3f(FTR.x- width/2, FTR.y-height/3, FTR.z);

	
	glEnd() ;
	

	//fornt inside 
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x- width/2, FTR.y-height/3, FTR.z);
	
	glTexCoord2d(0 , 0  ) ; 
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z); 
	
	glTexCoord2d( 0 , 1  ) ; 
	glVertex3f(FTR.x-width, FTR.y, FTR.z); 
	
	glTexCoord2d(1 ,1 ) ; 
	glVertex3f(FTR.x - width/2 , FTR.y, FTR.z);
	
	
	glEnd() ;
	
	//front bottom
	glBindTexture(GL_TEXTURE_2D , trainwall) ; 
	glBegin(GL_QUADS); 
	
	glTexCoord2d(1.5 , 1 ); 
	
	glVertex3f(FTR.x , FTR.y-(height/1.4), FTR.z);
	glTexCoord2d(0 , 1 ); 
	
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);

	glTexCoord2d(0 , 0 ); 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);


	glTexCoord2d(1.5 , 0 ); 
	glVertex3f(FTR.x , FTR.y-height, FTR.z);
	
	glEnd(); 

	//front bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS); 
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	glTexCoord2d( 0, 0  ) ; 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);
	
	glTexCoord2d(0, 1  ) ; 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	
	
	glEnd(); 

	//left
	
	Point FTL = Point(FTR.x-width, FTR.y, FTR.z) ;   
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(1 , 1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z);
	
	glTexCoord2d(0 , 1 ) ;
	glVertex3f( FTL.x , FTL.y , FTL.z-depth );
	
	glTexCoord2d(0 , 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height/2.5, FTL.z-depth );
	
	glTexCoord2d(1 , 0 ) ;
	glVertex3f( FTL.x, FTL.y-height/2.5, FTR.z );
	
	glEnd();
	
	
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1, 1 ) ;  
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth/3 );
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height, FTL.z-depth/3 );
	
	glTexCoord2d(1, 0 ) ;
	glVertex3f( FTL.x, FTL.y-height, FTR.z );
	
	glEnd();
	
	
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 	
	glBegin(GL_QUADS);
	
	glTexCoord2d(1, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z - depth*2/3);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z - depth);
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f( FTL.x  , FTL.y-height, FTL.z - depth );
	
	glTexCoord2d(1, 0 ) ;
	glVertex3f( FTL.x, FTL.y-height, FTR.z - depth*2/3);
	
	glEnd();
	

	
	
	//left inside Top
	glColor3f(1,1,1) ; 

	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y-height/2.5, FTL.z );
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height/2.5, FTL.z-depth );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z-depth );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y , FTL.z);
	
	glEnd();
	
	//left inside bottom
	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y- height, FTR.z );
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height , FTL.z-depth/3 );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth/3 );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z);
	
	glEnd();
	
	//left inside bottom 
	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f( FTL.x, FTL.y- height, FTR.z -depth*2/3);
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f( FTL.x  , FTL.y-height , FTL.z-depth );
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth );
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f( FTL.x , FTL.y-height/2.5 , FTL.z-depth*2/3);
	
	glEnd();
	
	
	//back
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1.5 ,1 ) ; 
	glVertex3f(FTR.x-width/2, FTR.y, FTR.z-depth);
	
	glTexCoord2d(1.5 , 0) ;
	glVertex3f(FTR.x-width/2, FTR.y-height/3, FTR.z-depth);

	glTexCoord2d(0 ,0 ) ;
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z-depth); 

	glTexCoord2d(0 ,1 ) ;
	glVertex3f(FTR.x-width, FTR.y, FTR.z-depth); 
	
	glEnd() ;
	
	//back bottom
	glBindTexture(GL_TEXTURE_2D ,trainwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1.5 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glTexCoord2d(1.5, 0  ) ;
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 1 ) ;
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 

	
	//back inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f(FTR.x-width, FTR.y, FTR.z-depth); 
	
	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f(FTR.x - width , FTR.y-height/3, FTR.z-depth); 
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f(FTR.x - width/2, FTR.y-height/3, FTR.z-depth);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x - width/2, FTR.y, FTR.z-depth);
		
	
	glEnd() ;
	
	//back bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	  
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);

	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 
	
	//right 
	
	glBindTexture(GL_TEXTURE_2D , traintopwall) ; 
	glBegin(GL_QUADS) ; 

	glTexCoord2d( 1, 1) ;
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z-depth);
	
	glTexCoord2d( 0, 1) ;
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z);
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x, FTR.y-height , FTR.z);
	
	glTexCoord2d( 1, 0) ;
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth);	
	
	glEnd(); 

	
	//right inside

	glBindTexture(GL_TEXTURE_2D , wall) ;
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x , FTR.y-height , FTR.z-depth);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x, FTR.y-height , FTR.z);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z-depth);
	
	glEnd();

	//Control 
	glBindTexture(GL_TEXTURE_2D , control) ;
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x - width/ 10 , FTR.y-height /1.2 , FTR.z-depth);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x- width/ 10, FTR.y-height /1.2 , FTR.z);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x, FTR.y-height/1.4, FTR.z-depth);
	
	glEnd();

	glBindTexture(GL_TEXTURE_2D ,wall ) ;
	
	glBegin(GL_QUADS);

	
	glTexCoord2d(1 , 0); 
	glVertex3f(FTR.x - width/ 10 , FTR.y-height , FTR.z-depth);
	
	glTexCoord2d(0 ,0 );
	glVertex3f(FTR.x- width/ 10, FTR.y-height  , FTR.z);
	
	glTexCoord2d(0 , 1 );
	glVertex3f(FTR.x- width/ 10, FTR.y-height/1.2, FTR.z);
	
	glTexCoord2d(1, 1);
	glVertex3f(FTR.x - width/ 10, FTR.y-height/1.2, FTR.z-depth);
	
	glEnd();

	
	//Lighting
	DrawSolidCircle ( Point ( FTR.x, FTR.y-height/1.2 , FTR.z-depth/4 )  , 1 ); 
	
	DrawSolidCircle ( Point ( FTR.x, FTR.y-height/1.2 , FTR.z-depth*3/4 )  , 1 ); 
	
    //top
	glBindTexture(GL_TEXTURE_2D , traintop) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x - width /2, FTR.y, FTR.z);
	
	glTexCoord2d( 1 , 0.6) ;
	glVertex3f(FTR.x - width/2 , FTR.y, FTR.z-depth);
	
	glTexCoord2d( 0 , 0.6 ) ;
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	
	glTexCoord2d( 0 , 0 ) ;
	glVertex3f(FTR.x - width , FTR.y , FTR.z);

		
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , traintop) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d( 1 , 0 ) ; 
	glVertex3f(FTR.x, FTR.y - height/3 , FTR.z);
	
	glTexCoord2d( 1 , 0.6) ;
	glVertex3f(FTR.x, FTR.y - height/3, FTR.z-depth);
	
	glTexCoord2d( 0 , 0.6 ) ;
	glVertex3f(FTR.x - width/2 , FTR.y- height/3, FTR.z-depth);
	
	glTexCoord2d( 0 , 0 ) ;
	glVertex3f(FTR.x-width/2 , FTR.y - height/3, FTR.z);

		
	glEnd();
	
	glPushMatrix() ;
	glTranslated(FTR.x - width/3 , FTR.y- height/4, FTR.z-depth/2) ;
	istwani() ; 
	glPopMatrix() ;
	//top inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d(0 ,0);
	glVertex3f(FTR.x-width , FTR.y , FTR.z);
	
	glTexCoord2d(0 , 1);
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	
	glTexCoord2d(1 , 1);
	glVertex3f(FTR.x  - width/2, FTR.y, FTR.z-depth);
	
	glTexCoord2d(1,0);
	glVertex3f(FTR.x  - width/2 , FTR.y, FTR.z);
	
		
	glEnd();
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0 ,0);
	glVertex3f(FTR.x-width/2 , FTR.y - height/3, FTR.z);
	
	glTexCoord2d(0 , 1);
	glVertex3f(FTR.x - width/2 , FTR.y- height/3, FTR.z-depth);
	
	glTexCoord2d(1 , 1);
	glVertex3f(FTR.x, FTR.y- height/3, FTR.z-depth);
	
	glTexCoord2d(1,0);
	glVertex3f(FTR.x, FTR.y- height/3, FTR.z);
	
		
	glEnd();
	
	//bottom

	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glEnd() ; 

	//bottom inside
	glBindTexture(GL_TEXTURE_2D , carpet ) ; 

	glBegin(GL_QUADS);
	glTexCoord2d(3 ,3 ) ; 
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glTexCoord2d(0 , 3 ) ; 
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);

	glTexCoord2d(0 ,0 ) ; 
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);

		
	glTexCoord2d(3 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	

	glEnd();
	
	
	//Doors
	glDisable(GL_CULL_FACE); 
	
	
	
	glPopMatrix();  
	//left Door 
	glPushMatrix();
	
	if(keys['O'])
	{
		Doors_Open = true ; 
		Doors_Opening = true ; 
		Doors_Closing = false ;
		stime = clock();  
	}
	if(Doors_Open)
	{
		etime=clock();
		
		if (etime  - stime  > 4000)
		{
			Doors_Opening = false ;
			Doors_Closing = true ;
		}

		if( Translate_door < 2 && Doors_Opening)
		{
			Translate_door += 0.1; 
		}

		if (Doors_Closing)
		{			
			if(Translate_door < 0)
				Doors_Open = false ;

			Translate_door -=0.1 ; 
		}
		
	}

	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	glBegin(GL_QUADS);
	

	glTexCoord2d(0,1);
	glVertex3f( FTL.x+0.01 , FTL.y-height/2.5 , FTL.z-depth/3 + Translate_door);
	
	glTexCoord2d(0.5, 1);
	glVertex3f( FTL.x+0.01 , FTL.y-height/2.5 , FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0.5 ,0);
	glVertex3f( FTL.x +0.01 , FTL.y-height, FTL.z-depth/2 + Translate_door);
	
	glTexCoord2d(0 , 0);
	glVertex3f( FTL.x +0.01, FTL.y-height, FTR.z -depth/3 + Translate_door);
	
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D , fulldoor) ; 
	
	glBegin(GL_QUADS);
	
	glTexCoord2d(0.5,1);
	glVertex3f( FTL.x +0.01, FTL.y-height/2.5 , FTL.z-depth/2 - Translate_door);
	
	glTexCoord2d(1,1);
	glVertex3f( FTL.x +0.01, FTL.y-height/2.5 , FTL.z-depth*2/3 - Translate_door);

	glTexCoord2d(1,0);	
	glVertex3f( FTL.x  +0.01, FTL.y-height, FTL.z-depth*2/3 - Translate_door);
	
	glTexCoord2d(0.5 ,0 );
	
	glVertex3f( FTL.x +0.01, FTL.y-height, FTR.z -depth/2- Translate_door);
	
	glEnd();
	
	glPopMatrix(); 
	

	
	glPopMatrix(); 
	
	
	//Lines 
	glLineWidth(5) ;
	
	glBegin(GL_LINES) ; 
	glVertex3f(FTR.x-width/5, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z);

	glVertex3f(FTR.x-width/3, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z);


	
	glVertex3f(FTR.x-width/2, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z);


	glVertex3f(FTR.x-width/1.5, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z);

	
	glVertex3f(FTR.x-width/1.2, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z);

	//Lines back 

	glVertex3f(FTR.x-width/5, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/3, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z-depth);


	
	glVertex3f(FTR.x-width/2, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.5, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.2, FTR.y-height/3, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glEnd() ;


	//Wheel
	glBindTexture(GL_TEXTURE_2D , wheel) ; 
	glBegin(GL_QUADS);// 
	
	glTexCoord2d(3 , 1) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y-height, FTR.z); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height*1.2, FTR.z); 
	
	glTexCoord2d( 3 , 0) ;
	glVertex3f(FTR.x, FTR.y-height*1.2, FTR.z);

	glEnd() ;
	
	//Back Wheel
	glBindTexture(GL_TEXTURE_2D , wheel) ; 
	glBegin(GL_QUADS);// 
	
	glTexCoord2d(3 , 1) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d( 0 , 1) ;
	glVertex3f(FTR.x-width, FTR.y-height, FTR.z-depth); 
	
	glTexCoord2d( 0, 0) ;
	glVertex3f(FTR.x - width , FTR.y-height*1.2, FTR.z-depth); 
	
	glTexCoord2d( 3 , 0) ;
	glVertex3f(FTR.x, FTR.y-height*1.2, FTR.z-depth);

	glEnd() ;

	glColor4f(0 , 0 , 1 , 0.5);
	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x-width, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x, FTR.y-height/3 , FTR.z);
	
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);

	
	glEnd(); 

	//front windows inside 

	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z);
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z);
	
	glEnd(); 

	//Back windows
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z-depth);
	
	glEnd(); 
	
	
	//back windows inside 
	glBegin(GL_QUADS);
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z-depth);
	
	glEnd(); 

	//right windows 
	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-height/3 , FTR.z-depth);
	glVertex3f(FTR.x , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x, FTR.y-height/3, FTR.z);
	
	glEnd(); 

	
	//right windows 
	glBegin(GL_QUADS);
	glVertex3f(FTR.x - width/2, FTR.y-height/3 , FTR.z-depth);
	glVertex3f(FTR.x- width/2 , FTR.y, FTR.z-depth);
	glVertex3f(FTR.x- width/2, FTR.y, FTR.z);
	glVertex3f(FTR.x- width/2, FTR.y-height/3, FTR.z);
	
	glEnd(); 
	
	glColor4f( 1 ,1 ,1 , 0.5) ; 
	glDisable(GL_LIGHT1) ; 
	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}

void Library_Carriage(Point FTR, float width , float height , float depth)
{
	 
	Carriage(FTR , width , height , depth) ; 
	
	Point FTL = Point(FTR.x-width, FTR.y, FTR.z) ;   
	glDisable(GL_CULL_FACE) ; 
	//first BookCase
	glBindTexture(GL_TEXTURE_2D , Wood1) ; 
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(FTL.x+(width/2.5),FTL.y-1.5,FTL.z-0.5);
	glTexCoord2d(1,0);
	glVertex3f(FTL.x+(width/2.5),FTL.y-1.5,FTL.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTL.x+(width/2.5),FTL.y-height,FTL.z-3);
	glTexCoord2d(0,1);
	glVertex3f(FTL.x+(width/2.5),FTL.y-height,FTL.z-0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , bookLocker1) ; 
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(FTL.x+(width/2.5),FTL.y-1.5,FTL.z-3);
	glTexCoord2d(1,0);
	glVertex3f(FTL.x+(width/2.5),FTL.y-height,FTL.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-height,FTL.z-3);
	glTexCoord2d(0,1);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-1.5,FTL.z-3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood1) ; 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-height,FTL.z-3);
	glTexCoord2d(1,0);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-1.5,FTL.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-1.5,FTL.z-0.5);
	glTexCoord2d(0,1);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-height,FTL.z-0.5);
		glEnd();

		glBegin(GL_QUADS);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-1.5,FTL.z-0.5);
	glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-height,FTL.z-0.5);
	glVertex3f(FTL.x+(width/2.5),FTL.y-height,FTL.z-0.5);
	glVertex3f(FTL.x+(width/2.5),FTL.y-1.5,FTL.z-0.5);
		glEnd();
	
	//Secondy BookCase
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
	glVertex3f(FTR.x-(width/2.5),FTR.y-1.5,FTR.z-0.5);
	glTexCoord2d(1,0);
	glVertex3f(FTR.x-(width/2.5),FTR.y-1.5,FTR.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTR.x-(width/2.5),FTR.y-height,FTR.z-3);
	glTexCoord2d(0,1);
	glVertex3f(FTR.x-(width/2.5),FTR.y-height,FTR.z-0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , bookLocker2) ;
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
	glVertex3f(FTR.x-(width/2.5),FTR.y-1.5,FTR.z-3);
	glTexCoord2d(1,0);
	glVertex3f(FTR.x-(width/2.5),FTR.y-height,FTR.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-height,FTR.z-3);
	glTexCoord2d(0,1);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-1.5,FTR.z-3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
			glBegin(GL_QUADS);
			glTexCoord2d(0,0);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-height,FTR.z-3);
	glTexCoord2d(1,0);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-1.5,FTR.z-3);
	glTexCoord2d(1,1);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-1.5,FTR.z-0.5);
	glTexCoord2d(0,1);
	glVertex3f(FTR.x-(width/(width/6)),FTR.y-height,FTR.z-0.5);
		glEnd();
		
		
		//Chair
		glBindTexture(GL_TEXTURE_2D , faceChair); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
		glBegin(GL_QUADS);	
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+0.5);
		glEnd();
		
		glBegin(GL_QUADS);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , faceChair); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8-0.2),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8-0.2),FTL.y-(height/1.2),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+2.8);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+2.8);
		glEnd();
		//table
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glEnd();	
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+2.8);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.35),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+2.8);
		glEnd();
			glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glPushMatrix();
		glTranslated(width/2,0,0);
		glBindTexture(GL_TEXTURE_2D , faceChair); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
		glBegin(GL_QUADS);	
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glBindTexture(GL_TEXTURE_2D , Wood2) ; 
		glEnd();
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.7),FTL.z-depth+0.5);
		glEnd();
		
		glBegin(GL_QUADS);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , faceChair); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/(width-1.5)),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.225),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8-0.2),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8-0.2),FTL.y-(height/1.2),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+2.8);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8),FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin(GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/0.9),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+0.7,FTL.y-(height/1.2),FTL.z-depth+2.8);
		glEnd();
		//table
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glEnd();	
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.4),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+2.8);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.35),FTL.z-depth+3);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+3);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+3);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+2.8);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+2.8);
		glEnd();
			glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.01),FTL.z-depth+0.7);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+6),FTL.y-(height/1.35),FTL.z-depth+0.7);
		glEnd();
		glBindTexture(GL_TEXTURE_2D , Wood2); 
		glBegin (GL_QUADS);
		glTexCoord2d(0,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glTexCoord2d(1,0);
		glVertex3f(FTL.x+(width/8+1),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(1,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.01),FTL.z-depth+0.5);
		glTexCoord2d(0,1);
		glVertex3f(FTL.x+(width/8+1+0.2),FTL.y-(height/1.35),FTL.z-depth+0.5);
		glEnd();
		glPopMatrix();


	//Front windows
	
	glColor4f(0 , 0 , 1 , 0.5);
	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x-width/10, FTR.y-height/3, FTR.z);
	
	glVertex3f(FTR.x-width, FTR.y-height/3 , FTR.z);
	
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	
	glVertex3f(FTR.x-width/10, FTR.y-(height/1.4), FTR.z);

	
	glEnd(); 
	draw_windows(FTR , width , height , depth) ; 
	
	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}

void ConnectorCarrige(Point FTR , float width  , float height ,  float depth , float carrigedepth )
{
	
	//front bottom
	glBindTexture(GL_TEXTURE_2D , trainwall) ; 
	glBegin(GL_QUADS); 
	
	glTexCoord2d(1 , 1 ); 
	glVertex3f(FTR.x  , FTR.y-(height/1.4), FTR.z);
	glTexCoord2d(0 , 1 ); 
	
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);

	glTexCoord2d(0 , 0 ); 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);


	glTexCoord2d(1 , 0 ); 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	glEnd();

	//front bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS); 
	
	glTexCoord2d( 1 , 0 ) ;
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	glTexCoord2d( 0, 0  );
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z);
	
	glTexCoord2d(0, 1  ); 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	
	
	glEnd(); 

	
	//back bottom
	glBindTexture(GL_TEXTURE_2D ,trainwall) ; 
	glBegin(GL_QUADS);
	
	glTexCoord2d(1 ,3 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glTexCoord2d(1, 0  ) ;
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 0 ) ;
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	glTexCoord2d(0, 3 ) ;
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 

	
	
	//back bottom inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	  
	glTexCoord2d( 0 ,1 ) ; 
	glVertex3f(FTR.x-width, FTR.y-(height/1.4), FTR.z-depth);

	glTexCoord2d( 0 ,0 ) ; 
	glVertex3f(FTR.x - width , FTR.y-height, FTR.z-depth);
	
	
	glTexCoord2d( 1 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z-depth);
	
	glTexCoord2d( 1 ,1 ) ; 
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	
	glEnd(); 
	
	
    //top
	//glBindTexture(GL_TEXTURE_2D) ; 
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x, FTR.y, FTR.z);
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	glVertex3f(FTR.x-width , FTR.y , FTR.z);

		
	glEnd();
	
	//top inside
	
	glBindTexture(GL_TEXTURE_2D , wall) ;
	glBegin(GL_QUADS);
	
	glTexCoord2d(0 ,0);
	glVertex3f(FTR.x-width , FTR.y , FTR.z);
	
	glTexCoord2d(0 , 1);
	glVertex3f(FTR.x - width , FTR.y, FTR.z-depth);
	
	glTexCoord2d(1 , 1);
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glTexCoord2d(1,0);
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
		
	glEnd();
	
	//bottom

	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glEnd(); 

	//bottom inside
	glBindTexture(GL_TEXTURE_2D , carpet ); 

	glBegin(GL_QUADS);
	glTexCoord2d(3 ,3 ) ; 
	glVertex3f(FTR.x, FTR.y - height, FTR.z-depth);

	glTexCoord2d(0 , 3 ) ; 
	glVertex3f(FTR.x - width , FTR.y- height, FTR.z-depth);

	glTexCoord2d(0 ,0 ) ; 
	glVertex3f(FTR.x-width , FTR.y - height, FTR.z);

		
	glTexCoord2d(3 ,0 ) ; 
	glVertex3f(FTR.x, FTR.y-height, FTR.z);
	
	

	glEnd();
	
	//Front windows
	
	glColor4f(0 , 0 , 1 , 0.5);
	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width, FTR.y , FTR.z);
	
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);

	
	glEnd(); 

	//front windows inside 

	glBindTexture(GL_TEXTURE_2D ,white); 
	
	glBegin(GL_QUADS);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z);
	glVertex3f(FTR.x-width, FTR.y , FTR.z);
	glVertex3f(FTR.x, FTR.y, FTR.z);
	
	glEnd(); 

	//Back windows
	glBegin(GL_QUADS);
	
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x-width, FTR.y , FTR.z-depth);
	
	glEnd(); 
	
	
	//back windows inside 
	glBegin(GL_QUADS);
	glVertex3f(FTR.x-width, FTR.y , FTR.z-depth);
	glVertex3f(FTR.x - width , FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y-(height/1.4), FTR.z-depth);
	glVertex3f(FTR.x, FTR.y, FTR.z-depth);
	
	glEnd(); 
	
	

	
	glDisable(GL_CULL_FACE); 
	//Lines
	
	
	
	glColor4f(0.75,0.75,0.83 , 1) ; 
		
	glLineWidth(5) ;
	
	glBegin(GL_LINES) ; 
	glVertex3f(FTR.x-width/5, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z);

	glVertex3f(FTR.x-width/3, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z);


	
	glVertex3f(FTR.x-width/2, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z);


	glVertex3f(FTR.x-width/1.5, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z);

	
	glVertex3f(FTR.x-width/1.2, FTR.y, FTR.z);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z);

	
	
	glVertex3f(FTR.x-width/5, FTR.y, FTR.z-depth);
	
	glVertex3f(FTR.x-width/5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/3, FTR.y, FTR.z-depth);
	
	glVertex3f(FTR.x-width/3 ,  FTR.y-(height/1.4), FTR.z-depth);


	
	glVertex3f(FTR.x-width/2, FTR.y, FTR.z-depth);
	
	glVertex3f(FTR.x-width/2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.5, FTR.y, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.5 ,  FTR.y-(height/1.4), FTR.z-depth);


	glVertex3f(FTR.x-width/1.2, FTR.y, FTR.z-depth);
	
	glVertex3f(FTR.x-width/1.2 ,  FTR.y-(height/1.4), FTR.z-depth);


	glEnd() ;

	glEnable(GL_CULL_FACE); 
	
	glColor4f(1 ,1,1,1) ;
	
}


int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	
	//Enable Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	
	//Enable Texture 
	glEnable(GL_TEXTURE_2D) ;  
	glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S ,GL_REPEAT)  ; 
	glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S ,GL_REPEAT) ;
   
	//Enable Cull Face
	glEnable(GL_CULL_FACE);
	
	loadimage(); 
	loadmodel() ;
	First_Person_Shooter = Camera();

	First_Person_Shooter.Position.x =  FTR_First_Carriage.x - 15 ; 
	First_Person_Shooter.Position.y =  FTR_First_Carriage.y - 6 ;
	First_Person_Shooter.Position.z =  FTR_First_Carriage.z - 7  ;
	//PlaySound("sound\\TRAIN Sound Effects - Steam Train Start and Whistle.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
	
	return TRUE;										// Initialization Went OK
}

void makeHouse(float house_x,float house_y,float house_z,float house_rotate,float house_scale){
	
	//Grass Left
	glBindTexture(GL_TEXTURE_2D,hgrass);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-3, 0, 3);
	glTexCoord2d(1,0);
	glVertex3d(-3, 1, 3);
	glTexCoord2d(1,1);
	glVertex3d(-3, 1, -3);
	glTexCoord2d(0,1);
	glVertex3d(-3, 0, -3);
	glEnd();
	//Grass Right
	glBindTexture(GL_TEXTURE_2D,hgrass);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(3, 0, 3);
	glTexCoord2d(1,0);
	glVertex3d(3, 1, 3);
	glTexCoord2d(1,1);
	glVertex3d(3, 1, -3);
	glTexCoord2d(0,1);
	glVertex3d(3, 0, -3);
	glEnd();
	//Grass Back
	glBindTexture(GL_TEXTURE_2D,hgrass);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-3, 0, -3);
	glTexCoord2d(1,0);
	glVertex3d(-3, 1, -3);
	glTexCoord2d(1,1);
	glVertex3d(3, 1, -3);
	glTexCoord2d(0,1);
	glVertex3d(3, 0, -3);
	glEnd();
	//Grass Front Left
	glBindTexture(GL_TEXTURE_2D,hgrass);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-3, 0, 3);
	glTexCoord2d(1,0);
	glVertex3d(-3, 1, 3);
	glTexCoord2d(1,1);
	glVertex3d(-1, 1, 3);
	glTexCoord2d(0,1);
	glVertex3d(-1, 0, 3);
	glEnd();
	//Grass Front Right
	glBindTexture(GL_TEXTURE_2D,hgrass);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(3, 0, 3);
	glTexCoord2d(1,0);
	glVertex3d(3, 1, 3);
	glTexCoord2d(1,1);
	glVertex3d(1, 1, 3);
	glTexCoord2d(0,1);
	glVertex3d(1, 0, 3);
	glEnd();
	//Name
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3d(1, 0, 0);
	glVertex3d(2, 0, 3.5);
	glVertex3d(2, 0.8, 3.5); 
	glEnd();
	glBindTexture(GL_TEXTURE_2D,hwelcome);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(1.5, 0.8, 3.5);
	glTexCoord2d(1,0);
	glVertex3d(2.5, 0.8, 3.5);
	glTexCoord2d(1,1);
	glVertex3d(2.5, 1.3, 3.5);
	glTexCoord2d(0,1);
	glVertex3d(1.5, 1.3, 3.5);
	glEnd();
	//front wall
	glBindTexture(GL_TEXTURE_2D,hwalls);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2, 0, 2);
	glTexCoord2d(1,0);
	glVertex3d(2, 0, 2);
	glTexCoord2d(1,1);
	glVertex3d(2, 2, 2);
	glTexCoord2d(0,1);
	glVertex3d(-2, 2, 2);
	glEnd();
	//Door
	glBindTexture(GL_TEXTURE_2D,hdoor);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-0.5, 0, 2);
	glTexCoord2d(1,0);
	glVertex3d(0.5, 0, 2);
	glTexCoord2d(1,1);
	glVertex3d(0.5, 1.3, 2);
	glTexCoord2d(0,1);
	glVertex3d(-0.5, 1.3, 2);
	glEnd();
	//Right Window
	glBindTexture(GL_TEXTURE_2D,hwindow);
	glBegin(GL_QUADS);
	glColor3d(1 , 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(1, 1, 2);
	glTexCoord2d(1,0);
	glVertex3d(1.5, 1, 2);
	glTexCoord2d(1,1);
	glVertex3d(1.5, 1.5, 2);
	glTexCoord2d(0,1);
	glVertex3d(1, 1.5, 2);
	glEnd();
	//Left Window
	glBindTexture(GL_TEXTURE_2D,hwindow);
	glBegin(GL_QUADS);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-1, 1, 2);
	glTexCoord2d(1,0);
	glVertex3d(-1.5, 1, 2);
	glTexCoord2d(1,1);
	glVertex3d(-1.5, 1.5, 2);
	glTexCoord2d(0,1);
	glVertex3d(-1, 1.5, 2);
	glEnd();
	//Right wall
	glBindTexture(GL_TEXTURE_2D,hwalls);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(2, 0, 2);
	glTexCoord2d(1,0);
	glVertex3d(2, 0, -2);
	glTexCoord2d(1,1);
	glVertex3d(2, 2, -2);
	glTexCoord2d(0,1);
	glVertex3d(2, 2, 2);
	glEnd();
	//Left wall
	glBindTexture(GL_TEXTURE_2D,hwalls);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2, 0, 2);
	glTexCoord2d(1,0);
	glVertex3d(-2, 0, -2);
	glTexCoord2d(1,1);
	glVertex3d(-2, 2, -2);
	glTexCoord2d(0,1);
	glVertex3d(-2, 2, 2);
	glEnd();
	//Back 
	glBindTexture(GL_TEXTURE_2D,hwalls);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2, 0, -2);
	glTexCoord2d(1,0);
	glVertex3d(2, 0, -2);
	glTexCoord2d(1,1);
	glVertex3d(2, 2, -2);
	glTexCoord2d(0,1);
	glVertex3d(-2, 2, -2);
	glEnd();
	//Roof Front
	glBindTexture(GL_TEXTURE_2D,hroof);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2.2, 1.8, 2.2);
	glTexCoord2d(1,0);
	glVertex3d(2.2, 1.8, 2.2);
	glTexCoord2d(0.5,0.5);
	glVertex3d(0, 4,0);
	glEnd();
	//Roof Back
	glBindTexture(GL_TEXTURE_2D,hroof);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2.2, 1.8, -2.2);
	glTexCoord2d(1,0);
	glVertex3d(2.2, 1.8, -2.2);
	glTexCoord2d(0.5,0.5);
	glVertex3d(0, 4, 0);
	glEnd();
	//Roof Right
	glBindTexture(GL_TEXTURE_2D,hroof);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(2.2, 1.8, 2.2);
	glTexCoord2d(0,1);
	glVertex3d(2.2, 1.8, -2.2);
	glTexCoord2d(0.5,0.5);
	glVertex3d(0, 4, 0);
	glEnd();
	//Pipe
	glBindTexture(GL_TEXTURE_2D,hpip);
	glBegin(GL_POLYGON);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(1, 0, 1);
	glTexCoord2d(1,0);
	glVertex3d(1.5, 0, 1);
	glTexCoord2d(1,1);
	glVertex3d(1.5, 0, 0.5);
	glTexCoord2d(0,1);
	glVertex3d(1, 0, 0.5);

	glVertex3d(1, 4, 0.5); 
	glVertex3d(1.5, 4, 0.5);
	glVertex3d(1.5, 4, 1);
	glVertex3d(1, 4, 1);
	glVertex3d(1, 4, 0.5);
	glEnd();
	//Roof Left
	glBindTexture(GL_TEXTURE_2D,hroof);
	glBegin(GL_TRIANGLES);
	glColor3d(1, 1, 1);
	glTexCoord2d(0,0);
	glVertex3d(-2.2, 1.8, 2.2);
	glTexCoord2d(0,1);
	glVertex3d(-2.2, 1.8, -2.2);
	glTexCoord2d(0.5,0.5);
	glVertex3d(0, 4, 0);
	glEnd();



}

float xtrain = 0  ; 
void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();					// Reset The Current Modelview Matrix
	 
	
	if(xtrain <= 1800)
	{
		xtrain += 1  ;
		First_Person_Shooter.Position.x +=1 ; 
 	}
	else
	{
		if(keys[VK_SPACE])
		{
			xtrain = 0 ; 
			First_Person_Shooter.Position.x =  -1850 - 15 ; 
			First_Person_Shooter.Position.y =  -70 - 6;
			First_Person_Shooter.Position.z =  -25 - 7 ;
	
		}
	}

	FTR_First_Carriage = Point ( -1850 + xtrain ,-70 ,-25) ;


	
	
	float Train_Points_Collision[20] ; 
	
	Train_Points_Collision[0] = FTR_First_Carriage.x -30 ;
	Train_Points_Collision[1] = FTR_First_Carriage.x  ;
	Train_Points_Collision[2] = FTR_First_Carriage.x + 6 ;
	Train_Points_Collision[3] = FTR_First_Carriage.x + 36;
	Train_Points_Collision[4] = FTR_First_Carriage.x + 42 ;
	Train_Points_Collision[5] = FTR_First_Carriage.x + 72 ;
	Train_Points_Collision[6] = FTR_First_Carriage.x + 78;
	Train_Points_Collision[7] = FTR_First_Carriage.x + 108 ;
	Train_Points_Collision[8] = FTR_First_Carriage.x + 114 ;
	Train_Points_Collision[9] = FTR_First_Carriage.x + 144;
	Train_Points_Collision[10] = FTR_First_Carriage.x + 150 ;
	Train_Points_Collision[11] = FTR_First_Carriage.x + 180 ;
	Train_Points_Collision[12] = FTR_First_Carriage.x + 186;
	Train_Points_Collision[13] = FTR_First_Carriage.x + 216 ;
	Train_Points_Collision[14] = FTR_First_Carriage.x + 222 ;
	Train_Points_Collision[15] = FTR_First_Carriage.x + 252 ;
	Train_Points_Collision[16] = FTR_First_Carriage.x + 258;
	Train_Points_Collision[17] = FTR_First_Carriage.x + 288 ;
	Train_Points_Collision[18] = FTR_First_Carriage.x + 294 ;
	Train_Points_Collision[19] = FTR_First_Carriage.x + 324 ;

	CameraKeyboardControl(Train_Points_Collision);
		
	
	glPushMatrix() ; 
	glDisable(GL_CULL_FACE) ; 
	
	glTranslated(0 , 0 , -87.5); 
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();
	glTranslated(0,5.7,0);
	Skybox1();//----------------------------------------------------------------------Sky Box 1
	//makeBuilding();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-780,5.7,0);
	Skybox2();//----------------------------------------------------------------------Sky Box 2
	//makeBuilding();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-1560,5.7,0);
	Skybox3();//----------------------------------------------------------------------Sky Box 3
	glPopMatrix();
	//--------------------------------------------------------City
		//First Line Building
	glPushMatrix();
	glScaled(5.5,8,9.5);
	glTranslated(-220,-4,10); //130 //330
	makeBuilding3();
	glPopMatrix();


	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-230,-5,10);//115
	makeBuilding1();
	glPopMatrix();


	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-250,-5,10);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-260,-5,10);
	makeBuilding3();
	glPopMatrix();
	

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-270,-5,10);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-290,-5,10);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-300,-5,10);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-310,-5,10);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-325,-5,10);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-345,-5,10);
	makeBuilding3();
	glPopMatrix();
	
	
	// Second Line Building
	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-220,-5,15); //220 --- 330
	makeBuilding1();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-235,-5,17);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-250,-5,15);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-265,-5,19);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-280,-5,17);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-295,-5,15);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-315,-5,20);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-335,-5,16);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-340,-5,16);
	makeBuilding3();
	glPopMatrix();

	// Third Line Building
	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-220,-3,24);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-250,-3,26);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-280,-3.3,22);
	makeBuilding1();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9.5,9.5);
	glTranslated(-310,-2.5,27);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9.5,9.5);
	glTranslated(-325,-2,25);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,10,9.5);
	glTranslated(-335,-2,26);
	makeBuilding3();
	glPopMatrix();
	/*--------------------Right---------------------*/
	//First Line Building
	glPushMatrix();
	glScaled(5.5,8,9.5);
	glTranslated(-220,-4,2); //130 //330
	makeBuilding3();
	glPopMatrix();


	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-230,-5,2);//115
	makeBuilding1();
	glPopMatrix();


	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-250,-5,2);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-260,-5,2);
	makeBuilding3();
	glPopMatrix();
	

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-270,-5,2);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-290,-5,2);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-300,-5,2);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-310,-5,2);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-325,-5,2);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-345,-5,2);
	makeBuilding3();
	glPopMatrix();
	
	
	// Second Line Building
	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-220,-5,-15); //220 --- 330
	makeBuilding1();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-235,-5,-17);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-250,-5,-10);
	makeBuilding2();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-265,-5,-13);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-280,-5,-18);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-295,-5,-16);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-315,-5,-20);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-335,-5,-22);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,7.5,9.5);
	glTranslated(-340,-5,-19);
	makeBuilding3();
	glPopMatrix();

	// Third Line Building
	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-220,-3,-24);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-250,-3,-25);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9,9.5);
	glTranslated(-280,-3.3,-17);
	makeBuilding1();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9.5,9.5);
	glTranslated(-310,-2.5,-20);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,9.5,9.5);
	glTranslated(-325,-2,-23);
	makeBuilding3();
	glPopMatrix();

	glPushMatrix();
	glScaled(5.5,10,9.5);
	glTranslated(-335,-2,-18);
	makeBuilding3();
	glPopMatrix();
	
	//--------------------------------------------------------Forest
	//first
	makeTree(-400,-84,0,180,4.5);
	makeTree(-500,-84,0,180,5.5);
	makeTree(-700,-84,0,180,5.5);
	makeTree(-800,-84,0,180,4.5);
	makeTree(-900,-84,0,180,5.5);
	makeTree(-1050,-84,0,180,5.5);
	
	//second
	makeTree(-450,-84,-100,180,6.5);
	makeTree(-550,-84,-80,180,6.5);
	makeTree(-650,-84,-50,180,6.5);
	makeTree(-750,-84,-60,180,6.5);
	makeTree(-850,-84,-40,180,6.5);
	makeTree(-950,-84,-50,180,6.5);
	
		//third
	makeTree(-450,-84,-200,180,8.5);
	makeTree(-600,-84,-180,180,9);
	makeTree(-700,-84,-220,180,7.5);
	makeTree(-850,-84,-230,180,7.5);
	makeTree(-950,-84,-230,180,8.5);
	makeTree(-1060,-84,-230,180,8.5);

	//-------------------------------------------Left
	
	glPushMatrix();
	glScaled(18,18,18);
	glTranslated(-60,-4.5,12);
	glRotated(180,0,1,0);
	makeHouse(-950,-84,175,180,0.03);
	glPopMatrix();

	
	glPushMatrix();
	glScaled(18,18,18);
	glTranslated(-46,-4.5,12);
	glRotated(180,0,1,0);
	makeHouse(-500,-84,175,180,0.03);
	glPopMatrix();

	
	glPushMatrix();
	glScaled(18,18,18);
	glTranslated(-32,-4.5,12);
	glRotated(180,0,1,0);
	makeHouse(-500,-84,175,180,0.03);
	glPopMatrix();
	makeTree(-600,-84,150,0,9);
	makeTree(-750,-84,150,0,9);
	makeTree(-550,-84,80,0,4);
	makeTree(-800,-84,80,0,4);
	makeTree(-1000,-84,80,0,4);
	////-----------------------------------------------------Desert
	makeTower(-350,-94,-250,0,14);
	makeTower(350,-94,-250,0,14);
	makeTower(-350,-94,250,0,14);
	makeTower(350,-94,250,0,14);
	makeStation(0,-84,110,-197.5,0.009);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	glPopMatrix() ;
	
	//Carriage 1
	glEnable(GL_CULL_FACE) ; 
	Library_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	
	Point Connector_Carriage_Point = Point ( FTR_First_Carriage.x+6, FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 

	
	//Carriage 2
	FTR_First_Carriage.x += 36 ; 
	Passenger_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	



	//Carriage 3
	FTR_First_Carriage.x += 36 ; 
	bedroom_Carriage(FTR_First_Carriage , 30 , 10 , 13) ;
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ;
	
	
	//Carriage 4
	FTR_First_Carriage.x += 36 ; 
	Kitchen_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	

	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	

	
	//Carriage 5
	FTR_First_Carriage.x += 36 ; 
	
	Food_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 

	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 

	
	//Carriage6
	FTR_First_Carriage.x += 36 ; 
	Passenger_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	
	
	//Carriage 7
	FTR_First_Carriage.x += 36 ; 
	Food_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	
	
	//Carriage 8
	FTR_First_Carriage.x += 36 ; 
	bedroom_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	
	
	//Carriage 9
	FTR_First_Carriage.x += 36 ; 
	Library_Carriage(FTR_First_Carriage , 30 , 10 , 13) ; 
	
	Connector_Carriage_Point = Point (FTR_First_Carriage.x+6 , FTR_First_Carriage.y  - 4, FTR_First_Carriage.z-4.3) ;
	ConnectorCarrige(Connector_Carriage_Point , 6 , 6 , 4.3 , 13 ) ; 
	

	//CarriageDriver 
	FTR_First_Carriage.x += 36 ; 
	DriverCarriage(FTR_First_Carriage , 30 , 10 ,13 ) ; 
	
	glFlush();	
    
	//Do NOT REMOVE THIS
	SwapBuffers(hDC);			
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL,0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL,NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL,"Release Of DC And RC Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL,"Release Rendering Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		}
		hRC=NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd,hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL,"Release Device Context Failed.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hDC=NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL,"Could Not Release hWnd.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hWnd=NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL",hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL,"Could Not Unregister Class.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		hInstance=NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
 *	title			- Title To Appear At The Top Of The Window				*
 *	width			- Width Of The GL Window Or Fullscreen Mode				*
 *	height			- Height Of The GL Window Or Fullscreen Mode			*
 *	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
 *	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/
 
BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left=(long)0;			// Set Left Value To 0
	WindowRect.right=(long)width;		// Set Right Value To Requested Width
	WindowRect.top=(long)0;				// Set Top Value To 0
	WindowRect.bottom=(long)height;		// Set Bottom Value To Requested Height

	fullscreen=fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance			= GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc		= (WNDPROC) WndProc;					// WndProc Handles Messages
	wc.cbClsExtra		= 0;									// No Extra Window Data
	wc.cbWndExtra		= 0;									// No Extra Window Data
	wc.hInstance		= hInstance;							// Set The Instance
	wc.hIcon			= LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground	= NULL;									// No Background Required For GL
	wc.lpszMenuName		= NULL;									// We Don't Want A Menu
	wc.lpszClassName	= "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL,"Failed To Register The Window Class.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}
	
	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth	= width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight	= height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel	= bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL,"The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?","NeHe GL",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				fullscreen=FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL,"Program Will Now Close.","ERROR",MB_OK|MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle=WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle=WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle=WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd=CreateWindowEx(	dwExStyle,							// Extended Style For The Window
								"OpenGL",							// Class Name
								title,								// Window Title
								dwStyle |							// Defined Window Style
								WS_CLIPSIBLINGS |					// Required Window Style
								WS_CLIPCHILDREN,					// Required Window Style
								0, 0,								// Window Position
								WindowRect.right-WindowRect.left,	// Calculate Window Width
								WindowRect.bottom-WindowRect.top,	// Calculate Window Height
								NULL,								// No Parent Window
								NULL,								// No Menu
								hInstance,							// Instance
								NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Window Creation Error.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};
	
	if (!(hDC=GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Device Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat=ChoosePixelFormat(hDC,&pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Find A Suitable PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!SetPixelFormat(hDC,PixelFormat,&pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Set The PixelFormat.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC=wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Create A GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if(!wglMakeCurrent(hDC,hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Can't Activate The GL Rendering Context.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd,SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL,"Initialization Failed.","ERROR",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
		case WM_PAINT: 
			DrawGLScene();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
	
		case WM_TIMER:
			DrawGLScene();
			return 0;

		case WM_ACTIVATE:							// Watch For Window Activate Message
		{
			if (!HIWORD(wParam))					// Check Minimization State
			{
				active=TRUE;						// Program Is Active
			}
			else
			{
				active=FALSE;						// Program Is No Longer Active
			}

			return 0;								// Return To The Message Loop
		}

		case WM_SYSCOMMAND:							// Intercept System Commands
		{
			switch (wParam)							// Check System Calls
			{
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
				return 0;							// Prevent From Happening
			}
			break;									// Exit
		}

		case WM_CLOSE:								// Did We Receive A Close Message?
		{
			PostQuitMessage(0);						// Send A Quit Message
			return 0;								// Jump Back
		}

		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
			keys[wParam] = TRUE;					// If So, Mark It As TRUE
			return 0;								// Jump Back
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
			keys[wParam] = FALSE;					// If So, Mark It As FALSE
			return 0;								// Jump Back
		}

		case WM_SIZE:								// Resize The OpenGL Window
		{
			ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));  // LoWord=Width, HiWord=Height
			return 0;								// Jump Back
		}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
					HINSTANCE	hPrevInstance,		// Previous Instance
					LPSTR		lpCmdLine,			// Command Line Parameters
					int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done=FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen=FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Madhat NeHe Template",640,480,16,fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer=SetTimer(hWnd,0,50,(TIMERPROC) NULL);

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
			TranslateMessage(&msg);	
			DispatchMessage(&msg);
	}

	return 0;

}