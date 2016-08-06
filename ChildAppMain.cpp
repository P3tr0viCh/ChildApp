//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ChildAppMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain *Main;

HHOOK Hook;

const int LeftRight = 100;
const int TopBottom = 100;

//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode < 0)
		return CallNextHookEx(NULL, nCode, wParam, lParam);

	tagKBDLLHOOKSTRUCT *str = (tagKBDLLHOOKSTRUCT *)lParam;

	if (wParam == WM_KEYDOWN)
	{
		switch (str->vkCode)
		{
			case VK_RWIN:
			case VK_LWIN:
			case VK_SLEEP:
			return 1;
		}
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormCreate(TObject *Sender)
{
	#ifdef _DEBUG
	btnClose->Visible = true;
	#endif

	Hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc,
		GetModuleHandle(NULL), 0);

	randomize();
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormDestroy(TObject *Sender)
{
	UnhookWindowsHookEx(Hook);
}
//---------------------------------------------------------------------------
TColor TMain::GetRandomColor()
{
	return (TColor) RGB(random(255),random(255),random(255));
}
//---------------------------------------------------------------------------
void TMain::UpdateScreen(WideString S)
{
	lblChar->Visible = S != "";

	lblChar->Caption = S;

	lblChar->Font->Color = GetRandomColor();

	int CharWidth = lblChar->Width;
	int CharHeight = lblChar->Height;
	int CharLeft = LeftRight + random(Width - CharWidth - LeftRight * 2);
	int CharTop = TopBottom + random(Height - CharHeight - TopBottom);

	lblChar->SetBounds(CharLeft, CharTop, CharWidth, CharHeight);

//	Canvas->Brush->Color = clWhite;
//	Canvas->FrameRect(Rect(LeftRight, TopBottom,
//		Width - LeftRight, Height - TopBottom));
}
//---------------------------------------------------------------------------
WideString TMain::VirtualKeyToString(WORD Key)
{
	if (Key >= VK_F1 && Key <= VK_F24)
		return "F" + IntToStr(Key - 111);

	if (Key >= 48 && Key <= 58) // 0..9
		return IntToStr(Key - 48);

	if (Key >= VK_NUMPAD0 && Key <= VK_NUMPAD9)
		return IntToStr(Key - 96);

	switch (Key) {
		case VK_CANCEL:     return "CTRL+BREAK";
		case VK_BACK:		return L"←";
		case VK_TAB:		return "TAB";
		case VK_RETURN:		return L"\u23CE";
		case VK_SHIFT:		return "SHIFT";
		case VK_CONTROL:	return "CTRL";
		case VK_MENU:		return "ALT";
		case VK_PAUSE:		return "PAUSE";
		case VK_CAPITAL:	return "CAPS LOCK";
		case VK_ESCAPE:		return "ESC";
		case VK_SPACE:		return L"\u2423";
		case VK_PRIOR:		return "PAGE UP";
		case VK_NEXT:		return "PAGE DOWN";
		case VK_END:		return "END";
		case VK_HOME:		return "HOME";
		case VK_LEFT:		return L"←";
		case VK_UP:			return L"↑";
		case VK_RIGHT:		return L"→";
		case VK_DOWN:		return L"↓";
		case VK_SELECT:		return "SELECT";
		case VK_EXECUTE:	return "EXECUTE";
		case VK_SNAPSHOT:
		case VK_PRINT:		return "PRT SC";
		case VK_INSERT:		return "INSERT";
		case VK_DELETE:		return "DELETE";
		case VK_HELP:		return "HELP";
		case VK_APPS:		return "APPS";
		case VK_MULTIPLY:	return "*";
		case VK_ADD:		return "+";
		case VK_SEPARATOR:	return "SEPARATOR";
		case 189: //-
		case VK_SUBTRACT:	return "-";
		case VK_DECIMAL:	return ",";
        case 191:
		case VK_DIVIDE:		return "/";
		case VK_NUMLOCK:	return "NUM LK";
		case VK_SCROLL:		return "SCROLL";

		case VK_LWIN:
		case VK_RWIN:		return "WIN";

		case 12:           	return "5"; // Num5

		case 187:           return "=";
		case 220:         	return "\\";

		case 65:         	return "Ф";
		case 66:         	return "И";
		case 67:         	return "С";
		case 68:         	return "В";
		case 69:         	return "У";
		case 70:         	return "А";
		case 71:         	return "П";
		case 72:         	return "Р";
		case 73:         	return "Ш";
		case 74:         	return "О";
		case 75:         	return "Л";
		case 76:         	return "Д";
		case 77:         	return "Ь";
		case 78:         	return "Т";
		case 79:         	return "Щ";
		case 80:         	return "З";
		case 81:         	return "Й";
		case 82:         	return "К";
		case 83:         	return "Ы";
		case 84:         	return "Е";
		case 85:         	return "Г";
		case 86:         	return "М";
		case 87:         	return "Ц";
		case 88:         	return "Ч";
		case 89:         	return "Н";
		case 90:         	return "Я";
		case 186:         	return "Ж";
		case 188:         	return "Б";
		case 190:         	return "Ю";
		case 192:           return "Ё";
		case 219:         	return "Х";
		case 221:         	return "Ъ";
		case 222:         	return "Э";

		default:
//			return "VK == " + IntToStr(Key);
            return "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UpdateScreen(VirtualKeyToString(Key));
    Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	WideString S;

	switch (Button) {
		case TMouseButton::mbLeft:   S = "LEFT"; break;
		case TMouseButton::mbMiddle: S = "MIDDLE"; break;
		case TMouseButton::mbRight:	 S = "RIGHT"; break;
		default: S = "";
	}

	UpdateScreen(S);
}
//---------------------------------------------------------------------------

