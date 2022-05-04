#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <thread>
#include <chrono>


using namespace sf;
using namespace std;

int N=31,M=21;
int size=16;
int w = size*N;
int h = size*M;
// sanke
int dir,num=4; 
// luu diem 
int _Score=0;
int valueFood = 10;
int level = 3, oldLevel = 3;
float delay = 0.1;
//
bool endGame = false;
bool isPlaying = false;
bool b_level = false;
bool b_map = false;
bool b_classic = true;
bool b_highScore = false;
bool classic = true;
bool modern = false;
bool b_sEat = false;
//
struct Snake 
{ int x,y;}  s[100];

struct Fruit
{ int x,y;} f;

struct tuong
{ int x, y; } tg; 

struct highscore
{ int highScore = 0; string ten; } diem;

void Tick();
void fEndgame();
void Class();
void randomSnake();
void randomFood();
void fmodern();
void HandleMouseClick( int x, int y);
void fHighScore();
void fValueFood();

int main()
{  
  	srand(time(0));
	// tao 1 cua so hinh anh
  	RenderWindow window(VideoMode(w,(M+3)*size), "GAME SNAKE");
  	
  	// random vi tri ban dau cua food va snake;
  	randomSnake();
  	randomFood();
  	fValueFood();
  	fHighScore();
  	// do nhanh cham cua ran
  	Clock clock;
  	float timer = 0;
  	
  	// tao hinh anh ;
  	Texture t1, t2, t3, t4, t6, t7, t8, t9;
  	Texture l1, l2, l3, l4, l5;
  	
  	t1.loadFromFile("images/red.png");
  	t2.loadFromFile("images/green.png");
  	t3.loadFromFile("images/white.png");
  	t4.loadFromFile("images/sankeMenu.jpg");
  	t6.loadFromFile("images/snakeHighScore.jpg");
  	t7.loadFromFile("images/snakeBg.png");
  	t8.loadFromFile("images/snakeMap1.jpg");
  	t9.loadFromFile("images/snakeMap2.jpg");
  	
  	l1.loadFromFile("images/snakeLevel1.jpg");
  	l2.loadFromFile("images/snakeLevel2.jpg");
  	l3.loadFromFile("images/snakeLevel3.jpg");
  	l4.loadFromFile("images/snakeLevel4.jpg");
  	l5.loadFromFile("images/snakeLevel5.jpg");
  	
  	Sprite sprite1(t1);
  	Sprite sprite2(t2);
  	Sprite sprite3(t3);
  	//
  	Sprite imageMenu(t4);
  	Sprite imageHighScore(t6);
  	Sprite imageBg(t7);
  	//
  	Sprite imageMap1(t8);
  	Sprite imageMap2(t9);
  	//
  	Sprite imageLevel1(l1);
  	Sprite imageLevel2(l2);
  	Sprite imageLevel3(l3);
  	Sprite imageLevel4(l4);
  	Sprite imageLevel5(l5);
  	
// file sound
	SoundBuffer soundEat, soundEnd, soundDirection, soundCongratulation;
	
	soundEat.loadFromFile("sound/soundSnakeEat.wav");
	soundEnd.loadFromFile("sound/soundSnakeGameOver.wav");
	soundDirection.loadFromFile("sound/soundSnakeDirection.wav");
	soundCongratulation.loadFromFile("sound/soundSnakeCongratulation.wav");
	
	Sound sEat, sEnd, sDirection, sCongratulation;
	
	sEat.setBuffer(soundEat);
	sEnd.setBuffer(soundEnd);
	sDirection.setBuffer(soundDirection);
	sCongratulation.setBuffer(soundCongratulation);

	// tao phong chu
  	Font font;
  	if( !font.loadFromFile("VAGRB.TTF") ) return EXIT_FAILURE;
  	//Pick Color
  	Color colorYourScore(42, 184, 20);
  	Color colorNewHighScore(244, 45, 247);
  	
  	// text Game Over ;
  	Text t_GameOver;
  	
  	t_GameOver.setFont(font);
  	t_GameOver.setPosition(110, 110);
  	t_GameOver.setFillColor(Color::Red);
  	t_GameOver.setCharacterSize(50);
  	t_GameOver.setString("Game Over!");	
  	// text luu diem so;
  	
	Text s_score, t_score;
  	s_score.setFont(font);
  	s_score.setPosition(5*size,22*size );
  	s_score.setFillColor(Color::Red);
  	s_score.setCharacterSize(24);
	// ----
  	t_score.setFont(font);
  	t_score.setPosition(0, 22*size);
  	t_score.setFillColor(Color::Red);
  	t_score.setCharacterSize(24);
  	t_score.setString("Score: ");
  	
  	// text New High Score
  	Text textNewHighScore;
  	
  	textNewHighScore.setFont(font);
  	textNewHighScore.setPosition(90, 150);
  	textNewHighScore.setFillColor(colorNewHighScore);
  	textNewHighScore.setCharacterSize(35);
  	
  	// text highscore;
  	Text t_highScore;
  	t_highScore.setFont(font);
  	t_highScore.setPosition(280, 130);
  	t_highScore.setFillColor(Color::Red);
  	t_highScore.setCharacterSize(32);
  	// text Your Score
  	Text t_yourScore;
  	t_yourScore.setFont(font);
  	t_yourScore.setPosition(145, 180);
  	t_yourScore.setFillColor(colorYourScore);
  	t_yourScore.setCharacterSize(32);
  	

  	// 
  	while(window.isOpen()){
  		// setting do nhanh cham cua ran
  		float time = clock.getElapsedTime().asSeconds();
  		clock.restart();
  		timer+=time;
  		
  		// tao su kien
  		Event event;
  		while(window.pollEvent(event)){
  			if(isPlaying==false && event.type == sf::Event::MouseButtonPressed)
                
			{
				if(event.mouseButton.button == Mouse::Left)
				{	
					HandleMouseClick( event.mouseButton.x, event.mouseButton.y);
				}
			} 

            else if (event.type == sf::Event::Closed)
                window.close();
		  }
		
		window.clear(Color::Yellow);
		
		if(isPlaying==true){
			
			if (Keyboard::isKeyPressed(Keyboard::Left)){ dir=1; }
			if (Keyboard::isKeyPressed(Keyboard::Right)) { dir=2;}   
			if (Keyboard::isKeyPressed(Keyboard::Up)) { dir=3; }
			if (Keyboard::isKeyPressed(Keyboard::Down)) { dir=0; }
	
			if(timer>delay) {
				
				timer = 0;
				Tick();
				if(b_sEat == true) {
					sEat.play();
					b_sEat = false;
				}
				fEndgame();

			}
			if(endGame)
			{	
				randomSnake();
				randomFood(); 
				// sound gameOver;
				sEnd.play();
				//
				endGame=false;
				isPlaying=false;
					
				window.draw(t_GameOver);
				
				t_yourScore.setString("Your Score: " + to_string(_Score));
				window.draw(t_yourScore);
				
				window.display();
				this_thread::sleep_for(chrono::milliseconds(3000));
				
				if(_Score > diem.highScore)
				{
					window.clear(Color::Yellow);
					
					fHighScore();
					textNewHighScore.setString("New High Score: " + to_string(_Score));
					window.draw(textNewHighScore);
					sCongratulation.play();
					window.display();
					this_thread::sleep_for(chrono::milliseconds(2000));
				}
			
				
				_Score=0;
			}
		}
		
		if( isPlaying==true && b_level==false && b_highScore==false && b_map==false) 
		{
	
			//draw hinh anh 
			window.draw(imageBg);	 
			if(modern==true && classic==false){
				for(int i=0;i<w;i+=16)
					for(int j=0;j<h;j+=16)
					{
						if(i==0 || j==0 || i==(N-1)*16 || j==(M-1)*16){
	 						sprite3.setPosition(i,j);
	 						window.draw(sprite3);
		 				}			 
			    	}
			}
			// ve hoa qua	
		 	sprite1.setPosition(f.x*size, f.y*size);  window.draw(sprite1);
			// ve snake
			for (int i=0;i<num;i++)
		    { sprite2.setPosition(s[i].x*size, s[i].y*size);  window.draw(sprite2); }
		 	// ve score
		 	s_score.setString(to_string(_Score)); // update score
			window.draw(t_score);
		 	window.draw(s_score);
		}

		if(isPlaying==false && b_map==true  && b_level==false && b_highScore==false ){
			if(classic == true && modern == false)
			{ 
				window.draw(imageMap1);
			}
			if(classic == false && modern == true)
			{
				window.draw(imageMap2);
			}
		} 
		if(isPlaying==false && b_level==false && b_highScore==false && b_map==false){		
			window.draw(imageMenu);
		}
		if(isPlaying==false && b_level==true && b_highScore==false && b_map==false){
			switch(level)
			{
				case 1:
				{ window.draw(imageLevel1); break; }
				case 2:
				{ window.draw(imageLevel2); break; }
				case 3:
				{ window.draw(imageLevel3); break; }
				case 4:
				{ window.draw(imageLevel4); break; }
				case 5:
				{ window.draw(imageLevel5); break; }
			}
		}
		if(isPlaying==false && b_level==false && b_highScore==true && b_map==false){
			t_highScore.setString(to_string(diem.highScore));
			window.draw(imageHighScore);
			window.draw(t_highScore);
		}
		// hien thi len window;
 		window.display();
		  
	}

    return 0;
}

////////////////////////////////////////////////////////////

void HandleMouseClick( int x, int y)
{
// play;
    if( ( x >= 236  && x <= 408)  && (y >=24 && y <= 72) )
    {
    	isPlaying = true;
    }
	
// map
	if( ( x >= 236  && x <= 408)  && (y >= 120 && y <= 168) )
    {
    	b_map = true;
    }
    if(b_map==true){
    	//classic
    	if( ( x >= 236  && x <= 408)  && (y >=48 && y <= 144) )
    	{
    		classic = true;
    		modern = false;
    		fValueFood(); 	
    	}
    	//modern
    	if( ( x >= 236  && x <= 408)  && (y >= 240 && y <= 336) )
    	{
    		classic = false;
    		modern = true;
    		fValueFood();
    	}
    	// back menu
    	if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
			b_map = false;
		}
	}

// highScore
	if( ( x >= 236  && x <= 408)  && (y >=312 && y <= 360) )
    {
    	b_highScore = true;
    }
    // tro lai menu-highScore
    if(b_highScore == true){
    	if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
			b_highScore = false;
		}
	}

// level
    if(( x >=236  && x <= 408) && (y >= 216 && y <= 264)){
    	b_level = true;
	}
	// chon level
	if( b_level == true){
		//
		
		// level 1
		if(( x >=236  && x <= 408) && (y >= 19 && y <= 57)){
			delay = 0.15;
			level = 1;
			fValueFood();
			isPlaying = false;
		}
		// level 2
		if(( x >=236  && x <= 408) && (y >= 95 && y <= 133)){
			delay = 0.12;
			level = 2;
			fValueFood();
		}
		//level 3
		if(( x >=236  && x <= 408) && (y >= 171 && y <= 209)){
			delay = 0.1;
			level = 3;
			fValueFood();
		}
		// level 4
		if(( x >=236  && x <= 408) && (y >= 247 && y <= 285)){
			delay = 0.07;
			level = 4;
			fValueFood();
		}
		// level 5
		if(( x >=236  && x <= 408) && (y >= 323 && y <= 361)){
			delay = 0.05;
			level = 5;
			fValueFood();
			b_highScore = false;
		}
		// tro lai menu-level
		if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
			b_level = false;
		}
	}

}

void fHighScore()
{
	ifstream readFile;
	readFile.open("highScore.txt");
	
	if(readFile.is_open()){
		while(!readFile.eof()){
			readFile >> diem.highScore;
		}
	}
	readFile.close();
	
	ofstream writeFile("highScore.txt");
	
	if(writeFile.is_open()){
		if(_Score > diem.highScore){
			diem.highScore = _Score;
		}
		writeFile << diem.highScore;
	}
}

void Classic()
 {
 	// che do class 
    if (s[0].x>N-2) s[0].x=1;  if (s[0].x<1) s[0].x=N-2;
    if (s[0].y>M-2) s[0].y=1;  if (s[0].y<1) s[0].y=M-2;
 }
 
  void fEndgame()
 {
     for (int i=1;i<num;i++)
	     if (s[0].x==s[i].x && s[0].y==s[i].y)
		 {
	     	endGame = true;
	     	num=4;
		 }
 }
 
 void fmodern(){
 	
	if(s[0].x==0 || s[0].y==0 || s[0].x==30 || s[0].y==20){
		endGame = true;
	 	num=4;
	}
 }


 void randomSnake(){
 	while(1){
 		s[0].x = rand()%21+5;
 		s[0].y = rand()%11+5;
 		if(s[0].x != 0 && s[0].y != 0 && s[0].x != 30*16 && s[0].y != 20*16) break;
	}
 }
 
void randomFood()
{
	while(1){
		int count=0;
		f.x = rand()%(N-2)+1;
  		f.y = rand()%(M-2)+1;
		for(int i=0;i<num;++i){
			if( s[i].x==f.x && s[i].y==f.y ) count++;
		}
		if(count == 0) break;
	}
}

// ham tick diem
void Tick()
 {
    for (int i=num;i>0;--i)
     {
		 s[i].x=s[i-1].x; 
		 s[i].y=s[i-1].y;
	 }
     
    if ((s[0].x==f.x) && (s[0].y==f.y)) 
    {  	
		num++;
	  	randomFood();
	   	_Score+=valueFood;
	   	b_sEat = true;
	}
	
    if (dir==0) s[0].y+=1; // xuong      
    if (dir==1) s[0].x-=1; // phai      
    if (dir==2) s[0].x+=1; // trai        
    if (dir==3) s[0].y-=1; // len 
    
    if(classic==true && modern==false){
    	Classic();
	}
	if(classic==false && modern==true){
		fmodern();
	}

 }

void fValueFood()
{
	if(modern == true && classic == false){
		switch(level)
		{
			case 1:
				{
					valueFood = 10;
					break;
				}
			case 2:
				{
					valueFood = 13;
					break;
				}
			case 3:
			{
				valueFood = 15;
				break;
			}
			case 4:
			{
				valueFood = 18;
				break;
			}
			case 5:
			{
				valueFood = 20;
				break;
			}
		}
	}
	if(modern == false && classic == true){
		switch(level)
		{
			case 1:
				{
					valueFood = 5;
					break;
				}
			case 2:
				{
					valueFood = 8;
					break;
				}
			case 3:
			{
				valueFood = 10;
				break;
			}
			case 4:
			{
				valueFood = 12;
				break;
			}
			case 5:
			{
				valueFood = 15;
				break;
			}
		}
	}
}

 
 


