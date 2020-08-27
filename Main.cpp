using namespace std;
#include <iostream>
#include <vector> 

// Rift Device Access
#include "OculusRiftDevice.class"

// Scene and Prop Building classes
#include "Globals.class"
#include "Scene.class"
#include "Prop.class"

// The "ACTS"
#include "Acts\ActOneTemplate.class"
#include "Acts\ActOne.class"

bool Rolling();
void CrewCall(HINSTANCE hinst);
void ItsAWrap();

#define WM_VOICECOMMAND             0x0235

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int)
{
    bool isSetHot = false;

    CrewCall( hinst );

	if (((Scene*)Globals::myScene) != nullptr)
	{
        Script *actOne = new ActOne();

        // Set up the stage for the actor..... 
        actOne->SetTheStage();

        actOne->BeatSheet.Add( new Beat("This is a test BEAT") );

        while ( Rolling() )
		{
            if(!isSetHot)
            {
                isSetHot = true;

                // keep the action running!
                actOne->Action();

                // TODO: need to think of a way to externalize positional settings from the scene handler
                // and push it into the act itself. I'm thinking using actOne->Camera for the placement,
                // but because I'm trying to personalize this to actors I am leaning towards having 'actors'
                // separate and distinct from camera positions. MAYBE a default camera position will 
                // always be a first person perspective from an actor's POV. So maybe I set up camera positioning
                // based on the actor and push scene positioning based on the current camera in content....
                // ANHHOOO
                // TODO: NEED CAMERA AND CURRENT LOCATION PLACEMENT SETTIGNS HERE.... TOMORROW or day after...




                // ANOTHER TODO!!!!!!!!!!!!!!!!!!
                // CREATE EVENT BASED SYSTEM FOR PROCESSING MODEL LEVEL EVENTS!!!
                // Render anything done to the Oculus, breaking when done
                if (!((OculusRiftDevice *)Globals::myRift)->Process(((Scene*)Globals::myScene)))
                    break;

            }

            isSetHot = false;
        }
    }

    ItsAWrap();
	return(0);
}


// ------------------------------------------------------------------------------------------------------
// Ok, here's the primary message loop function, equivalated to the 'rolling' of cameras on a movie set
// when the director (aka player) yells cut /or/ the process terminates, this is where I'd detect that. 
// ------------------------------------------------------------------------------------------------------
bool Rolling()
{
    MSG msg;
    while (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        // ------------------------------------------------------
        // GLOBAL KEYSTROKE HANDLERS ONLY!!!!!!!!!!!!!!!!!!!!!!!!
        // ------------------------------------------------------
        if (msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE)
        {
            PostQuitMessage(0);
            return false;
        }
    }
    return Platform.Running;
}

// ------------------------------------------------------------------------------------------------------
// Global Memory Management Initialization and Cleanup functions.... A codependent relationship for sure
// ------------------------------------------------------------------------------------------------------
void CrewCall(HINSTANCE hinst)
{
    Globals::InitGlobals();
    Globals::myRift = new OculusRiftDevice(hinst);
    Globals::myScene = ((OculusRiftDevice *)Globals::myRift)->Initialize();
    return;
}

void ItsAWrap()
{
    if (Globals::myScene != nullptr)
    {
        delete ((Scene *)Globals::myScene);
        Globals::myScene = nullptr;
    }
    if (Globals::myRift != nullptr)
    {
        delete ((OculusRiftDevice *)Globals::myRift);
        Globals::myRift = nullptr;
    }
    return;
}
