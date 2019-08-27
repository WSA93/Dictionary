#include "SearchSPFrame.h"
#include"SingularPlural.h"
SingularPlural singularPluralSearch;

//(*InternalHeaders(SearchSPFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SearchSPFrame)
const long SearchSPFrame::ID_STATICTEXT1 = wxNewId();
const long SearchSPFrame::ID_TEXTCTRL1 = wxNewId();
const long SearchSPFrame::ID_STATICTEXT2 = wxNewId();
const long SearchSPFrame::ID_TEXTCTRL2 = wxNewId();
const long SearchSPFrame::ID_BUTTON1 = wxNewId();
const long SearchSPFrame::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SearchSPFrame,wxFrame)
	//(*EventTable(SearchSPFrame)
	//*)
END_EVENT_TABLE()

SearchSPFrame::SearchSPFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SearchSPFrame)
	Create(parent, wxID_ANY, _("Dictionary - Search Singular Plural"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	SetBackgroundColour(wxColour(176,176,255));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Singular"), wxPoint(232,160), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(328,160), wxSize(136,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Plural"), wxPoint(232,216), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(328,216), wxSize(136,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	Button1 = new wxButton(this, ID_BUTTON1, _("Search"), wxPoint(296,280), wxSize(128,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	wxFont Button1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("SEARCH SINGULAR PLURALS"), wxPoint(144,104), wxSize(424,256), 0, _T("ID_STATICBOX1"));
	wxFont StaticBox1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	StaticBox1->SetFont(StaticBox1Font);
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SearchSPFrame::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SearchSPFrame::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&SearchSPFrame::OnClose);
	//*)

	singularPluralSearch.loadDataFromFile();
}

SearchSPFrame::~SearchSPFrame()
{
	//(*Destroy(SearchSPFrame)
	//*)
}


void SearchSPFrame::OnClose(wxCloseEvent& event)
{
    singularPluralSearch.releaseMemory();
    Destroy();
}

void SearchSPFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
   tempInput1 = event.GetString();
   tempInput2 = singularPluralSearch.findData(tempInput1);
}

void SearchSPFrame::OnButton1Click(wxCommandEvent& event)
{
   TextCtrl2->SetLabel(tempInput2);
}

