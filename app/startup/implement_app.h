#pragma once
#include <wx/wx.h>

namespace HelloWorld
{
	class HelloApp : public wxApp
	{
	public:
		bool OnInit() override
		{
			wxFrame* frame = new wxFrame(NULL, -1, "Hello World");
			wxButton* btn = new wxButton(frame, -1, "Click");
			btn->Bind(wxEVT_BUTTON, &HelloApp::OnButtonClicked, this);
			frame->Show();
			return true;
		}

		void OnButtonClicked(wxCommandEvent& evt)
		{
			wxMessageBox("Button Clicked!");
		}
	};
}

IMPLEMENT_APP(HelloWorld::HelloApp);
