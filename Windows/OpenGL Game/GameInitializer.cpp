#include "RenderGame.h"
#include <Header files\Header.h>

int main(int argc, char** argv)
{
    Magick::InitializeMagick(*argv);
    GLUTBackendInit(argc, argv);

    if (!GLUTBackendCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, 32, false, "My First OpenGL Game")) {
        return 1;
    }

	RenderGame *pApp = new RenderGame();
	pApp->run();

    delete pApp;
	system("PAUSE");
	
    return 0;
}


