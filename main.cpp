#include <wx/wx.h>
#include <wx/generic/statbmpg.h>

class App: public wxApp
{
public:
    bool OnInit() override;

private:
    wxFrame* m_pFrame;
};

wxIMPLEMENT_APP(App);

class Frame: public wxFrame
{
public:
    Frame();
private:

};

bool App::OnInit()
{
    wxInitAllImageHandlers();
    if(!wxApp::OnInit())
    {
        return false;
    }

    m_pFrame = new Frame();
    m_pFrame->Show();    
    return true;
}

Frame::Frame()
: wxFrame(nullptr, wxID_ANY, wxS("HoloCure"))
{
    auto pSizer = new wxBoxSizer(wxVERTICAL);
    auto pStaticBitmap = new wxGenericStaticBitmap(this, wxID_ANY, wxBitmap(wxS("IDI_LOGO"), wxBITMAP_TYPE_PNG_RESOURCE), wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE);
    pStaticBitmap->SetScaleMode(wxStaticBitmap::Scale_AspectFit);
    pSizer->Add(pStaticBitmap, 1, wxEXPAND);
    auto pSizer2 = new wxBoxSizer(wxHORIZONTAL);
    auto pComboBox = new wxComboBox(this, wxID_INDEX);
    auto pButton = new wxButton(this, wxID_EXECUTE, wxS("실행"));
    pSizer2->Add(pComboBox, 1, wxALL);
    pSizer2->Add(pButton, 0, 0);
    pSizer->Add(pSizer2, 0, wxEXPAND | wxALL, 5);
    SetSizer(pSizer);
    Layout();
}
