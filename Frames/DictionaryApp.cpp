/***************************************************************
 * Name:      DictionaryApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-05-02
 * Copyright:  ()
 * License:
 **************************************************************/

#include "DictionaryApp.h"

//(*AppHeaders
#include "DictionaryMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(DictionaryApp);

bool DictionaryApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	DictionaryFrame* Frame = new DictionaryFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
