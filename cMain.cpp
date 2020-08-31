#include "cMain.h"


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Tic Tac Toe", wxPoint(30,30), wxSize(800,600))
{
	btn = new wxButton * [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);
	nField = new char[nFieldWidth * nFieldHeight];
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int i = 0; i < nFieldWidth; i++)
	{
		for (int j = 0; j < nFieldHeight; j++)
		{
			btn[j * nFieldWidth + i] = new wxButton(this, 10000 + (j * nFieldWidth + i));
			btn[j * nFieldWidth + i]->SetFont(font);
			grid->Add(btn[j * nFieldWidth + i], 1, wxEXPAND | wxALL);

			btn[j * nFieldWidth + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
			nField[j * nFieldWidth + i] = ' ';
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain()
{
	delete[]btn;
	delete[]nField;
}

void cMain::OnButtonClicked(wxCommandEvent& evt)
{
	//Get coordinates of button in nField array
	int i = (evt.GetId() - 10000) % nFieldWidth;
	int j = (evt.GetId() - 10000) / nFieldWidth;
	bool win = false;
	//Disable button, cant be pressed again
	btn[j * nFieldWidth + i]->Enable(false);
	//Place label of current player
	if (turn)
	{
		btn[j * nFieldWidth + i]->SetLabel('X');
		nField[j * nFieldWidth + i] = 'X';
		win = CheckWinner('X');
	}
	else
	{
		btn[j * nFieldWidth + i]->SetLabel('O');
		nField[j * nFieldWidth + i] = 'O';
		win = CheckWinner('O');
	}
	
	//If winner, display message and reset
	if (win)
	{
		//msg
		if (turn)
		{
			wxMessageBox("X Wins");
		}
		else
		{
			wxMessageBox("O Wins");
		}
		
		//reset
		for (int i = 0; i < nFieldWidth; i++)
		{
			for (int j = 0; j < nFieldWidth; j++)
			{
				nField[j * nFieldWidth + i] = ' ';
				btn[j * nFieldWidth + i]->SetLabel("");
				btn[j * nFieldWidth + i]->Enable(true);
			}
		}
	}
	turn = !turn;
	evt.Skip();
}

bool cMain::CheckWinner(char player)
{
	if (nField[0] == player && nField[1] == player && nField[2] == player)
	{
		return true;
	}
	else if (nField[3] == player && nField[4] == player && nField[5] == player)
	{
		return true;
	}
	else if (nField[6] == player && nField[7] == player && nField[8] == player)
	{
		return true;
	}
	else if (nField[0] == player && nField[3] == player && nField[6] == player)
	{
		return true;
	}
	else if (nField[1] == player && nField[4] == player && nField[7] == player)
	{
		return true;
	}
	else if (nField[2] == player && nField[5] == player && nField[8] == player)
	{
		return true;
	}
	else if (nField[0] == player && nField[4] == player && nField[8] == player)
	{
		return true;
	}
	else if (nField[2] == player && nField[4] == player && nField[6] == player)
	{
		return true;
	}
	return false;
}
