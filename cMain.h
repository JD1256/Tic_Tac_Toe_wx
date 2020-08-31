#include <wx/wx.h>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:
	int nFieldWidth = 3;
	int nFieldHeight = 3;
	wxButton** btn;
	char* nField = nullptr;
	bool turn = true;

	void OnButtonClicked(wxCommandEvent& evt);
	bool CheckWinner(char player);

};

