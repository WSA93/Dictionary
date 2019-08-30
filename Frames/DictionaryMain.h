/***************************************************************
 * Name:      DictionaryMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-05-02
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DICTIONARYMAIN_H
#define DICTIONARYMAIN_H

//(*Headers(DictionaryFrame)
#include <wx/stattext.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class DictionaryFrame: public wxFrame
{
    public:

        DictionaryFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~DictionaryFrame();

    private:

        //(*Handlers(DictionaryFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(DictionaryFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_STATICBOX1;
        static const long ID_STATICTEXT1;
        //*)

        //(*Declarations(DictionaryFrame)
        wxButton* Button4;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticBox* StaticBox1;
        wxButton* Button2;
        wxButton* Button6;
        wxButton* Button5;
        wxButton* Button3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DICTIONARYMAIN_H
