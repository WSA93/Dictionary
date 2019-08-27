#include "SearchMeaningFrame.h"
#include"WordsMeanings.h"

WordsMeanings wordMeanSearch;

//(*InternalHeaders(SearchMeaningFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SearchMeaningFrame)
const long SearchMeaningFrame::ID_STATICTEXT1 = wxNewId();
const long SearchMeaningFrame::ID_TEXTCTRL1 = wxNewId();
const long SearchMeaningFrame::ID_STATICTEXT2 = wxNewId();
const long SearchMeaningFrame::ID_BUTTON1 = wxNewId();
const long SearchMeaningFrame::ID_TEXTCTRL2 = wxNewId();
const long SearchMeaningFrame::ID_STATICBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SearchMeaningFrame,wxFrame)
	//(*EventTable(SearchMeaningFrame)
	//*)
END_EVENT_TABLE()

SearchMeaningFrame::SearchMeaningFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SearchMeaningFrame)
	Create(parent, wxID_ANY, _("Dictionary-Search Meaning"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(700,500));
	SetBackgroundColour(wxColour(176,176,255));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Word"), wxPoint(104,160), wxSize(40,16), 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(168,160), wxSize(128,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont TextCtrl1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	TextCtrl1->SetFont(TextCtrl1Font);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Meaning"), wxPoint(104,232), wxSize(56,18), 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Button1 = new wxButton(this, ID_BUTTON1, _("Search"), wxPoint(288,288), wxSize(136,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHTTEXT));
	Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(168,232), wxSize(392,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont TextCtrl2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
	TextCtrl2->SetFont(TextCtrl2Font);
	StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("SEARCH MEANING"), wxPoint(88,112), wxSize(528,248), 0, _T("ID_STATICBOX1"));
	StaticBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	Center();

	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&SearchMeaningFrame::OnTextCtrl1Text);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SearchMeaningFrame::OnButton1Click);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&SearchMeaningFrame::OnClose);
	//*)

	wordMeanSearch.loadDataFromFile();
}

SearchMeaningFrame::~SearchMeaningFrame()
{
	//(*Destroy(SearchMeaningFrame)
	//*)
}

//string word = "";
//string meaning = "";

void SearchMeaningFrame::OnClose(wxCloseEvent& event)
{
    wordMeanSearch.releaseMemory();
    Destroy();
}

void SearchMeaningFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
   tempInput1 = event.GetString();
   tempInput2 = wordMeanSearch.findData(tempInput1);
}

void SearchMeaningFrame::OnButton1Click(wxCommandEvent& event)
{
   TextCtrl2->SetLabel(tempInput2);
}
