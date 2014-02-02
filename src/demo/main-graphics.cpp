#include "GlutWrapper.h"
#include "NBodyWindow.h"
#include "Shaders.h"

#include <glload/gl_3_0.h>
#include <glload/gll.hpp>
#include <GL/freeglut.h>

#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cmath>

namespace nBodyShaders {
  const std::string vertex1(
    "#version 130\n"
    "in vec4 position;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = position;\n"
    "}\n"
  );

  const std::string fragment1(
    "#version 130\n"
    "out vec4 outputColor;\n"
    "void main()\n"
    "{\n"
    "   outputColor = vec4(1.0f,1.0f,1.0f,1.0f);"
    "}\n"
  );
} // namespace shaders



int main( int argc, char **argv ) {
	try {
		size_t N = 13;
		size_t bufSize = 4 * N;
		float *buf = new float[bufSize];

		for( size_t i = 0; i < N; ++i ) {
			buf[4*i] = cosf( 2 * 3.1415f * float( i ) / float( N - 1 ) );
			buf[4*i+1] = sinf( 2 * 3.1415f * float( i ) / float( N - 1 ) );
			buf[4*i+2] = 0.0f;
			buf[4*i+3] = 1.0f;
			std::cout << buf[4*i] << " " << buf[4*i+1];
			std::cout << " " << buf[4*i+2] << " " << buf[4*i+3] << "\n";
		}

		Shaders shaders;
		shaders.addToVertexList( nBodyShaders::vertex1 );
		shaders.addToFragmentList( nBodyShaders::fragment1 );
		
		NBodyWindow window{ "N-Body Simulation", GlutWrapper::NDEBUG };
		window.init( argc, argv, 500, 500, &shaders, bufSize, buf );
		window.run();

		delete [] buf;
		return 0;
	} catch( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << "\n";
		return 1;
	}
}