#include "NBodyWindow.h"

#include <glload/gl_3_0.h>
#include <glload/gll.hpp>
#include <GL/freeglut.h>
#include <cmath>

NBodyWindow::NBodyWindow( const std::string &title, Mode debugMode ) : 
	GlutWrapper{ title, debugMode }, _elapsedTime{0.0f} {
	_instance = this; 
}

NBodyWindow::~NBodyWindow() {}

void NBodyWindow::reshape( int theWidth, int theHeight ) {
	glViewport( 0, 0, (GLsizei) theWidth, (GLsizei) theHeight );
}

void NBodyWindow::keyboard( unsigned char key, int /*x*/, int /*y*/ ) {
	const char ESCAPE_KEY = 27;
	if( key == ESCAPE_KEY ) {
		glutLeaveMainLoop();
	}
}

void NBodyWindow::updateElapsedTime() {
	// glutGet returns time in milliseconds
	_elapsedTime = glutGet( GLUT_ELAPSED_TIME ) / 1000.0f;
}

void NBodyWindow::updateBuffer() {
	updateElapsedTime();
	size_t nVertices = _bufSize / 4;
	for( size_t i = 0; i < nVertices; ++i ) {
		float xFraction = float( i + 2 * _elapsedTime ) / float( nVertices - 1 );
		float yFraction = float( i - 2 * _elapsedTime ) / float( nVertices - 1 );
		_buf[4*i] = cosf( 2 * 3.1415f * xFraction  );
		_buf[4*i+1] = sinf( 2 * 3.1415f * yFraction );
		_buf[4*i+2] = 0.0f; // ignore z-coordinate
		_buf[4*i+3] = 1.0f; // ignore extra
	}

	glBindBuffer( GL_ARRAY_BUFFER, _positionBufferObject );
	glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof( float ) * _bufSize, _buf );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}

void NBodyWindow::drawBuffer() {
	glUseProgram( _program );
	glBindBuffer( GL_ARRAY_BUFFER, _positionBufferObject );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 0, 0 );

	glDrawArrays( GL_QUADS, 0, (GLsizei) _bufSize );

	glDisableVertexAttribArray( 0 );
	glUseProgram( 0 );
}

void NBodyWindow::display() {
	updateBuffer();

	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	drawBuffer();

	glutSwapBuffers();
	glutPostRedisplay();
}
