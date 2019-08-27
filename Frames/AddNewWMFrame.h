#ifndef ADDNEWWMFRAME_H
#define ADDNEWWMFRAME_H

//(*Headers(AddNewWMFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/statbox.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class AddNewWMFrame: public wxFrame
{
	public:

		AddNewWMFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AddNewWMFrame();

		//(*Declarations(AddNewWMFrame)
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxStaticText* StaticText1;
		wxStaticBox* StaticBox1;
		wxButton* Button2;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl1;
		wxMessageDialog* MessageDialog1;
		//*)

	protected:

		//(*Identifiers(AddNewWMFrame)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICBOX1;
		static const long ID_MESSAGEDIALOG1;
		//*)

	private:

		//(*Handlers(AddNewWMFrame)
		void OnClose(wxCloseEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
