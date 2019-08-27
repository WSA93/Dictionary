#ifndef SEARCHWOFRAME_H
#define SEARCHWOFRAME_H

//(*Headers(SearchWOFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class SearchWOFrame: public wxFrame
{
	public:

		SearchWOFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SearchWOFrame();

		//(*Declarations(SearchWOFrame)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticBox* StaticBox1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(SearchWOFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_STATICBOX1;
		//*)

	private:

		//(*Handlers(SearchWOFrame)
		void OnClose(wxCloseEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
