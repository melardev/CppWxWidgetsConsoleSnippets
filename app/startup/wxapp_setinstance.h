#pragma once
#include <wx/wx.h>

/// How to use SetInstance function, this is good when you
/// don't want to use the IMPLEMENT_APP macro, but I still don't recommend this approach
/// Instead I recommend to use IMPLEMENT_APP_NO_MAIN
namespace SetAppInstance
{
	class MyWxApp : public wxApp
	{
		bool OnInit() override
		{
			// Create frame
			wxFrame* frame = new wxFrame(NULL, wxID_ANY, "wxApp::SetInstance usage");

			// default argument is already true, so Show() is the same as Show(true)
			frame->Show();
			return true;
		}
	};

	int main(int argc, char** argv)
	{
		// MyWxApp derives from wxApp
		// This line is very important, because at this point wxWidgets does not know
		// who is our wxApp instance, let it know about that
		wxApp::SetInstance(new MyWxApp());
		wxEntryStart(argc, argv);
		if (wxTheApp->OnInit())
		{
			// Enter Main Ui Loop if Initialization was successful
			wxTheApp->OnRun();
		}
		wxTheApp->OnExit();
		wxEntryCleanup();
		return 0;
	}
}
