#pragma once
#include "afxdialogex.h"


// 程序信息 对话框

class 程序信息 : public CDialogEx
{
	DECLARE_DYNAMIC(程序信息)

public:
	程序信息(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~程序信息();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
