#include <SFML/Graphics.hpp>
#include <sstream>
using namespace std;
using namespace sf;

bool spritesChocan(Sprite sp1, Sprite sp2){
	return sp1.getGlobalBounds().intersects(sp2.getGlobalBounds());
}

void setPuntaje(Text &textoPuntaje, int puntaje){
	stringstream ss;
	ss<<puntaje;
	textoPuntaje.setString(ss.str());
}


int main(int argc, char *argv[]){
	// crea la ventana de juego (RenderWindow)
	RenderWindow window;
	window.create(VideoMode(640,480),"SFML Pong");
	window.setFramerateLimit(60);
	
	// *********** declaraciones ***********
	Texture texPad1, texBall, texWall;	// texturas
	Sprite spPad1, spBall, spWall1;		// sprites
	Font fontScore;						// fuente
	Text score1, score2;				// texto de los puntajes
	
	
	
	// *********** carga de texturas, fuentes, etc ***********
	// carga las texturas
	texPad1.loadFromFile("assets/images/pad1.png");
	texBall.loadFromFile("assets/images/ball.png");
	texWall.loadFromFile("assets/images/wall.png");
	// carga la fuente
	fontScore.loadFromFile("assets/fonts/BackOutPrint.otf");
	
	
	// *********** configurar y posicionar sprites, texto, etc ***********
	// asigna las texturas a los sprites
	spPad1.setTexture(texPad1);
	spBall.setTexture(texBall);
	spWall1.setTexture(texWall);
	// posiciona los sprites
	spPad1.setPosition(20, 130);
	spBall.setPosition(100, 100);
	spWall1.setPosition(5, 5);
	
	// asigna la fuente a los textos de puntaje
	score1.setFont(fontScore);
	score2.setFont(fontScore);
	// posiciona los textos de los puntajes
	score1.setPosition(144, 40);
	score2.setPosition(464, 40);
	// posiciona los textos de los puntajes
	score1.setFillColor(Color(250, 50, 10));
	score2.setFillColor(Color(250, 50, 10));
	setPuntaje(score1, 0);
	setPuntaje(score2, 0);
	
	// *********** bucle de juego ***********
	// rapidez de la pelota
	const float BALL_VEL = 2;
	// velocidad de la pelota (componentes X e Y)
	float velBallX = BALL_VEL, velBallY = -BALL_VEL;
	// puntaje de los jugadores
	int puntajeJugador1 = 0, puntajeJugador2 = 0;
	
	// *********** bucle de juego ***********
	while(window.isOpen()) {
		Event e;
		while(window.pollEvent(e)) {
			if(e.type == Event::Closed)
				window.close();
		}
		
		// *********** mover y actualizar ***********
		// mueve la primer paleta
		if(Keyboard::isKeyPressed(Keyboard::W)){
			spPad1.move(0, -3);
		}
		
		// revisa si la pelota choca con algo
		if(spritesChocan(spBall, spWall1)){
			velBallY = BALL_VEL;
		}
		
		// mueve la pelota
		spBall.move(velBallX, velBallY);
		
		// *********** dibujado ***********
		// limpia la pantalla
		window.clear(Color::White);
		// dibuja todos los sprites
		window.draw(spPad1);
		window.draw(spWall1);
		window.draw(spBall);
		window.draw(score1);
		window.draw(score2);
		// refresca la pantalla
		window.display();
	}
	return 0;
}


