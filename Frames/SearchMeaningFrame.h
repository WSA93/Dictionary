#ifndef SEARCHMEANINGFRAME_H
#define SEARCHMEANINGFRAME_H

//(*Headers(SearchMeaningFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class SearchMeaningFrame: public wxFrame
{
	public:

		SearchMeaningFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~SearchMeaningFrame();

		//(*Declarations(SearchMeaningFrame)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticBox* StaticBox1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(SearchMeaningFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICBOX1;
		//*)

	private:

		//(*Handlers(SearchMeaningFrame)
		void OnClose(wxCloseEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
