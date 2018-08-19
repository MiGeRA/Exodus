#include "OperatorView.h"
#include "resource.h"

//----------------------------------------------------------------------------------------------------------------------
// Constructors
//----------------------------------------------------------------------------------------------------------------------
OperatorView::OperatorView(IUIManager& uiManager, OperatorViewPresenter& presenter, IYM2612& model, unsigned int channelNo, unsigned int operatorNo)
:ViewBase(uiManager, presenter), _presenter(presenter), _model(model), _initializedDialog(false), _currentControlFocus(0), _channelNo(channelNo), _operatorNo(operatorNo)
{
	SetDialogTemplateSettings(presenter.GetUnqualifiedViewTitle(), GetAssemblyHandle(), MAKEINTRESOURCE(IDD_YM2612_OPERATOR));
	SetDialogViewType();
}

//----------------------------------------------------------------------------------------------------------------------
// Operator functions
//----------------------------------------------------------------------------------------------------------------------
void OperatorView::SetTargetOperator(unsigned int channelNo, unsigned int operatorNo)
{
	_channelNo = channelNo;
	_operatorNo = operatorNo;
}

//----------------------------------------------------------------------------------------------------------------------
// Member window procedure
//----------------------------------------------------------------------------------------------------------------------
INT_PTR OperatorView::WndProcDialog(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	WndProcDialogImplementSaveFieldWhenLostFocus(hwnd, msg, wparam, lparam);
	switch (msg)
	{
	case WM_INITDIALOG:
		return msgWM_INITDIALOG(hwnd, wparam, lparam);
	case WM_DESTROY:
		return msgWM_DESTROY(hwnd, wparam, lparam);
	case WM_TIMER:
		return msgWM_TIMER(hwnd, wparam, lparam);
	case WM_COMMAND:
		return msgWM_COMMAND(hwnd, wparam, lparam);
	}
	return FALSE;
}

//----------------------------------------------------------------------------------------------------------------------
// Event handlers
//----------------------------------------------------------------------------------------------------------------------
INT_PTR OperatorView::msgWM_INITDIALOG(HWND hwnd, WPARAM wparam, LPARAM lparam)
{
	SetTimer(hwnd, 1, 100, NULL);

	return TRUE;
}

//----------------------------------------------------------------------------------------------------------------------
INT_PTR OperatorView::msgWM_DESTROY(HWND hwnd, WPARAM wparam, LPARAM lparam)
{
	KillTimer(hwnd, 1);

	return FALSE;
}

//----------------------------------------------------------------------------------------------------------------------
INT_PTR OperatorView::msgWM_TIMER(HWND hwnd, WPARAM wparam, LPARAM lparam)
{
	_initializedDialog = true;

	//##TODO## Ensure if the operator and channel have changed since the last time, that
	// we update them.

	return TRUE;
}

//----------------------------------------------------------------------------------------------------------------------
INT_PTR OperatorView::msgWM_COMMAND(HWND hwnd, WPARAM wparam, LPARAM lparam)
{
	//##TODO##

	return TRUE;
}
