#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
using namespace sf;
using namespace std;
int gameField[5][5]={{0,2,0,2,0},{2,0,2,2,2},{0,2,0,0,0},{2,0,0,2,2},{0,0,2,0,2}};
bool a=false,d=false,w=false,s=false;
int v,vector,score,move=0,tmove;
int ir,xr;
int cofx = 0, cofy = 0; //переменная, прибавляем к координате сравниваемой клетки, зависит от нажатой клавиши.
int ones=0, fists=0;
void randomiz();







class Button {

    bool pressed;
    int weight, height, posx, posy;
    std::ostringstream label;

    public:
    sf::Text text;
    sf::Font font;

    sf::RectangleShape button;

    void newButton(int wh, int hh, int px, int py)
    {

        weight=wh; height=hh; posx=px; posy=py;
        button.setSize(sf::Vector2f(weight, height));
        button.setPosition(posx,posy);
        button.setFillColor(sf::Color(200, 200, 200));
    };

    bool isCursor (float corx, float cory)
    {
        if ((corx>posx) && (corx<weight+posx) && (cory>posy) && (cory<height+posy)) {
        button.setFillColor(sf::Color(100, 100, 100));
        return true; }
        else { button.setFillColor(sf::Color(200, 200, 200));
        return false;
        }
    }

    void setLabel (std::string lb, std::string fnt)
    {
        label <<lb;

        font.loadFromFile(fnt);
        text.setString(label.str());
        text.setFont(font);

        text.setCharacterSize(24);
        text.setColor(sf::Color::Black);
        text.setPosition(posx+20,posy);

    }


};













int scores(){   // LEGACY
	score=0;
for(int s=0;s<6;s++){
		for(int x=0;x<6;x++){
			score+=gameField[s][x];
					}
					}
return score;
}


int step(){
	if(w==true){
		for(int s=0;s<=5;s++){
	for(int i=0;i<=4;i++){//горизонталь
		for(int x=1;x<=4;x++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x-1][i] || gameField[x-1][i]==0){
gameField[x-1][i]=gameField[x-1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	} else if(s==true){
		for(int s=0;s<=5;s++){
		for(int i=0;i<=4;i++){//горизонталь
			for(int x=3;x>=0;x--){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x+1][i] || gameField[x+1][i]==0){
gameField[x+1][i]=gameField[x+1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(a==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=1;i<=4;i++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x][i-1] || gameField[x][i-1]==0){
gameField[x][i-1]=gameField[x][i-1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(d==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=3;i>=0;i--){//вертикаль
				    //на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x][i+1] || gameField[x][i+1]==0){
gameField[x][i+1]=gameField[x][i+1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");

					}
					}


			}
			}
	}
	//else if(move=10000){ exit(0);}
	move++;
	cout<<move<<endl;
	randomiz();

}






int newStep()
{

    if(w==true){
		for(int s=0;s<=5;s++){
	for(int i=0;i<=4;i++){//горизонталь
		for(int x=1;x<=4;x++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x-1][i]==0){
gameField[x-1][i]=gameField[x-1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	} else if(s==true){
		for(int s=0;s<=5;s++){
		for(int i=0;i<=4;i++){//горизонталь
			for(int x=3;x>=0;x--){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x+1][i]==0){
gameField[x+1][i]=gameField[x+1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(a==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=1;i<=4;i++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i-1]==0){
gameField[x][i-1]=gameField[x][i-1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(d==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=3;i>=0;i--){//вертикаль
				    //на всякий случай) [строка][столбец]
					if(gameField[x][i+1]==0){
gameField[x][i+1]=gameField[x][i+1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");

					}
					}


			}
			}
	}






    if(w==true){

	for(int i=0;i<=4;i++){//горизонталь
		for(int x=1;x<=4;x++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x-1][i]){
gameField[x-1][i]=gameField[x-1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}

	} else if(s==true){

		for(int i=0;i<=4;i++){//горизонталь
			for(int x=3;x>=0;x--){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x+1][i]){
gameField[x+1][i]=gameField[x+1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}

	}else if(a==true){

		for(int x=0;x<=4;x++){//горизонталь
			for(int i=1;i<=4;i++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x][i-1]){
gameField[x][i-1]=gameField[x][i-1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}

	}else if(d==true){

		for(int x=0;x<=4;x++){//горизонталь
			for(int i=3;i>=0;i--){//вертикаль
				    //на всякий случай) [строка][столбец]
					if(gameField[x][i]==gameField[x][i+1]){
gameField[x][i+1]=gameField[x][i+1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");

					}
					}


			}

	}



        if(w==true){
		for(int s=0;s<=5;s++){
	for(int i=0;i<=4;i++){//горизонталь
		for(int x=1;x<=4;x++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x-1][i]==0){
gameField[x-1][i]=gameField[x-1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	} else if(s==true){
		for(int s=0;s<=5;s++){
		for(int i=0;i<=4;i++){//горизонталь
			for(int x=3;x>=0;x--){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x+1][i]==0){
gameField[x+1][i]=gameField[x+1][i]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(a==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=1;i<=4;i++){//вертикаль
				//на всякий случай) [строка][столбец]
					if(gameField[x][i-1]==0){
gameField[x][i-1]=gameField[x][i-1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");
					}
					}


			}
			}
	}else if(d==true){
		for(int s=0;s<=5;s++){
		for(int x=0;x<=4;x++){//горизонталь
			for(int i=3;i>=0;i--){//вертикаль
				    //на всякий случай) [строка][столбец]
					if(gameField[x][i+1]==0){
gameField[x][i+1]=gameField[x][i+1]+gameField[x][i];
gameField[x][i]=0;
//draw();
//system("cls");

					}
					}


			}
			}
	}





    move++;
	cout<<ones<<" "<<fists<<" "<<cofx<<" "<<cofy<<" "<<"/n "<<000000000000<<endl;
	randomiz();

}








void randomiz(){
	int tmp00=0, tmp04=0, tmp44=0, tmp40=0, u=0,z=0;

while(u!=1){

ir=rand()%5;
xr=rand()%5;
if(gameField[ir][xr]==0){
gameField[ir][xr]=2;
u++;
}
if(gameField[ir][xr]!=0){
z++;
if (z==5){break;}
}
	}
}






void draw(){
	Clock clock;
	int q=0;

    RenderWindow window(sf::VideoMode(536, 640), "2048 epta");

    Image heroimage;
	heroimage.loadFromFile("images/2048.png");
	Texture herotexture;
	herotexture.loadFromImage(heroimage);
	Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(20,11,104,104));

    Font font;
	font.loadFromFile("times.ttf");
    Text text("",font,20);
	text.setColor(Color::Red);
	text.setStyle(Text::Bold | Text::Underlined);









	Button testButton;
    testButton.newButton(80,30,440,600);
    testButton.setLabel("exit","times.ttf");












		while (window.isOpen()) {
			float time=clock.getElapsedTime().asMicroseconds();
			clock.restart();
	time=time/800;


        Event event;
        while (window.pollEvent(event))
        {
           if (event.type == Event::Closed)
               window.close();
		   if (event.type == sf::Event::KeyPressed){
	a=false,d=false,w=false,s=false;
	    if (event.key.code == sf::Keyboard::Left) {a=true; cofx=0; cofy=-1; ones=1; fists=4;}
		if(event.key.code == sf::Keyboard::Right){ d=true; cofx=0; cofy=1; ones=3; fists=0;}
		if(event.key.code == sf::Keyboard::Up){ w=true; cofx=-1; cofy=0; ones=1; fists=4;}
		if(event.key.code == sf::Keyboard::Down){ s=true; cofx=1; cofy=0; ones=3; fists=0;}
		//break;
		//step();
		newStep();
		}
        }
		q=0;
		window.setKeyRepeatEnabled (false);




        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f pos = window.mapPixelToCoords(pixelPos);

        if ((testButton.isCursor(pos.x,pos.y)) && /*(sf::Mouse::isButtonPressed(sf::Mouse::Left))*/ (event.type == sf::Event::MouseButtonReleased) )
        break;







        window.clear(sf::Color(240,240,200));
		for(int i=0;i<5;i++){
			for(int w=0;w<5;w++){
				if (gameField[w][i]==0){herosprite.setTextureRect(IntRect(643,140,104,104));}
				if (gameField[w][i]==2){herosprite.setTextureRect(IntRect(20,11,104,104));}
				if (gameField[w][i]==4){herosprite.setTextureRect(IntRect(139,12,104,104));}
				if (gameField[w][i]==8){herosprite.setTextureRect(IntRect(262,12,104,104));}
				if (gameField[w][i]==16){herosprite.setTextureRect(IntRect(386,12,104,104));}
				if (gameField[w][i]==32){herosprite.setTextureRect(IntRect(518,13,104,104));}
				if (gameField[w][i]==64){herosprite.setTextureRect(IntRect(644,15,104,104));}
				if (gameField[w][i]==128){herosprite.setTextureRect(IntRect(19,138,104,104));}
				if (gameField[w][i]==256){herosprite.setTextureRect(IntRect(144,136,104,104));}
				if (gameField[w][i]==512){herosprite.setTextureRect(IntRect(266,137,104,104));}
				if (gameField[w][i]==1024){herosprite.setTextureRect(IntRect(392,136,104,104));}
				if (gameField[w][i]==2048){herosprite.setTextureRect(IntRect(521,138,104,104));}
			herosprite.setPosition(i*108,w*108);
			text.setPosition(0,540);
			ostringstream strskr;
			strskr<<scores();
			text.setString("Score:" + strskr.str());
			window.draw(text);
			window.draw(testButton.button);
        window.draw(testButton.text);
        window.draw(herosprite);
			}

		}

		  window.display();



    }

}
int main()
{
	draw();

    return 0;
}
