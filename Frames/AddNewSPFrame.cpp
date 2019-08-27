#include "AddNewSPFrame.h"
#include"SingularPlural.h"

SingularPlural singularPluralAdd;

//(*InternalHeaders(AddNewSPFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(AddNewSPFrame)
const long AddNewSPFrame::ID_STATICTEXT1 = wxNewId();
const long AddNewSPFrame::ID_TEXTCTRL1 = wxNewId();
const long AddNewSPFrame::ID_STATICTEXT2 = wxNewId();
const long AddNewSPFrame::ID_TEXTCTRL2 = wxNewId();
const long AddNewSPFrame::ID_BUTTON1 = wxNewId();
const long AddNewSPFrame::ID_BUTTON2 = wxNewId();
const long AddNewSPFrame::ID_STATICBOX1 = wxNewId();
const long AddNewSPFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AddNewSPFrame,wxFrame)
	//(*EventTable(AddNewSPFrame)
	//*)
END_EVENT_TABLE()

AddNewSPFrame::AddNewSPFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AddNewSPFrame)
	Create(parent, wxID_ANY, _("Dictionary - Add Singular Plural"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	SetBackgroundColour(wxColour(176,176,255));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Singular"), wxPoint(232,160), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(328,160), wxSize(144,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Plural"), wxPoint(232,216), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(328,216), wxSize(144,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxPoint(232,280), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	Button2 = new wxButton(this, ID_BUTTON2, _("Save"), wxPoint(368,280), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("ADD NEW SINGULARS PLURALS"), wxPoint(144,112), wxSize(416,240), 0, _T("ID_STATICBOX1"));
	MessageDialog1 = new wxMessageDialog(this, _("This Word Already Exists"), _("Message"), wxOK, wxDefaultPosition);
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AddNewSPFrame::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AddNewSPFrame::OnTextCtrl2Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddNewSPFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddNewSPFrame::OnButton2Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&AddNewSPFrame::OnClose);
	//*)

	singularPluralAdd.loadDataFromFile();
}

AddNewSPFrame::~AddNewSPFrame()
{
	//(*Destroy(AddNewSPFrame)
	//*)
}

void AddNewSPFrame::OnClose(wxCloseEvent& event)
{
    singularPluralAdd.releaseMemory();
    Destroy();
}

void AddNewSPFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
   tempInput1 = event.GetString();
   if(singularPluralAdd.alreadyExist(tempInput1))
   {
       MessageDialog1->ShowModal();
   }
}

void AddNewSPFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
   tempInput2 = event.GetString();
}

void AddNewSPFrame::OnButton1Click(wxCommandEvent& event)
{
    singularPluralAdd.addNewToList(tempInput1,tempInput2);
}

void AddNewSPFrame::OnButton2Click(wxCommandEvent& event)
{
    singularPluralAdd.saveInFile();
}
