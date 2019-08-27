/***************************************************************
 * Name:      DictionaryMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-05-02
 * Copyright:  ()
 * License:
 **************************************************************/

#include "DictionaryMain.h"
#include <wx/msgdlg.h>

#include"SearchMeaningFrame.h"
#include"SearchSPFrame.h"
#include"SearchWOFrame.h"
#include"AddNewWMFrame.h"
#include"AddNewSPFrame.h"
#include"AddNewWOFrame.h"

//(*InternalHeaders(DictionaryFrame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(DictionaryFrame)
const long DictionaryFrame::ID_BUTTON1 = wxNewId();
const long DictionaryFrame::ID_BUTTON2 = wxNewId();
const long DictionaryFrame::ID_BUTTON3 = wxNewId();
const long DictionaryFrame::ID_BUTTON4 = wxNewId();
const long DictionaryFrame::ID_BUTTON5 = wxNewId();
const long DictionaryFrame::ID_BUTTON6 = wxNewId();
const long DictionaryFrame::ID_STATICBOX1 = wxNewId();
const long DictionaryFrame::ID_STATICTEXT1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DictionaryFrame,wxFrame)
    //(*EventTable(DictionaryFrame)
    //*)
END_EVENT_TABLE()

DictionaryFrame::DictionaryFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(DictionaryFrame)
    Create(parent, wxID_ANY, _("Dictionary"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(700,500));
    Move(wxPoint(0,0));
    SetBackgroundColour(wxColour(176,176,255));
    wxFont thisFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    SetFont(thisFont);
    Button1 = new wxButton(this, ID_BUTTON1, _("Search Meanings"), wxPoint(128,160), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button1->SetToolTip(_("Press To Search Meanings"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Search Plurals"), wxPoint(128,224), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button2->SetToolTip(_("Press To Search Plurals"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Search Opposites"), wxPoint(128,296), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
    Button3->SetToolTip(_("Press To Serach Opposites"));
    Button4 = new wxButton(this, ID_BUTTON4, _("Add New Words Meanings"), wxPoint(376,160), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button4Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button4->SetFont(Button4Font);
    Button4->SetToolTip(_("Press To Add New Words Meanings In The Dictionary"));
    Button5 = new wxButton(this, ID_BUTTON5, _("Add New Singular Plurals"), wxPoint(376,224), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button5->SetFont(Button5Font);
    Button5->SetToolTip(_("Press To Add New Singular Plurals In The Dictionary"));
    Button6 = new wxButton(this, ID_BUTTON6, _("Add New Words Opposites"), wxPoint(376,296), wxSize(192,40), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    Button6->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    Button6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));
    wxFont Button6Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    Button6->SetFont(Button6Font);
    Button6->SetToolTip(_("Press To Add New Words Opposites In The Dictionary"));
    StaticBox1 = new wxStaticBox(this, ID_STATICBOX1, _("MAIN MENU"), wxPoint(88,112), wxSize(520,264), 0, _T("ID_STATICBOX1"));
    StaticBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DICTIONARY"), wxPoint(224,40), wxSize(225,56), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxFont StaticText1Font(24,wxSWISS,wxFONTSTYLE_ITALIC,wxBOLD,false,_T("Kristen ITC"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DictionaryFrame::OnButton6Click);
    //*)
}

DictionaryFrame::~DictionaryFrame()
{
    //(*Destroy(DictionaryFrame)
    //*)
}

void DictionaryFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

///____________________________________________________________________________________


void DictionaryFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void DictionaryFrame::OnButton1Click(wxCommandEvent& event)
{
   SearchMeaningFrame* smframe = new SearchMeaningFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
   smframe->Show(true);

}

void DictionaryFrame::OnButton2Click(wxCommandEvent& event)
{
   SearchSPFrame* sspframe = new SearchSPFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
   sspframe->Show(true);
}

void DictionaryFrame::OnButton3Click(wxCommandEvent& event)
{
   SearchWOFrame* swoframe = new SearchWOFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
   swoframe->Show(true);
}

void DictionaryFrame::OnButton4Click(wxCommandEvent& event)
{
   AddNewWMFrame* anwmframe = new AddNewWMFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
   anwmframe->Show(true);
}

void DictionaryFrame::OnButton5Click(wxCommandEvent& event)
{
    AddNewSPFrame* anspframe = new AddNewSPFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    anspframe ->Show(true);
}

void DictionaryFrame::OnButton6Click(wxCommandEvent& event)
{
    AddNewWOFrame* anwoframe = new AddNewWOFrame(NULL,wxID_ANY,wxDefaultPosition,wxDefaultSize);
    anwoframe->Show(true);
}
