#pragma once
#include <wx/wx.h>

namespace MessageOutputDebug
{
	void main(int argc, char** argv)
	{
		wxEntryStart(argc, argv);

		// This messages, at least in Windows VS2017 don't appear in the console
		// but on the Output tab(usually it is at the bottom)
		wxMessageOutputDebug().Printf("Cool debug utility, isn't it? %s",
		                              "Yes, absolutely");

		wxMessageOutputDebug().Output("Its cool, I have really a nice time learning wxWidgets"),
			wxMessageOutputDebug().Output("With wxMessageOutputDebug I don't need to write a new line,"
				"it is done for me");

		wxEntryCleanup();
	}
}
