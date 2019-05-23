#pragma once
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/ffile.h>

namespace ReadWriteFile
{
	bool WriteToFile(const wxFileName& fileName, const wxString& content, const wxMBConv& mbConv = wxConvAuto())
	{
		//wxT("w+b") for binary mode
		wxFFile file(fileName.GetFullPath(), wxT("w"));
		if (!file.IsOpened()) { return false; }

		if (!file.Write(content, mbConv)) { return false; }
		return true;
	}

	bool ReadFromFile(const wxFileName& fileName, wxString* contents, const wxMBConv& mbConv = wxConvAuto())
	{
		// The default mode of wxFFile is "r" so there is no need to wxT("r") but for the sake
		// of readability we did
		wxFFile file(fileName.GetFullPath(), wxT("r"));
		if (file.IsOpened())
		{
			if (file.ReadAll(contents, mbConv))
				return true;
		}
		return false;
	}

	void main()
	{
		wxMBConvStrictUTF8 c;
		if (WriteToFile(wxFileName("./wx_file.txt"), "Written from wxWidgets", c))
			wxPrintf("File created and written successfully\n");

		wxString contents;
		if (ReadFromFile(wxFileName("./wx_file.txt"), &contents))
			wxPrintf("File contents:\n%s", contents);
	}
}
