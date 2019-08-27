#include "AddNewWMFrame.h"
#include"WordsMeanings.h"

WordsMeanings wordsMeanAdd;

//(*InternalHeaders(AddNewWMFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(AddNewWMFrame)
const long AddNewWMFrame::ID_STATICTEXT1 = wxNewId();
const long AddNewWMFrame::ID_TEXTCTRL1 = wxNewId();
const long AddNewWMFrame::ID_STATICTEXT2 = wxNewId();
const long AddNewWMFrame::ID_TEXTCTRL2 = wxNewId();
const long AddNewWMFrame::ID_BUTTON1 = wxNewId();
const long AddNewWMFrame::ID_BUTTON2 = wxNewId();
const long AddNewWMFrame::ID_STATICBOX1 = wxNewId();
const long AddNewWMFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(AddNewWMFrame,wxFrame)
	//(*EventTable(AddNewWMFrame)
	//*)
END_EVENT_TABLE()

AddNewWMFrame::AddNewWMFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(AddNewWMFrame)
	Create(parent, wxID_ANY, _("Dictionary-Add Words Meanings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	SetBackgroundColour(wxColour(176,176,255));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Word"), wxPoint(128,160), wxSize(48,18), 0, _T("ID_STATICTEXT1"));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(200,160), wxSize(128,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Meaning"), wxPoint(128,232), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(200,232), wxSize(360,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxPoint(232,296), wxSize(107,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	Button2 = new wxButton(this, ID_BUTTON2, _("Save"), wxPoint(368,296), wxSize(104,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("ADD NEW WORDS MEANINGS"), wxPoint(96,112), wxSize(512,264), 0, _T("ID_STATICBOX1"));
	MessageDialog1 = new wxMessageDialog(this, _("This Word Already Exists"), _("Message"), wxOK, wxDefaultPosition);
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AddNewWMFrame::OnTextCtrl1Text);
	Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&AddNewWMFrame::OnTextCtrl2Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddNewWMFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddNewWMFrame::OnButton2Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&AddNewWMFrame::OnClose);
	//*)

	wordsMeanAdd.loadDataFromFile();
}

AddNewWMFrame::~AddNewWMFrame()
{
	//(*Destroy(AddNewWMFrame)
	//*)
}

void AddNewWMFrame::OnClose(wxCloseEvent& event)
{
    wordsMeanAdd.releaseMemory();
    Destroy();
}

void AddNewWMFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
   tempInput1 = event.GetString();
   if(wordsMeanAdd.alreadyExist(tempInput1))
   {
      MessageDialog1->ShowModal();
   }
}

void AddNewWMFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
    tempInput2 = event.GetString();
}

void AddNewWMFrame::OnButton1Click(wxCommandEvent& event)
{
    wordsMeanAdd.addNewToList(tempInput1,tempInput2);
}

void AddNewWMFrame::OnButton2Click(wxCommandEvent& event)
{
    wordsMeanAdd.saveInFile();
}
