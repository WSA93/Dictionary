#include "SearchWOFrame.h"
#include"WordOpposite.h"
WordOpposite wordsOppositesSearch;

//(*InternalHeaders(SearchWOFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SearchWOFrame)
const long SearchWOFrame::ID_STATICTEXT1 = wxNewId();
const long SearchWOFrame::ID_TEXTCTRL1 = wxNewId();
const long SearchWOFrame::ID_STATICTEXT2 = wxNewId();
const long SearchWOFrame::ID_TEXTCTRL2 = wxNewId();
const long SearchWOFrame::ID_BUTTON1 = wxNewId();
const long SearchWOFrame::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SearchWOFrame,wxFrame)
	//(*EventTable(SearchWOFrame)
	//*)
END_EVENT_TABLE()

SearchWOFrame::SearchWOFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SearchWOFrame)
	Create(parent, wxID_ANY, _("Dictionary - Search Words Opposites"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	SetBackgroundColour(wxColour(176,176,255));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Word"), wxPoint(232,160), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(328,160), wxSize(128,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Opposite"), wxPoint(232,216), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(328,216), wxSize(128,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	Button1 = new wxButton(this, ID_BUTTON1, _("Search"), wxPoint(288,272), wxSize(128,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
	wxFont Button1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	Button1->SetFont(Button1Font);
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("SEARCH WORDS OPPOSITES"), wxPoint(144,104), wxSize(408,264), 0, _T("ID_STATICBOX1"));
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SearchWOFrame::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SearchWOFrame::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&SearchWOFrame::OnClose);
	//*)

	wordsOppositesSearch.loadDataFromFile();
}

SearchWOFrame::~SearchWOFrame()
{
	//(*Destroy(SearchWOFrame)
	//*)
}


void SearchWOFrame::OnClose(wxCloseEvent& event)
{
    wordsOppositesSearch.releaseMemory();
    Destroy();
}

void SearchWOFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    tempInput1 = event.GetString();
    tempInput2 = wordsOppositesSearch.findData(tempInput1);
}

void SearchWOFrame::OnButton1Click(wxCommandEvent& event)
{
   TextCtrl2->SetLabel(tempInput2);
}

