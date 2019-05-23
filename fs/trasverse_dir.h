#pragma once
#include <wx/dir.h>
#include <wx/wxcrtvararg.h>

namespace TraverseDirectory
{
	class MyTraverser : public wxDirTraverser
	{
	public:
		bool found = false;

		virtual wxDirTraverseResult OnFile(const wxString& filename) override
		{
			if (found)
				return wxDIR_STOP;

			wxPrintf("%s\n", filename);
			if (filename.Contains("dir.h"))
			{
				found = true;
				return wxDIR_STOP;
			}
			return wxDIR_CONTINUE;
		}

		virtual wxDirTraverseResult OnDir(const wxString& dirname) override
		{
			if (found)
				return wxDIR_STOP;
			return wxDIR_CONTINUE;
		}
	};


	void main()
	{
		MyTraverser directoryWalker;
		wxDir startingPoint(wxGetCwd());
		startingPoint.Traverse(directoryWalker);
	}
}
