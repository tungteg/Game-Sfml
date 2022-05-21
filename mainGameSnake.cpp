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
int dir=2,num=4; 
// luu diem 
int _Score=0;
int valueFood = 10;
int level = 3, oldLevel = 3;
int skin = 1;
float delay = 0.1;
//
bool endGame = false;
bool b_play = false;
bool b_level = false;
bool b_map = false;
bool b_classic = true;
bool b_highScore = false;
bool classic = true;
bool modern = false;
bool b_sEat = false;
bool b_option = false;
bool b_skin = false;
//
struct Snake 
{ int x,y;}  s[600];

struct Food
{ int x,y;} f;

struct tuong
{ int x, y; } wall; 

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
  	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
  	
  	t1.loadFromFile("images/red.png");
  	t2.loadFromFile("images/green.png");
  	t3.loadFromFile("images/white.png");
  	t4.loadFromFile("images/snakeMenu.jpg");
  	t5.loadFromFile("images/snakeOption.jpg");
  	t6.loadFromFile("images/snakeHighScore.jpg");
  	t7.loadFromFile("images/snakeBg.png");
  	t11.loadFromFile("images/newHigh.png");
  	t8.loadFromFile("images/snakeType1.png");
  	t9.loadFromFile("images/snakeType2.png");
  	t10.loadFromFile("images/imageModern1.png");

  	Sprite imageFood(t1);
  	Sprite wallgreen(t2);
  	Sprite wallWhite(t3);
  	Sprite imageNewHighScore(t11);
  	Sprite imageMenu(t4);
  	Sprite imageOption(t5);
  	Sprite imageHighScore(t6);
  	Sprite imageClassic(t7);
  	Sprite imageModern1(t10);
  	Sprite imageType1(t8);
  	Sprite imageType2(t9);
  	//
  	Texture l1, l2, l3, l4, l5;
  	l1.loadFromFile("images/snakeLevel1.jpg");
  	l2.loadFromFile("images/snakeLevel2.jpg");
  	l3.loadFromFile("images/snakeLevel3.jpg");
  	l4.loadFromFile("images/snakeLevel4.jpg");
  	l5.loadFromFile("images/snakeLevel5.jpg");
  	
  	Sprite imageLevel1(l1);
  	Sprite imageLevel2(l2);
  	Sprite imageLevel3(l3);
  	Sprite imageLevel4(l4);
  	Sprite imageLevel5(l5);
  	// 
  	  	
  	Texture s0, s1, s2, s3, s5, s6;
  	s0.loadFromFile("images/snake0.png");
  	s1.loadFromFile("images/snake1.png");
  	s2.loadFromFile("images/snake2.png");
  	s3.loadFromFile("images/snake3.png");
  	s5.loadFromFile("images/snake5.png");
	    	
  	Sprite snake0(s0);
  	Sprite snake1(s1);
  	Sprite snake2(s2);
  	Sprite snake3(s3);
  	Sprite snake5(s5);
  	// 
  	Texture s20, s21, s22, s23, s52;
  	s20.loadFromFile("images/snake20.png");
  	s21.loadFromFile("images/snake21.png");
  	s22.loadFromFile("images/snake22.png");
  	s23.loadFromFile("images/snake23.png");
  	s52.loadFromFile("images/snake52.png");
  	
  	Sprite snake20(s20);
  	Sprite snake21(s21);
  	Sprite snake22(s22);
  	Sprite snake23(s23);
  	Sprite snake52(s52);
  	//
  	
  	Texture sk1, sk2, sk3, sk4;
  	
  	sk1.loadFromFile("images/skin1.jpg");
  	sk2.loadFromFile("images/skin2.jpg");
  	sk3.loadFromFile("images/skin3.jpg");
  	sk4.loadFromFile("images/skin4.jpg");
  	
  	Sprite imageSkin1(sk1);
  	Sprite imageSkin2(sk2);
  	Sprite imageSkin3(sk3);
  	Sprite imageSkin4(sk4);
  	
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
//Pick Color
  	Color colorYourScore(42, 184, 20);
  	Color colorNewHighScore(244, 45, 247);
  	Color colorBackgroud(206, 245, 66);
  	
// fornt chu
  	Font font;
  	if( !font.loadFromFile("VAGRB.TTF") ) return EXIT_FAILURE;
 
  	
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
	// ---
  	t_score.setFont(font);
  	t_score.setPosition(0, 22*size);
  	t_score.setFillColor(Color::Red);
  	t_score.setCharacterSize(24);
  	t_score.setString("Score: ");
  	
  	// text New High Score
  	Text textNewHighScore;
  	
  	textNewHighScore.setFont(font);
  	textNewHighScore.setPosition(90, 165);
  	textNewHighScore.setFillColor(colorNewHighScore);
  	textNewHighScore.setCharacterSize(35);
  	
  	// text highscore;
  	Text t_highScore;
  	t_highScore.setFont(font);
  	t_highScore.setPosition(190, 170);
  	t_highScore.setFillColor(Color::Red);
  	t_highScore.setCharacterSize(60);
  	// text Your Score
  	Text t_yourScore;
  	t_yourScore.setFont(font);
  	t_yourScore.setPosition(135, 180);
  	t_yourScore.setFillColor(colorYourScore);
  	t_yourScore.setCharacterSize(32);

  	// 
  	while(window.isOpen()){
  		
  		// time
  		float time = clock.getElapsedTime().asSeconds();
  		clock.restart();
  		timer+=time;
  		
  		Event event;
  		while(window.pollEvent(event)){
  			if(b_play==false && event.type == sf::Event::MouseButtonPressed)
                
			{
				if(event.mouseButton.button == Mouse::Left)
				{	
					HandleMouseClick( event.mouseButton.x, event.mouseButton.y);
				}
			} 

            else if (event.type == sf::Event::Closed)
                window.close();
		  }
		
		window.clear(colorBackgroud);
		
		if(b_play==true){
			
			if(dir==1)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left)){ dir=1; }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { dir=1;}   
				if (Keyboard::isKeyPressed(Keyboard::Up)) { dir=3; }
				if (Keyboard::isKeyPressed(Keyboard::Down)) { dir=0; }
			}
			if(dir==2)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left)){ dir=2; }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { dir=2;}   
				if (Keyboard::isKeyPressed(Keyboard::Up)) { dir=3; }
				if (Keyboard::isKeyPressed(Keyboard::Down)) { dir=0; }
			}
			if(dir==3)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left)){ dir=1; }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { dir=2;}   
				if (Keyboard::isKeyPressed(Keyboard::Up)) { dir=3; }
				if (Keyboard::isKeyPressed(Keyboard::Down)) { dir=3; }
			}
			if(dir==0)
			{
				if (Keyboard::isKeyPressed(Keyboard::Left)){ dir=1; }
				if (Keyboard::isKeyPressed(Keyboard::Right)) { dir=2;}   
				if (Keyboard::isKeyPressed(Keyboard::Up)) { dir=0; }
				if (Keyboard::isKeyPressed(Keyboard::Down)) { dir=0; }
			}
	
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
				b_play=false;
				if(classic == true)
				{
					window.draw(imageClassic);
				}
				if(modern == true)
				{
					window.draw(imageModern1);
				}
				window.draw(t_GameOver);
				
				t_yourScore.setString("Your Score: " + to_string(_Score));
				window.draw(t_yourScore);
				
				window.display();
				this_thread::sleep_for(chrono::milliseconds(3000));
				
				if(_Score > diem.highScore)
				{
					window.draw(imageNewHighScore);
					
					fHighScore();
					
					textNewHighScore.setString("New High Score: " + to_string(_Score));
					window.draw(textNewHighScore);
					
					sCongratulation.play();
					window.display();
					
					this_thread::sleep_for(chrono::milliseconds(3000));
				
				}
				
				_Score = 0;	
			}
		}
		
		if( b_play==true && b_option==false && b_highScore==false ) 
		{
	
			//draw hinh anh 
			window.draw(imageClassic);	 
			if(modern==true && classic==false){
				window.draw(imageModern1);
			}
			// ve hoa qua	
		 	imageFood.setPosition(f.x*size, f.y*size);  window.draw(imageFood);
			// ve snake
			for (int i=0;i<num;i++)
		    { 
		    	
				if(skin==1)
				{
					if(dir==1){
	    			snake1.setPosition(s[0].x*size, s[0].y*size);
	    			window.draw(snake1);
					}
					if(dir==2){
		    			snake2.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake2);
					}
					if(dir==3){
		    			snake3.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake3);
					}
					if(dir==0){
		    			snake0.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake0);
					}
					
					snake5.setPosition(s[i].x*size, s[i].y*size);
					window.draw(snake5);
					}
				if(skin == 2)
				{
					if(dir==1){
		    			snake21.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake21);
					}
					if(dir==2){
		    			snake22.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake22);
					}
					if(dir==3){
		    			snake23.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake23);
					}
					if(dir==0){
		    			snake20.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake20);
					}
				
				snake52.setPosition(s[i].x*size, s[i].y*size);
				window.draw(snake52);
				}
				if(skin == 3)
				{
					if(dir==1){
	    			snake1.setPosition(s[0].x*size, s[0].y*size);
	    			window.draw(snake1);
					}
					if(dir==2){
		    			snake2.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake2);
					}
					if(dir==3){
		    			snake3.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake3);
					}
					if(dir==0){
		    			snake0.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake0);
					}
					
					if(i%2==1){
						snake52.setPosition(s[i].x*size, s[i].y*size);
						window.draw(snake52);
					}
					else{
						snake5.setPosition(s[i].x*size, s[i].y*size);
						window.draw(snake5);
					}
					
				}
				if(skin == 4)
				{
					if(dir==1){
	    			snake21.setPosition(s[0].x*size, s[0].y*size);
	    			window.draw(snake21);
					}
					if(dir==2){
		    			snake22.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake22);
					}
					if(dir==3){
		    			snake23.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake23);
					}
					if(dir==0){
		    			snake20.setPosition(s[0].x*size, s[0].y*size);
		    			window.draw(snake20);
					}
					
					if(i%2==1){
						snake5.setPosition(s[i].x*size, s[i].y*size);
						window.draw(snake5);
					}
					else{
						snake52.setPosition(s[i].x*size, s[i].y*size);
						window.draw(snake52);
					}
					
				}
    			
			}
		 	// draw score
		 	s_score.setString(to_string(_Score)); // update score
			window.draw(t_score);
		 	window.draw(s_score);
		}
		
		if( b_play==false && b_option==true && b_highScore==false )
		{
			
			if(b_skin==true && b_map==false  && b_level==false)
			{
				switch(skin)
				{
					case 1:
						{ window.draw(imageSkin1); break; }
					case 2:
						{ window.draw(imageSkin2); break; }
					case 3:
						{ window.draw(imageSkin3); break; }
					case 4:
						{ window.draw(imageSkin4); break; }
				}
			}
			
			if(b_skin==false && b_map==true  && b_level==false)
			{
				if(classic == true && modern == false)
				{ 
					window.draw(imageType1);
				}
				if(classic == false && modern == true)
				{
					window.draw(imageType2);
				}
			}
			if(b_skin==false && b_level==true && b_map==false)
			{
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
			if(b_skin==false && b_level==false && b_map==false)
			{
				window.draw(imageOption);
			}
			
		}
		
		if(b_play==false && b_option==false && b_highScore==true ){
			t_highScore.setString(to_string(diem.highScore));
			window.draw(imageHighScore);
			window.draw(t_highScore);
		}
		
		if(b_play == false && b_option == false && b_highScore == false)
		{
			window.draw(imageMenu);
		}
		
		// hien thi len window;
 		window.display();
		  
	}

    return 0;
}
//----------------------------------------//
void HandleMouseClick( int x, int y)
{
// play;
    if( ( x >= 189  && x <= 456)  && (y >=77 && y <= 138) && b_option == false && b_highScore==false )
    {
    	b_play = true;
	}
// opiton	
	if(( x >=236  && x <= 408) && (y >= 312 && y <= 360) && b_play==false && b_highScore==false){
    	b_option = true;
    	
	}
	if(b_option == true && b_play==false && b_highScore==false){
		
	// skin
		if( ( x >= 236  && x <= 408)  && (y >= 24 && y <= 72) && b_map==false && b_level==false )
		{
			b_skin = true;
		}
		if(b_skin == true && b_map == false && b_level == false)
		{
			
			if( ( x >= 64  && x <= 236)  && (y >=48 && y <= 96) )
	    	{
	    		skin = 1;
	    	}
	    	if( ( x >= 64  && x <= 236)  && (y >=126 && y <=174) )
	    	{
	    		skin = 2;
			}
			if( ( x >= 64  && x <= 236)  && (y >=204 && y <= 252) )
			{
				skin = 3;
			}
			if( ( x >= 64  && x <= 236)  && (y >=282 && y <= 330) )
			{
				skin = 4;
			}
			// back
			if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
				b_skin = false;
			}
		}
			
	// type
		if( ( x >= 236  && x <= 408)  && (y >= 120 && y <= 168) && b_play==false && b_level==false && b_highScore==false )
	    {
	    	b_map = true;
	    }
	    if(b_play==false && b_level==false && b_highScore==false && b_map==true){
	    	if( ( x >= 32  && x <= 186)  && (y >=246 && y <= 338) )
	    	{
	    		classic = true;
	    		modern = false;
	    		fValueFood(); 	
	    	}
		    if( ( x >= 316  && x <= 464)  && (y >= 246 && y <= 338) )
	    	{
	    		classic = false;
	    		modern = true;
	    		fValueFood();
	    	}
	    	if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){ 
				b_map = false;
			}
		}
	// level
	    if(( x >=236  && x <= 408) && (y >= 216 && y <= 264) && b_skin==false  && b_map==false)
		{
	    	b_level = true;
		}
		
		// chon level
		if( b_skin==false && b_level==true && b_map==false){
			
			if(( x >=236  && x <= 408) && (y >= 19 && y <= 57)){
				delay = 0.15;
				level = 1;
				fValueFood();
			}
			
			if(( x >=236  && x <= 408) && (y >= 95 && y <= 133)){
				delay = 0.12;
				level = 2;
				fValueFood();
			}
			
			if(( x >=236  && x <= 408) && (y >= 171 && y <= 209)){
				delay = 0.1;
				level = 3;
				fValueFood();
			}
			
			if(( x >=236  && x <= 408) && (y >= 247 && y <= 285)){
				delay = 0.07;
				level = 4;
				fValueFood();
			}
			
			if(( x >=236  && x <= 408) && (y >= 323 && y <= 361)){
				delay = 0.05;
				level = 5;
				fValueFood();
			}
			// tro lai menu-level
			if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
				b_level = false;
			}
		}
		// back menu
		if(( x >=136  && x <= 186) && (y >= 16 && y <= 46)){
				b_option = false;
		}
	}

// highScore
	if( ( x >= 236  && x <= 408)  && (y >=216 && y <= 264) && b_play==false && b_option==false )
    {
    	b_highScore = true;
    }
    // back
    if(b_play==false && b_option==false && b_highScore==true){
    	if(( x >=16  && x <= 64) && (y >= 16 && y <= 35)){
			b_highScore = false;
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
	     	dir = 2;
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
    if (dir==1) s[0].x-=1; // trai     
    if (dir==2) s[0].x+=1; // phai       
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

 
 


