#ifndef NBODYWINDOW_H
#define NBODYWINDOW_H

#include "GlutWrapper.h"

class NBodyWindow : public GlutWrapper {
	float _elapsedTime;
public:
	NBodyWindow( const std::string &title, Mode debugMode = Mode::NDEBUG );
	~NBodyWindow();

	void updateElapsedTime();
	void updateBuffer();
	void drawBuffer();

	void display();
	void reshape();
	void reshape( int theWidth, int theHeight );
	void keyboard( unsigned char key, int x, int y );
};

#endif //NBODYWINDOW_H
