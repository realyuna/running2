#include <bangtal.h>

SceneID scene1, scene2;
ObjectID startbutton, endbutton, pitch1, mario1, mush1, play1, Pitch, Mario, Mush;
int pitch1X = 0, pitch1Y = 360;
int mario1X = 0, mario1Y = 190;
int mush1X = 0, mush1Y = 40;


void keyboardCallback(KeyCode code, KeyState state)
{

	if (code == KeyCode::KEY_DOWN_ARROW) {		// DOWN
		mario1X = mario1X + 30;
		locateObject(mario1, scene1, mario1X, mario1Y);

		if (mario1X > 1280) {
			enterScene(scene2);
			locateObject(Mario, scene2, 600, 150);
			showObject(Mario);
			showMessage("우승자는 마리오!");
		}
	}

	else if (code == KeyCode::KEY_RIGHT_ARROW) {		// RIGHT
	pitch1X = pitch1X + 30;
		locateObject(pitch1, scene1, pitch1X, pitch1Y);


		if (pitch1X > 1280) {
			enterScene(scene2);
			locateObject(Pitch, scene2, 600, 150);
			showObject(Pitch);
			showMessage("우승자는 피치!");
			
		}
	}
	else if (code == KeyCode::KEY_LEFT_ARROW) {		// LEFT
		mush1X = mush1X + 30;
		locateObject(mush1, scene1, mush1X, mush1Y);

		if (mush1X > 1280) {
			enterScene(scene2);
			locateObject(Mush, scene2, 600, 150);
			showObject(Mush);
			showMessage("우승자는 키노피오!");
		}
	}
}



int main() {
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);


	setKeyboardCallback(keyboardCallback);


	//장면1
	scene1 = createScene("scene1", "육상경기장.png");

	showMessage("피치는 오른쪽, 마리오는 아래, 키노피오는 왼쪽 방향키를 연타하세요!");


	//런 캐릭터//
	pitch1 = createObject("pitch1.png");
	locateObject(pitch1, scene1, pitch1X, pitch1Y);
	showObject(pitch1);

	mario1 = createObject("mario1.png");
	locateObject(mario1, scene1, mario1X, mario1Y);
	showObject(mario1);


	mush1 = createObject("mush1.png");
	locateObject(mush1, scene1, mush1X, mush1Y);
	showObject(mush1);



	//우승자//
	Pitch = createObject("realpitch1.png");
	locateObject(Pitch, scene2, 600, 300);

	Mario = createObject("realmario1.png");
	locateObject(Mario, scene2, 600, 300);

	Mush = createObject("realmush1.png");
	locateObject(Mush, scene2, 600, 300);







	scene2 = createScene("scene2", "rank1.png");























	startGame(scene1);
}

